/*
 *  The scanner definition for COOL.
 */

/*
 *  Stuff enclosed in %{ %} in the first section is copied verbatim to the
 *  output, so headers and global definitions are placed here to be visible
 * to the code in the file.  Don't remove anything that was here initially
 */
%{
#include <cool-parse.h>
#include <stringtab.h>
#include <utilities.h>
#include <execinfo.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/* The compiler assumes these identifiers. */
#define yylval cool_yylval
#define yylex  cool_yylex

/* Max size of string constants */
#define MAX_STR_CONST 1025
#define YY_NO_UNPUT   /* keep g++ happy */

extern FILE *fin; /* we read from this file */

/* define YY_INPUT so we read from the FILE fin:
 * This change makes it possible to use this scanner in
 * the Cool compiler.
 */
#undef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( (result = fread( (char*)buf, sizeof(char), max_size, fin)) < 0) \
		YY_FATAL_ERROR( "read() in flex scanner failed");

char string_buf[MAX_STR_CONST]; /* to assemble string constants */
char *string_buf_ptr;

extern int curr_lineno;
extern int verbose_flag;

extern YYSTYPE cool_yylval;

void handler(int sig) {
	void* array[10];
	size_t size;
	size = backtrace(array, 10);
	fprintf(stderr, "Error: signal %d:\n", sig);
	backtrace_symbols_fd(array, size, STDERR_FILENO);
	exit(1);
}

int comment_start = 0;

/*
 *  Add Your own definitions here
 */
// Use <(":"|"@"|"new"|"inherits"|"class")[" ""\t""\n"]*>
%}

/*
 * Define names for regular expressions here.
 */

CLASS			[cC][lL][aA][sS][sS]
ELSE			[eE][lL][sS][eE]
FI				[fF][iI]
IF				[iI][fF]
IN				[iI][nN]
NOT				[nN][oO][tT]
INHERITS		[iI][nN][hH][eE][rR][iI][tT][sS]
LET				[lL][eE][tT]
LOOP			[lL][oO][oO][pP]
POOL			[pP][oO][oO][lL]
THEN			[tT][hH][eE][nN]
WHILE			[wW][hH][iI][lL][eE]
CASE			[cC][aA][sS][eE]
ESAC			[eE][sS][aA][cC]
OF				[oO][fF]
DARROW			"=>"
NEW				[nN][eE][wW]
ISVOID			[iI][sS][vV][oO][iI][dD]
TRUE			(t[rR][uU][eE])
FALSE			(f[aA][lL][sS][eE])
INT_CONST		[0-9][0-9]*
ASSIGN			"<-"
LE				"<="
TYPEID			[A-Z][A-Za-z0-9_]*
OBJECTID		[a-z][A-Za-z0-9_]*
SINGLE_CHAR		"."|"@"|"~"|"*"|"/"|"+"|"-"|"<"|"="|"("|")"|"{"|"}"|";"|":"|","
SINGLE_LINE_COMMENT		"--".*
%%

 /*
  *  Nested comments
  */


 /*
  *  The multiple-character operators.
  */
\n				{
					curr_lineno ++;
				}
[ \t\r\n\f\v]+		{};
{CLASS}			{ return CLASS; }
{ELSE}			{ return ELSE; }
{FI}			{ return FI; }
{IF}			{ return IF; }
{IN}			{ return IN; }
{INHERITS}		{ return INHERITS; }
{LET}			{ return LET; }
{LOOP}			{ return LOOP; }
{POOL}			{ return POOL; }
{THEN}			{ return THEN; }
{WHILE}			{ return WHILE; }
{CASE}			{ return CASE; }
{ESAC}			{ return ESAC; }
{OF}			{ return OF; }
{DARROW}		{ return DARROW; }
{NEW}			{ return NEW; }
{ISVOID}		{ return ISVOID; }
{NOT}			{ return NOT; }
{INT_CONST}		{
					cool_yylval.symbol = inttable.add_string(yytext);
					return INT_CONST; 
				}
{TRUE}			{
					cool_yylval.boolean = true;
					return BOOL_CONST;
				}
{FALSE}			{
					cool_yylval.boolean = false;
					return BOOL_CONST;
				}
{TYPEID}		{
					cool_yylval.symbol = idtable.add_string(yytext);
					return TYPEID;
				}
{OBJECTID}		{
					cool_yylval.symbol = idtable.add_string(yytext);
					return OBJECTID;
				}
{ASSIGN}		{ return ASSIGN; }
{LE}			{ return LE; }
{SINGLE_CHAR}	{ return yytext[0]; }
{SINGLE_LINE_COMMENT} {}
"(*"			{
					comment_start ++;
					int c;
					int next_char;
					int use_next_char = 0;
					for(;;) {
						if(use_next_char) {
							c = next_char;
							use_next_char = 0;
						} else {
							c = yyinput();
						}
						if(c == EOF) {
							cool_yylval.error_msg = "EOF in comment";
							return ERROR;
						}
						if(c == '\n') {
							curr_lineno ++;
							continue;
						}
						if(c == '(') {
							next_char = yyinput();
							if(next_char != '*') {
								use_next_char = 1;
								continue;
							} else {
								use_next_char = 0;
								comment_start ++;
							}
						}
						if(c == '*') {
							next_char = yyinput();
							if(next_char != ')') {
								use_next_char = 1;
								continue;
							} else {
								use_next_char = 0;
								comment_start --;
								if(comment_start == 0) {
									break;
								} else {
									continue;
								}
							}
						}
					}
				}
"*)"			{
					cool_yylval.error_msg = "Unmatched *)";
					return ERROR;
				}
\"				{
					signal(SIGSEGV, handler);
					int charCnt = 0;
					int currChar;
					int escCharEnc = 0;
					int found_error = 0;
					for(;;) {
						currChar = yyinput();
						// If escape character encountered and an escape char is not previously recorded.
						if(currChar == '\\' && !escCharEnc) {
							escCharEnc = 1;
							continue;
						}
						if(currChar == EOF) {
							if(!found_error) {
								cool_yylval.error_msg = "EOF in string constant";
							}
							return ERROR;
						}
						if(escCharEnc && !found_error) {
							escCharEnc = 0;
							if(currChar == '\n') {
								curr_lineno ++;
								currChar = '\n';
							}
							if(currChar == '\0') {
								cool_yylval.error_msg = "String contains escaped null character.";
								found_error = 1;
							}
							if(currChar == 'b') {
								currChar = '\b';
							} else if(currChar == 't') {
								currChar = '\t';
							} else if(currChar == 'n') {
								currChar = '\n';
							} else if(currChar == 'f') {
								currChar = '\f';
							} else {
								currChar = currChar;
							}
						} else {	
							if(currChar == '\n') {
								curr_lineno ++;
								if(!found_error) {
									cool_yylval.error_msg = "Unterminated string constant";	
								}
								return ERROR;
							} else if(currChar == '\0' && !found_error) {
								cool_yylval.error_msg = "String contains null character";								
								found_error = 1;
							} else if(currChar == '\"') {
								if(found_error) {
									return ERROR;
								} else {
									cool_yylval.symbol = stringtable.add_string(string_buf, charCnt);
									return STR_CONST;
								}
							} else {
								currChar = currChar;
							}
						}
						if(found_error) {
							continue;
						}
						string_buf[charCnt] = currChar;
						charCnt ++;
						if(charCnt == MAX_STR_CONST) {
							cool_yylval.error_msg = "String constant too long";
							found_error = 1;
							continue;
						}
					}

				}	
.				{
					cool_yylval.error_msg = yytext;
					return ERROR;
				}


 /*
  * Keywords are case-insensitive except for the values true and false,
  * which must begin with a lower-case letter.
  */


 /*
  *  String constants (C syntax)
  *  Escape sequence \c is accepted for all characters c. Except for 
  *  \n \t \b \f, the result is c.
  *
  */


%%
