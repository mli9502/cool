// FIXME: Each method should have a new local_object_env.
// It can not use the passed in local_object_env!

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"


extern int semant_debug;
extern char *curr_filename;

//
// Initializing the predefined symbols.
//
static void initialize_constants(void)
{
    arg         = idtable.add_string("arg");
    arg2        = idtable.add_string("arg2");
    Bool        = idtable.add_string("Bool");
    concat      = idtable.add_string("concat");
    cool_abort  = idtable.add_string("abort");
    copy        = idtable.add_string("copy");
    Int         = idtable.add_string("Int");
    in_int      = idtable.add_string("in_int");
    in_string   = idtable.add_string("in_string");
    IO          = idtable.add_string("IO");
    length      = idtable.add_string("length");
    Main        = idtable.add_string("Main");
    main_meth   = idtable.add_string("main");
    //   _no_class is a symbol that can't be the name of any 
    //   user-defined class.
    No_class    = idtable.add_string("_no_class");
    No_type     = idtable.add_string("_no_type");
    Object      = idtable.add_string("Object");
    out_int     = idtable.add_string("out_int");
    out_string  = idtable.add_string("out_string");
    prim_slot   = idtable.add_string("_prim_slot");
    self        = idtable.add_string("self");
    SELF_TYPE   = idtable.add_string("SELF_TYPE");
    Str         = idtable.add_string("String");
    str_field   = idtable.add_string("_str_field");
    substr      = idtable.add_string("substr");
    type_name   = idtable.add_string("type_name");
    val         = idtable.add_string("_val");
}



ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr), out_stream(cout), 
                                            classes_map_(), inheritance_graph_() {

    /* Fill this in */
    install_basic_classes();
}

void ClassTable::install_basic_classes() {

    // The tree package uses these globals to annotate the classes built below.
   // curr_lineno  = 0;
    Symbol filename = stringtable.add_string("<basic class>");
    
    // The following demonstrates how to create dummy parse trees to
    // refer to basic Cool classes.  There's no need for method
    // bodies -- these are already built into the runtime system.
    
    // IMPORTANT: The results of the following expressions are
    // stored in local variables.  You will want to do something
    // with those variables at the end of this method to make this
    // code meaningful.

    // 
    // The Object class has no parent class. Its methods are
    //        abort() : Object    aborts the program
    //        type_name() : Str   returns a string representation of class name
    //        copy() : SELF_TYPE  returns a copy of the object
    //
    // There is no need for method bodies in the basic classes---these
    // are already built in to the runtime system.

    Class_ Object_class =
	class_(Object, 
	       No_class,
	       append_Features(
			       append_Features(
					       single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
					       single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
			       single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	       filename);
    classes_map_[Object->get_string()] = Object_class;                
    // 
    // The IO class inherits from Object. Its methods are
    //        out_string(Str) : SELF_TYPE       writes a string to the output
    //        out_int(Int) : SELF_TYPE            "    an int    "  "     "
    //        in_string() : Str                 reads a string from the input
    //        in_int() : Int                      "   an int     "  "     "
    //
    Class_ IO_class = 
	class_(IO, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       single_Features(method(out_string, single_Formals(formal(arg, Str)),
										      SELF_TYPE, no_expr())),
							       single_Features(method(out_int, single_Formals(formal(arg, Int)),
										      SELF_TYPE, no_expr()))),
					       single_Features(method(in_string, nil_Formals(), Str, no_expr()))),
			       single_Features(method(in_int, nil_Formals(), Int, no_expr()))),
	       filename);  
    classes_map_[IO->get_string()] = IO_class;
    //
    // The Int class has no methods and only a single attribute, the
    // "val" for the integer. 
    //
    Class_ Int_class =
	class_(Int, 
	       Object,
	       single_Features(attr(val, prim_slot, no_expr())),
	       filename);
    classes_map_[Int->get_string()] = Int_class;
    //
    // Bool also has only the "val" slot.
    //
    Class_ Bool_class =
	class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename);
    classes_map_[Bool->get_string()] = Bool_class;
    //
    // The class Str has a number of slots and operations:
    //       val                                  the length of the string
    //       str_field                            the string itself
    //       length() : Int                       returns length of the string
    //       concat(arg: Str) : Str               performs string concatenation
    //       substr(arg: Int, arg2: Int): Str     substring selection
    //       
    Class_ Str_class =
	class_(Str, 
	       Object,
	       append_Features(
			       append_Features(
					       append_Features(
							       append_Features(
									       single_Features(attr(val, Int, no_expr())),
									       single_Features(attr(str_field, prim_slot, no_expr()))),
							       single_Features(method(length, nil_Formals(), Int, no_expr()))),
					       single_Features(method(concat, 
								      single_Formals(formal(arg, Str)),
								      Str, 
								      no_expr()))),
			       single_Features(method(substr, 
						      append_Formals(single_Formals(formal(arg, Int)), 
								     single_Formals(formal(arg2, Int))),
						      Str, 
						      no_expr()))),
	       filename);
    classes_map_[Str->get_string()] = Str_class;
}

void ClassTable::add_user_defined_classes(program_class program) {
    Classes classes = program.get_classes();
    for(int i = 0; i < classes->len(); i ++) {
        std::string class_name = classes->nth(i)->get_classname()->get_string();
        if(class_name == No_class->get_string()) {
            this->semant_error(classes->nth(i)->get_filename(), classes->nth(i)) << "Found user defined class with name _no_class!" << std::endl;
            return;
        }
        if(classes_map_.find(class_name) != classes_map_.end()) {
            this->semant_error(classes->nth(i)->get_filename(), classes->nth(i)) << "Class " << class_name << " was previously defined." << std::endl;
            return; 
        }
        classes_map_[class_name] = classes->nth(i);
    }
    // Set up inheritance graph.
    for(std::map<std::string, Class_>::const_iterator it = classes_map_.begin(); it != classes_map_.end(); it ++) {
        const std::string& class_name = it->first;
        const std::string& parent_name = it->second->get_parentname()->get_string();
        // Do not check the parent of Object since it is No_class.
        if(classes_map_.find(parent_name) == classes_map_.end() && class_name != Object->get_string()) {
            this->semant_error(it->second->get_filename(), it->second) << "Class " << class_name << " inherits from an undefined class " << parent_name << std::endl;
            return;
        } else {
            if(inheritance_graph_.find(parent_name) == inheritance_graph_.end()) {
                inheritance_graph_[parent_name] = std::vector<std::string>();
            }
            inheritance_graph_[parent_name].push_back(class_name);
        }
    }
    /*
    // Stuff used to print class hierechy.
    for(const auto& entry : inheritance_graph_) {
        std::cout << entry.first << ": ";
        for(const auto& class_name : entry.second) {
            std::cout << class_name << ", ";
        }
        std::cout << std::endl;
    }
    */
    std::map<std::string, int> visited;
    for(std::map<std::string, Class_>::const_iterator it = classes_map_.begin(); it != classes_map_.end(); it ++) {
        std::map<std::string, int> curr_visit;
        // Do not visit Object. All the other classes are derived from Object. So, if one of them if visited first, and Object is then visited, it will be falsely detected as a cycle.
        if(visited[it->first] == 0 && it->first != Object->get_string()) {
            // std::cerr << "Visiting " << it->first << std::endl;
            // If cycle is detected.
            if(!dfs_detect_cycle(visited, curr_visit, it->first)) {
                for(std::map<std::string, int>::const_iterator it = curr_visit.begin(); it != curr_visit.end(); it ++) {
                    if(it->second) {
                        Class_ cycle_class = classes_map_[it->first];
                        this->semant_error(cycle_class->get_filename(), cycle_class) << "Class " << it->first << ", or an ancestor of " << it->first << ", is involved in an inheritance cycle." << std::endl;
                    }
                }
                return;
            }
        }
    }
    // Check if there are any classes inherit from Int or String.
    if(!inheritance_graph_["String"].empty() || !inheritance_graph_["Int"].empty() || !inheritance_graph_["Bool"].empty()) {
        for(const auto& class_name : inheritance_graph_["String"]) {
            this->semant_error(classes_map_[class_name]) << "Class " << class_name << " cannot inherit class String." << std::endl;
        }
        for(const auto& class_name : inheritance_graph_["Int"]) {
            this->semant_error(classes_map_[class_name]) << "Class " << class_name << " cannot inherit class Int." << std::endl;
        }
        for(const auto& class_name : inheritance_graph_["Bool"]) {
            this->semant_error(classes_map_[class_name]) << "Class " << class_name << " cannot inherit class Bool." << std::endl;
        }
    }
}
// return false if cycle is detected.
// 1: is visiting. 2: finish.
bool ClassTable::dfs_detect_cycle(std::map<std::string, int>& visited, std::map<std::string, int>& curr_visit, const std::string& curr_class) {
    if(visited[curr_class] == 1) {
        return false;
    }
    visited[curr_class] = 1;
    curr_visit[curr_class] = 1;
    const std::vector<std::string>& sub_classes = inheritance_graph_[curr_class];
    for(std::vector<std::string>::const_iterator it = sub_classes.begin(); it != sub_classes.end(); it ++) {
        if(!dfs_detect_cycle(visited, curr_visit, *it)) {
            return false;
        }
    }
    visited[curr_class] = 2;
    return true;
}

////////////////////////////////////////////////////////////////////
//
// semant_error is an overloaded function for reporting errors
// during semantic analysis.  There are three versions:
//
//    ostream& ClassTable::semant_error()                
//
//    ostream& ClassTable::semant_error(Class_ c)
//       print line number and filename for `c'
//
//    ostream& ClassTable::semant_error(Symbol filename, tree_node *t)  
//       print a line number and filename
//
///////////////////////////////////////////////////////////////////

ostream& ClassTable::semant_error(const std::string& class_name, tree_node* t) {
    return semant_error(classes_map_[class_name]->get_filename(), t);
}

ostream& ClassTable::semant_error(Class_ c)
{                                                             
    return semant_error(c->get_filename(),c);
}    

ostream& ClassTable::semant_error(Symbol filename, tree_node *t)
{
    error_stream << filename << ":" << t->get_line_number() << ": ";
    return semant_error();
}

ostream& ClassTable::semant_error()                  
{                                                 
    semant_errors++;                            
    return error_stream;
} 



/*   This is the entry point to the semantic checker.

     Your checker should do the following two things:

     1) Check that the program is semantically correct
     2) Decorate the abstract syntax tree with type information
        by setting the `type' field in each Expression node.
        (see `tree.h')

     You are free to first do 1), make sure you catch all semantic
     errors. Part 2) can be done in a second stage, when you want
     to build mycoolc.
 */
void program_class::semant()
{
    initialize_constants();
    /* ClassTable constructor may do some semantic analysis */
    ClassTable* classtable = new ClassTable(classes);
    classtable->add_user_defined_classes(*this);
    classtable->init_classes_symbol_map();
    if (classtable->errors()) {
        cerr << "Compilation halted due to static semantic errors." << endl;
        exit(1);
    }
    /* some semantic analysis code may go here */
    // Initialize object environemnt and method environment here.
    // NOTE: While initializing environments, also find objectId with undefined types.
    // Check for undefined types in both object environment and method environment. 
    // Assign no_type_ to these attribute and methods. 
    // TODO: no_type_ needs to be handled specially else where.
    classtable->init_all_envs();
    // std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
    // classtable->dump_method_env();
    // std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
    classtable->check_for_main_class();
    // std::cout << "Start type checking ..." << std::endl;
    this->check_type(*classtable);
    if (classtable->errors()) {
        cerr << "Compilation halted due to static semantic errors." << endl;
        exit(1);
    }
    // According to the given semant, it does not stop when redudent defination is found.
    // As a result, the exit here is not needed.
    // if (classtable->errors()) {
	//     cerr << "Compilation halted due to static semantic errors." << endl;
	//     exit(1);
    // }
}

Classes program_class::get_classes() {
    return this->classes;
}

void program_class::check_type(ClassTable& class_table) {
    Classes classes = this->get_classes();
    for(int i = 0; i < classes->len(); i ++) {
        classes->nth(i)->check_type(class_table);
    }
    return;
}

void class__class::check_type(ClassTable& class_table) {
    SymbolTable<std::string, Symbol> local_object_env;
    const std::string& class_name = name->get_string();
    // std::cerr << "--- Start type checking for class: " << class_name << std::endl;
    for(int i = 0; i < features->len(); i ++) {
        features->nth(i)->check_type(class_name, local_object_env, class_table);
    }
}

std::pair<std::string, Symbol> formal_class::construct_id_type_pair(const std::string& class_name, ClassTable& class_table) {
    if(!class_table.is_basic_class(class_name) && !class_table.exists_type(type_decl)) {
        // FIXME: May need to change No_type to Object.
        class_table.semant_error(class_name, this) << "Class " << type_decl->get_string() << " of formal parameter " << name->get_string() << " is undefined." << std::endl;
        return std::make_pair(name->get_string(), No_type);
    }
    return std::make_pair(name->get_string(), type_decl);
}
void attr_class::init_envs(const std::string& class_name, ClassTable& class_table) {
    std::string object_id = name->get_string();
    if(class_table.is_basic_class(class_name)) {
        class_table.add_to_object_env(class_name, object_id, &type_decl);
    } else {
        // If attribute name is self, report error.
        if(object_id == self->get_string()) {
            class_table.semant_error(class_name, this) << "'self' cannot be the name of an attribute." << std::endl;
            return;
        }
        // If objectId is previously defined in a parent class. Report error, but add to this class's environment.
        if(class_table.get_from_object_env(class_name, object_id) != nullptr) {
            class_table.semant_error(class_name, this) << "Attribute " << object_id << " is an attribute of an inherited class." << std::endl;
        }
        // If objectId is previously defined in this class, do not add to this class's environment.
        if(class_table.get_from_object_env_local(class_name, object_id) != nullptr) {
            class_table.semant_error(class_name, this) << "Attribute " << object_id << " is multiply defined in class." << std::endl;
            return;
        }
        // Check if if basic class to prevent checking for some werid class used by basic classes.
        if(!class_table.exists_type(type_decl)) {
            class_table.semant_error(class_name, this) << "Class " << type_decl->get_string() << " of attribute " << object_id << " is undefined." << std::endl;
            // FIXME: May need to change No_type to Object.
            class_table.add_to_object_env(class_name, object_id, &No_type);
        } else {
            class_table.add_to_object_env(class_name, object_id, &type_decl);
        }
    }
}

Symbol* branch_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    Symbol* id_type = class_table.get_symbol(type_decl->get_string());
    // FIXME: May need to check id_type. If No_type, report error.
    local_object_env.enterscope();
    local_object_env.addid(name->get_string(), id_type);
    rtn = expr->check_type(class_name, local_object_env, class_table);
    local_object_env.exitscope();
    return rtn;
}

Symbol* typcase_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    bool found_err = false;
    // T0
    Symbol* expr_type = expr->check_type(class_name, local_object_env, class_table);
    std::unordered_set<std::string> branch_types_set;
    // FIXME: Check unique for declared types instead of types labled by type checking.
    for(int i = 0; i < cases->len(); i ++) {
        Symbol branch_decl_type = cases->nth(i)->get_type_decl();
        std::string branch_decl_type_str = branch_decl_type->get_string();
        if(branch_types_set.find(branch_decl_type_str) != branch_types_set.end()) {
            class_table.semant_error(class_name, this) << "Found duplicate branch type " << branch_decl_type_str << "." << std::endl;
            break;
        } else {
            branch_types_set.insert(branch_decl_type_str);
        }
    }
    // T1' ... Tn'
    std::vector<Symbol*> branch_types;
    for(int i = 0; i < cases->len(); i ++) {
        Symbol* branch_type = cases->nth(i)->check_type(class_name, local_object_env, class_table);
        std::string branch_type_str = (*branch_type)->get_string();
        branch_types.push_back(branch_type);
    }
    // std::cerr << "~~~ branch_types.size() is: " << branch_types.size() << std::endl;
    Symbol* curr_common_ancestor = branch_types.at(0);
    for(unsigned i = 1; i < branch_types.size(); i ++) {
        curr_common_ancestor = class_table.lca(*curr_common_ancestor, *(branch_types.at(i)), class_name);
    }
    if(!found_err) {
        rtn = curr_common_ancestor;
    }
    this->type = *rtn;
    return rtn;
}

Symbol* eq_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if(class_table.isIntStringBool(e1_type) && 
        class_table.isIntStringBool(e2_type) &&
        (*e1_type)->get_string() != (*e2_type)->get_string()) {
            class_table.semant_error(class_name, this) << "Both e1 and e2 type are Int, String or Bool, but e1 type " << (*e1_type)->get_string() << " is not equal to e2 type " << (*e2_type)->get_string() << "." << std::endl;
    } else {
        rtn = class_table.get_symbol(Bool->get_string());
    }
    this->type = *rtn;
    return rtn;
}
// FIXME: IMPORTANT: When "self" veriable is found, SELF_TYPE is returned as type.
// SELF_TYPE is then used as key to look up for the actual type in object env. 
void attr_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    // std::cerr << "--- Start type checking for attr_class: " << name->get_string() << std::endl;
    local_object_env.enterscope();
    Symbol* class_symbol = class_table.get_symbol(class_name);
    // local_object_env.addid(SELF_TYPE->get_string(), class_symbol);
    Symbol* expr_type = init->check_type(class_name, local_object_env, class_table);
    // If there is an expr type.
    // if((expr_type != nullptr) && (*expr_type)->get_string() == SELF_TYPE->get_string()) {
    //     expr_type = class_table.get_self_type_symbol(class_name, local_object_env);
    // }
    local_object_env.exitscope();
    Symbol* decl_type = &type_decl;
    // if(type_decl->get_string() == SELF_TYPE->get_string()) {
    //     decl_type = class_table.get_self_type_symbol(class_name, local_object_env);
    // }
    // If Attr-No-Init.
    // TODO: no_expr return nullptr as type.
    if(expr_type == nullptr) {
        return;
    } else {
        // Check T1(expr_type) <= T0(type_decl).
        if(class_table.is_sub_class(*expr_type, *decl_type, class_name)) {
            return;
        } else {
            class_table.semant_error(class_name, this) << "Type " << (*expr_type)->get_string() << " does not match " << (*decl_type)->get_string() << "." << std::endl;
            return;
        }
    }
}
// FIXME: type may need to be No_type.
Symbol* no_expr_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    this->type = (Symbol)nullptr;
    return nullptr;
}

Symbol* let_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    bool found_err = false;
    // T0'
    Symbol* id_type = class_table.get_symbol(type_decl->get_string());
    // FIXME: May need to check id_type. If it is No_type, report error.
    // T1 (Let-Init). If it's Let-No-Init, init_type is nullptr.
    Symbol* init_type = init->check_type(class_name, local_object_env, class_table);
    // If it is Let-Init.
    if(init_type != nullptr) {
        // T1 <= T0'
        if(!class_table.is_sub_class(*init_type, *id_type, class_name)) {
            class_table.semant_error(class_name, this) << "Type " << (*init_type)->get_string() << " is not a child of " << (*id_type)->get_string() << "." << std::endl;
            found_err = true;
        }
    }
    // Check if self is used as identifier.
    if(identifier->get_string() == self->get_string()) {
        class_table.semant_error(class_name, this) << "'self' cannot be bound in a 'let' expression." << std::endl;
    } else {
        local_object_env.enterscope();
        local_object_env.addid(identifier->get_string(), id_type);
        // T2 (Let-Init) / T1 (Let-No-Init)
        Symbol* body_type = body->check_type(class_name, local_object_env, class_table);
        local_object_env.exitscope();
        if(!found_err) {
            rtn = body_type;
        }
    }
    this->type = *rtn;
    return rtn;
}
// NOTE: For method class, it does not use the passed in local_object_env.
// Each method creates a new local_object_env, which is method_local_object_env, and pass that down.
void method_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    SymbolTable<std::string, Symbol> method_local_object_env;
    // std::cerr << "--- Start type checking for method: " << this->name->get_string() << std::endl;
    method_local_object_env.enterscope();
    Symbol* class_symbol = class_table.get_symbol(class_name);
    // local_object_env.addid(SELF_TYPE->get_string(), class_symbol);
    // std::cerr << "------------------------" << std::endl;
    // local_object_env.dump();
    // std::cerr << "------------------------" << std::endl;
    for(int i = 0; i < formals->len(); i ++) {
        std::pair<std::string, Symbol> formal_pair = formals->nth(i)->construct_id_type_pair(class_name, class_table);
        Symbol* formal_symbol = class_table.get_symbol(formal_pair.second->get_string());
        method_local_object_env.addid(formal_pair.first, formal_symbol);
    }
    // std::cerr << "~~~ Before expression check type" << std::endl;
    Symbol* expr_type = expr->check_type(class_name, method_local_object_env, class_table);
    // std::cerr << (*expr_type)->get_string() << std::endl;
    // if((*expr_type)->get_string() == SELF_TYPE->get_string()) {
    //     expr_type = class_table.get_self_type_symbol(class_name, local_object_env);
    // }
    method_local_object_env.exitscope();
    // Check T0'(expr_type_symbol) <= T0(return_type)
    Symbol* method_rtn_type = class_table.get_method_rtn_type(class_name, name->get_string());
    // std::cerr << "check for is_sub_class: " << (*expr_type)->get_string() << ", " << (*method_rtn_type)->get_string() << std::endl;
    if(class_table.is_sub_class(*expr_type, *method_rtn_type, class_name)) {
        return;
    } else {
        class_table.semant_error(class_name, this) << "Type " << (*expr_type)->get_string() << " does not match " << (*method_rtn_type)->get_string() << "." << std::endl;
        return;
    }
}

void method_class::init_envs(const std::string& class_name, ClassTable& class_table) {
    std::string method_id = name->get_string();
    // std::cerr << "----------------- class_name: " << class_name << ", method_id: " << method_id << std::endl;  
    std::vector<std::pair<std::string, Symbol>> args;
    // NOTE: Need to handle base class first to prevent werid base class types.
    if(class_table.is_basic_class(class_name)) {
        for(int i = 0; i < formals->len(); i ++) {
            args.push_back(formals->nth(i)->construct_id_type_pair(class_name, class_table));
        }
        args.push_back(std::make_pair("", return_type));
        class_table.add_to_method_env(class_name, method_id, args);
    } else {
        // If method is already defined in current class, report error.
        if(class_table.get_from_method_env_local(class_name, method_id) != nullptr) {
            class_table.semant_error(class_name, this) << "Method " << method_id << " is multiply defined in class." << std::endl;
            return;
        }
        // Need to check for dup formals here, and also self type as a formal parameter.
        std::unordered_set<std::string> argSet;
        for(int i = 0; i < formals->len(); i ++) {
            auto tmpPair = formals->nth(i)->construct_id_type_pair(class_name, class_table);
            if(tmpPair.second->get_string() == SELF_TYPE->get_string()) {
                class_table.semant_error(class_name, this) << "Formal parameter " << tmpPair.first << " cannot have type SELF_TYPE." << std::endl;
            }
            if(tmpPair.first == self->get_string()) {
                class_table.semant_error(class_name, this) << "'self' cannot be the name of a formal parameter." << std::endl;
            }
            if(argSet.find(tmpPair.first) != argSet.end()) {
                class_table.semant_error(class_name, this) << "Formal parameter " << tmpPair.first << " is multiply defined." << std::endl;
            }
            args.push_back(tmpPair);
            argSet.insert(tmpPair.first);
        }
        // If method is defined in parent class.
        auto* env_rtn = class_table.get_from_method_env(class_name, method_id);
        if(env_rtn != nullptr) {
            std::vector<std::pair<std::string, Symbol>> env_rtn_args(env_rtn->begin(), env_rtn->end() - 1);
            if(!class_table.is_method_args_same(args, env_rtn_args)) {
                // Check for inheritance here!
                // Need to make sure that the arguments are the same as the method got from parent.
                // NOTE: If method does not have the same arguments as the method from parent. Just report error.
                class_table.semant_error(class_name, this) << "Method " << method_id << " is a method of an inherited class." << std::endl;            
                return;
            }
        }
        if(!class_table.exists_type(return_type)) {
            class_table.semant_error(class_name, this) << "Undefined return type " << return_type->get_string() << " in method " << method_id << "." << std::endl;
            args.push_back(std::make_pair("", No_type));
        } else {
            args.push_back(std::make_pair("", return_type));
        }
        class_table.add_to_method_env(class_name, method_id, args);
    }
}

void class__class::init_envs(const std::string& class_name, ClassTable& class_table) {
    for(int i = 0; i < features->len(); i ++) {
        features->nth(i)->init_envs(class_name, class_table);
    }
}

Symbol* assign_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    Symbol* id_type = class_table.get_from_all_object_env(class_name, name->get_string(), local_object_env);
    if(id_type == nullptr) {
        class_table.semant_error(class_name, this) << "Assignment to undeclared variable " << name->get_string() << "." << std::endl;
    } else {
        Symbol* expr_type = expr->check_type(class_name, local_object_env, class_table);
        // If T' <= T.
        if(class_table.is_sub_class(*expr_type, *id_type, class_name)) {
            rtn = expr_type;
        } else {
            class_table.semant_error(class_name, this) << "Type " << (*expr_type)->get_string() << " of assigned expression does not conform to declared type " << (*id_type)->get_string() << " of id." << std::endl;
        }
    }
    this->type = *rtn;
    return rtn;
}

Symbol* cond_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    Symbol* pred_type = pred->check_type(class_name, local_object_env, class_table);
    // If condition is not bool.
    if((*pred_type)->get_string() != Bool->get_string()) {
        // FIXME: Fix error message.
        class_table.semant_error(class_name, this) << "Found condition type " << (*pred_type)->get_string() << ", should be Bool instead." << std::endl;
    } else {
        Symbol* then_expr_type = then_exp->check_type(class_name, local_object_env, class_table);
        Symbol* else_expr_type = else_exp->check_type(class_name, local_object_env, class_table);
        rtn = class_table.lca(*then_expr_type, *else_expr_type, class_name);
    }
    this->type = *rtn;
    return rtn;
}

Symbol* loop_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    Symbol* pred_type = pred->check_type(class_name, local_object_env, class_table);
    // If condition is not bool.
    if((*pred_type)->get_string() != Bool->get_string()) {
        // FIXME: Fix error message.
        class_table.semant_error(class_name, this) << "Found condition type " << (*pred_type)->get_string() << ", should be Bool instead." << std::endl;
    } else {
        Symbol* body_type = body->check_type(class_name, local_object_env, class_table);
    }
    this->type = *rtn;
    return rtn;
}

Symbol* block_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    for(int i = 0; i < body->len(); i ++) {
        Symbol* expr_type = body->nth(i)->check_type(class_name, local_object_env, class_table);
        if(i == body->len() - 1) {
            rtn = expr_type;
        }
    }
    this->type = *rtn;
    return rtn;
}

Symbol* static_dispatch_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    // e0: T0.
    Symbol* caller_type = expr->check_type(class_name, local_object_env, class_table);
    // T
    Symbol* method_lookup_type = class_table.get_symbol(type_name->get_string());
    const std::string& method_lookup_class = (*method_lookup_type)->get_string();
    // Need to check T0 <= T first.
    if(!class_table.is_sub_class(*caller_type, *method_lookup_type, class_name)) {
        class_table.semant_error(class_name, this) << "Expression type " << (*caller_type)->get_string() << " does not conform to declared static dispatch type " << method_lookup_class << "." << std::endl;
    } else {
        const std::string& method_id = name->get_string();
        // T1 ... Tn
        std::vector<Symbol*> arg_symbols;
        for(int i = 0; i < this->actual->len(); i ++) {
            arg_symbols.push_back(this->actual->nth(i)->check_type(class_name, local_object_env, class_table));
        }
        if(!class_table.is_method_exist(method_lookup_class, method_id)) {
            // FIXME: Fix error message.
            class_table.semant_error(class_name, this) << "Method " << method_id << " does not exist for class " << method_lookup_class << "." << std::endl;
        } else {
            // Tn+1'
            Symbol* method_rtn_type = class_table.get_method_rtn_type(method_lookup_class, method_id);
            std::vector<std::pair<std::string, Symbol>>* method_args = class_table.get_from_method_env(method_lookup_class, method_id);
            // T1' ... Tn'
            std::vector<Symbol> method_params_types;
            for(unsigned i = 0; i < (*method_args).size() - 1; i ++) {
                method_params_types.push_back((*method_args)[i].second);
            }
            if(arg_symbols.size() != method_params_types.size()) {
                class_table.semant_error(class_name, this) << "Method " << method_id << " is called with " << arg_symbols.size() << " arguments, but require " << method_params_types.size() << " parameters!" << std::endl;
            } else {
                bool found_err = false;
                // Check Ti <= Ti' for 1 <= i <=n.
                for(unsigned i = 0; i < arg_symbols.size(); i ++) {
                    if(!class_table.is_sub_class(*(arg_symbols[i]), method_params_types[i], class_name)) {
                        // FIXME: Error message may need to include parameter name.
                        class_table.semant_error(class_name, this) << "Method " << method_id << " requires type " << (*(arg_symbols[i]))->get_string() << ", but found " << method_params_types[i]->get_string() << "." << std::endl;
                        found_err = true;
                    }
                }
                if(!found_err) {
                    if((*method_rtn_type)->get_string() == SELF_TYPE->get_string()) {
                        rtn = caller_type;
                    } else {
                        rtn = method_rtn_type;
                    }
                }
            }
        }
    }
    this->type = *rtn;
    return rtn;
}

Symbol* object_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    // std::cerr << "--- Start type checking for object_class: " << name->get_string() << std::endl;
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    if(name->get_string() == self->get_string()) {
        rtn = &SELF_TYPE;
    } else {
        Symbol* id_type = class_table.get_from_all_object_env(class_name, name->get_string(), local_object_env);
        if(id_type != nullptr) {
            rtn = id_type;
        } else {
            class_table.semant_error(class_name, this) << "Object id " << name->get_string() << " is not defined." << endl;
        }
    }
    this->type = *rtn;
    return rtn;
}

// If SELF_TYPE is in object env, return its values, else, return current class.
Symbol* dispatch_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    // std::cerr << "--- Start type checking for dispatch: " << this->name->get_string() << std::endl;
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    // T0
    Symbol* caller_type = expr->check_type(class_name, local_object_env, class_table);
    // std::cerr << "~~~ caller_type is: " << (*caller_type)->get_string() << std::endl;
    // T0' (Type used for method lookup.)
    Symbol* method_lookup_type = caller_type;
    if((*method_lookup_type)->get_string() == SELF_TYPE->get_string()) {
        // method_lookup_type = class_table.get_self_type_symbol(class_name, local_object_env);
        method_lookup_type = class_table.get_symbol(class_name);
    }
    // std::cerr << " !!!!!!!!!!!!!!!!!!!!!!!! " << std::endl; 
    // FIXME: Handle method_lookup_type is nullptr case.
    // NOTE: This is the class name used to look up method!
    const std::string& method_lookup_class = (*method_lookup_type)->get_string();
    // std::cerr << "method_lookup_class: " << method_lookup_class << std::endl;
    // T1 ... Tn
    std::vector<Symbol*> arg_symbols;
    for(int i = 0; i < this->actual->len(); i ++) {
        Symbol* actual_symbol = actual->nth(i)->check_type(class_name, local_object_env, class_table);
        if((*actual_symbol)->get_string() == SELF_TYPE->get_string()) {
            arg_symbols.push_back(class_table.get_symbol(class_name));
        } else {
            arg_symbols.push_back(this->actual->nth(i)->check_type(class_name, local_object_env, class_table));
        }
    }
    const std::string& method_id = name->get_string();
    // Check if method exists for method lookup type.
    if(!class_table.is_method_exist(method_lookup_class, method_id)) {
        // FIXME: Fix error message.
        class_table.semant_error(class_name, this) << "Method " << method_id << " does not exist for class " << method_lookup_class << "." << std::endl; 
    } else {
        // Get method return type and argument types.
        // Tn+1'
        // std::cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        Symbol* method_rtn_type = class_table.get_method_rtn_type(method_lookup_class, method_id);
        // std::cerr << "~~~ method rtn type is: " << (*method_rtn_type)->get_string() << std::endl;
        // std::cerr << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::vector<std::pair<std::string, Symbol>>* method_args = class_table.get_from_method_env(method_lookup_class, method_id);
        // T1' ... Tn'
        std::vector<Symbol> method_params_types;
        for(unsigned i = 0; i < (*method_args).size() - 1; i ++) {
            // FIXME: Debugging printout here...
            // std::cerr << (*method_args)[i].first << std::endl;
            method_params_types.push_back((*method_args)[i].second);
        }
        // FIXME: Check method argument number match here. Not sure whether this is needed or not.
        if(arg_symbols.size() != method_params_types.size()) {
            class_table.semant_error(class_name, this) << "Method " << method_id << " is called with " << arg_symbols.size() << " arguments, but require " << method_params_types.size() << " parameters!" << std::endl;
        } else {
            bool found_err = false;
            // Check Ti <= Ti' for 1 <= i <= n.
            for(unsigned i = 0; i < arg_symbols.size(); i ++) {
                if(!class_table.is_sub_class(*(arg_symbols[i]), method_params_types[i], class_name)) {
                    // FIXME: Error message may need to include parameter name.
                    class_table.semant_error(class_name, this) << "Method " << method_id << " requires type " << (*(arg_symbols[i]))->get_string() << ", but found " << method_params_types[i]->get_string() << "." << std::endl;
                    found_err = true;
                }
            }
            if(!found_err) {
                if((*method_rtn_type)->get_string() == SELF_TYPE->get_string()) {
                    rtn = caller_type;
                } else {
                    rtn = method_rtn_type;
                }
            }
        }
    }
    this->type = *rtn;
    return rtn;
}

Symbol* new__class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Object->get_string());
    if(!class_table.exists_type(type_name)) {
        // FIXME: Fix error message.
        class_table.semant_error(class_name, this) << "'new' used with undefined class " << type_name->get_string() << "." << std::endl; 
    } else {
        rtn = class_table.get_symbol(type_name->get_string());
    }
    this->type = *rtn;
    return rtn;
}

Symbol* bool_const_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Bool->get_string());
    this->type = *rtn;
    return rtn;
}

Symbol* isvoid_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Bool->get_string());
    Symbol* expr_type = e1->check_type(class_name, local_object_env, class_table);
    this->type = *rtn;
    return rtn;
}

Symbol* plus_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Int->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Plus argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl; 
    }
    if((*e2_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Plus argument expects Int, but found " << (*e2_type)->get_string() << "." << std::endl; 
    }
    this->type = *rtn;
    return rtn;
}

Symbol* sub_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Int->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Sub argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl; 
    }
    if((*e2_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Sub argument expects Int, but found " << (*e2_type)->get_string() << "." << std::endl; 
    }
    this->type = *rtn;
    return rtn;
}

Symbol* mul_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Int->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Mul argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl; 
    }
    if((*e2_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Mul argument expects Int, but found " << (*e2_type)->get_string() << "." << std::endl; 
    }
    this->type = *rtn;
    return rtn;
}

Symbol* divide_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Int->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Divide argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl; 
    }
    if((*e2_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Divide argument expects Int, but found " << (*e2_type)->get_string() << "." << std::endl; 
    }
    this->type = *rtn;
    return rtn;
}

Symbol* lt_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Bool->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Lt argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl; 
    }
    if((*e2_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Lt argument expects Int, but found " << (*e2_type)->get_string() << "." << std::endl; 
    }
    this->type = *rtn;
    return rtn;
}

Symbol* leq_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Bool->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    Symbol* e2_type = e2->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Leq argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl; 
    }
    if((*e2_type)->get_string() != Int->get_string()) {
       rtn = class_table.get_symbol(Object->get_string());
       // FIXME: Fix error message.
       class_table.semant_error(class_name, this) << "Leq argument expects Int, but found " << (*e2_type)->get_string() << "." << std::endl; 
    }
    this->type = *rtn;
    return rtn;
}

Symbol* neg_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Int->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Int->get_string()) {
        rtn = class_table.get_symbol(Object->get_string());
        // FIXME: Fix error message.
        class_table.semant_error(class_name, this) << "Neg argument expects Int, but found " << (*e1_type)->get_string() << "." << std::endl;
    }
    this->type = *rtn;
    return rtn;
}

Symbol* comp_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Bool->get_string());
    Symbol* e1_type = e1->check_type(class_name, local_object_env, class_table);
    if((*e1_type)->get_string() != Bool->get_string()) {
        rtn = class_table.get_symbol(Object->get_string());
        // FIXME: Fix error message.
        class_table.semant_error(class_name, this) << "Comp (not) argument expects Bool, but found " << (*e1_type)->get_string() << "." << std::endl;
    }
    this->type = *rtn;
    return rtn;
}

Symbol* int_const_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Int->get_string());
    this->type = *rtn;
    return rtn;
}

Symbol* string_const_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    Symbol* rtn = class_table.get_symbol(Str->get_string());
    this->type = *rtn;
    return rtn;
}

// This method go through the inheritance tree to find attribute defination.
Symbol* ClassTable::get_from_object_env(const std::string& class_name, const std::string& id) {
    Symbol* rtn = object_env_[class_name].lookup(id);
    if(class_name == Object->get_string()) {
        return rtn;
    }
    const std::string& parent_name = classes_map_[class_name]->get_parentname()->get_string();
    if(rtn == nullptr) {
        if(parent_name == Object->get_string()) {
            return nullptr;
        } else {
            return get_from_object_env(parent_name, id);
        }
    } else {
        return rtn;
    }
}

// This method go through the inheritance tree to find method defination.
std::vector<std::pair<std::string, Symbol>>* ClassTable::get_from_method_env(const std::string& class_name, const std::string& method_id) {
    const std::string& parent_name = classes_map_[class_name]->get_parentname()->get_string();
    // std::cerr << "~~~ class_name: " << class_name << ", method_id: " << method_id << std::endl;
    // std::cerr << "~~~ parent_name: " << parent_name << ", method_id: " << method_id << std::endl;
    if(method_env_[class_name].find(method_id) == method_env_[class_name].end()) {
        // std::cerr << "*** method " << method_id << " not found in class " << class_name << std::endl; 
        if(parent_name == No_class->get_string()) {
            return nullptr;
        } else {
            // std::cerr << "*** try to find method " << method_id << " in " << parent_name << std::endl;
            return get_from_method_env(parent_name, method_id);
        }
    } else {
        // std::cerr << "*** FOUND METHOD " << method_id << " IN CLASS: " << class_name << std::endl;
        return &(method_env_[class_name][method_id]);
    }
}

void ClassTable::check_for_main_class() {
    // Check whether class Main is defined.
    if(classes_map_.find(Main->get_string()) == classes_map_.end()) {
        this->semant_error() << "Class Main is not defined." << std::endl;
    }
    return;
}
void ClassTable::init_envs(Class_ c) {
    std::string class_name = c->get_classname()->get_string();
    if(class_name == SELF_TYPE->get_string()) {
        this->semant_error("SELF_TYPE", c) << "Redefinition of basic class SELF_TYPE." << std::endl;
    }
    // std::cerr << class_name << std::endl;
    object_env_[class_name] = SymbolTable<std::string, Symbol>();
    // TODO: The symbol table used by class is not the same as the symbol table used when doing type checking.
    // A new symbol table is needed when doing type checking for each class.
    method_env_[class_name] = std::map<std::string, std::vector<std::pair<std::string, Symbol>>>();
    object_env_[class_name].enterscope();
    c->init_envs(class_name, *this);
} 
// NOTE: enter scope will push a new list to stack.
// exit scope will pop that list. If scope is exit, it is gone.
void ClassTable::init_all_envs() {
    for(const auto& entry : classes_map_) {
        init_envs(entry.second);
        // std::cerr << ">>>>>>>>>" << std::endl;
        // object_env_[entry.first].dump();
        // std::cerr << "<<<<<<<<<" << std::endl;
    }
}
