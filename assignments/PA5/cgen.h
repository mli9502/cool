#include <assert.h>
#include <stdio.h>
#include <map>
#include <queue>
#include <utility>
#include <stdlib.h>
#include "emit.h"
#include "cool-tree.h"
#include "symtab.h"

extern int cgen_debug;

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

class MemAddr;
bool operator==(const MemAddr& lhs, const MemAddr& rhs);

class MemAddr {
public:
  std::string reg_name;
  // offsets are 0, 1, ... Does not include * WORD_SIZE.
  int offset;
  MemAddr(const std::string& reg) {
    reg_name = reg;
    offset = 0;
  }
  MemAddr(const std::string& reg, int offset) {
    reg_name = reg;
    this->offset = offset;
  }
};

bool operator==(const MemAddr& lhs, const MemAddr& rhs) {
  return (lhs.reg_name == rhs.reg_name) && (lhs.offset == rhs.offset);
}

class CgenClassTable;
typedef CgenClassTable *CgenClassTableP;

class CgenNode;
typedef CgenNode *CgenNodeP;

class CgenNode : public class__class {
private: 
  CgenNodeP parentnd;                        // Parent of class
  List<CgenNode> *children;                  // Children of class
  Basicness basic_status;                    // `Basic' if class is basic
                                            // `NotBasic' otherwise
  // A map keeping track of which method of current class has been included in the dispatch table while going through the methods in parent class.
  std::map<std::string, std::pair<method_class*, bool>> method_included;
  // A map keeping track of let var cnt for methods.
  // FIXME: 5/28/2018: Need to make this representing local_var_cnt. Which contains both local_var_cnt and case_var_cnt.
  std::map<std::string, int> local_var_map;
  // Dispatch table.
  // This includes all the methods from parent class and the current class.
  // In the form of: <P, m1>, <C, m2>, <P, m3>, <P, m4>, <C, m5>, <C, m6>.
  // In which parent class P contains m1, m2, m3, and current class C contains m2 (override), m5, m6.
  std::vector<std::pair<CgenNodeP, method_class*>> dispatch_table;

public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

  void add_child(CgenNodeP child);
  List<CgenNode> *get_children() { return children; }
  void set_parentnd(CgenNodeP p);
  CgenNodeP get_parentnd() { return parentnd; }
  int basic() { return (basic_status == Basic); }
  const std::vector<std::pair<CgenNodeP, method_class*>>& get_dispatch_table() {
    return this->dispatch_table;
  }
  const std::map<std::string, int>& get_local_var_map() {
    return this->local_var_map;
  }
  void set_local_var_map(const std::string& key, int val) {
    this->local_var_map[key] = val;
  }
  void set_dispatch_table() {
    // First put all methods into method_included map.
    const auto& node_methods = get_target_features<method_class, true>();
    for(auto& node_method : node_methods) {
      method_included[node_method->name->get_string()] = {node_method, false};
    }
    // If there's no parent. (This should be true only for Object class.)
    if(parentnd == nullptr) {
      for(auto& node_method : node_methods) {
        dispatch_table.push_back({this, node_method});
      }
      return;
    }
    const auto& parent_dispatch_table = parentnd->get_dispatch_table();
    // Go through parent dispatch table first.
    for(auto& entry : parent_dispatch_table) {
      std::string method_name = entry.second->name->get_string();
      if(method_included.find(method_name) != method_included.end()) { // If this method in parent is overriden by child.
        // Mark this method as visited.
        method_included[method_name].second = true;
        // Push this into dispatch table.
        dispatch_table.push_back({this, method_included[method_name].first});
      } else {
        dispatch_table.push_back(entry);
      }
    }
    // Then, go through methods of current class, and put in remaining ones.
    for(auto& node_method : node_methods) {
      const auto& val = method_included[node_method->name->get_string()];
      if(val.second) { // If this method is already included in the dispatch table.
        continue;
      } else {
        dispatch_table.push_back({this, node_method});
      }
    }
  }
  // This depends on dispatch table.
  // TODO: Call this method when doing BFS to correctly setup local var map.
  // TODO: Do a bottom-up DFS to update local-var-cnt to max of a class's children.
  void set_local_var_map() {
    for(auto& entry : this->dispatch_table) {
      std::string method_name = entry.second->name->get_string();
      // If this method is inherited from a parent class.
      // Use the local var cnt from parent class.
      if(entry.first != this) {
        auto& parent_local_var_map = entry.first->get_local_var_map();
        this->local_var_map[method_name] = parent_local_var_map.at(method_name);
      } else {
        this->local_var_map[method_name] = entry.second->count_max_local_vars();
      }
    }
  }
};

class CgenClassTable : public SymbolTable<Symbol,CgenNode> {
private:
  List<CgenNode> *nds;
  ostream& str;
  int stringclasstag;
  int intclasstag;
  int boolclasstag;

  // The following methods emit code for
  // constants and global declarations.
  // count for tag.
  int tag_cnt;
  // After entering let_expression or case expression, increase curr_local_cnt.
  // Before exiting let_expression or case expression, decrease curr_local_cnt.
  // To get the location of the local var, use (4 * curr_local_cnt)($s1).
  // Setup activation record after method activation.
  // Initial value is 1.
  int curr_local_cnt;

  void code_global_data();
  void code_global_text();
  void code_bools(int);
  void code_select_gc();
  void code_constants();
  void code_class_nameTab();
  void code_class_dispTab();
  void code_class_protObj();
  void code_single_class_protObj(CgenNode* curr_class);
  void code_single_class_init(CgenNode* curr_class);
  void code_class_methods();
  void code_single_class_methods(CgenNode* curr_class);
  void disp_count_local_vars();
  void set_class_tags_member();
  void set_class_tags_member_helper(CgenNodeP node, int& tag);

  // Get all methods (including methods from parents) of the given node.
  // Order: Parent first, node at the end.
  template <typename T, bool check>
  std::vector<std::pair<CgenNodeP, T*>> get_target_features_helper(CgenNodeP node) {
    std::vector<std::pair<CgenNodeP, T*>> rtn;
    for(auto m : node->get_target_features<T, check>()) {
      rtn.push_back(std::make_pair(node, m));
    }
    if(node == root()) {
      return rtn;
    } else {
      auto parent_rtn = get_target_features_helper<T, check>(node->get_parentnd());
      rtn.insert(rtn.begin(), parent_rtn.begin(), parent_rtn.end());
      return rtn;
    }
  }

// The following creates an inheritance graph from
// a list of classes.  The graph is implemented as
// a tree of `CgenNode', and class names are placed
// in the base class symbol table.

   void install_basic_classes();
   void install_class(CgenNodeP nd);
   void install_classes(Classes cs);
   void build_inheritance_tree();
   void set_relations(CgenNodeP nd);
   void set_class_tags();
public:
    CgenClassTable(Classes, ostream& str);
    void update_store(const std::string& mem_addr, int offset, Symbol type) {
      if(type == nullptr) {
        if(cgen_debug) std::cout << "[CgenClassTable::update_store]: type is NULL!" << std::endl;
        return;
      }
      update_store(mem_addr, offset, type->get_string());
    }

    void update_store(const std::string& mem_addr, int offset, std::string type) {
      if(cgen_debug) std::cout << "In update_store..." << endl;
      MemAddr addr(mem_addr, offset);
      auto store_rtn = this->store.lookup(addr);
      // If this address is not found, add it first.
      if(store_rtn == nullptr) {
        if(cgen_debug) std::cout << "store_rtn is null" << endl;
        store.addid(addr, nullptr);
      }
      this->store.update(addr, new std::string(type));
    }
    // Using BFS to initialize dispatch table for classes.
    // Note that BFS is needed because dispatch table for parent classes needs to be setup before proceeding to child classes.
    void bfs_init_classes_dispatch_table();
    // Using BFS to initialize local var cnt map after dispatch table is set up.
    void bfs_init_classes_local_var_cnt_map();
    // Using bottom-up dfs to update local var cnt to correct value.
    void dfs_correct_classes_local_var_cnt_map();
    void dfs_correct_classes_local_var_cnt_map_helper(CgenNodeP node);
    void code_callee_activation_record_setup(ostream& s, int local_var_cnt);
    void code_callee_activation_record_cleanup(ostream& s, int curr_arg_cnt, int curr_local_var_cnt);
    void code_caller_activation_record_setup(ostream& s, Expressions args, CgenClassTable& cgenClassTable);
    int get_method_offset(const std::string& class_name, const std::string& method_name);
    int get_method_local_var_cnt_dynamic(const std::string& class_name, const std::string& method_name);
    int get_method_local_var_cnt_static(const std::string& class_name, const std::string& method_name);
    void init_local_var(const std::string& type_name, ostream& os);
    CgenNodeP get_cgen_node_from_class_name(const std::string& class_name);
    CgenNodeP get_cgen_node_from_symbol(Symbol s);
    std::vector<branch_class*> sort_branches(Cases cases);
    void code();
    CgenNodeP root();
    std::vector<std::pair<CgenNodeP, method_class*>> get_all_methods(CgenNodeP node) {
      return this->get_target_features_helper<method_class, true>(node);
    }
    std::vector<std::pair<CgenNodeP, attr_class*>> get_all_attrs(CgenNodeP node) {
      return this->get_target_features_helper<attr_class, false>(node);
    }
    int get_tag_cnt() {
      return this->tag_cnt ++;
    }
    void init_curr_local_cnt() {
      this->curr_local_cnt = 1;
    }
    int get_curr_local_cnt() {
      return this->curr_local_cnt ++;
    }
    void dec_curr_local_cnt() {
      this->curr_local_cnt --;
    }

     /*
    Key: variable name.
    Val: MemAddr
    */
    SymbolTable<std::string, MemAddr> environment;
    /*
    Key: MemAddr
    Val: Name of the object in the location specified by key.
    */
    SymbolTable<MemAddr, std::string> store;
    // Class name of the current self object.
    Symbol self_class;
    // val.first: class tag.
    // val.second: max class tag of its subclass. This is needed to generate case expression.
    std::map<CgenNodeP, std::pair<int, int>> _class_tags;
    // The parameter cnt for current method.
    // This is set at code_single_class_methods.
    // This is needed for let expression to locate the starting location of the first let_var.
    int curr_method_actual_cnt;
    int curr_method_max_local_cnt;
};

class BoolConst 
{
 private: 
  int val;
 public:
  BoolConst(int);
  void code_def(ostream&, int boolclasstag);
  void code_ref(ostream&) const;
};

