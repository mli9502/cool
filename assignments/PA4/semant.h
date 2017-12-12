#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include <map>
#include <vector>
#include <utility>
#include <string>
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

class ClassTable;
typedef ClassTable *ClassTableP;

// This is a structure that may be used to contain the semantic
// information such as the inheritance graph.  You may use it or not as
// you like: it is only here to provide a container for the supplied
// methods.

class ClassTable {
private:
  void install_basic_classes();
  bool dfs_detect_cycle(std::map<std::string, int>& visited, std::map<std::string, int>& curr_visit, const std::string& curr_class);

  int semant_errors;
  ostream& error_stream;
  // key: class name, val: the actual class.
  std::map<std::string, Class_> classes_map_;
  // key: class name, val: all the classes that inherits from it.
  std::map<std::string, std::vector<std::string> > inheritance_graph_;
  // key: class name, val: symbol table representing O corresponds to it.
  std::map<std::string, ObjectEnvType<std::string>> object_env_;
  // key: class name, val: { key: method name, val: vector representing list of arguments and return type. }
  // pair.first: name of the argument, note, the last entry has an empty name (""), used to represent return value.
  std::map<std::string, MethodEnvType<std::string>> method_env_;
public:
  ClassTable(Classes);
  int errors() { return semant_errors; }
  ostream& semant_error();
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  void add_user_defined_classes(program_class program);
  // Initialize object_env_ and method_env_ for a given class.
  void init_envs(Class_ c);
};


#endif

