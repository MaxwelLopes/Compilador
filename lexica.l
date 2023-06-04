%{
#include <string>

%}

ESPACO [ \t] 
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"bool"      {return TK_TIPO_BOOL;}

[(){}[\];,]	{ return *yytext; }

[+\-*/=]		{ return *yytext; }

[<>]		    { return *yytext; }
"=="    { return EQ; }
"!="    { return NE; }
">="    { return GE; }
"<="    { return LE; }
"&&"    { return AND; }
"||"    { return OR; }

"True"      { yylval.label = yytext; return TK_TRUE; }
"False"     { yylval.label = yytext; return TK_FALSE; }
{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.label = yytext; return TK_REAL; }

.			{ *yytext; }

%%
