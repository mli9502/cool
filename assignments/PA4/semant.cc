

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



ClassTable::ClassTable(Classes classes) : semant_errors(0) , error_stream(cerr),
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
// FIXME: Need to check whether Main class contains method "main".
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
    std::map<std::string, int> visited;
    for(std::map<std::string, Class_>::const_iterator it = classes_map_.begin(); it != classes_map_.end(); it ++) {
        std::map<std::string, int> curr_visit;
        // Do not visit Object. All the other classes are derived from Object. So, if one of them if visited first, and Object is then visited, it will be falsely detected as a cycle.
        if(!visited[it->first] && it->first != Object->get_string()) {
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
    // Check whether class Main is defined.
    if(classes_map_.find(Main->get_string()) == classes_map_.end()) {
        this->semant_error() << "Class Main is not defined." << std::endl;
        return;
    }
    return;
}
// return false if cycle is detected.
bool ClassTable::dfs_detect_cycle(std::map<std::string, int>& visited, std::map<std::string, int>& curr_visit, const std::string& curr_class) {
    if(visited[curr_class]) {
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
    /* some semantic analysis code may go here */

    if (classtable->errors()) {
	cerr << "Compilation halted due to static semantic errors." << endl;
	exit(1);
    }
}

Classes program_class::get_classes() {
    return this->classes;
}


