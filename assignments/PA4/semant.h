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
  ostream& out_stream;
  // key: class name, val: the actual class.
  std::map<std::string, Class_> classes_map_;
  // key: class name, val: corresponding Symbol.
  std::map<std::string, Symbol> classes_symbol_map_;
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
  ostream& semant_error(const std::string& class_name, tree_node* t);
  ostream& semant_error(Class_ c);
  ostream& semant_error(Symbol filename, tree_node *t);
  void add_user_defined_classes(program_class program);
  // FIXME: May need to filter out base classes?
  void init_classes_symbol_map() {
    for(auto entry : classes_map_) {
      char* class_name = const_cast<char*>(entry.first.c_str());
      classes_symbol_map_[entry.first] = idtable.add_string(class_name);
    }
  }
  Symbol* get_symbol(const std::string& class_name) {
    // FIXME: This may need to change to Object.
    if(classes_map_.find(class_name) == classes_map_.end()) {
      return &No_type;
    } else {
      return &classes_symbol_map_[class_name];
    }
  }
  void check_for_main_class();
  // Initialize envs for all classes in classes_map_.
  void init_all_envs();
  // Initialize object_env_ and method_env_ for a given class.
  // init_envs will also check for undefined types, and assign no_type_ to these attributes or methods.
  void init_envs(Class_ c);
  bool is_basic_class(const std::string& class_name) {
    if(std::string(classes_map_[class_name]->get_filename()->get_string()) == "<basic class>") {
      return true;
    }
    return false;
  }
  bool exists_type(Symbol type_decl) {
    if(classes_map_.find(type_decl->get_string()) == classes_map_.end()) {
      return false;
    }
    return true;
  }
  bool is_sub_class(Symbol sub_class, Symbol base_class) {
    // If sub_class is No_type.
    if(sub_class->get_string() == No_type->get_string()) {
      return true;
    }
    // If sub_class is Object.
    if(sub_class->get_string() == Object->get_string()) {
      if(base_class->get_string() == Object->get_string()) {
        return true;
      }
      return false;
    }
    Symbol parent = classes_map_[sub_class->get_string()]->get_parentname();
    std::string parent_name = parent->get_string();
    if(parent_name == base_class->get_string()) {
      return true;
    } else {
      return is_sub_class(parent, base_class);
    }
  }
  // Helper function.
  void add_to_object_env(const std::string& class_name, const std::string& id, Symbol* type) {
    object_env_[class_name].addid(id, type);
  }
  Symbol* get_from_all_object_env(const std::string& class_name, const std::string& id, SymbolTable<std::string, Symbol>& local_object_env) {
    auto prob_result = local_object_env.probe(id);
    auto lookup_result = local_object_env.lookup(id);
    auto global_result = get_from_object_env(class_name, id);
    if(prob_result != nullptr) {
      return prob_result;
    }
    if(lookup_result != nullptr) {
      return lookup_result;
    }
    return global_result;
  }
  // This method go through the inheritance tree to find attribute defination.
  Symbol* get_from_object_env(const std::string& class_name, const std::string& id);
  Symbol* get_from_object_env_local(const std::string& class_name, const std::string& id) {
    return object_env_[class_name].lookup(id);
  }
  void add_to_method_env(const std::string& class_name, const std::string& method_id, const std::vector<std::pair<std::string, Symbol>>& args) {
    method_env_[class_name][method_id] = args;
  }
  // This method go through the inheritance tree to find method defination.
  std::vector<std::pair<std::string, Symbol>>* get_from_method_env(const std::string& class_name, const std::string& method_id);
  std::vector<std::pair<std::string, Symbol>>* get_from_method_env_local(const std::string& class_name, const std::string& method_id) {
    if(method_env_[class_name].find(method_id) == method_env_[class_name].end()) {
      return nullptr;
    } else {
      return &(method_env_[class_name][method_id]);
    }
  }
  Symbol* get_method_rtn_type(const std::string& class_name, const std::string& method_id) {
    auto* args = get_from_method_env(class_name, method_id);
    const std::pair<std::string, Symbol>& rtn_arg = args->back();
    return get_symbol(rtn_arg.second->get_string());
  }

  ObjectEnvType<std::string>& get_class_object_env(const std::string& class_name) {
    return object_env_[class_name];
  }
  MethodEnvType<std::string>& get_class_method_env(const std::string& class_name) {
    return method_env_[class_name];
  }
  void dump_method_env() {
    for(const auto& entry : method_env_) {
      std::cout << "----- class: " << entry.first << " -----" << std::endl;
      for(const auto& method_entry : entry.second) {
        unsigned arg_size = method_entry.second.size();
        std::cout << method_entry.first << " : " << method_entry.second[arg_size - 1].second->get_string() << " (";
        // If there's no arg.
        if(arg_size == 1) {
          std::cout << ")" << std::endl;
          break;
        }
        for(unsigned i = 0; i < arg_size - 2; i ++) {
          dump_arg(method_entry.second[i]) << ", ";
        }
        dump_arg(method_entry.second[arg_size - 2]) << ")" << std::endl;
      }
    }
  }
  ostream& dump_arg(const std::pair<std::string, Symbol>& arg) {
    return out_stream << arg.first << " : " << arg.second->get_string();
  }
};


#endif

