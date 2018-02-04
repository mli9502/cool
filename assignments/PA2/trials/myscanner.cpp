#include <iostream>
#include <vector>
#include <string>
#include "myscanner.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;

vector<string> names{"", "db_type", "db_name", "db_table_prefix", "db_port"};

int main() {
	int ntoken, vtoken;
	ntoken = yylex();
	while(ntoken) {
		int catToken = ntoken;
		string catStr(yytext);
		if(yylex() != COLON) {
			cout << "Expect a colon!" << endl;
			exit(1);
		}
		ntoken = yylex();
		switch(catToken) {
		case TYPE: 
		case NAME:
		case TABLE_PREFIX: {
			if(ntoken != IDENTIFIER) {
				cout << "Expect id, but find " << yytext << " at " << yylineno << endl;
			} else {
				cout << catToken << " : " << yytext << endl;
			}
					
		}
		break;
		case PORT: {
			if(ntoken != INTEGER) {
				cout << "Expect int, but find " << yytext << " at " << yylineno << endl;						
			} else {
				cout << catToken << " : " << yytext << endl;
	        }
		}
		break;
		default: {
			cout << "Found illegial character: " << catStr << " at line " << yylineno  << endl;
			exit(1);
		}
		break;
		}
		ntoken = yylex();
	}
	return 0;
}
