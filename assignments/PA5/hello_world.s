	.data
	.align	2
	.globl	class_nameTab
	.globl	Main_protObj
	.globl	Int_protObj
	.globl	String_protObj
	.globl	bool_const0
	.globl	bool_const1
	.globl	_int_tag
	.globl	_bool_tag
	.globl	_string_tag
_int_tag:
	.word	10
_bool_tag:
	.word	11
_string_tag:
	.word	12
	.globl	_MemMgr_INITIALIZER
_MemMgr_INITIALIZER:
	.word	_NoGC_Init
	.globl	_MemMgr_COLLECTOR
_MemMgr_COLLECTOR:
	.word	_NoGC_Collect
	.globl	_MemMgr_TEST
_MemMgr_TEST:
	.word	0
	.word	-1
str_const65:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const2
	.ascii	"LambdaListRef"
	.byte	0	
	.align	2
	.word	-1
str_const64:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const3
	.ascii	"LambdaListNE"
	.byte	0	
	.align	2
	.word	-1
str_const63:
	.word	12
	.word	7
	.word	String_dispTab
	.word	int_const4
	.ascii	"LambdaList"
	.byte	0	
	.align	2
	.word	-1
str_const62:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const61:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const60:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const7
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const59:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const58:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"Term"
	.byte	0	
	.align	2
	.word	-1
str_const57:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const7
	.ascii	"App"
	.byte	0	
	.align	2
	.word	-1
str_const56:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Lambda"
	.byte	0	
	.align	2
	.word	-1
str_const55:
	.word	12
	.word	7
	.word	String_dispTab
	.word	int_const8
	.ascii	"Variable"
	.byte	0	
	.align	2
	.word	-1
str_const54:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"Expr"
	.byte	0	
	.align	2
	.word	-1
str_const53:
	.word	12
	.word	7
	.word	String_dispTab
	.word	int_const9
	.ascii	"VarListNE"
	.byte	0	
	.align	2
	.word	-1
str_const52:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const10
	.ascii	"VarList"
	.byte	0	
	.align	2
	.word	-1
str_const51:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const50:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const49:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const2
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const48:
	.word	12
	.word	9
	.word	String_dispTab
	.word	int_const12
	.ascii	"after call beta()\n"
	.byte	0	
	.align	2
	.word	-1
str_const47:
	.word	12
	.word	9
	.word	String_dispTab
	.word	int_const13
	.ascii	"before call beta()\n"
	.byte	0	
	.align	2
	.word	-1
str_const46:
	.word	12
	.word	11
	.word	String_dispTab
	.word	int_const14
	.ascii	"-------------beta-reduce: "
	.byte	0	
	.align	2
	.word	-1
str_const45:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"z"
	.byte	0	
	.align	2
	.word	-1
str_const44:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"y"
	.byte	0	
	.align	2
	.word	-1
str_const43:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"x"
	.byte	0	
	.align	2
	.word	-1
str_const42:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const10
	.ascii	"  esac)"
	.byte	0	
	.align	2
	.word	-1
str_const41:
	.word	12
	.word	17
	.word	String_dispTab
	.word	int_const15
	.ascii	"    o : Object => { abort(); new EvalObject; };\n"
	.byte	0	
	.align	2
	.word	-1
str_const40:
	.word	12
	.word	12
	.word	String_dispTab
	.word	int_const16
	.ascii	"    c : Closure => c.apply(y);\n"
	.byte	0	
	.align	2
	.word	-1
str_const39:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const3
	.ascii	"  case x of\n"
	.byte	0	
	.align	2
	.word	-1
str_const38:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	" in\n"
	.byte	0	
	.align	2
	.word	-1
str_const37:
	.word	12
	.word	10
	.word	String_dispTab
	.word	int_const17
	.ascii	"     y : EvalObject <- "
	.byte	0	
	.align	2
	.word	-1
str_const36:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	",\n"
	.byte	0	
	.align	2
	.word	-1
str_const35:
	.word	12
	.word	10
	.word	String_dispTab
	.word	int_const17
	.ascii	"(let x : EvalObject <- "
	.byte	0	
	.align	2
	.word	-1
str_const34:
	.word	12
	.word	11
	.word	String_dispTab
	.word	int_const18
	.ascii	"\n is type expression...\n"
	.byte	0	
	.align	2
	.word	-1
str_const33:
	.word	12
	.word	10
	.word	String_dispTab
	.word	int_const19
	.ascii	"\n is type Lambda...\n"
	.byte	0	
	.align	2
	.word	-1
str_const32:
	.word	12
	.word	9
	.word	String_dispTab
	.word	int_const13
	.ascii	"App beta is called\n"
	.byte	0	
	.align	2
	.word	-1
str_const31:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"))"
	.byte	0	
	.align	2
	.word	-1
str_const30:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const7
	.ascii	")@("
	.byte	0	
	.align	2
	.word	-1
str_const29:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const11
	.ascii	"(("
	.byte	0	
	.align	2
	.word	-1
str_const28:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const6
	.ascii	"App\n"
	.byte	0	
	.align	2
	.word	-1
str_const27:
	.word	12
	.word	10
	.word	String_dispTab
	.word	int_const19
	.ascii	"App init is called!\n"
	.byte	0	
	.align	2
	.word	-1
str_const26:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const7
	.ascii	"};\n"
	.byte	0	
	.align	2
	.word	-1
str_const25:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const20
	.ascii	";}};\n"
	.byte	0	
	.align	2
	.word	-1
str_const24:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const21
	.ascii	"      x <- y;\n"
	.byte	0	
	.align	2
	.word	-1
str_const23:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const5
	.byte	92
	.ascii	"n\");\n"
	.byte	0	
	.align	2
	.word	-1
str_const22:
	.word	12
	.word	13
	.word	String_dispTab
	.word	int_const22
	.ascii	"    { out_string(\"Applying closure "
	.byte	0	
	.align	2
	.word	-1
str_const21:
	.word	12
	.word	14
	.word	String_dispTab
	.word	int_const23
	.ascii	"  apply(y : EvalObject) : EvalObject {\n"
	.byte	0	
	.align	2
	.word	-1
str_const20:
	.word	12
	.word	10
	.word	String_dispTab
	.word	int_const19
	.ascii	" inherits Closure {\n"
	.byte	0	
	.align	2
	.word	-1
str_const19:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const2
	.ascii	"class Closure"
	.byte	0	
	.align	2
	.word	-1
str_const18:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const5
	.ascii	"self))"
	.byte	0	
	.align	2
	.word	-1
str_const17:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const2
	.ascii	"new Closure))"
	.byte	0	
	.align	2
	.word	-1
str_const16:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const10
	.ascii	").init("
	.byte	0	
	.align	2
	.word	-1
str_const15:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const2
	.ascii	"((new Closure"
	.byte	0	
	.align	2
	.word	-1
str_const14:
	.word	12
	.word	11
	.word	String_dispTab
	.word	int_const24
	.ascii	"Lambda::apply is called...\n"
	.byte	0	
	.align	2
	.word	-1
str_const13:
	.word	12
	.word	10
	.word	String_dispTab
	.word	int_const25
	.ascii	"lam beta is called..."
	.byte	0	
	.align	2
	.word	-1
str_const12:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"."
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const1
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const10
	.ascii	"Lambda\n"
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	12
	.word	6
	.word	String_dispTab
	.word	int_const10
	.ascii	"get_x()"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	12
	.word	11
	.word	String_dispTab
	.word	int_const24
	.ascii	"Error:  free occurrence of "
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const2
	.ascii	"get_parent()."
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	12
	.word	16
	.word	String_dispTab
	.word	int_const26
	.ascii	"\nError: Expr is pure virtual; can't gen_code\n"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	12
	.word	16
	.word	String_dispTab
	.word	int_const27
	.ascii	"\nError: Expr is pure virtual; can't substitute\n"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	12
	.word	17
	.word	String_dispTab
	.word	int_const15
	.ascii	"\nError: Expr is pure virtual; can't beta-reduce\n"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	12
	.word	16
	.word	String_dispTab
	.word	int_const27
	.ascii	"\nError: Expr is pure virtual; can't print self\n"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	" "
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const0
	.ascii	"\n"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	12
	.word	8
	.word	String_dispTab
	.word	int_const21
	.ascii	"hello_world.cl"
	.byte	0	
	.align	2
	.word	-1
int_const27:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	47
	.word	-1
int_const26:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	45
	.word	-1
int_const25:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	21
	.word	-1
int_const24:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	27
	.word	-1
int_const23:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	39
	.word	-1
int_const22:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	35
	.word	-1
int_const21:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	14
	.word	-1
int_const20:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	5
	.word	-1
int_const19:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	20
	.word	-1
int_const18:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	24
	.word	-1
int_const17:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	23
	.word	-1
int_const16:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	31
	.word	-1
int_const15:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	48
	.word	-1
int_const14:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	26
	.word	-1
int_const13:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	19
	.word	-1
int_const12:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	18
	.word	-1
int_const11:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const10:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	7
	.word	-1
int_const9:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const8:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	8
	.word	-1
int_const7:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const6:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const5:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const4:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const3:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	12
	.word	-1
int_const2:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const1:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
int_const0:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
bool_const0:
	.word	11
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	11
	.word	4
	.word	Bool_dispTab
	.word	1
class_nameTab:
	.word	str_const50
	.word	str_const51
	.word	str_const52
	.word	str_const53
	.word	str_const54
	.word	str_const55
	.word	str_const56
	.word	str_const57
	.word	str_const58
	.word	str_const59
	.word	str_const60
	.word	str_const61
	.word	str_const62
	.word	str_const63
	.word	str_const64
	.word	str_const65
class_objTab:
	.word	Object_protObj
	.word	Object_init
	.word	IO_protObj
	.word	IO_init
	.word	VarList_protObj
	.word	VarList_init
	.word	VarListNE_protObj
	.word	VarListNE_init
	.word	Expr_protObj
	.word	Expr_init
	.word	Variable_protObj
	.word	Variable_init
	.word	Lambda_protObj
	.word	Lambda_init
	.word	App_protObj
	.word	App_init
	.word	Term_protObj
	.word	Term_init
	.word	Main_protObj
	.word	Main_init
	.word	Int_protObj
	.word	Int_init
	.word	Bool_protObj
	.word	Bool_init
	.word	String_protObj
	.word	String_init
	.word	LambdaList_protObj
	.word	LambdaList_init
	.word	LambdaListNE_protObj
	.word	LambdaListNE_init
	.word	LambdaListRef_protObj
	.word	LambdaListRef_init
Object_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
LambdaListRef_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	LambdaListRef.isNil
	.word	LambdaListRef.headE
	.word	LambdaListRef.headC
	.word	LambdaListRef.headN
	.word	LambdaListRef.reset
	.word	LambdaListRef.add
	.word	LambdaListRef.removeHead
LambdaList_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	LambdaList.isNil
	.word	LambdaList.headE
	.word	LambdaList.headC
	.word	LambdaList.headN
	.word	LambdaList.tail
	.word	LambdaList.add
LambdaListNE_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	LambdaListNE.isNil
	.word	LambdaListNE.headE
	.word	LambdaListNE.headC
	.word	LambdaListNE.headN
	.word	LambdaListNE.tail
	.word	LambdaList.add
	.word	LambdaListNE.init
String_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	String.length
	.word	String.concat
	.word	String.substr
Bool_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
Int_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
IO_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
Term_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Term.var
	.word	Term.lam
	.word	Term.app
	.word	Term.i
	.word	Term.k
	.word	Term.s
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Term.var
	.word	Term.lam
	.word	Term.app
	.word	Term.i
	.word	Term.k
	.word	Term.s
	.word	Main.beta_reduce
	.word	Main.main
Expr_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Expr.print_self
	.word	Expr.beta
	.word	Expr.substitute
	.word	Expr.gen_code
App_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	App.print_self
	.word	App.beta
	.word	App.substitute
	.word	App.gen_code
	.word	App.init
Lambda_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Lambda.print_self
	.word	Lambda.beta
	.word	Lambda.substitute
	.word	Lambda.gen_code
	.word	Lambda.init
	.word	Lambda.apply
	.word	Lambda.gen_closure_code
Variable_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Variable.print_self
	.word	Variable.beta
	.word	Variable.substitute
	.word	Variable.gen_code
	.word	Variable.init
VarList_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	VarList.isNil
	.word	VarList.head
	.word	VarList.tail
	.word	VarList.add
	.word	VarList.print
VarListNE_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	VarListNE.isNil
	.word	VarListNE.head
	.word	VarListNE.tail
	.word	VarList.add
	.word	VarListNE.print
	.word	VarListNE.init
	.word	-1
Object_protObj:
	.word	0
	.word	3
	.word	Object_dispTab
	.word	-1
LambdaListRef_protObj:
	.word	15
	.word	5
	.word	LambdaListRef_dispTab
	.word	int_const1
	.word	0
	.word	-1
LambdaList_protObj:
	.word	13
	.word	3
	.word	LambdaList_dispTab
	.word	-1
LambdaListNE_protObj:
	.word	14
	.word	7
	.word	LambdaListNE_dispTab
	.word	0
	.word	int_const1
	.word	0
	.word	0
	.word	-1
String_protObj:
	.word	12
	.word	5
	.word	String_dispTab
	.word	int_const1
	.word	0
	.word	-1
Bool_protObj:
	.word	11
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
Int_protObj:
	.word	10
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
IO_protObj:
	.word	1
	.word	3
	.word	IO_dispTab
	.word	-1
Term_protObj:
	.word	8
	.word	3
	.word	Term_dispTab
	.word	-1
Main_protObj:
	.word	9
	.word	3
	.word	Main_dispTab
	.word	-1
Expr_protObj:
	.word	4
	.word	3
	.word	Expr_dispTab
	.word	-1
App_protObj:
	.word	7
	.word	5
	.word	App_dispTab
	.word	0
	.word	0
	.word	-1
Lambda_protObj:
	.word	6
	.word	5
	.word	Lambda_dispTab
	.word	0
	.word	0
	.word	-1
Variable_protObj:
	.word	5
	.word	4
	.word	Variable_dispTab
	.word	str_const11
	.word	-1
VarList_protObj:
	.word	2
	.word	3
	.word	VarList_dispTab
	.word	-1
VarListNE_protObj:
	.word	3
	.word	5
	.word	VarListNE_dispTab
	.word	0
	.word	0
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main
Object_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	la	$a0 int_const1
	sw	$a0 12($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListNE_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	LambdaList_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
String_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Bool_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Int_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
IO_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Term_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Term_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Expr_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
App_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Expr_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Lambda_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Expr_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Variable_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	Expr_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarList_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	IO_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarListNE_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	jal	VarList_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	bne	$a0 $zero label0
	la	$a0 str_const0
	li	$t1 409
	jal	_dispatch_abort
label0:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef.headE:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	bne	$a0 $zero label1
	la	$a0 str_const0
	li	$t1 410
	jal	_dispatch_abort
label1:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef.headC:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	bne	$a0 $zero label2
	la	$a0 str_const0
	li	$t1 411
	jal	_dispatch_abort
label2:
	lw	$t1 8($a0)
	lw	$t1 20($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef.headN:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	bne	$a0 $zero label3
	la	$a0 str_const0
	li	$t1 412
	jal	_dispatch_abort
label3:
	lw	$t1 8($a0)
	lw	$t1 24($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef.reset:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 int_const1
	sw	$a0 12($s0)
	la	$a0 LambdaList_protObj
	jal	Object.copy
	jal	LambdaList_init
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListRef.add:
	addiu	$sp $sp -16
	sw	$fp 16($sp)
	sw	$s0 12($sp)
	sw	$ra 8($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 0($fp)
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label4
	la	$a0 str_const0
	li	$t1 422
	jal	_dispatch_abort
label4:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 16($s0)
	lw	$s1 12($s0)
	la	$a0 int_const0
	jal	Object.copy
	lw	$t2 12($a0)
	lw	$t1 12($s1)
	add	$t1 $t1 $t2
	sw	$t1 12($a0)
	sw	$a0 12($s0)
	lw	$s1 12($s0)
	la	$a0 int_const0
	jal	Object.copy
	lw	$t2 12($a0)
	lw	$t1 12($s1)
	sub	$t1 $t1 $t2
	sw	$t1 12($a0)
	lw	$s1 0($fp)
	lw	$fp 16($sp)
	lw	$s0 12($sp)
	lw	$ra 8($sp)
	addiu	$sp $sp 24
	jr	$ra	
LambdaListRef.removeHead:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	bne	$a0 $zero label5
	la	$a0 str_const0
	li	$t1 429
	jal	_dispatch_abort
label5:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList.headE:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label6
	la	$a0 str_const0
	li	$t1 376
	jal	_dispatch_abort
label6:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 VarList_protObj
	jal	Object.copy
	jal	VarList_init
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList.headC:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label7
	la	$a0 str_const0
	li	$t1 377
	jal	_dispatch_abort
label7:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 Lambda_protObj
	jal	Object.copy
	jal	Lambda_init
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList.headN:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label8
	la	$a0 str_const0
	li	$t1 378
	jal	_dispatch_abort
label8:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 int_const1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label9
	la	$a0 str_const0
	li	$t1 379
	jal	_dispatch_abort
label9:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 LambdaList_protObj
	jal	Object.copy
	jal	LambdaList_init
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaList.add:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 LambdaListNE_protObj
	jal	Object.copy
	jal	LambdaListNE_init
	bne	$a0 $zero label10
	la	$a0 str_const0
	li	$t1 381
	jal	_dispatch_abort
label10:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 24
	jr	$ra	
LambdaListNE.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListNE.headE:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 20($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListNE.headC:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListNE.headN:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListNE.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 24($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
LambdaListNE.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 24($fp)
	sw	$a0 20($s0)
	lw	$a0 20($fp)
	sw	$a0 12($s0)
	lw	$a0 16($fp)
	sw	$a0 16($s0)
	lw	$a0 12($fp)
	sw	$a0 24($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 28
	jr	$ra	
Term.var:
	addiu	$sp $sp -16
	sw	$fp 16($sp)
	sw	$s0 12($sp)
	sw	$ra 8($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 0($fp)
	la	$a0 Variable_protObj
	jal	Object.copy
	jal	Variable_init
	move	$s1 $a0
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s1
	bne	$a0 $zero label11
	la	$a0 str_const0
	li	$t1 692
	jal	_dispatch_abort
label11:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$s1 0($fp)
	lw	$fp 16($sp)
	lw	$s0 12($sp)
	lw	$ra 8($sp)
	addiu	$sp $sp 20
	jr	$ra	
Term.lam:
	addiu	$sp $sp -16
	sw	$fp 16($sp)
	sw	$s0 12($sp)
	sw	$ra 8($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 0($fp)
	la	$a0 Lambda_protObj
	jal	Object.copy
	jal	Lambda_init
	move	$s1 $a0
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s1
	bne	$a0 $zero label12
	la	$a0 str_const0
	li	$t1 697
	jal	_dispatch_abort
label12:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$s1 0($fp)
	lw	$fp 16($sp)
	lw	$s0 12($sp)
	lw	$ra 8($sp)
	addiu	$sp $sp 24
	jr	$ra	
Term.app:
	addiu	$sp $sp -16
	sw	$fp 16($sp)
	sw	$s0 12($sp)
	sw	$ra 8($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 0($fp)
	la	$a0 App_protObj
	jal	Object.copy
	jal	App_init
	move	$s1 $a0
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s1
	bne	$a0 $zero label13
	la	$a0 str_const0
	li	$t1 702
	jal	_dispatch_abort
label13:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$s1 0($fp)
	lw	$fp 16($sp)
	lw	$s0 12($sp)
	lw	$ra 8($sp)
	addiu	$sp $sp 24
	jr	$ra	
Term.i:
	addiu	$sp $sp -16
	sw	$fp 16($sp)
	sw	$s0 12($sp)
	sw	$ra 8($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 0($fp)
	la	$a0 str_const43
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label14
	la	$a0 str_const0
	li	$t1 709
	jal	_dispatch_abort
label14:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$s1 $a0
	sw	$s1 0($sp)
	addiu	$sp $sp -4
	sw	$s1 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label15
	la	$a0 str_const0
	li	$t1 710
	jal	_dispatch_abort
label15:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	lw	$s1 0($fp)
	lw	$fp 16($sp)
	lw	$s0 12($sp)
	lw	$ra 8($sp)
	addiu	$sp $sp 16
	jr	$ra	
Term.k:
	addiu	$sp $sp -20
	sw	$fp 20($sp)
	sw	$s0 16($sp)
	sw	$ra 12($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 4($fp)
	sw	$s2 0($fp)
	la	$a0 str_const43
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label16
	la	$a0 str_const0
	li	$t1 714
	jal	_dispatch_abort
label16:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$s2 $a0
	la	$a0 str_const44
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label17
	la	$a0 str_const0
	li	$t1 715
	jal	_dispatch_abort
label17:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$s1 $a0
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	sw	$s1 0($sp)
	addiu	$sp $sp -4
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label18
	la	$a0 str_const0
	li	$t1 716
	jal	_dispatch_abort
label18:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label19
	la	$a0 str_const0
	li	$t1 716
	jal	_dispatch_abort
label19:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	lw	$s1 4($fp)
	lw	$s2 0($fp)
	lw	$fp 20($sp)
	lw	$s0 16($sp)
	lw	$ra 12($sp)
	addiu	$sp $sp 20
	jr	$ra	
Term.s:
	addiu	$sp $sp -24
	sw	$fp 24($sp)
	sw	$s0 20($sp)
	sw	$ra 16($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 8($fp)
	sw	$s2 4($fp)
	sw	$s3 0($fp)
	la	$a0 str_const43
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label20
	la	$a0 str_const0
	li	$t1 720
	jal	_dispatch_abort
label20:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$s3 $a0
	la	$a0 str_const44
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label21
	la	$a0 str_const0
	li	$t1 721
	jal	_dispatch_abort
label21:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$s2 $a0
	la	$a0 str_const45
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label22
	la	$a0 str_const0
	li	$t1 722
	jal	_dispatch_abort
label22:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$s1 $a0
	sw	$s3 0($sp)
	addiu	$sp $sp -4
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	sw	$s1 0($sp)
	addiu	$sp $sp -4
	sw	$s3 0($sp)
	addiu	$sp $sp -4
	sw	$s1 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label23
	la	$a0 str_const0
	li	$t1 723
	jal	_dispatch_abort
label23:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	sw	$s1 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label24
	la	$a0 str_const0
	li	$t1 723
	jal	_dispatch_abort
label24:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label25
	la	$a0 str_const0
	li	$t1 723
	jal	_dispatch_abort
label25:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label26
	la	$a0 str_const0
	li	$t1 723
	jal	_dispatch_abort
label26:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label27
	la	$a0 str_const0
	li	$t1 723
	jal	_dispatch_abort
label27:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label28
	la	$a0 str_const0
	li	$t1 723
	jal	_dispatch_abort
label28:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	lw	$s1 8($fp)
	lw	$s2 4($fp)
	lw	$s3 0($fp)
	lw	$fp 24($sp)
	lw	$s0 20($sp)
	lw	$ra 16($sp)
	addiu	$sp $sp 24
	jr	$ra	
Main.beta_reduce:
	addiu	$sp $sp -24
	sw	$fp 24($sp)
	sw	$s0 20($sp)
	sw	$ra 16($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 8($fp)
	sw	$s2 4($fp)
	sw	$s3 0($fp)
	la	$a0 str_const46
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label29
	la	$a0 str_const0
	li	$t1 732
	jal	_dispatch_abort
label29:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 24($fp)
	bne	$a0 $zero label30
	la	$a0 str_const0
	li	$t1 733
	jal	_dispatch_abort
label30:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	la	$s3 bool_const0
	move	$s2 $zero
label31:
	lw	$t1 12($s3)
	la	$a0 bool_const1
	beqz	$t1 label33
	la	$a0 bool_const0
label33:
	lw	$t1 12($a0)
	beq	$t1 $zero label32
	la	$a0 str_const47
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label34
	la	$a0 str_const0
	li	$t1 739
	jal	_dispatch_abort
label34:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 24($fp)
	bne	$a0 $zero label35
	la	$a0 str_const0
	li	$t1 740
	jal	_dispatch_abort
label35:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	move	$s2 $a0
	la	$a0 str_const48
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label36
	la	$a0 str_const0
	li	$t1 741
	jal	_dispatch_abort
label36:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$s1 $s2
	lw	$t2 24($fp)
	move	$t1 $s1
	la	$a0 bool_const1
	beq	$t1 $t2 label39
	la	$a1 bool_const0
	jal	equality_test
label39:
	lw	$t1 12($a0)
	beqz	$t1 label37
	la	$s3 bool_const1
	move	$a0 $s3
	b	label38
label37:
	sw	$s2 24($fp)
	move	$a0 $s2
label38:
	b	label31
label32:
	move	$a0 $zero
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label40
	la	$a0 str_const0
	li	$t1 753
	jal	_dispatch_abort
label40:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 24($fp)
	lw	$s1 8($fp)
	lw	$s2 4($fp)
	lw	$s3 0($fp)
	lw	$fp 24($sp)
	lw	$s0 20($sp)
	lw	$ra 16($sp)
	addiu	$sp $sp 28
	jr	$ra	
Main.main:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label41
	la	$a0 str_const0
	li	$t1 767
	jal	_dispatch_abort
label41:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label42
	la	$a0 str_const0
	li	$t1 767
	jal	_dispatch_abort
label42:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label43
	la	$a0 str_const0
	li	$t1 767
	jal	_dispatch_abort
label43:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label44
	la	$a0 str_const0
	li	$t1 767
	jal	_dispatch_abort
label44:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label45
	la	$a0 str_const0
	li	$t1 767
	jal	_dispatch_abort
label45:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label46
	la	$a0 str_const0
	li	$t1 767
	jal	_dispatch_abort
label46:
	lw	$t1 8($a0)
	lw	$t1 52($t1)
	jalr		$t1
	la	$a0 int_const1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Expr.print_self:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const3
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label47
	la	$a0 str_const0
	li	$t1 446
	jal	_dispatch_abort
label47:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label48
	la	$a0 str_const0
	li	$t1 447
	jal	_dispatch_abort
label48:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Expr.beta:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const4
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label49
	la	$a0 str_const0
	li	$t1 455
	jal	_dispatch_abort
label49:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label50
	la	$a0 str_const0
	li	$t1 456
	jal	_dispatch_abort
label50:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Expr.substitute:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const5
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label51
	la	$a0 str_const0
	li	$t1 464
	jal	_dispatch_abort
label51:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label52
	la	$a0 str_const0
	li	$t1 465
	jal	_dispatch_abort
label52:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
Expr.gen_code:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const6
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label53
	la	$a0 str_const0
	li	$t1 473
	jal	_dispatch_abort
label53:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label54
	la	$a0 str_const0
	li	$t1 474
	jal	_dispatch_abort
label54:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
App.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const27
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label55
	la	$a0 str_const0
	li	$t1 619
	jal	_dispatch_abort
label55:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($fp)
	sw	$a0 12($s0)
	lw	$a0 12($fp)
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
App.print_self:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const28
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label56
	la	$a0 str_const0
	li	$t1 628
	jal	_dispatch_abort
label56:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const29
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label57
	la	$a0 str_const0
	li	$t1 629
	jal	_dispatch_abort
label57:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	bne	$a0 $zero label58
	la	$a0 str_const0
	li	$t1 630
	jal	_dispatch_abort
label58:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	la	$a0 str_const30
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label59
	la	$a0 str_const0
	li	$t1 631
	jal	_dispatch_abort
label59:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($s0)
	bne	$a0 $zero label60
	la	$a0 str_const0
	li	$t1 632
	jal	_dispatch_abort
label60:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	la	$a0 str_const31
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label61
	la	$a0 str_const0
	li	$t1 633
	jal	_dispatch_abort
label61:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
App.beta:
	addiu	$sp $sp -24
	sw	$fp 24($sp)
	sw	$s0 20($sp)
	sw	$ra 16($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 8($fp)
	sw	$s2 4($fp)
	sw	$s3 0($fp)
	la	$a0 str_const32
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label62
	la	$a0 str_const0
	li	$t1 640
	jal	_dispatch_abort
label62:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	bne	$a0 $zero label63
	la	$a0 str_const0
	li	$t1 641
	jal	_dispatch_abort
label63:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	lw	$a0 12($s0)
	bne	$a0 $zero label65
	la	$a0 str_const0
	li	$t1 642
	jal	_case_abort2
label65:
	lw	$t2 0($a0)
	blt	$t2 6 label66
	bgt	$t2 6 label66
	move	$s3 $a0
	la	$a0 str_const33
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label67
	la	$a0 str_const0
	li	$t1 644
	jal	_dispatch_abort
label67:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s3
	bne	$a0 $zero label68
	la	$a0 str_const0
	li	$t1 645
	jal	_dispatch_abort
label68:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
	b	label64
label66:
	blt	$t2 4 label69
	bgt	$t2 7 label69
	move	$s3 $a0
	la	$a0 str_const34
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label70
	la	$a0 str_const0
	li	$t1 649
	jal	_dispatch_abort
label70:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	bne	$a0 $zero label71
	la	$a0 str_const0
	li	$t1 650
	jal	_dispatch_abort
label71:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	move	$s2 $a0
	la	$a0 App_protObj
	jal	Object.copy
	jal	App_init
	move	$s1 $a0
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s1
	bne	$a0 $zero label72
	la	$a0 str_const0
	li	$t1 652
	jal	_dispatch_abort
label72:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	b	label64
label69:
	jal	_case_abort
label64:
	lw	$s1 8($fp)
	lw	$s2 4($fp)
	lw	$s3 0($fp)
	lw	$fp 24($sp)
	lw	$s0 20($sp)
	lw	$ra 16($sp)
	addiu	$sp $sp 24
	jr	$ra	
App.substitute:
	addiu	$sp $sp -24
	sw	$fp 24($sp)
	sw	$s0 20($sp)
	sw	$ra 16($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 8($fp)
	sw	$s2 4($fp)
	sw	$s3 0($fp)
	lw	$a0 28($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 24($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($s0)
	bne	$a0 $zero label73
	la	$a0 str_const0
	li	$t1 659
	jal	_dispatch_abort
label73:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	move	$s3 $a0
	lw	$a0 28($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 24($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label74
	la	$a0 str_const0
	li	$t1 660
	jal	_dispatch_abort
label74:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	move	$s2 $a0
	la	$a0 App_protObj
	jal	Object.copy
	jal	App_init
	move	$s1 $a0
	sw	$s3 0($sp)
	addiu	$sp $sp -4
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s1
	bne	$a0 $zero label75
	la	$a0 str_const0
	li	$t1 662
	jal	_dispatch_abort
label75:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	lw	$s1 8($fp)
	lw	$s2 4($fp)
	lw	$s3 0($fp)
	lw	$fp 24($sp)
	lw	$s0 20($sp)
	lw	$ra 16($sp)
	addiu	$sp $sp 32
	jr	$ra	
App.gen_code:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const35
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label76
	la	$a0 str_const0
	li	$t1 667
	jal	_dispatch_abort
label76:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($s0)
	bne	$a0 $zero label77
	la	$a0 str_const0
	li	$t1 668
	jal	_dispatch_abort
label77:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	la	$a0 str_const36
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label78
	la	$a0 str_const0
	li	$t1 669
	jal	_dispatch_abort
label78:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const37
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label79
	la	$a0 str_const0
	li	$t1 670
	jal	_dispatch_abort
label79:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label80
	la	$a0 str_const0
	li	$t1 671
	jal	_dispatch_abort
label80:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	la	$a0 str_const38
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label81
	la	$a0 str_const0
	li	$t1 672
	jal	_dispatch_abort
label81:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const39
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label82
	la	$a0 str_const0
	li	$t1 673
	jal	_dispatch_abort
label82:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const40
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label83
	la	$a0 str_const0
	li	$t1 674
	jal	_dispatch_abort
label83:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const41
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label84
	la	$a0 str_const0
	li	$t1 675
	jal	_dispatch_abort
label84:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const42
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label85
	la	$a0 str_const0
	li	$t1 676
	jal	_dispatch_abort
label85:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
Lambda.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($fp)
	sw	$a0 12($s0)
	lw	$a0 12($fp)
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
Lambda.print_self:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const10
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label86
	la	$a0 str_const0
	li	$t1 545
	jal	_dispatch_abort
label86:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const11
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label87
	la	$a0 str_const0
	li	$t1 546
	jal	_dispatch_abort
label87:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	bne	$a0 $zero label88
	la	$a0 str_const0
	li	$t1 547
	jal	_dispatch_abort
label88:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	la	$a0 str_const12
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label89
	la	$a0 str_const0
	li	$t1 548
	jal	_dispatch_abort
label89:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($s0)
	bne	$a0 $zero label90
	la	$a0 str_const0
	li	$t1 549
	jal	_dispatch_abort
label90:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Lambda.beta:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const13
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label91
	la	$a0 str_const0
	li	$t1 556
	jal	_dispatch_abort
label91:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Lambda.apply:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const14
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label92
	la	$a0 str_const0
	li	$t1 563
	jal	_dispatch_abort
label92:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label93
	la	$a0 str_const0
	li	$t1 564
	jal	_dispatch_abort
label93:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
Lambda.substitute:
	addiu	$sp $sp -20
	sw	$fp 20($sp)
	sw	$s0 16($sp)
	sw	$ra 12($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 4($fp)
	sw	$s2 0($fp)
	lw	$s2 24($fp)
	lw	$t2 12($s0)
	move	$t1 $s2
	la	$a0 bool_const1
	beq	$t1 $t2 label96
	la	$a1 bool_const0
	jal	equality_test
label96:
	lw	$t1 12($a0)
	beqz	$t1 label94
	move	$a0 $s0
	b	label95
label94:
	lw	$a0 24($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label97
	la	$a0 str_const0
	li	$t1 573
	jal	_dispatch_abort
label97:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	move	$s2 $a0
	la	$a0 Lambda_protObj
	jal	Object.copy
	jal	Lambda_init
	move	$s1 $a0
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	sw	$s2 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s1
	bne	$a0 $zero label98
	la	$a0 str_const0
	li	$t1 575
	jal	_dispatch_abort
label98:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
label95:
	lw	$s1 4($fp)
	lw	$s2 0($fp)
	lw	$fp 20($sp)
	lw	$s0 16($sp)
	lw	$ra 12($sp)
	addiu	$sp $sp 28
	jr	$ra	
Lambda.gen_code:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const15
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label99
	la	$a0 str_const0
	li	$t1 581
	jal	_dispatch_abort
label99:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	bne	$a0 $zero label100
	la	$a0 str_const0
	li	$t1 582
	jal	_dispatch_abort
label100:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label101
	la	$a0 str_const0
	li	$t1 582
	jal	_dispatch_abort
label101:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	la	$a0 str_const16
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label102
	la	$a0 str_const0
	li	$t1 583
	jal	_dispatch_abort
label102:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($fp)
	bne	$a0 $zero label105
	la	$a0 str_const0
	li	$t1 584
	jal	_dispatch_abort
label105:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	lw	$t1 12($a0)
	beqz	$t1 label103
	la	$a0 str_const17
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label106
	la	$a0 str_const0
	li	$t1 585
	jal	_dispatch_abort
label106:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	b	label104
label103:
	la	$a0 str_const18
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label107
	la	$a0 str_const0
	li	$t1 587
	jal	_dispatch_abort
label107:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
label104:
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
Lambda.gen_closure_code:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const19
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label108
	la	$a0 str_const0
	li	$t1 595
	jal	_dispatch_abort
label108:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label109
	la	$a0 str_const0
	li	$t1 596
	jal	_dispatch_abort
label109:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	la	$a0 str_const20
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label110
	la	$a0 str_const0
	li	$t1 597
	jal	_dispatch_abort
label110:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const21
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label111
	la	$a0 str_const0
	li	$t1 598
	jal	_dispatch_abort
label111:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const22
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label112
	la	$a0 str_const0
	li	$t1 599
	jal	_dispatch_abort
label112:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 20($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label113
	la	$a0 str_const0
	li	$t1 600
	jal	_dispatch_abort
label113:
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
	la	$a0 str_const23
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label114
	la	$a0 str_const0
	li	$t1 601
	jal	_dispatch_abort
label114:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const24
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label115
	la	$a0 str_const0
	li	$t1 602
	jal	_dispatch_abort
label115:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($fp)
	bne	$a0 $zero label116
	la	$a0 str_const0
	li	$t1 603
	jal	_dispatch_abort
label116:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	lw	$a0 16($s0)
	bne	$a0 $zero label117
	la	$a0 str_const0
	li	$t1 603
	jal	_dispatch_abort
label117:
	lw	$t1 8($a0)
	lw	$t1 40($t1)
	jalr		$t1
	la	$a0 str_const25
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label118
	la	$a0 str_const0
	li	$t1 604
	jal	_dispatch_abort
label118:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	la	$a0 str_const26
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label119
	la	$a0 str_const0
	li	$t1 605
	jal	_dispatch_abort
label119:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 24
	jr	$ra	
Variable.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 12($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
Variable.print_self:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label120
	la	$a0 str_const0
	li	$t1 494
	jal	_dispatch_abort
label120:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Variable.beta:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Variable.substitute:
	addiu	$sp $sp -16
	sw	$fp 16($sp)
	sw	$s0 12($sp)
	sw	$ra 8($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 0($fp)
	lw	$s1 20($fp)
	move	$t2 $s0
	move	$t1 $s1
	la	$a0 bool_const1
	beq	$t1 $t2 label123
	la	$a1 bool_const0
	jal	equality_test
label123:
	lw	$t1 12($a0)
	beqz	$t1 label121
	lw	$a0 16($fp)
	b	label122
label121:
	move	$a0 $s0
label122:
	lw	$s1 0($fp)
	lw	$fp 16($sp)
	lw	$s0 12($sp)
	lw	$ra 8($sp)
	addiu	$sp $sp 24
	jr	$ra	
Variable.gen_code:
	addiu	$sp $sp -20
	sw	$fp 20($sp)
	sw	$s0 16($sp)
	sw	$ra 12($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	sw	$s1 4($fp)
	sw	$s2 0($fp)
	lw	$s2 24($fp)
label124:
	move	$a0 $s2
	bne	$a0 $zero label128
	la	$a0 str_const0
	li	$t1 505
	jal	_dispatch_abort
label128:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	lw	$t1 12($a0)
	beqz	$t1 label126
	la	$a0 bool_const0
	b	label127
label126:
	move	$a0 $s2
	bne	$a0 $zero label131
	la	$a0 str_const0
	li	$t1 508
	jal	_dispatch_abort
label131:
	lw	$t1 8($a0)
	lw	$t1 32($t1)
	jalr		$t1
	move	$s1 $a0
	move	$t2 $s0
	move	$t1 $s1
	la	$a0 bool_const1
	beq	$t1 $t2 label130
	la	$a1 bool_const0
	jal	equality_test
label130:
	lw	$t1 12($a0)
	la	$a0 bool_const1
	beqz	$t1 label129
	la	$a0 bool_const0
label129:
label127:
	lw	$t1 12($a0)
	beq	$t1 $zero label125
	la	$a0 str_const7
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label132
	la	$a0 str_const0
	li	$t1 510
	jal	_dispatch_abort
label132:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s2
	bne	$a0 $zero label133
	la	$a0 str_const0
	li	$t1 511
	jal	_dispatch_abort
label133:
	lw	$t1 8($a0)
	lw	$t1 36($t1)
	jalr		$t1
	move	$s2 $a0
	b	label124
label125:
	move	$a0 $zero
	move	$a0 $s2
	bne	$a0 $zero label136
	la	$a0 str_const0
	li	$t1 514
	jal	_dispatch_abort
label136:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	lw	$t1 12($a0)
	beqz	$t1 label134
	la	$a0 str_const8
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label137
	la	$a0 str_const0
	li	$t1 515
	jal	_dispatch_abort
label137:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label138
	la	$a0 str_const0
	li	$t1 516
	jal	_dispatch_abort
label138:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label139
	la	$a0 str_const0
	li	$t1 517
	jal	_dispatch_abort
label139:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	move	$a0 $s0
	bne	$a0 $zero label140
	la	$a0 str_const0
	li	$t1 518
	jal	_dispatch_abort
label140:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	move	$a0 $s0
	b	label135
label134:
	la	$a0 str_const9
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label141
	la	$a0 str_const0
	li	$t1 522
	jal	_dispatch_abort
label141:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
label135:
	lw	$s1 4($fp)
	lw	$s2 0($fp)
	lw	$fp 20($sp)
	lw	$s0 16($sp)
	lw	$ra 12($sp)
	addiu	$sp $sp 28
	jr	$ra	
VarList.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarList.head:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label142
	la	$a0 str_const0
	li	$t1 353
	jal	_dispatch_abort
label142:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 Variable_protObj
	jal	Object.copy
	jal	Variable_init
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarList.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	move	$a0 $s0
	bne	$a0 $zero label143
	la	$a0 str_const0
	li	$t1 354
	jal	_dispatch_abort
label143:
	lw	$t1 8($a0)
	lw	$t1 0($t1)
	jalr		$t1
	la	$a0 VarList_protObj
	jal	Object.copy
	jal	VarList_init
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarList.add:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($fp)
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	la	$a0 VarListNE_protObj
	jal	Object.copy
	jal	VarListNE_init
	bne	$a0 $zero label144
	la	$a0 str_const0
	li	$t1 355
	jal	_dispatch_abort
label144:
	lw	$t1 8($a0)
	lw	$t1 48($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 16
	jr	$ra	
VarList.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 str_const1
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label145
	la	$a0 str_const0
	li	$t1 356
	jal	_dispatch_abort
label145:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarListNE.isNil:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	la	$a0 bool_const0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarListNE.head:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarListNE.tail:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
VarListNE.init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 16($fp)
	sw	$a0 12($s0)
	lw	$a0 12($fp)
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
VarListNE.print:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 4
	move	$s0 $a0
	lw	$a0 12($s0)
	bne	$a0 $zero label146
	la	$a0 str_const0
	li	$t1 366
	jal	_dispatch_abort
label146:
	lw	$t1 8($a0)
	lw	$t1 28($t1)
	jalr		$t1
	la	$a0 str_const2
	sw	$a0 0($sp)
	addiu	$sp $sp -4
	move	$a0 $s0
	bne	$a0 $zero label147
	la	$a0 str_const0
	li	$t1 366
	jal	_dispatch_abort
label147:
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 16($s0)
	bne	$a0 $zero label148
	la	$a0 str_const0
	li	$t1 367
	jal	_dispatch_abort
label148:
	lw	$t1 8($a0)
	lw	$t1 44($t1)
	jalr		$t1
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
