#ifndef SEMANT_H_
#define SEMANT_H_

#include <assert.h>
#include <iostream>  
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <unordered_set>
#include "cool-tree.h"
#include "stringtab.h"
#include "symtab.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

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
    if(class_name == SELF_TYPE->get_string()) {
      return &SELF_TYPE;
    }
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
    if(type_decl->get_string() == SELF_TYPE->get_string() || type_decl->get_string() == No_type->get_string()) {
      return true;
    }
    if(classes_map_.find(type_decl->get_string()) == classes_map_.end()) {
      return false;
    }
    return true;
  }
  // SELF_TYPE_C <= SELF_TYPE_C
  // SELF_TYPE_C <= T if C <= T
  // T <= SELF_TYPE_C is always false !!! 
  bool is_sub_class(Symbol sub_class, Symbol base_class, const std::string& class_name) {
    if(sub_class->get_string() == SELF_TYPE->get_string() && base_class->get_string() == SELF_TYPE->get_string()) {
      return true;
    }
    if(base_class->get_string() == SELF_TYPE->get_string()) {
      return false;
    }
    if(sub_class->get_string() == SELF_TYPE->get_string()) {
      sub_class = *get_symbol(class_name);
    }
    return is_sub_class(sub_class, base_class);
  }
  bool is_sub_class(Symbol sub_class, Symbol base_class) {
    // std::cerr << "~~~ Check sub class for: " << sub_class->get_string() << " and " << base_class->get_string() << std::endl; 
    // If sub_class is No_type.
    if(sub_class->get_string() == No_type->get_string()) {
      // std::cerr << "~~~ check rtn: true" << std::endl;
      return true;
    }
    if(sub_class->get_string() == base_class->get_string()) {
      // std::cerr << "~~~ check rtn: true" << std::endl;
      return true;
    }
    // If sub_class is Object.
    if(sub_class->get_string() == Object->get_string()) {
      if(base_class->get_string() == Object->get_string()) {
        // std::cerr << "~~~ check rtn: true" << std::endl;
        return true;
      }
      // std::cerr << "~~~ check rtn: false" << std::endl;
      return false;
    }
    Symbol parent = classes_map_[sub_class->get_string()]->get_parentname();
    std::string parent_name = parent->get_string();
    if(parent_name == base_class->get_string()) {
      // std::cerr << "~~~ check rtn: true" << std::endl;
      return true;
    } else {
      return is_sub_class(parent, base_class);
    }
  }

  bool isIntStringBool(Symbol* symbol) {
    std::string sym_str = (*symbol)->get_string();
    if(sym_str == Int->get_string() || sym_str == Str->get_string() || sym_str == Bool->get_string()) {
      return true;
    }
    return false;
  }

  // Find the least common ancestor for symbol1 and symbol2.
  // FIXME: lca needs to handle SELF_TYPE! See lecture for more information.
  Symbol* lca(const Symbol& s1, const Symbol& s2, const std::string& class_name) {
    bool base_of_s1 = false, base_of_s2 = false;
    if(s1->get_string() == SELF_TYPE->get_string() && s2->get_string() == SELF_TYPE->get_string()) {
      return get_symbol(SELF_TYPE->get_string());
    } else if(s1->get_string() == SELF_TYPE->get_string()) {
      return lca_helper(Object->get_string(), class_name, s2->get_string(), base_of_s1, base_of_s2);
    } else if(s2->get_string() == SELF_TYPE->get_string()) {
      return lca_helper(Object->get_string(), s1->get_string(), class_name, base_of_s1, base_of_s2);
    } else {
      return lca_helper(Object->get_string(), s1->get_string(), s2->get_string(), base_of_s1, base_of_s2);
    }
  }
  Symbol* lca_helper(const std::string& curr_symbol, const std::string& s1, const std::string& s2, bool& base_of_s1, bool& base_of_s2) {
    const std::vector<std::string>& children = inheritance_graph_[curr_symbol];
    bool base_s1 = false, base_s2 = false;
    // Go through all children.
    for(const auto& child : children) {
      bool tmp_base_s1 = false, tmp_base_s2 = false;
      Symbol* rtn = lca_helper(child, s1, s2, tmp_base_s1, tmp_base_s2);
      if(rtn != nullptr) { // If a children is already a common base, return.
        return rtn;
      } else { // If not, check whether this children is a base.
        base_s1 |= tmp_base_s1;
        base_s2 |= tmp_base_s2;
      }
    }
    // Check if current symbol is a base for a Symbol.
    base_s1 |= (curr_symbol == s1);
    base_s2 |= (curr_symbol == s2);
    base_of_s1 = base_s1;
    base_of_s2 = base_s2;
    // If current Symbol is base for both left and right, return this symbol.
    if(base_of_s1 && base_of_s2) {
      return get_symbol(curr_symbol);
    } else {
      return nullptr;
    }
  }
  // Helper function.
  void add_to_object_env(const std::string& class_name, const std::string& id, Symbol* type) {
    object_env_[class_name].addid(id, type);
  }
  Symbol* get_from_all_object_env(const std::string& class_name, const std::string& id, SymbolTable<std::string, Symbol>& local_object_env) {
    // std::cerr << "~~~ id is: " << id << std::endl;
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
  Symbol* get_self_type_symbol(const std::string& class_name, SymbolTable<std::string, Symbol>& local_object_env) {
    Symbol* rtn = get_from_all_object_env(class_name, SELF_TYPE->get_string(), local_object_env);
    if(rtn == nullptr) {
      return get_symbol(class_name);
    } else {
      return rtn;
    }
  }
  // This method go through the inheritance tree to find attribute defination.
  Symbol* get_from_object_env(const std::string& class_name, const std::string& id);
  Symbol* get_from_object_env_local(const std::string& class_name, const std::string& id) {
    return object_env_[class_name].lookup(id);
  }
  void add_to_method_env(const std::string& class_name, const std::string& method_id, const std::vector<std::pair<std::string, Symbol>>& args) {
    method_env_[class_name][method_id] = args;
  }
  bool is_method_exist(const std::string& class_name, const std::string& method_id) {
    if(get_from_method_env(class_name, method_id) == nullptr) {
      return false;
    }
    return true;
  }
  // Give two methods, check whether they have the same argument types and return type.
  bool is_method_args_same(const std::vector<std::pair<std::string, Symbol>>& m1, const std::vector<std::pair<std::string, Symbol>>& m2) {
    // std::cerr << "m1.size() is: " << m1.size() << " m2.size() is: " << m2.size() << std::endl; 
    if(m1.size() != m2.size()) {
      return false;
    }
    for(unsigned i = 0; i < m1.size(); i ++) {
      // std::cerr << "m1: " << m1[i].second->get_string() << " m2: " << m2[i].second->get_string() << std::endl;
      if(m1[i].second->get_string() != m2[i].second->get_string()) {
        return false;
      }
    }
    return true;
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
    if(args == nullptr) {
      return get_symbol(Object->get_string());
    }
    const std::pair<std::string, Symbol>& rtn_arg = args->back();
    // std::cerr << rtn_arg.second->get_string() << std::endl;
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
          continue;
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

