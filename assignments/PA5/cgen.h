#include <assert.h>
#include <stdio.h>
#include "emit.h"
#include "cool-tree.h"
#include "symtab.h"

enum Basicness     {Basic, NotBasic};
#define TRUE 1
#define FALSE 0

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

public:
   CgenNode(Class_ c,
            Basicness bstatus,
            CgenClassTableP class_table);

   void add_child(CgenNodeP child);
   List<CgenNode> *get_children() { return children; }
   void set_parentnd(CgenNodeP p);
   CgenNodeP get_parentnd() { return parentnd; }
   int basic() { return (basic_status == Basic); }
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

  void code_global_data();
  void code_global_text();
  void code_bools(int);
  void code_select_gc();
  void code_constants();
  void code_class_nameTab();
  void code_class_dispTab();
  void code_class_protObj();
  void code_single_class_protObj(CgenNode* curr_class);
  // Get all methods (including methods from parents) of the given node.
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
  std::vector<std::pair<CgenNodeP, method_class*>> get_all_methods(CgenNodeP node) {
    return this->get_target_features_helper<method_class, true>(node);
  }
  std::vector<std::pair<CgenNodeP, attr_class*>> get_all_attrs(CgenNodeP node) {
    return this->get_target_features_helper<attr_class, false>(node);
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
   void code();
   CgenNodeP root();
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

