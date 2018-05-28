//////////////////////////////////////////////////////////
//
// file: cool-tree.cc
//
// This file defines the functions of each class
//
//////////////////////////////////////////////////////////


#include "tree.h"
#include "cool-tree.handcode.h"
#include "cool-tree.h"


// constructors' functions
Program program_class::copy_Program()
{
   return new program_class(classes->copy_list());
}


void program_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "program\n";
   classes->dump(stream, n+2);
}

int program_class::count_max_let_vars() {
  int rtn = 0;
  for(int i = 0; i < classes->len(); i ++) {
    rtn = std::max(classes->nth(i)->count_max_let_vars(), rtn);
  }
  return rtn;
}

int program_class::count_max_case_vars() {
  int rtn = 0;
  for(int i = 0; i < classes->len(); i ++) {
    rtn = std::max(classes->nth(i)->count_max_case_vars(), rtn);
  }
  return rtn;
}


Class_ class__class::copy_Class_()
{
   return new class__class(copy_Symbol(name), copy_Symbol(parent), features->copy_list(), copy_Symbol(filename));
}


void class__class::dump(ostream& stream, int n)
{
   stream << pad(n) << "class_\n";
   dump_Symbol(stream, n+2, name);
   dump_Symbol(stream, n+2, parent);
   features->dump(stream, n+2);
   dump_Symbol(stream, n+2, filename);
}

int class__class::count_max_let_vars() {
  int rtn = 0;
  for(int i = 0; i < features->len(); i ++) {
    rtn = std::max(features->nth(i)->count_max_let_vars(), rtn);
  }
  return rtn;
}

int class__class::count_max_case_vars() {
  int rtn = 0;
  for(int i = 0; i < features->len(); i ++) {
    rtn = std::max(features->nth(i)->count_max_case_vars(), rtn);
  }
  return rtn;
}


Feature method_class::copy_Feature()
{
   return new method_class(copy_Symbol(name), formals->copy_list(), copy_Symbol(return_type), expr->copy_Expression());
}


void method_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "method\n";
   dump_Symbol(stream, n+2, name);
   formals->dump(stream, n+2);
   dump_Symbol(stream, n+2, return_type);
   expr->dump(stream, n+2);
}

int method_class::count_max_let_vars() {
  int rtn = expr->count_max_let_vars();
  for(int i = 0; i < formals->len(); i ++) {
    rtn = std::max(formals->nth(i)->count_max_let_vars(), rtn);
  }
  return rtn;
}

int method_class::count_max_case_vars() {
  int rtn = expr->count_max_case_vars();
  for(int i = 0; i < formals->len(); i ++) {
    rtn = std::max(formals->nth(i)->count_max_case_vars(), rtn);
  }
  return rtn;
}


Feature attr_class::copy_Feature()
{
   return new attr_class(copy_Symbol(name), copy_Symbol(type_decl), init->copy_Expression());
}


void attr_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "attr\n";
   dump_Symbol(stream, n+2, name);
   dump_Symbol(stream, n+2, type_decl);
   init->dump(stream, n+2);
}

int attr_class::count_max_let_vars() {
  return init->count_max_let_vars();
}

int attr_class::count_max_case_vars() {
  return init->count_max_case_vars();
}

Formal formal_class::copy_Formal()
{
   return new formal_class(copy_Symbol(name), copy_Symbol(type_decl));
}


void formal_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "formal\n";
   dump_Symbol(stream, n+2, name);
   dump_Symbol(stream, n+2, type_decl);
}

int formal_class::count_max_let_vars() {
  return 0;
}

int formal_class::count_max_case_vars() {
  return 0;
}

Case branch_class::copy_Case()
{
   return new branch_class(copy_Symbol(name), copy_Symbol(type_decl), expr->copy_Expression());
}


void branch_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "branch\n";
   dump_Symbol(stream, n+2, name);
   dump_Symbol(stream, n+2, type_decl);
   expr->dump(stream, n+2);
}

int branch_class::count_max_let_vars() {
  return expr->count_max_let_vars();
}

int branch_class::count_max_case_vars() {
  return expr->count_max_case_vars();
}

Expression assign_class::copy_Expression()
{
   return new assign_class(copy_Symbol(name), expr->copy_Expression());
}


void assign_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "assign\n";
   dump_Symbol(stream, n+2, name);
   expr->dump(stream, n+2);
}

int assign_class::count_max_let_vars() {
  return expr->count_max_let_vars();
}

int assign_class::count_max_case_vars() {
  return expr->count_max_case_vars();
}


Expression static_dispatch_class::copy_Expression()
{
   return new static_dispatch_class(expr->copy_Expression(), copy_Symbol(type_name), copy_Symbol(name), actual->copy_list());
}


void static_dispatch_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "static_dispatch\n";
   expr->dump(stream, n+2);
   dump_Symbol(stream, n+2, type_name);
   dump_Symbol(stream, n+2, name);
   actual->dump(stream, n+2);
}

int static_dispatch_class::count_max_let_vars() {
  int rtn = expr->count_max_let_vars();
  for(int i = 0; i < actual->len(); i ++) {
    rtn = std::max(actual->nth(i)->count_max_let_vars(), rtn);
  }
  return rtn;
}

int static_dispatch_class::count_max_case_vars() {
  int rtn = expr->count_max_case_vars();
  for(int i = 0; i < actual->len(); i ++) {
    rtn = std::max(actual->nth(i)->count_max_case_vars(), rtn);
  }
  return rtn;
}


Expression dispatch_class::copy_Expression()
{
   return new dispatch_class(expr->copy_Expression(), copy_Symbol(name), actual->copy_list());
}


void dispatch_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "dispatch\n";
   expr->dump(stream, n+2);
   dump_Symbol(stream, n+2, name);
   actual->dump(stream, n+2);
}

int dispatch_class::count_max_let_vars() {
  int rtn = expr->count_max_let_vars();
  for(int i = 0; i < actual->len(); i ++) {
    rtn = std::max(actual->nth(i)->count_max_let_vars(), rtn);
  }
  return rtn;
}

int dispatch_class::count_max_case_vars() {
  int rtn = expr->count_max_case_vars();
  for(int i = 0; i < actual->len(); i ++) {
    rtn = std::max(actual->nth(i)->count_max_case_vars(), rtn);
  }
  return rtn;
}

Expression cond_class::copy_Expression()
{
   return new cond_class(pred->copy_Expression(), then_exp->copy_Expression(), else_exp->copy_Expression());
}


void cond_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "cond\n";
   pred->dump(stream, n+2);
   then_exp->dump(stream, n+2);
   else_exp->dump(stream, n+2);
}

int cond_class::count_max_let_vars() {
  return std::max(pred->count_max_let_vars(),
                    std::max(then_exp->count_max_let_vars(),
                              else_exp->count_max_let_vars()));
}

int cond_class::count_max_case_vars() {
  return std::max(pred->count_max_case_vars(),
                    std::max(then_exp->count_max_case_vars(),
                              else_exp->count_max_case_vars()));
}


Expression loop_class::copy_Expression()
{
   return new loop_class(pred->copy_Expression(), body->copy_Expression());
}


void loop_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "loop\n";
   pred->dump(stream, n+2);
   body->dump(stream, n+2);
}

int loop_class::count_max_let_vars() {
  return std::max(pred->count_max_let_vars(), 
                  body->count_max_let_vars());
}


int loop_class::count_max_case_vars() {
  return std::max(pred->count_max_case_vars(), 
                  body->count_max_case_vars());
}


Expression typcase_class::copy_Expression()
{
   return new typcase_class(expr->copy_Expression(), cases->copy_list());
}


void typcase_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "typcase\n";
   expr->dump(stream, n+2);
   cases->dump(stream, n+2);
}

int typcase_class::count_max_let_vars() {
  int rtn = expr->count_max_let_vars();
  for(int i = 0; i < cases->len(); i ++) {
    rtn = std::max(cases->nth(i)->count_max_let_vars(), rtn);
  }
  return rtn;
}

int typcase_class::count_max_case_vars() {
  int rtn = expr->count_max_let_vars();
  for(int i = 0; i < cases->len(); i ++) {
    rtn = std::max(cases->nth(i)->count_max_let_vars(), rtn);
  }
  return 1 + rtn;
}

Expression block_class::copy_Expression()
{
   return new block_class(body->copy_list());
}


void block_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "block\n";
   body->dump(stream, n+2);
}

int block_class::count_max_let_vars() {
  int rtn = 0;
  for(int i = 0; i < body->len(); i ++) {
    rtn = std::max(rtn, body->nth(i)->count_max_let_vars());
  }
  return rtn;
}

int block_class::count_max_case_vars() {
  int rtn = 0;
  for(int i = 0; i < body->len(); i ++) {
    rtn = std::max(rtn, body->nth(i)->count_max_case_vars());
  }
  return rtn;
}


Expression let_class::copy_Expression()
{
   return new let_class(copy_Symbol(identifier), copy_Symbol(type_decl), init->copy_Expression(), body->copy_Expression());
}


void let_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "let\n";
   dump_Symbol(stream, n+2, identifier);
   dump_Symbol(stream, n+2, type_decl);
   init->dump(stream, n+2);
   body->dump(stream, n+2);
}

int let_class::count_max_let_vars() {
  return 1 + std::max(init->count_max_let_vars(), 
                      body->count_max_let_vars());
}

int let_class::count_max_case_vars() {
  return std::max(init->count_max_case_vars(), body->count_max_case_vars());
}


Expression plus_class::copy_Expression()
{
   return new plus_class(e1->copy_Expression(), e2->copy_Expression());
}


void plus_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "plus\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int plus_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(),
                  e2->count_max_let_vars());
}

int plus_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(),
                  e2->count_max_case_vars());
}

Expression sub_class::copy_Expression()
{
   return new sub_class(e1->copy_Expression(), e2->copy_Expression());
}


void sub_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "sub\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int sub_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(),
                  e2->count_max_let_vars());
}

int sub_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(),
                  e2->count_max_case_vars());
}


Expression mul_class::copy_Expression()
{
   return new mul_class(e1->copy_Expression(), e2->copy_Expression());
}


void mul_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "mul\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int mul_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(),
                  e2->count_max_let_vars());
}

int mul_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(),
                  e2->count_max_case_vars());
}

Expression divide_class::copy_Expression()
{
   return new divide_class(e1->copy_Expression(), e2->copy_Expression());
}


void divide_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "divide\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int divide_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(),
                  e2->count_max_let_vars());
}

int divide_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(),
                  e2->count_max_case_vars());
}

Expression neg_class::copy_Expression()
{
   return new neg_class(e1->copy_Expression());
}


void neg_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "neg\n";
   e1->dump(stream, n+2);
}

int neg_class::count_max_let_vars() {
  return e1->count_max_let_vars();
}

int neg_class::count_max_case_vars() {
  return e1->count_max_case_vars();
}

Expression lt_class::copy_Expression()
{
   return new lt_class(e1->copy_Expression(), e2->copy_Expression());
}


void lt_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "lt\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int lt_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(),
                  e2->count_max_let_vars());
}

int lt_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(),
                  e2->count_max_case_vars());
}

Expression eq_class::copy_Expression()
{
   return new eq_class(e1->copy_Expression(), e2->copy_Expression());
}


void eq_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "eq\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int eq_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(),
                  e2->count_max_let_vars());
}

int eq_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(),
                  e2->count_max_case_vars());
}

Expression leq_class::copy_Expression()
{
   return new leq_class(e1->copy_Expression(), e2->copy_Expression());
}


void leq_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "leq\n";
   e1->dump(stream, n+2);
   e2->dump(stream, n+2);
}

int leq_class::count_max_let_vars() {
  return std::max(e1->count_max_let_vars(), 
                  e2->count_max_let_vars());
}

int leq_class::count_max_case_vars() {
  return std::max(e1->count_max_case_vars(), 
                  e2->count_max_case_vars());
}

Expression comp_class::copy_Expression()
{
   return new comp_class(e1->copy_Expression());
}


void comp_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "comp\n";
   e1->dump(stream, n+2);
}

int comp_class::count_max_let_vars() {
  return e1->count_max_let_vars();
}

int comp_class::count_max_case_vars() {
  return e1->count_max_case_vars();
}

Expression int_const_class::copy_Expression()
{
   return new int_const_class(copy_Symbol(token));
}


void int_const_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "int_const\n";
   dump_Symbol(stream, n+2, token);
}

int int_const_class::count_max_let_vars() {
  return 0;
}

int int_const_class::count_max_case_vars() {
  return 0;
}



Expression bool_const_class::copy_Expression()
{
   return new bool_const_class(copy_Boolean(val));
}


void bool_const_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "bool_const\n";
   dump_Boolean(stream, n+2, val);
}

int bool_const_class::count_max_let_vars() {
  return 0;
}

int bool_const_class::count_max_case_vars() {
  return 0;
}

Expression string_const_class::copy_Expression()
{
   return new string_const_class(copy_Symbol(token));
}


void string_const_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "string_const\n";
   dump_Symbol(stream, n+2, token);
}

int string_const_class::count_max_let_vars() {
  return 0;
}

int string_const_class::count_max_case_vars() {
  return 0;
}

Expression new__class::copy_Expression()
{
   return new new__class(copy_Symbol(type_name));
}


void new__class::dump(ostream& stream, int n)
{
   stream << pad(n) << "new_\n";
   dump_Symbol(stream, n+2, type_name);
}

int new__class::count_max_let_vars() {
  return 0;
}

int new__class::count_max_case_vars() {
  return 0;
}

Expression isvoid_class::copy_Expression()
{
   return new isvoid_class(e1->copy_Expression());
}


void isvoid_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "isvoid\n";
   e1->dump(stream, n+2);
}

int isvoid_class::count_max_let_vars() {
  return e1->count_max_let_vars();
}

int isvoid_class::count_max_case_vars() {
  return e1->count_max_case_vars();
}

Expression no_expr_class::copy_Expression()
{
   return new no_expr_class();
}

void no_expr_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "no_expr\n";
}

int no_expr_class::count_max_let_vars() {
  return 0;
}

int no_expr_class::count_max_case_vars() {
  return 0;
}

Expression object_class::copy_Expression()
{
   return new object_class(copy_Symbol(name));
}


void object_class::dump(ostream& stream, int n)
{
   stream << pad(n) << "object\n";
   dump_Symbol(stream, n+2, name);
}

int object_class::count_max_let_vars() {
  return 0;
}

int object_class::count_max_case_vars() {
  return 0;
}


// interfaces used by Bison
Classes nil_Classes()
{
   return new nil_node<Class_>();
}

Classes single_Classes(Class_ e)
{
   return new single_list_node<Class_>(e);
}

Classes append_Classes(Classes p1, Classes p2)
{
   return new append_node<Class_>(p1, p2);
}

Features nil_Features()
{
   return new nil_node<Feature>();
}

Features single_Features(Feature e)
{
   return new single_list_node<Feature>(e);
}

Features append_Features(Features p1, Features p2)
{
   return new append_node<Feature>(p1, p2);
}

Formals nil_Formals()
{
   return new nil_node<Formal>();
}

Formals single_Formals(Formal e)
{
   return new single_list_node<Formal>(e);
}

Formals append_Formals(Formals p1, Formals p2)
{
   return new append_node<Formal>(p1, p2);
}

Expressions nil_Expressions()
{
   return new nil_node<Expression>();
}

Expressions single_Expressions(Expression e)
{
   return new single_list_node<Expression>(e);
}

Expressions append_Expressions(Expressions p1, Expressions p2)
{
   return new append_node<Expression>(p1, p2);
}

Cases nil_Cases()
{
   return new nil_node<Case>();
}

Cases single_Cases(Case e)
{
   return new single_list_node<Case>(e);
}

Cases append_Cases(Cases p1, Cases p2)
{
   return new append_node<Case>(p1, p2);
}

Program program(Classes classes)
{
  return new program_class(classes);
}

Class_ class_(Symbol name, Symbol parent, Features features, Symbol filename)
{
  return new class__class(name, parent, features, filename);
}

Feature method(Symbol name, Formals formals, Symbol return_type, Expression expr)
{
  return new method_class(name, formals, return_type, expr);
}

Feature attr(Symbol name, Symbol type_decl, Expression init)
{
  return new attr_class(name, type_decl, init);
}

Formal formal(Symbol name, Symbol type_decl)
{
  return new formal_class(name, type_decl);
}

Case branch(Symbol name, Symbol type_decl, Expression expr)
{
  return new branch_class(name, type_decl, expr);
}

Expression assign(Symbol name, Expression expr)
{
  return new assign_class(name, expr);
}

Expression static_dispatch(Expression expr, Symbol type_name, Symbol name, Expressions actual)
{
  return new static_dispatch_class(expr, type_name, name, actual);
}

Expression dispatch(Expression expr, Symbol name, Expressions actual)
{
  return new dispatch_class(expr, name, actual);
}

Expression cond(Expression pred, Expression then_exp, Expression else_exp)
{
  return new cond_class(pred, then_exp, else_exp);
}

Expression loop(Expression pred, Expression body)
{
  return new loop_class(pred, body);
}

Expression typcase(Expression expr, Cases cases)
{
  return new typcase_class(expr, cases);
}

Expression block(Expressions body)
{
  return new block_class(body);
}

Expression let(Symbol identifier, Symbol type_decl, Expression init, Expression body)
{
  return new let_class(identifier, type_decl, init, body);
}

Expression plus(Expression e1, Expression e2)
{
  return new plus_class(e1, e2);
}

Expression sub(Expression e1, Expression e2)
{
  return new sub_class(e1, e2);
}

Expression mul(Expression e1, Expression e2)
{
  return new mul_class(e1, e2);
}

Expression divide(Expression e1, Expression e2)
{
  return new divide_class(e1, e2);
}

Expression neg(Expression e1)
{
  return new neg_class(e1);
}

Expression lt(Expression e1, Expression e2)
{
  return new lt_class(e1, e2);
}

Expression eq(Expression e1, Expression e2)
{
  return new eq_class(e1, e2);
}

Expression leq(Expression e1, Expression e2)
{
  return new leq_class(e1, e2);
}

Expression comp(Expression e1)
{
  return new comp_class(e1);
}

Expression int_const(Symbol token)
{
  return new int_const_class(token);
}

Expression bool_const(Boolean val)
{
  return new bool_const_class(val);
}

Expression string_const(Symbol token)
{
  return new string_const_class(token);
}

Expression new_(Symbol type_name)
{
  return new new__class(type_name);
}

Expression isvoid(Expression e1)
{
  return new isvoid_class(e1);
}

Expression no_expr()
{
  return new no_expr_class();
}

Expression object(Symbol name)
{
  return new object_class(name);
}

