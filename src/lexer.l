%option noyywrap 
%{
#include "header.h" 
int linenumber=0;
int symnum=0;
int strnum=0;
symtab * lookup();
symtab * ptr;
void     insertID();
void 	 printSymTab();
%}


letter   [A-Za-z]
digit    [0-9]
ID	 {letter}({letter}|{digit}|"_")*
WS	 [ \t]+

/*Constant*/ 
Int_constant {digit}+
Float_constant  ({digit}*\.{digit}+|{digit}+\.?)([Ee][+-]?{digit}+)?
String_constant \"[^\n"]*\"
comment  \/\*([^*]*[*]+[^*/])*([^*]*[*]+)\/



/* Operators*/ 
OP_plus		"+"
OP_minus	"-"
OP_mul		"*"
OP_div		"/"

OP_eq		"=="
OP_neq		"!="
OP_grt		">"
OP_lss		"<"
OP_geq		">="
OP_leq		"<="

OP_or   	"||"
OP_and		"&&"
OP_not		"!"

OP_assign   "="

/*Separators*/ 
newline  "\n"
DL_lparen "("
DL_rparen ")"
DL_lsquar "["
DL_rsquar "]"
DL_lbrace "{"
DL_rbrace "}"
DL_comma  ","
DL_semicol ";"
DL_dot  "."

error    .

%%
"return" /* reserved word */
"typedef"
"if"
"else"	
"int"
"float"
"for"
"void"
"while"

{WS}            {}
{Int_constant}  {/* return INT; */ }
{Float_constant} {/* return FLOAT; */}
{String_constant} {/* return STRING; */}
{comment}		{printf("%s\n",yytext);}
{ID}            { 
				ptr = lookup(yytext);
				if (ptr == NULL){
					if(strlen(yytext)>strnum) strnum=strlen(yytext);
			    	insertID(yytext);	
			    	symnum++;
				}
				else {
			    	ptr->counter++;
				}
				}
{OP_plus}     	/* return OP_PLUS; */ 
{OP_minus}     	/* return OP_MINUS; */ 
{OP_mul}     	/* return OP_MUL; */ 
{OP_div}     	/* return OP_DIV; */ 

{OP_eq}     	/* return OP_EQ; */ 
{OP_neq}     	/* return OP_NEQ; */ 
{OP_grt}     	/* return OP_GRT; */ 
{OP_lss}     	/* return OP_LSS; */ 
{OP_geq}     	/* return OP_GEQ; */ 
{OP_leq}     	/* return OP_LEQ; */ 

{OP_or}         /* return OP_OR; */
{OP_and}        /* return OP_AND; */
{OP_not}        /* return OP_NOT; */

{OP_assign}     /* return OP_ASSIGN; */ 

{DL_lparen}     /* return MK_LPAREN; */
{DL_rparen}     /* return MK_RPAREN; */
{DL_lsquar}     /* return MK_LSQUAR; */
{DL_rsquar}     /* return MK_RSQUAR; */
{DL_lbrace}     /* return MK_LBRACE; */
{DL_rbrace}     /* return MK_RBRACE; */
{DL_comma}      {}
{DL_semicol}    {}
{newline}       linenumber += 1;
{error}         printf("ERR \n");/* return ERROR; */

%%

int main(int argc, char **argv)
{
   	argc--; ++argv;
   	if (argc > 0)
      	yyin = fopen(argv[0], "r");
 	else
      	yyin = stdin;
  	 yylex();
   	printSymTab();

   return 0;
}