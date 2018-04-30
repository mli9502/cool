
//**************************************************************
//
// Code generator SKELETON
//
// Read the comments carefully. Make sure to
//    initialize the base class tags in
//       `CgenClassTable::CgenClassTable'
//
//    Add the label for the dispatch tables to
//       `IntEntry::code_def'
//       `StringEntry::code_def'
//       `BoolConst::code_def'
//
//    Add code to emit everyting else that is needed
//       in `CgenClassTable::code'
//
//
// The files as provided will produce code to begin the code
// segments, declare globals, and emit constants.  You must
// fill in the rest.
//
//**************************************************************

// FIXME: 2/28/2017: <class>_init is only meaningful for classes that assign initial value for attributes.
// This can be checked by checking the init field of attr_class.
// Check Main class in arith.s/cl for example.
// FIXME: 3/29/2018: Need to handle empty class case (ACC == 0)

#include <string>
#include <limits>
#include <limits.h>

#include "cgen.h"
#include "cgen_gc.h"

extern void emit_string_constant(ostream& str, char *s);

//
// Three symbols from the semantic analyzer (semant.cc) are used.
// If e : No_type, then no code is generated for e.
// Special code is generated for new SELF_TYPE.
// The name "self" also generates code different from other references.
//
//////////////////////////////////////////////////////////////////////
//
// Symbols
//
// For convenience, a large number of symbols are predefined here.
// These symbols include the primitive type and method names, as well
// as fixed names used by the runtime system.
//
//////////////////////////////////////////////////////////////////////
Symbol 
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

static char *gc_init_names[] =
  { "_NoGC_Init", "_GenGC_Init", "_ScnGC_Init" };
static char *gc_collect_names[] =
  { "_NoGC_Collect", "_GenGC_Collect", "_ScnGC_Collect" };


//  BoolConst is a class that implements code generation for operations
//  on the two booleans, which are given global names here.
BoolConst falsebool(FALSE);
BoolConst truebool(TRUE);

//*********************************************************
//
// Define method for code generation
//
// This is the method called by the compiler driver
// `cgtest.cc'. cgen takes an `ostream' to which the assembly will be
// emmitted, and it passes this and the class list of the
// code generator tree to the constructor for `CgenClassTable'.
// That constructor performs all of the work of the code
// generator.
//
//*********************************************************

void program_class::cgen(ostream &os) 
{
  // spim wants comments to start with '#'
  os << "# start of generated code\n";

  initialize_constants();
  CgenClassTable *codegen_classtable = new CgenClassTable(classes,os);

  os << "\n# end of generated code\n";
}


//////////////////////////////////////////////////////////////////////////////
//
//  emit_* procedures
//
//  emit_X  writes code for operation "X" to the output stream.
//  There is an emit_X for each opcode X, as well as emit_ functions
//  for generating names according to the naming conventions (see emit.h)
//  and calls to support functions defined in the trap handler.
//
//  Register names and addresses are passed as strings.  See `emit.h'
//  for symbolic names you can use to refer to the strings.
//
//////////////////////////////////////////////////////////////////////////////

static void emit_load(char *dest_reg, int offset, char *source_reg, ostream& s)
{
  s << LW << dest_reg << " " << offset * WORD_SIZE << "(" << source_reg << ")" 
    << endl;
}

static void emit_store(char *source_reg, int offset, char *dest_reg, ostream& s)
{
  s << SW << source_reg << " " << offset * WORD_SIZE << "(" << dest_reg << ")"
      << endl;
}

static void emit_load_imm(char *dest_reg, int val, ostream& s)
{ s << LI << dest_reg << " " << val << endl; }

static void emit_load_address(char *dest_reg, char *address, ostream& s)
{ s << LA << dest_reg << " " << address << endl; }

static void emit_partial_load_address(char *dest_reg, ostream& s)
{ s << LA << dest_reg << " "; }

static void emit_load_bool(char *dest, const BoolConst& b, ostream& s)
{
  emit_partial_load_address(dest,s);
  b.code_ref(s);
  s << endl;
}

static void emit_load_string(char *dest, StringEntry *str, ostream& s)
{
  emit_partial_load_address(dest,s);
  str->code_ref(s);
  s << endl;
}

static void emit_load_int(char *dest, IntEntry *i, ostream& s)
{
  emit_partial_load_address(dest,s);
  i->code_ref(s);
  s << endl;
}

static void emit_move(char *dest_reg, char *source_reg, ostream& s)
{ s << MOVE << dest_reg << " " << source_reg << endl; }

static void emit_neg(char *dest, char *src1, ostream& s)
{ s << NEG << dest << " " << src1 << endl; }

static void emit_add(char *dest, char *src1, char *src2, ostream& s)
{ s << ADD << dest << " " << src1 << " " << src2 << endl; }

static void emit_addu(char *dest, char *src1, char *src2, ostream& s)
{ s << ADDU << dest << " " << src1 << " " << src2 << endl; }

static void emit_addiu(char *dest, char *src1, int imm, ostream& s)
{ s << ADDIU << dest << " " << src1 << " " << imm << endl; }

static void emit_div(char *dest, char *src1, char *src2, ostream& s)
{ s << DIV << dest << " " << src1 << " " << src2 << endl; }

static void emit_mul(char *dest, char *src1, char *src2, ostream& s)
{ s << MUL << dest << " " << src1 << " " << src2 << endl; }

static void emit_sub(char *dest, char *src1, char *src2, ostream& s)
{ s << SUB << dest << " " << src1 << " " << src2 << endl; }

static void emit_sll(char *dest, char *src1, int num, ostream& s)
{ s << SLL << dest << " " << src1 << " " << num << endl; }

static void emit_jalr(char *dest, ostream& s)
{ s << JALR << "\t" << dest << endl; }

static void emit_jal(char *address,ostream &s)
{ s << JAL << address << endl; }

static void emit_return(ostream& s)
{ s << RET << endl; }

static void emit_gc_assign(ostream& s)
{ s << JAL << "_GenGC_Assign" << endl; }

static void emit_disptable_ref(Symbol sym, ostream& s)
{  s << sym << DISPTAB_SUFFIX; }

static void emit_init_ref(Symbol sym, ostream& s)
{ s << sym << CLASSINIT_SUFFIX; }

static void emit_init_def(Symbol sym, ostream& s)
{ s << sym << CLASSINIT_SUFFIX << ":" << endl; }

static void emit_label_ref(int l, ostream &s)
{ s << "label" << l; }

static void emit_protobj_ref(Symbol sym, ostream& s)
{ s << sym << PROTOBJ_SUFFIX; }

static void emit_method_ref(Symbol classname, Symbol methodname, ostream& s)
{ s << classname << METHOD_SEP << methodname; }

static void emit_label_def(int l, ostream &s)
{
  emit_label_ref(l,s);
  s << ":" << endl;
}

static void emit_label_def(std::string l, ostream& s) {
  s << l << ":" << endl;
}

static void emit_beqz(char *source, int label, ostream &s)
{
  s << BEQZ << source << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_beqz(char* source, std::string label, ostream& s) {
  s << BEQZ << source << " " << label << endl;
}

static void emit_beq(char *src1, char *src2, int label, ostream &s)
{
  s << BEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bne(char *src1, char *src2, int label, ostream &s)
{
  s << BNE << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bleq(char *src1, char *src2, int label, ostream &s)
{
  s << BLEQ << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blt(char *src1, char *src2, int label, ostream &s)
{
  s << BLT << src1 << " " << src2 << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blti(char *src1, int imm, int label, ostream &s)
{
  s << BLT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_blti(char *src1, int imm, const std::string& label, ostream &s)
{
  s << BLT << src1 << " " << imm << " " << label << endl;
}

static void emit_bgti(char *src1, int imm, int label, ostream &s)
{
  s << BGT << src1 << " " << imm << " ";
  emit_label_ref(label,s);
  s << endl;
}

static void emit_bgti(char *src1, int imm, const std::string& label, ostream &s)
{
  s << BGT << src1 << " " << imm << " " << label << endl;
}

static void emit_branch(int l, ostream& s)
{
  s << BRANCH;
  emit_label_ref(l,s);
  s << endl;
}

static void emit_branch(const std::string& l, ostream& s) {
  s << BRANCH << l << endl;
}

//
// Push a register on the stack. The stack grows towards smaller addresses.
//
static void emit_push(char *reg, ostream& str)
{
  emit_store(reg,0,SP,str);
  emit_addiu(SP,SP,-4,str);
}

//
// Fetch the integer value in an Int object.
// Emits code to fetch the integer value of the Integer object pointed
// to by register source into the register dest
//
static void emit_fetch_int(char *dest, char *source, ostream& s)
{ emit_load(dest, DEFAULT_OBJFIELDS, source, s); }

//
// Emits code to store the integer value contained in register source
// into the Integer object pointed to by dest.
//
static void emit_store_int(char *source, char *dest, ostream& s)
{ emit_store(source, DEFAULT_OBJFIELDS, dest, s); }


static void emit_test_collector(ostream &s)
{
  emit_push(ACC, s);
  emit_move(ACC, SP, s); // stack end
  emit_move(A1, ZERO, s); // allocate nothing
  s << JAL << gc_collect_names[cgen_Memmgr] << endl;
  emit_addiu(SP,SP,4,s);
  emit_load(ACC,0,SP,s);
}

static void emit_gc_check(char *source, ostream &s)
{
  if (source != (char*)A1) emit_move(A1, source, s);
  s << JAL << "_gc_check" << endl;
}

///////////////////////////////////////////////////////////////////////////////
//
// coding strings, ints, and booleans
//
// Cool has three kinds of constants: strings, ints, and booleans.
// This section defines code generation for each type.
//
// All string constants are listed in the global "stringtable" and have
// type StringEntry.  StringEntry methods are defined both for String
// constant definitions and references.
//
// All integer constants are listed in the global "inttable" and have
// type IntEntry.  IntEntry methods are defined for Int
// constant definitions and references.
//
// Since there are only two Bool values, there is no need for a table.
// The two booleans are represented by instances of the class BoolConst,
// which defines the definition and reference methods for Bools.
//
///////////////////////////////////////////////////////////////////////////////

//
// Strings
//
void StringEntry::code_ref(ostream& s)
{
  s << STRCONST_PREFIX << index;
}

//
// Emit code for a constant String.
// You should fill in the code naming the dispatch table.
//

void StringEntry::code_def(ostream& s, int stringclasstag)
{
  IntEntryP lensym = inttable.add_int(len);

  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s  << LABEL                                             // label
      << WORD << stringclasstag << endl                                 // tag
      << WORD << (DEFAULT_OBJFIELDS + STRING_SLOTS + (len+4)/4) << endl // size
      << WORD;
	  s << STRINGNAME << DISPTAB_SUFFIX;
      s << endl;                                              // dispatch table
      s << WORD;  lensym->code_ref(s);  s << endl;            // string length
  emit_string_constant(s,str);                                // ascii string
  s << ALIGN;                                                 // align to word
}

//
// StrTable::code_string
// Generate a string object definition for every string constant in the 
// stringtable.
//
void StrTable::code_string_table(ostream& s, int stringclasstag)
{  
  for (List<StringEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,stringclasstag);
}

//
// Ints
//
void IntEntry::code_ref(ostream &s)
{
  s << INTCONST_PREFIX << index;
}

//
// Emit code for a constant Integer.
// You should fill in the code naming the dispatch table.
//

void IntEntry::code_def(ostream &s, int intclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                // label
      << WORD << intclasstag << endl                      // class tag
      << WORD << (DEFAULT_OBJFIELDS + INT_SLOTS) << endl  // object size
      << WORD; 
	  s << INTNAME << DISPTAB_SUFFIX;
      s << endl;                                          // dispatch table
      s << WORD << str << endl;                           // integer value
}


//
// IntTable::code_string_table
// Generate an Int object definition for every Int constant in the
// inttable.
//
void IntTable::code_string_table(ostream &s, int intclasstag)
{
  for (List<IntEntry> *l = tbl; l; l = l->tl())
    l->hd()->code_def(s,intclasstag);
}


//
// Bools
//
BoolConst::BoolConst(int i) : val(i) { assert(i == 0 || i == 1); }

void BoolConst::code_ref(ostream& s) const
{
  s << BOOLCONST_PREFIX << val;
}
  
//
// Emit code for a constant Bool.
// You should fill in the code naming the dispatch table.
//

void BoolConst::code_def(ostream& s, int boolclasstag)
{
  // Add -1 eye catcher
  s << WORD << "-1" << endl;

  code_ref(s);  s << LABEL                                  // label
      << WORD << boolclasstag << endl                       // class tag
      << WORD << (DEFAULT_OBJFIELDS + BOOL_SLOTS) << endl   // object size
      << WORD;
	  s << BOOLNAME << DISPTAB_SUFFIX;
      s << endl;                                            // dispatch table
      s << WORD << val << endl;                             // value (0 or 1)
}

//////////////////////////////////////////////////////////////////////////////
//
//  CgenClassTable methods
//
//////////////////////////////////////////////////////////////////////////////

//***************************************************
//
//  Emit code to start the .data segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_data()
{
  Symbol main    = idtable.lookup_string(MAINNAME);
  Symbol string  = idtable.lookup_string(STRINGNAME);
  Symbol integer = idtable.lookup_string(INTNAME);
  Symbol boolc   = idtable.lookup_string(BOOLNAME);

  str << "\t.data\n" << ALIGN;
  //
  // The following global names must be defined first.
  //
  str << GLOBAL << CLASSNAMETAB << endl;
  str << GLOBAL; emit_protobj_ref(main,str);    str << endl;
  str << GLOBAL; emit_protobj_ref(integer,str); str << endl;
  str << GLOBAL; emit_protobj_ref(string,str);  str << endl;
  str << GLOBAL; falsebool.code_ref(str);  str << endl;
  str << GLOBAL; truebool.code_ref(str);   str << endl;
  str << GLOBAL << INTTAG << endl;
  str << GLOBAL << BOOLTAG << endl;
  str << GLOBAL << STRINGTAG << endl;

  //
  // We also need to know the tag of the Int, String, and Bool classes
  // during code generation.
  //
  str << INTTAG << LABEL
      << WORD << intclasstag << endl;
  str << BOOLTAG << LABEL 
      << WORD << boolclasstag << endl;
  str << STRINGTAG << LABEL 
      << WORD << stringclasstag << endl;    
}


//***************************************************
//
//  Emit code to start the .text segment and to
//  declare the global names.
//
//***************************************************

void CgenClassTable::code_global_text()
{
  str << GLOBAL << HEAP_START << endl
      << HEAP_START << LABEL 
      << WORD << 0 << endl
      << "\t.text" << endl
      << GLOBAL;
  emit_init_ref(idtable.add_string("Main"), str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Int"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("String"),str);
  str << endl << GLOBAL;
  emit_init_ref(idtable.add_string("Bool"),str);
  str << endl << GLOBAL;
  emit_method_ref(idtable.add_string("Main"), idtable.add_string("main"), str);
  str << endl;
}

void CgenClassTable::code_bools(int boolclasstag)
{
  falsebool.code_def(str,boolclasstag);
  truebool.code_def(str,boolclasstag);
}

void CgenClassTable::code_select_gc()
{
  //
  // Generate GC choice constants (pointers to GC functions)
  //
  str << GLOBAL << "_MemMgr_INITIALIZER" << endl;
  str << "_MemMgr_INITIALIZER:" << endl;
  str << WORD << gc_init_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_COLLECTOR" << endl;
  str << "_MemMgr_COLLECTOR:" << endl;
  str << WORD << gc_collect_names[cgen_Memmgr] << endl;
  str << GLOBAL << "_MemMgr_TEST" << endl;
  str << "_MemMgr_TEST:" << endl;
  str << WORD << (cgen_Memmgr_Test == GC_TEST) << endl;
}


//********************************************************
//
// Emit code to reserve space for and initialize all of
// the constants.  Class names should have been added to
// the string table (in the supplied code, is is done
// during the construction of the inheritance graph), and
// code for emitting string constants as a side effect adds
// the string's length to the integer table.  The constants
// are emmitted by running through the stringtable and inttable
// and producing code for each entry.
//
//********************************************************

void CgenClassTable::code_constants()
{
  //
  // Add constants that are required by the code generator.
  //
  stringtable.add_string("");
  inttable.add_string("0");

  stringtable.code_string_table(str,stringclasstag);
  inttable.code_string_table(str,intclasstag);
  code_bools(boolclasstag);
}

void CgenClassTable::code_class_nameTab() {
	str << CLASSNAMETAB << LABEL;
	for(List<CgenNode>* l = nds; l; l = l->tl()) {
		std::string class_name = l->hd()->get_name()->get_string();
		StringEntry* class_name_entry = stringtable.lookup_string(const_cast<char*>(class_name.c_str()));
		str << WORD;
		class_name_entry->code_ref(str);
		str << endl;
	}
}

void CgenClassTable::bfs_init_classes_dispatch_table() {
  CgenNodeP object_node = this->get_cgen_node_from_class_name("Object");
  std::queue<CgenNodeP> q;
  q.push(object_node);
  while(!q.empty()) {
    CgenNodeP node = q.front();
    q.pop();
    node->set_dispatch_table();
    for(List<CgenNode>* l = node->get_children(); l; l = l->tl()) {
      q.push(l->hd());
    }
  }
}

void CgenClassTable::code_class_dispTab() {
	for(List<CgenNode>* l = nds; l; l = l->tl()) {
    const auto& dispatch_table = l->hd()->get_dispatch_table();
    str << l->hd()->get_name()->get_string() << DISPTAB_SUFFIX << LABEL;
    for(const auto& class_method_pair : dispatch_table) {
      Symbol class_name = class_method_pair.first->get_name();
      std::string method_name = class_method_pair.second->name->get_string();
      str << WORD << class_name << METHOD_SEP << method_name << endl;
    }
	}
}

void CgenClassTable::code_class_protObj() {
	for(List<CgenNode>* l = nds; l; l = l->tl()) {
		code_single_class_protObj(l->hd());
	}
}
// emit method code for only the current class. 
// this method will not emit code for parent classes of curr_class.
void CgenClassTable::code_single_class_methods(CgenNode* curr_class) {
  // Add class attributes to environment.
  environment.enterscope();
  int cnt = 0;
  for(auto& attr : get_all_attrs(curr_class)) {
    environment.addid(attr.second->name->get_string(), new MemAddr(SELF, DEFAULT_OBJFIELDS + cnt));
  }
  // Emit code for class init.
  // This needs to be put here because we need the attributes to be in the environment before we init variables.
  // if (cgen_debug) cout << "Before coding init for class " << curr_class->name << endl;
  code_single_class_init(curr_class);
  // if (cgen_debug) cout << "After coding init for class " << curr_class->name << endl;
  // If current class is not one of the basic class.
  if(!curr_class->basic()) {
    for(auto& m : curr_class->get_target_features<method_class, true>()) {
      environment.enterscope();
      store.enterscope();
      // Add actual parameters to environment.
      for(int i = 0; i < m->formals->len(); i ++) {
        environment.addid(m->formals->nth(i)->get_name()->get_string(), new MemAddr(FP, 1 + i));
      }
      std::string method_tag = std::string(curr_class->get_name()->get_string()) + "." + std::string(m->name->get_string());
      str << method_tag << LABEL;
      m->code(str, *this);
      store.exitscope();
      environment.exitscope();
    }
  }
  environment.exitscope();
}

void CgenClassTable::code_class_methods() {
  for(List<CgenNode>* l = nds; l; l = l->tl()) {
    code_single_class_methods(l->hd());
  }
}

// Emit code for class init.
// This is called together when emiting code for class method.
void CgenClassTable::code_single_class_init(CgenNode* curr_class) {
  // Emit def for init.
  emit_init_def(curr_class->name, str);
  const auto& attributes = get_all_attrs(curr_class);
  int let_var_cnt = 0;
  // arg_cnt is always 0 for init.
  int arg_cnt = 0;
  for(const auto& attr : attributes) {
    let_var_cnt = std::max(let_var_cnt, attr.second->init->count_max_let_vars());
  }
  CgenNode* parent_class = curr_class->get_parentnd();
  // First set up called activation record.
  this->code_callee_activation_record_setup(str);
  // If parent class is not NULL, init parent class first.
  if(parent_class != nullptr) {
    std::string parent_init_name = parent_class->get_name()->get_string() + std::string(CLASSINIT_SUFFIX);
    emit_jal((char*)parent_init_name.c_str(), str);
  }
  // Init attributes.
  for(const auto& attr : attributes) {
    attr.second->init->code(str, *this);
  }
  // Restore save variables.
  this->code_callee_activation_record_cleanup(str, arg_cnt, let_var_cnt);
}

void CgenClassTable::disp_count_let_vars() {
  for(List<CgenNode>* l = nds; l; l = l->tl()) {
    std::cout << l->hd()->name << ": " << l->hd()->count_max_let_vars() << std::endl;
  }
}

void CgenClassTable::code_single_class_protObj(CgenNodeP curr_class) {
	// Add -1 eye catcher
  str << WORD << "-1" << endl;
	// Emit <object>_protObj: 
	emit_protobj_ref(curr_class->get_name(), str); str << LABEL;
	// Emit class tag.
	str << WORD << curr_class->class_tag << endl;
	// Get all attributes and calculate size.
	unsigned prot_size = DEFAULT_OBJFIELDS; // Base size, containing tag, size and dispatch table.
	const std::vector<std::pair<CgenNodeP, attr_class*>>& class_attrs = get_all_attrs(curr_class);
	prot_size += class_attrs.size();
	// Emit prototype size.
	str << WORD << prot_size << endl;
	// Emit dispatch table.
	str << WORD; emit_disptable_ref(curr_class->get_name(), str); str << endl;
	// Emit attributes.
	StringEntryP defaultStringSym = stringtable.add_string("");
	IntEntryP defaultIntSym = inttable.add_int(0);
	BoolConst* defaultBoolPtr = &falsebool;
	for(const auto& class_attr : class_attrs) {
		const std::string& class_name = class_attr.second->type_decl->get_string();
		str << WORD;
		if(class_name == "Int") {
			defaultIntSym->code_ref(str);
		} else if(class_name == "String") {
			defaultStringSym->code_ref(str);
		} else if(class_name == "Bool") {
			defaultBoolPtr->code_ref(str);
		} else {
			str << 0;
		}
		str << endl;
	}
}

CgenClassTable::CgenClassTable(Classes classes, ostream& s) : nds(NULL) , str(s)
{
  stringclasstag = -1;
  intclasstag =    -1;
  boolclasstag =   -1;

  curr_let_cnt = 0;

  enterscope();
  if (cgen_debug) cout << "Building CgenClassTable" << endl;
  install_basic_classes();
  install_classes(classes);
  build_inheritance_tree();
  // Set class tags by inorder traverse the inheritance tree.
  set_class_tags_member();
  stringclasstag = _class_tags[get_cgen_node_from_symbol(Str)].first;
  intclasstag = _class_tags[get_cgen_node_from_symbol(Int)].first;
  boolclasstag = _class_tags[get_cgen_node_from_symbol(Bool)].first;
  set_class_tags();
  code();
  exitscope();
}

void CgenClassTable::set_class_tags() {
  for(List<CgenNode>* l = nds; l; l = l->tl()) {
    l->hd()->class_tag = _class_tags[l->hd()].first;
  }
}

void CgenClassTable::install_basic_classes()
{

// The tree package uses these globals to annotate the classes built below.
  //curr_lineno  = 0;
  Symbol filename = stringtable.add_string("<basic class>");

//
// A few special class names are installed in the lookup table but not
// the class list.  Thus, these classes exist, but are not part of the
// inheritance hierarchy.
// No_class serves as the parent of Object and the other special classes.
// SELF_TYPE is the self class; it cannot be redefined or inherited.
// prim_slot is a class known to the code generator.
//
  addid(No_class,
	new CgenNode(class_(No_class,No_class,nil_Features(),filename),
			    Basic,this));
  addid(SELF_TYPE,
	new CgenNode(class_(SELF_TYPE,No_class,nil_Features(),filename),
			    Basic,this));
  addid(prim_slot,
	new CgenNode(class_(prim_slot,No_class,nil_Features(),filename),
			    Basic,this));

// 
// The Object class has no parent class. Its methods are
//        cool_abort() : Object    aborts the program
//        type_name() : Str        returns a string representation of class name
//        copy() : SELF_TYPE       returns a copy of the object
//
// There is no need for method bodies in the basic classes---these
// are already built in to the runtime system.
//
  install_class(
   new CgenNode(
    class_(Object, 
	   No_class,
	   append_Features(
           append_Features(
           single_Features(method(cool_abort, nil_Formals(), Object, no_expr())),
           single_Features(method(type_name, nil_Formals(), Str, no_expr()))),
           single_Features(method(copy, nil_Formals(), SELF_TYPE, no_expr()))),
	   filename),
    Basic,this));

// 
// The IO class inherits from Object. Its methods are
//        out_string(Str) : SELF_TYPE          writes a string to the output
//        out_int(Int) : SELF_TYPE               "    an int    "  "     "
//        in_string() : Str                    reads a string from the input
//        in_int() : Int                         "   an int     "  "     "
//
   install_class(
    new CgenNode(
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
	   filename),	    
    Basic,this));

//
// The Int class has no methods and only a single attribute, the
// "val" for the integer. 
//
   install_class(
    new CgenNode(
     class_(Int, 
	    Object,
            single_Features(attr(val, prim_slot, no_expr())),
	    filename),
     Basic,this));

//
// Bool also has only the "val" slot.
//
    install_class(
     new CgenNode(
      class_(Bool, Object, single_Features(attr(val, prim_slot, no_expr())),filename),
      Basic,this));

//
// The class Str has a number of slots and operations:
//       val                                  ???
//       str_field                            the string itself
//       length() : Int                       length of the string
//       concat(arg: Str) : Str               string concatenation
//       substr(arg: Int, arg2: Int): Str     substring
//       
   install_class(
    new CgenNode(
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
	     filename),
        Basic,this));

}

// CgenClassTable::install_class
// CgenClassTable::install_classes
//
// install_classes enters a list of classes in the symbol table.
//
void CgenClassTable::install_class(CgenNodeP nd)
{
  Symbol name = nd->get_name();

  if (probe(name))
    {
      return;
    }

  // The class name is legal, so add it to the list of classes
  // and the symbol table.
  nds = new List<CgenNode>(nd,nds);
  addid(name,nd);
}

void CgenClassTable::install_classes(Classes cs)
{
  for(int i = cs->first(); cs->more(i); i = cs->next(i))
    install_class(new CgenNode(cs->nth(i),NotBasic,this));
}

//
// CgenClassTable::build_inheritance_tree
//
void CgenClassTable::build_inheritance_tree()
{
  for(List<CgenNode> *l = nds; l; l = l->tl())
      set_relations(l->hd());
}

//
// CgenClassTable::set_relations
//
// Takes a CgenNode and locates its, and its parent's, inheritance nodes
// via the class table.  Parent and child pointers are added as appropriate.
//
void CgenClassTable::set_relations(CgenNodeP nd)
{
  CgenNode *parent_node = probe(nd->get_parent());
  nd->set_parentnd(parent_node);
  parent_node->add_child(nd);
}

void CgenNode::add_child(CgenNodeP n)
{
  children = new List<CgenNode>(n,children);
}

void CgenNode::set_parentnd(CgenNodeP p)
{
  assert(parentnd == NULL);
  assert(p != NULL);
  parentnd = p;
}



void CgenClassTable::code()
{
	if (cgen_debug) cout << "coding global data" << endl;
    code_global_data();

    if (cgen_debug) cout << "choosing gc" << endl;
    code_select_gc();

    if (cgen_debug) cout << "coding constants" << endl;
    code_constants();

    //                 Add your code to emit
    //                   - prototype objects
    // class_nameTab
    if(cgen_debug) cout << "coding class_nameTab" << endl;
    code_class_nameTab();
    // Initialize class dispatch tables.
    bfs_init_classes_dispatch_table();
    // dispatch tables
    if(cgen_debug) cout << "coding class_dispTab" << endl;
    code_class_dispTab();
    // exit(-1);
    // prototype objects
    if(cgen_debug) cout << "coding class_protObj" << endl;
    code_class_protObj();
    
    if(cgen_debug) cout << "coding global text" << endl;
    code_global_text();

#if 0
    std::cout << "let var count for each class..." << endl;
    disp_count_let_vars();
#endif 
    // In order to code init, need code for expression and assign expression.
    // Code methods for classes.
    if(cgen_debug) cout << "coding methods and inits for classes" << endl;
    code_class_methods();
    //                 Add your code to emit
    //                   - object initializer
    //                   - the class methods
    //                   - etc...

}

CgenNodeP CgenClassTable::root()
{
   return probe(Object);
}

void CgenClassTable::set_class_tags_member() {
  CgenNodeP object_node = root();
  int tag = 0;
  set_class_tags_member_helper(object_node, tag);
}

void CgenClassTable::set_class_tags_member_helper(CgenNodeP node, int& tag) {
  int class_tag = tag ++;  
  for(List<CgenNode>* l = node->get_children(); l; l = l->tl()) {
    set_class_tags_member_helper(l->hd(), tag);
  }
  _class_tags[node] = std::make_pair(class_tag, tag);
}

///////////////////////////////////////////////////////////////////////
//
// CgenNode methods
//
///////////////////////////////////////////////////////////////////////

CgenNode::CgenNode(Class_ nd, Basicness bstatus, CgenClassTableP ct) :
   class__class((const class__class &) *nd),
   parentnd(NULL),
   children(NULL),
   basic_status(bstatus),
   method_included(),
   dispatch_table()
{ 
   stringtable.add_string(name->get_string());          // Add class name to string table
}


//******************************************************************
//
//   Fill in the following methods to produce code for the
//   appropriate expression.  You may add or remove parameters
//   as you wish, but if you do, remember to change the parameters
//   of the declarations in `cool-tree.h'  Sample code for
//   constant integers, strings, and booleans are provided.
//
//*****************************************************************

void method_class::code(ostream& os, CgenClassTable& cgenClassTable) {
  cgenClassTable.init_curr_let_cnt();
  cgenClassTable.code_callee_activation_record_setup(os);
  // if(cgen_debug) std::cout << "before coding expr" << std::endl;
  expr->code(os, cgenClassTable);
  // if(cgen_debug) std::cout << "after coding expr" << std::endl;
  cgenClassTable.code_callee_activation_record_cleanup(os, cgenClassTable.curr_arg_cnt, cgenClassTable.curr_max_let_var_cnt);
  // FIXME: update store? Probably not needed.
}

void assign_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Gen code for expression. Result should be in ACC.
  expr->code(s, cgenClassTable);
  // Get the location of id from environment and value from ACC.
  MemAddr* addr_ptr = cgenClassTable.environment.lookup(this->name->get_string());
  // Get the value from ACC.
  std::string* val = cgenClassTable.store.lookup(MemAddr(ACC, 0));
  // Update value at addr_ptr in store.
  // TODO: This is needed because of dynamic type? Need to test this...
  cgenClassTable.update_store(addr_ptr->reg_name, addr_ptr->offset, *val);
  // emit store.
  emit_store(ACC, addr_ptr->offset, (char*)(addr_ptr->reg_name.c_str()), s);
}

void CgenClassTable::code_caller_activation_record_setup(ostream& s, int let_var_cnt, Expressions args, CgenClassTable& cgenClassTable) {
  int arg_cnt = args->len();
  // Allocate space on stack for let vars.
  emit_addiu(SP, SP, -4 * let_var_cnt, s);
  // Allocate space on stack for args.
  emit_addiu(SP, SP, -4 * arg_cnt, s);
  // Gen code for e1 through en and store args on stack.
  for(int i = 0; i < args->len(); i ++) {
    args->nth(i)->code(s, cgenClassTable);
    // Put arg on stack.
    // First arg in 4($sp), second arg in 8($sp)...
    emit_store(ACC, i + 1, SP, s);
  }
  // Update arg_cnt and let_var_cnt in cgenClassTable.
  cgenClassTable.curr_arg_cnt = arg_cnt;
  cgenClassTable.curr_max_let_var_cnt = let_var_cnt;
}

void CgenClassTable::code_callee_activation_record_setup(ostream& os) {
  // Allocate stack space for old $fp, $s0 and $ra.
  emit_addiu(SP, SP, -12, os);
  // Store old $fp, $s0 and $ra.
  emit_store(FP, 3, SP, os);
  emit_store(SELF, 2, SP, os);
  emit_store(RA, 1, SP, os);
  // NOTE: 4/24/2018: How to access args and let vars: 
  // To access first arg, use 4($fp). To accss the first let var, use (arg_cnt * 4 + 4)($fp)
  // To access ith arg (starting from 1), use (4 * i)($fp).
  // To access ith let var (starting from 1), use (4 * (arg_cnt + i))($fp).
  // Set new $fp to $sp + 12.
  emit_addiu(FP, SP, 12, os);
  // Move $a0 to $s0 since $a0 stores SELF.
  // FIXME: 4/24/2018: For dispatch and static dispatch, e0 needs to be evaluated AFTER actuals are evaluated! 
  emit_move(SELF, ACC, os);
}

void CgenClassTable::code_callee_activation_record_cleanup(ostream& os, int curr_arg_cnt, int curr_max_let_var_cnt) {
  // Restore saved $fp, $s0 and $ra.
  emit_load(FP, 3, SP, os);
  emit_load(SELF, 2, SP, os);
  emit_load(RA, 1, SP, os);
  // Pop old $fp, $sa, $ra, args and let_vars out of stack.
  emit_addiu(SP, SP, 4 * (3 + curr_arg_cnt + curr_max_let_var_cnt), os);
  // Return.
  emit_return(os);
}

// Find the class first, then, for this class and all its parent class, find the method.
int CgenClassTable::get_method_offset(const std::string& class_name, const std::string& method_name) {
  CgenNodeP class_node = get_cgen_node_from_class_name(class_name);
  auto class_methods = get_all_methods(class_node);
  // Start from the target class and going backwards.
  unsigned start_idx = class_methods.size() - 1;
  while(start_idx >= 0 && class_methods[start_idx].first->name->get_string() != class_name) {
    start_idx --;
  }
  assert(start_idx < 0);
  // Start from startIdx, find the first method with the given method_name.
  while(start_idx >= 0 && class_methods[start_idx].second->name->get_string() != method_name) {
    start_idx --;
  }
  assert(start_idx < 0);
  return start_idx;
}

// Find the class first, then, for this class and all its parent class, find the method and return its let var cnt.
int CgenClassTable::get_method_let_var_cnt(const std::string& class_name, const std::string& method_name) {
  CgenNodeP class_node = get_cgen_node_from_class_name(class_name);
  auto class_methods = get_all_methods(class_node);
  // Start from the target class and going backwards.
  unsigned start_idx = class_methods.size() - 1;
  while(start_idx >= 0 && class_methods[start_idx].first->name->get_string() != class_name) {
    start_idx --;
  }
  assert(start_idx < 0);
  // Start from startIdx, find the first method with the given method_name.
  while(start_idx >= 0 && class_methods[start_idx].second->name->get_string() != method_name) {
    start_idx --;
  }
  assert(start_idx < 0);
  return class_methods[start_idx].second->count_max_let_vars();
}

CgenNodeP CgenClassTable::get_cgen_node_from_class_name(const std::string& class_name) {
  for(List<CgenNode> *l = nds; l; l = l->tl()) {
    if(l->hd()->name->get_string() == class_name) {
      return l->hd();
    }
  }
  std::cerr << class_name << " is not found! This is not correct..." << std::endl;
  return nullptr;
}

CgenNodeP CgenClassTable::get_cgen_node_from_symbol(Symbol s) {
  return probe(s);
}

void static_dispatch_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Get method offset based on the static type name.
  int method_offset = cgenClassTable.get_method_offset(type_name->get_string(), name->get_string());
  // Get method max let var cnt.
  int let_var_cnt = cgenClassTable.get_method_let_var_cnt(type_name->get_string(), name->get_string());
  // Set up activation record.
  cgenClassTable.code_caller_activation_record_setup(s, let_var_cnt, actual, cgenClassTable);
  // Gen code for e0.
  expr->code(s, cgenClassTable);
  // Load dispatch table to $t1.
  emit_load(T1, DISPTABLE_OFFSET, ACC, s);
  // Load method tag into $t1.
  emit_load(T1, method_offset, T1, s);
  // Jump to method.
  emit_jalr(T1, s);
  // FIXME: May need to update store for ACC ???
}

void dispatch_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  if(cgen_debug) std::cout << "[dispatch_class::code]" << std::endl;
  // FIXME: 4/26/2018
  /*
  Consider this example, where B is a child of A:
  
  A a = new B;
  a.func(arg1);

  In this example, a.func(arg1) will actually call the B's override version of "func" (This is done through vtable.)
  As a result, during code gen, it is not possible to know exactly which method will be called for a given class type T and method name M.
  So, to pre-allocate space for let vars, we need to find the max let var used by method M for class T, and all T's child classes.

  When creating dispatch table for a class, C, we first go through the base class, B, for C. (C inherits B). 
  We need to put B's dispatch table before C's dispatch table.
  Say that B's dispatch table looks like this:
  --B::dispatch_tbl--
  B::m1
  B::m2
  -------------------
  If class C overrides B's m1, and C has an additional method C::m3. Then, the dispatch table for C should look something like this:
  --C::dispatch_tbl--
  C::m1
  B::m2
  C::m3
  -------------------
  */
  // Get method max let var cnt.
  int let_var_cnt = cgenClassTable.get_method_let_var_cnt(type_name->get_string(), name->get_string());
  // Set up activation record.
  cgenClassTable.code_caller_activation_record_setup(s, let_var_cnt, actual, cgenClassTable);
  // Gen code for e0. 
  if(cgen_debug) std::cout << "[dispatch_class::code]: before gen code for expr" << std::endl;
  expr->code(s, cgenClassTable);
  if(cgen_debug) std::cout << "[dispatch_class::code]: after gen code for expr" << std::endl;
  // Load dispatch table to $t1.
  emit_load(T1, DISPTABLE_OFFSET, ACC, s);
  // Get the class name stored in ACC.
  std::string* class_name = cgenClassTable.store.lookup(MemAddr(ACC, 0));
  // Get method offset based on the static type name.
  int method_offset = cgenClassTable.get_method_offset(*class_name, name->get_string());
  // Load method tag into $t1.
  emit_load(T1, method_offset, T1, s);
  // Jump to method.
  // FIXME: May need to update store for ACC ???
  emit_jalr(T1, s);
  // FIXME: At the start of code for each method, need to update environment!
  // All the class attributes can be referenced by offset of SELF.
  // All the actual parameters can be referenced by offset of FP.
  // Dispath will not update environment because it does not actually gen code for method.
  // Also, dispatch does not need to restore $s0, $s1, $ra and $fp because these are restored by callee at the end.
}

void cond_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  std::string true_tag = "cond_true_" + cgenClassTable.get_tag_cnt();
  std::string false_tag = "cond_false_" + cgenClassTable.get_tag_cnt();
  std::string finish_tag = "cond_finish_" + cgenClassTable.get_tag_cnt();
  // Gen code for compare.
  pred->code(s, cgenClassTable);
  // Move prediction result to $t1.
  emit_move(T1, ACC, s);
  // Load the 1/0 from the bool object in $t1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Jump to false_tag if 0.
  emit_beqz(T1, false_tag, s);
  // Gen code for true tag.
  emit_label_def(true_tag, s);
  then_exp->code(s, cgenClassTable);
  // Jump to finish_tag after true branch finish.
  emit_branch(finish_tag, s);
  // Gen code for false tag.
  emit_label_def(false_tag, s);
  else_exp->code(s, cgenClassTable);
  // Finish tag. The result should be in ACC.
  emit_label_def(finish_tag, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void loop_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  std::string loop_start_tag = "loop_start_" + cgenClassTable.get_tag_cnt();
  std::string loop_end_tag = "loop_end_" + cgenClassTable.get_tag_cnt();
  // Emit loop start label.
  emit_label_def(loop_start_tag, s);
  // Gen code for prediction expression.
  pred->code(s, cgenClassTable);
  // Move prediction result to $t1.
  emit_move(T1, ACC, s);
  // Load the 1/0 from the bool object in $t1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Jump to loop finish if 0.
  emit_beqz(T1, loop_end_tag, s);
  // Gen code for loop body.
  body->code(s, cgenClassTable);
  // Jump to loop_start_tag.
  emit_branch(loop_start_tag, s);
  // Emit loop end label.
  emit_label_def(loop_end_tag, s);
  // Need to update store with the result of if statement.
  // FIXME: Do we need this? Loop will always have NULL as type?
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

std::vector<branch_class*> CgenClassTable::sort_branches(Cases cases) {
  std::vector<branch_class*> rtn;
  // Sort in reverse order.
  // Keep the origional order if two tags are the same.
  unsigned len = cases->len();
  std::vector<bool> visited(len, false);
  while(rtn.size() != len) {
    branch_class* max_branch = nullptr;
    int max_branch_tag = INT_MIN;
    int max_branch_idx = 0;
    for(unsigned i = 0; i < len; i ++) {
      if(visited[i]) {
        continue;
      }
      branch_class* curr_branch = static_cast<branch_class*>(cases->nth(i));
      CgenNodeP curr_branch_class = get_cgen_node_from_symbol(curr_branch->type_decl);
      int curr_branch_class_tag = _class_tags[curr_branch_class].first;
      if(curr_branch_class_tag > max_branch_tag) {
        max_branch_tag = curr_branch_class_tag;
        max_branch_idx = i;
        max_branch = curr_branch;
      }
    }
    visited[max_branch_idx] = true;
    rtn.push_back(max_branch);
  }
  return rtn;
}

void typcase_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // 1. Sort cases with class tag in decending order.
  // 2. Go through these cases and generate code based on their class tag and the max tag value representing the most decendent child class.
  // FIXME: What if two branches have the same class? Is this valid?
  // Gen code for expression.
  expr->code(s, cgenClassTable);
  // FIXME: Check for null object.
  // Load class tag to $t2.
  emit_load(T2, TAG_OFFSET, ACC, s);
  // Gen code for branches.
  std::vector<branch_class*> branches = cgenClassTable.sort_branches(cases);
  std::string finish_label = "case_finish_" + cgenClassTable.get_tag_cnt();
  std::string next_label = "branch_" + cgenClassTable.get_tag_cnt();
  for(auto branch : branches) {
    CgenNodeP curr_branch_class = cgenClassTable.get_cgen_node_from_symbol(branch->type_decl);
    int class_tag = cgenClassTable._class_tags[curr_branch_class].first;
    int greatest_child_class_tag = cgenClassTable._class_tags[curr_branch_class].second;
    std::string curr_label = next_label;
    next_label = "branch_" + cgenClassTable.get_tag_cnt();
    emit_label_def(curr_label, s);
    emit_blti(T2, class_tag, next_label, s);
    emit_bgti(T2, greatest_child_class_tag, next_label, s);
    // Move $a0 to $s2, which could later be used by the expression for the branch.
    emit_move(S2, ACC, s);
    // Add new location ($s2) to environment.
    cgenClassTable.environment.enterscope();
    cgenClassTable.store.enterscope();
    MemAddr* var_addr = new MemAddr(S2, 0);
    cgenClassTable.environment.addid(curr_branch_class->name->get_string(), var_addr);
    cgenClassTable.store.addid(*var_addr, new std::string(branch->type_decl->get_string()));
    // Gen code for branch expression.
    branch->expr->code(s, cgenClassTable);
    // Gen code for branching to case_finish label.
    emit_branch(finish_label, s);
    cgenClassTable.store.exitscope();
    cgenClassTable.environment.exitscope();
    // FIXME: May need to gen code here to handle NULL object.
  }
  // Gen code for _case_abort if nothing matches.
  emit_label_def(next_label, s);
  emit_jal(CASE_ABORT, s);
  // Gen code for label case_finish.
  emit_label_def(finish_label, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void block_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  for(int i = 0; i < body->len(); i ++) {
    body->nth(i)->code(s, cgenClassTable);
  }
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void let_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Gen code for init expression.
  init->code(s, cgenClassTable);
  // Move ACC to location of let var.
  int curr_let_cnt = cgenClassTable.get_curr_let_cnt();
  emit_store(ACC, curr_let_cnt, S1, s);
  // Update environment and store.
  // FIXME: What's the difference between type from init and this->type_decl???
  MemAddr* var_addr = new MemAddr(S1, curr_let_cnt);
  cgenClassTable.environment.enterscope();
  cgenClassTable.store.enterscope();
  cgenClassTable.environment.addid(this->identifier->get_string(), var_addr);
  cgenClassTable.store.addid(*var_addr, new std::string(init->type->get_string()));
  // Gen code for body.
  body->code(s, cgenClassTable);
  cgenClassTable.environment.exitscope();
  cgenClassTable.store.exitscope();
  cgenClassTable.dec_curr_let_cnt();
  cgenClassTable.update_store(ACC, 0, type);
}

void plus_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  this->e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  this->e2->code(s, cgenClassTable);
  // Make a copy of the right Int.
  // The new object is now in ACC.
  emit_jal("Object.copy", s);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Load the actual int from T1 to T1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Load the actual int in ACC to T2.
  emit_load(T2, DEFAULT_OBJFIELDS, ACC, s);
  // Add and store result in T1.
  emit_add(T1, T1, T2, s);
  // Store this result back to ACC.
  emit_store(T1, DEFAULT_OBJFIELDS, ACC, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void sub_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  this->e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  this->e2->code(s, cgenClassTable);
  // Make a copy of the right Int.
  // The new object is now in ACC.
  emit_jal("Object.copy", s);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Load the actual int from T1 to T1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Load the actual int in ACC to T2.
  emit_load(T2, DEFAULT_OBJFIELDS, ACC, s);
  // Sub and store result in T1.
  emit_sub(T1, T1, T2, s);
  // Store this result back to ACC.
  emit_store(T1, DEFAULT_OBJFIELDS, ACC, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void mul_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  this->e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  this->e2->code(s, cgenClassTable);
  // Make a copy of the right Int.
  // The new object is now in ACC.
  emit_jal("Object.copy", s);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Load the actual int from T1 to T1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Load the actual int in ACC to T2.
  emit_load(T2, DEFAULT_OBJFIELDS, ACC, s);
  // Multi and store result in T1.
  emit_mul(T1, T1, T2, s);
  // Store this result back to ACC.
  emit_store(T1, DEFAULT_OBJFIELDS, ACC, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void divide_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  e2->code(s, cgenClassTable);
  // Make a copy of the right Int.
  // The new object is now in ACC.
  emit_jal("Object.copy", s);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Load the actual int from T1 to T1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Load the actual int in ACC to T2.
  emit_load(T2, DEFAULT_OBJFIELDS, ACC, s);
  // FIXME: Need to handle divide by 0 here...

  // Divide and store result in T1.
  emit_div(T1, T1, T2, s);
  // Store this result back to ACC.
  emit_store(T1, DEFAULT_OBJFIELDS, ACC, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}
// ~e1
void neg_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for e1.
  e1->code(s, cgenClassTable);
  // Make a new copy of $ACC.
  emit_jal("Object.copy", s);
  // Load the value from bool to $t1.
  emit_load(T1, DEFAULT_OBJFIELDS, ACC, s);
  // neg $t1.
  emit_neg(T1, T1, s);
  // Store T1 back to ACC.
  emit_store(T1, DEFAULT_OBJFIELDS, ACC, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void lt_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  e2->code(s, cgenClassTable);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Load the actual int from T1 to T1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Load the actual int in ACC to T2.
  emit_load(T2, DEFAULT_OBJFIELDS, ACC, s);
  // Load true to ACC.
  emit_load_bool(ACC, BoolConst(1), s);
  int label_cnt = cgenClassTable.get_tag_cnt();
  // Compare T1 and T2.
  emit_blt(T1, T2, label_cnt, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_label_def(label_cnt, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void eq_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  e2->code(s, cgenClassTable);
  // Put result in T2.
  emit_move(T2, ACC, s);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Move true to ACC, false to A1.
  emit_load_bool(ACC, BoolConst(1), s);
  emit_load_bool(A1, BoolConst(0), s);
  // Call equality_test.
  emit_jal("equality_test", s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void leq_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // Emit code for the left expression.
  e1->code(s, cgenClassTable);
  // Store result on stack.
  emit_store(ACC, 0, SP, s);
  emit_addiu(SP, SP, -4, s);
  // Emit code for the right epxression.
  e2->code(s, cgenClassTable);
  // Load left result from stack.
  emit_load(T1, 4, SP, s);
  emit_addiu(SP, SP, 4, s);
  // Load the actual int from T1 to T1.
  emit_load(T1, DEFAULT_OBJFIELDS, T1, s);
  // Load the actual int in ACC to T2.
  emit_load(T2, DEFAULT_OBJFIELDS, ACC, s);
  // Load true to ACC.
  emit_load_bool(ACC, BoolConst(1), s);
  int label_cnt = cgenClassTable.get_tag_cnt();
  // Compare T1 and T2.
  emit_bleq(T1, T2, label_cnt, s);
  emit_load_bool(ACC, BoolConst(0), s);
  emit_label_def(label_cnt, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}
// not e1.
void comp_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  std::string comp_finish_label = "comp_finish_" + cgenClassTable.get_tag_cnt();
  // Emit code for e1.
  e1->code(s, cgenClassTable);
  // Load the value from bool to $t1.
  emit_load(T1, DEFAULT_OBJFIELDS, ACC, s);
  // Load true to ACC.
  emit_load_bool(ACC, BoolConst(1), s);
  // If $t1 is 0, not $t1 is true, so jump to finish.
  emit_beqz(T1, comp_finish_label, s);
  // Load false to ACC.
  emit_load_bool(ACC, BoolConst(0), s);
  // Emit label def for comp_finish_label.
  emit_label_def(comp_finish_label, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void int_const_class::code(ostream& s, CgenClassTable& cgenClassTable) {
  //
  // Need to be sure we have an IntEntry *, not an arbitrary Symbol
  //
  emit_load_int(ACC,inttable.lookup_string(token->get_string()),s);
}

void string_const_class::code(ostream& s, CgenClassTable& cgenClassTable) {
  emit_load_string(ACC,stringtable.lookup_string(token->get_string()),s);
}

void bool_const_class::code(ostream& s, CgenClassTable& cgenClassTable) {
  emit_load_bool(ACC, BoolConst(val), s);
}

void new__class::code(ostream &s, CgenClassTable& cgenClassTable) {
  Symbol t0 = this->type_name;
  if(t0->get_string() == SELF_TYPE->get_string()) {
    t0 = cgenClassTable.self_class;
  }
  // Load <class>_protObj into $a0.
  std::string class_protObj_name = t0->get_string() + std::string(PROTOBJ_SUFFIX);
  emit_load_address(ACC, (char*)(class_protObj_name.c_str()), s);
  // Call Object.copy.
  emit_jal("Object.copy", s);
  // Call <class>_init.
  std::string class_init_name = t0->get_string() + std::string(CLASSINIT_SUFFIX);
  emit_jal((char*)class_init_name.c_str(), s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, t0->get_string());
}

void isvoid_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  std::string isvoid_true_tag = "is_void_true_" + cgenClassTable.get_tag_cnt();
  std::string isvoid_finish_tag = "is_void_finish_" + cgenClassTable.get_tag_cnt();
  // Gen code for e1.
  e1->code(s, cgenClassTable);
  // If ACC is void, jump to true tag.
  emit_beqz(ACC, isvoid_true_tag, s);
  // Load false to ACC.
  emit_load_bool(ACC, BoolConst(0), s);
  // Jump to finish tag.
  emit_branch(isvoid_finish_tag, s);
  // Label def for true tag.
  emit_label_def(isvoid_true_tag, s);
  // Load true to ACC.
  emit_load_bool(ACC, BoolConst(1), s);
  // Label def for finish tag.
  emit_label_def(isvoid_finish_tag, s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}

void no_expr_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  // FIXME: Not sure what to do about this...
  // // For now, just put 0 in ACC.
  // emit_load_imm(ACC, 0, s);
  // // Update store.
  // cgenClassTable.update_store(ACC, 0, type);
}

void object_class::code(ostream &s, CgenClassTable& cgenClassTable) {
  std::string reg = "";
  int offset = 0;
  // First get the location of id from environment.
  if(std::string(name->get_string()) == "self") {
    reg = SELF;
  } else {
    if(cgen_debug) std::cout << "[object_class] before lookup." << std::endl;
    MemAddr* addr_ptr = cgenClassTable.environment.lookup(name->get_string());
    reg = addr_ptr->reg_name;
    offset = addr_ptr->offset;
  }
  // Load this register to ACC.
  emit_load(ACC, offset, (char*)(reg.c_str()), s);
  // Update store.
  cgenClassTable.update_store(ACC, 0, type);
}


