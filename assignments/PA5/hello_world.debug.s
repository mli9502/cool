# start of generated code
Building CgenClassTable
coding global data
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
	.word	5
_bool_tag:
	.word	6
_string_tag:
	.word	7
choosing gc
	.globl	_MemMgr_INITIALIZER
_MemMgr_INITIALIZER:
	.word	_NoGC_Init
	.globl	_MemMgr_COLLECTOR
_MemMgr_COLLECTOR:
	.word	_NoGC_Collect
	.globl	_MemMgr_TEST
_MemMgr_TEST:
	.word	0
coding constants
	.word	-1
str_const24:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const0
	.byte	0	
	.align	2
	.word	-1
str_const23:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const2
	.ascii	"B"
	.byte	0	
	.align	2
	.word	-1
str_const22:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const2
	.ascii	"A"
	.byte	0	
	.align	2
	.word	-1
str_const21:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Main"
	.byte	0	
	.align	2
	.word	-1
str_const20:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"String"
	.byte	0	
	.align	2
	.word	-1
str_const19:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const3
	.ascii	"Bool"
	.byte	0	
	.align	2
	.word	-1
str_const18:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const5
	.ascii	"Int"
	.byte	0	
	.align	2
	.word	-1
str_const17:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const6
	.ascii	"IO"
	.byte	0	
	.align	2
	.word	-1
str_const16:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"Object"
	.byte	0	
	.align	2
	.word	-1
str_const15:
	.word	7
	.word	7
	.word	String_dispTab
	.word	int_const1
	.ascii	"_prim_slot"
	.byte	0	
	.align	2
	.word	-1
str_const14:
	.word	7
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"SELF_TYPE"
	.byte	0	
	.align	2
	.word	-1
str_const13:
	.word	7
	.word	7
	.word	String_dispTab
	.word	int_const7
	.ascii	"_no_class"
	.byte	0	
	.align	2
	.word	-1
str_const12:
	.word	7
	.word	8
	.word	String_dispTab
	.word	int_const8
	.ascii	"<basic class>"
	.byte	0	
	.align	2
	.word	-1
str_const11:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const9
	.ascii	"\nB::j: "
	.byte	0	
	.align	2
	.word	-1
str_const10:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"B::i: "
	.byte	0	
	.align	2
	.word	-1
str_const9:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const2
	.ascii	"\n"
	.byte	0	
	.align	2
	.word	-1
str_const8:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const9
	.ascii	"\nA::j: "
	.byte	0	
	.align	2
	.word	-1
str_const7:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"A::i: "
	.byte	0	
	.align	2
	.word	-1
str_const6:
	.word	7
	.word	10
	.word	String_dispTab
	.word	int_const10
	.ascii	"class type is Object\n"
	.byte	0	
	.align	2
	.word	-1
str_const5:
	.word	7
	.word	10
	.word	String_dispTab
	.word	int_const11
	.ascii	"class type is now B\n"
	.byte	0	
	.align	2
	.word	-1
str_const4:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"a_A_O\n"
	.byte	0	
	.align	2
	.word	-1
str_const3:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"a_A_B\n"
	.byte	0	
	.align	2
	.word	-1
str_const2:
	.word	7
	.word	6
	.word	String_dispTab
	.word	int_const4
	.ascii	"a_A_A\n"
	.byte	0	
	.align	2
	.word	-1
str_const1:
	.word	7
	.word	10
	.word	String_dispTab
	.word	int_const11
	.ascii	"class type is now A\n"
	.byte	0	
	.align	2
	.word	-1
str_const0:
	.word	7
	.word	8
	.word	String_dispTab
	.word	int_const12
	.ascii	"hello_world.cl"
	.byte	0	
	.align	2
	.word	-1
int_const12:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	14
	.word	-1
int_const11:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	20
	.word	-1
int_const10:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	21
	.word	-1
int_const9:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	7
	.word	-1
int_const8:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	13
	.word	-1
int_const7:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	9
	.word	-1
int_const6:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	2
	.word	-1
int_const5:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	3
	.word	-1
int_const4:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	6
	.word	-1
int_const3:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	4
	.word	-1
int_const2:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	1
	.word	-1
int_const1:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	10
	.word	-1
int_const0:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
bool_const0:
	.word	6
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
bool_const1:
	.word	6
	.word	4
	.word	Bool_dispTab
	.word	1
coding class_nameTab
class_nameTab:
	.word	str_const16
	.word	str_const17
	.word	str_const21
	.word	str_const22
	.word	str_const23
	.word	str_const18
	.word	str_const19
	.word	str_const20
-----------------
Class: B
abort: 0
copy: 0
getA: 0
in_int: 0
in_string: 0
ma: 0
out_int: 0
out_string: 0
type_name: 0
-----------------
-----------------
Class: A
abort: 0
copy: 0
getA: 0
in_int: 0
in_string: 0
ma: 0
out_int: 0
out_string: 0
type_name: 0
-----------------
-----------------
Class: Main
abort: 0
copy: 0
in_int: 0
in_string: 0
main: 0
out_int: 0
out_string: 0
type_name: 0
-----------------
-----------------
Class: String
abort: 0
concat: 0
copy: 0
length: 0
substr: 0
type_name: 0
-----------------
-----------------
Class: Bool
abort: 0
copy: 0
type_name: 0
-----------------
-----------------
Class: Int
abort: 0
copy: 0
type_name: 0
-----------------
-----------------
Class: IO
abort: 0
copy: 0
in_int: 0
in_string: 0
out_int: 0
out_string: 0
type_name: 0
-----------------
-----------------
Class: Object
abort: 0
copy: 0
type_name: 0
-----------------
coding class_dispTab
B_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	A.getA
	.word	B.ma
A_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	A.getA
	.word	A.ma
Main_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
	.word	IO.out_string
	.word	IO.out_int
	.word	IO.in_string
	.word	IO.in_int
	.word	Main.main
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
Object_dispTab:
	.word	Object.abort
	.word	Object.type_name
	.word	Object.copy
coding class_protObj
	.word	-1
B_protObj:
	.word	4
	.word	4
	.word	B_dispTab
	.word	int_const0
	.word	-1
A_protObj:
	.word	3
	.word	4
	.word	A_dispTab
	.word	int_const0
	.word	-1
Main_protObj:
	.word	2
	.word	5
	.word	Main_dispTab
	.word	0
	.word	int_const0
	.word	-1
String_protObj:
	.word	7
	.word	5
	.word	String_dispTab
	.word	int_const0
	.word	0
	.word	-1
Bool_protObj:
	.word	6
	.word	4
	.word	Bool_dispTab
	.word	0
	.word	-1
Int_protObj:
	.word	5
	.word	4
	.word	Int_dispTab
	.word	0
	.word	-1
IO_protObj:
	.word	1
	.word	3
	.word	IO_dispTab
	.word	-1
Object_protObj:
	.word	0
	.word	3
	.word	Object_dispTab
coding global text
	.globl	heap_start
heap_start:
	.word	0
	.text
	.globl	Main_init
	.globl	Int_init
	.globl	String_init
	.globl	Bool_init
	.globl	Main.main
coding methods and inits for classes
B_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
	jal	A_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
B.ma:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const10
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_int
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 4
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	lw	$a0 8($fp)
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const11
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_int
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 4
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	lw	$a0 4($fp)
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const9
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
A_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
	jal	IO_init
	la	$a0 int_const1
	sw	$a0 12($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
A.getA:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
A.ma:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const7
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_int
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 4
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	lw	$a0 8($fp)
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const8
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_int
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 4
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	lw	$a0 4($fp)
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 16($t1)
	jalr		$t1
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const9
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 20
	jr	$ra	
Main_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
	jal	IO_init
	la	$a0 B_protObj
	jal	Object.copy
	jal	B_init
	sw	$a0 12($s0)
	la	$a0 int_const0
	sw	$a0 16($s0)
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Main.main:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
	lw	$a0 12($s0)
	lw	$t2 0($a0)
branch_1:
	blt	$t2 4 branch_2
	bgt	$t2 5 branch_2
	move	$s2 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const5
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	b	case_finish_0
branch_2:
	blt	$t2 3 branch_3
	bgt	$t2 5 branch_3
	move	$s2 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const1
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	lw	$a0 12($s0)
	lw	$t2 0($a0)
branch_5:
	blt	$t2 4 branch_6
	bgt	$t2 5 branch_6
	move	$s2 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const3
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	b	case_finish_4
branch_6:
	blt	$t2 3 branch_7
	bgt	$t2 5 branch_7
	move	$s2 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const2
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	b	case_finish_4
branch_7:
	blt	$t2 0 branch_8
	bgt	$t2 8 branch_8
	move	$s2 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const4
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	b	case_finish_4
branch_8:
	jal	_case_abort
case_finish_4:
	b	case_finish_0
branch_3:
	blt	$t2 0 branch_9
	bgt	$t2 8 branch_9
	move	$s2 $a0
[dispatch_class::code]
[dispatch_class::code]: method_name: out_string
[dispatch_class::code]: let_var_cnt: 0
[dispatch_class::code]: actual_size: 1
[dispatch_class::code]: method_offset: 3
[dispatch_class::code]: --- Before caller activation record setup ---
[code_caller_activation_record_setup]: arg_cnt: 1
	addiu	$sp $sp 0
	addiu	$sp $sp -4
	la	$a0 str_const6
	sw	$a0 4($sp)
[dispatch_class::code]: ---------------------------------------------
[dispatch_class::code]: --------- Gen code for expr -----------------
	move	$a0 $s0
[dispatch_class::code]: ---------------------------------------------
	lw	$t1 8($a0)
	lw	$t1 12($t1)
	jalr		$t1
	b	case_finish_0
branch_9:
	jal	_case_abort
case_finish_0:
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
	addiu	$fp $sp 12
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
	addiu	$fp $sp 12
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
	addiu	$fp $sp 12
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
	addiu	$fp $sp 12
	move	$s0 $a0
	jal	Object_init
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	
Object_init:
	addiu	$sp $sp -12
	sw	$fp 12($sp)
	sw	$s0 8($sp)
	sw	$ra 4($sp)
	addiu	$fp $sp 12
	move	$s0 $a0
	move	$a0 $s0
	lw	$fp 12($sp)
	lw	$s0 8($sp)
	lw	$ra 4($sp)
	addiu	$sp $sp 12
	jr	$ra	

# end of generated code
