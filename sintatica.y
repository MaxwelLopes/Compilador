%{
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};

void naoDeclarado(string chave);
void declarado(string chave);
string genTemp();

//Struct de cada tipo
typedef struct{
    string nome;
    string tipo;
} TIPO_SIMBOLO;

//criando tabela de simbolos usando Hash(key: 'string', valor: 'struct')
unordered_map<string, TIPO_SIMBOLO> tabelaSimbolos;
int temp;

int yylex(void);
void yyerror(string);
%}

%token TK_NUM TK_REAL 
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT 
%token TK_FIM TK_ERROR

%start S 

%left '+' '-'
%left '*' '/'

%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador CAPY*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: '{' COMANDOS '}'
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			{
				
			}
			| TK_TIPO_INT TK_ID ';'
			{
				declarado($2.label);
				TIPO_SIMBOLO var;
				var.nome = $2.label;
				var.tipo = "int";
				
				tabelaSimbolos[var.nome] = var;
				
				
				$$.tipo = var.tipo;

				$$.traducao = "\t" + $$.tipo + " " + var.nome + ";\n";
				$$.label = "";
			}
			| TK_TIPO_FLOAT TK_ID ';'
			{
				declarado($2.label);
				TIPO_SIMBOLO var;
				var.nome = $2.label;
				var.tipo = "float";

				tabelaSimbolos[var.nome] = var;
				
				$$.tipo = var.tipo;

				$$.traducao = "\t" + $$.tipo + " " + var.nome + ";\n";
			}
			;
			 
E 			: E '+' E
			{
				$$.label = genTemp();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + "\n" + " = " + $1.label + " + " + $3.label + ";\n"; 
			}
			| E '-' E
			{
				$$.label = genTemp();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
			}
			| E '/' E
			{
				$$.label = genTemp();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
			}
			| E '*' E
			{
				$$.label = genTemp();
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
			}
			| TK_ID '=' E 
			{	
				
				naoDeclarado($1.label);
				
				$$.traducao = $1.traducao + $3.traducao + "\t" + $1.label + " = " + $3.label + ";\n";
			}
			| TK_NUM
			{
				$$.tipo = "int";
				$$.label = genTemp();

				$$.traducao = "\t" + $$.tipo + " " + $$.label + ";\n" + "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_REAL 
			{
				$$.tipo = "float";
				$$.label = genTemp();
				$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
			}
			| TK_ID
			{

				naoDeclarado($1.label);
				TIPO_SIMBOLO var;
				

				$$.label = genTemp();
				$$.traducao = "\t"  + $$.label + " = " + $1.label + ";\n";
			}
			;

%%

#include "lex.yy.c"

int yyparse();

string genTemp()
{
	temp++;
	return  "t" + std::to_string(temp);
}

void declarado(string chave){
	if (!(tabelaSimbolos.find(chave) == tabelaSimbolos.end()))
    	yyerror("Variável " + chave + " já foi declarada!");
}

void naoDeclarado(string chave){
	if (tabelaSimbolos.find(chave) == tabelaSimbolos.end())
		yyerror("Variável " + chave + " não foi declarada!");
}

int main( int argc, char* argv[] )
{
	temp = 0;
	yyparse();
	

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}	