%{
#include <string>
int contn = 0;
%}

ESPACO [ \t] 
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{DIGITO})\'
STRING \"([^\"\n])*\"
ID {LETRA}({LETRA}|{NUM})*


%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"if"        {return TK_IF;}

"else"      {return TK_ELSE;}

"int"		{return TK_TIPO_INT;}

"float"		{return TK_TIPO_FLOAT;}

"char"      {return TK_TIPO_CHAR;}

"bool"      {return TK_TIPO_BOOL;}

"string"    {return TK_TIPO_STRING;}

"(float)"   {return TK_CAST_FLOAT;}

"(int)"     {return TK_CAST_INT;}

"(char)"    {return TK_CAST_CHAR;}


[(){}[\];,]	{ return *yytext; }

[+\-*/=]		{ return *yytext; }

[<>]		    { return *yytext; }
"=="    { return EQ; }
"!="    { return NE; }
">="    { return GE; }
"<="    { return LE; }
"&&"    { return AND; }
"||"    { return OR; }
"!"     { return NO; }

"true"      { yylval.label = yytext; return TK_TRUE; }
"false"     { yylval.label = yytext; return TK_FALSE; }
{NUM}		{ yylval.label = yytext; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.label = yytext; return TK_REAL; }
{CHAR}      { yylval.label = yytext; return TK_CHAR; }
{STRING}    { yylval.label = yytext; return TK_STRING; }

[\n] {contn++;}
.			{ *yytext; }

%%
