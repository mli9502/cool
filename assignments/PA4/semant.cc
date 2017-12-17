

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "semant.h"
#include "utilities.h"


extern int semant_debug;
extern char *curr_filename;

//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
static Symbol 
    arg,
    arg2,
    Bool,
    concat,
    cool_abort,
    copy,
    Int,
    in_int,
    in_string,
    IO,
    length,
    Main,
    main_meth,
    No_class,
    No_type,
    Object,
    out_int,
    out_string,
    prim_slot,
    self,
    SELF_TYPE,
    Str,
    str_field,
    substr,
    type_name,
    val;
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
    if(!inheritance_graph_["String"].empty() || !inheritance_graph_["Int"].empty()) {
        for(const auto& class_name : inheritance_graph_["String"]) {
            this->semant_error(classes_map_[class_name]) << "Class " << class_name << " cannot inherit class String." << std::endl;
        }
        for(const auto& class_name : inheritance_graph_["Int"]) {
            this->semant_error(classes_map_[class_name]) << "Class " << class_name << " cannot inherit class Int." << std::endl;
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
    std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
    classtable->dump_method_env();
    std::cout << "+++++++++++++++++++++++++++++++" << std::endl;
    classtable->check_for_main_class();
    // FIXME: Add base calss symbol and method to child class.
    std::cout << "Start type checking ..." << std::endl;
    this->check_type(*classtable);

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

// TODO: Start working on type checking.
// NOTE: Do not have to return bool. Since error count will be incremented and checked after type check finish.
// TODO: Once global object env and method env are passed in, they are not going to be changed.
// TODO: Need to handle no_type_ for variable with type not defined.
// FIXME: Need to test inheritance.
// FIXME: Handle SELF_TYPE.
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
    for(int i = 0; i < features->len(); i ++) {
        features->nth(i)->check_type(class_name, local_object_env, class_table);
    }
}

std::pair<std::string, Symbol> formal_class::construct_id_type_pair(const std::string& class_name, ClassTable& class_table) {
    if(!class_table.is_basic_class(class_name) && !class_table.exists_type(type_decl)) {
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
            class_table.add_to_object_env(class_name, object_id, &No_type);
        } else {
            class_table.add_to_object_env(class_name, object_id, &type_decl);
        }
    }
}
void attr_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    local_object_env.enterscope();
    char* tmp_class_name = const_cast<char*>(class_name.c_str());
    Symbol class_symbol = idtable.add_string(tmp_class_name);
    local_object_env.addid(SELF_TYPE->get_string(), &class_symbol);
    Symbol expr_type = init->check_type(class_name, local_object_env, class_table);
    local_object_env.exitscope();
    // If Attr-No-Init.
    if(expr_type == nullptr) {
        return;
    } else {
        // Check T1(expr_type) <= T0(type_decl).
        if(class_table.is_sub_class(expr_type, type_decl)) {
            return;
        } else {
            class_table.semant_error(class_name, this) << "Type " << expr_type->get_string() << " does not match " << type_decl->get_string() << std::endl;
            return;
        }
    }
}
// TODO: Add method get_from_all_object_env(local_object_env, class_object_env) to search for ObjectId in all object envs. 
void method_class::check_type(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env, ClassTable& class_table) {
    
}

// If multiple defination happens, the later one overwrites the previous one.
void method_class::init_envs(const std::string& class_name, ClassTable& class_table) {
    std::string method_id = name->get_string();
    std::vector<std::pair<std::string, Symbol>> args;
    // NOTE: Need to handle base class first to prevent werid base class types.
    if(class_table.is_basic_class(class_name)) {  
        for(int i = 0; i < formals->len(); i ++) {
            args.push_back(formals->nth(i)->construct_id_type_pair(class_name, class_table));
        }
        args.push_back(std::make_pair("", return_type));
        class_table.add_to_method_env(class_name, method_id, args);
    } else {
        if(class_table.get_from_method_env(class_name, method_id) != nullptr) {
            class_table.semant_error(class_name, this) << ": Method " << method_id << " is a method of an inherited class." << std::endl;
        }
        if(class_table.get_from_method_env_local(class_name, method_id) != nullptr) {
            class_table.semant_error(class_name, this) << ": Method " << method_id << " is multiply defined in class." << std::endl;
            return;
        }
        for(int i = 0; i < formals->len(); i ++) {
            args.push_back(formals->nth(i)->construct_id_type_pair(class_name, class_table));
        }
        if(!class_table.exists_type(return_type)) {
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
    if(method_env_[class_name].find(method_id) == method_env_[class_name].end()) {
        if(parent_name == Object->get_string()) {
            return nullptr;
        } else {
            return get_from_method_env(parent_name, method_id);
        }
    } else {
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
    std::cerr << class_name << std::endl;
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
        std::cerr << ">>>>>>>>>" << std::endl;
        object_env_[entry.first].dump();
        std::cerr << "<<<<<<<<<" << std::endl;
    }
}