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
    string declaracao;
    string tipo;
};

void naoDeclarado(string chave);
void declarado(string chave);
void verificaTipo(string tipo1, string tipo2);
void verificarTipoIntFloat(atributos& $1, atributos& $3, atributos& $$);
string genTemp();

// Struct de cada tipo
typedef struct
{
    string nome;
    string tipo;
	string temp;
} TIPO_SIMBOLO;

// Criando tabela de símbolos usando Hash (key: 'string', valor: 'struct')
unordered_map<string, TIPO_SIMBOLO> tabelaSimbolos;
int temp;
string idTemp;

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

S           : TK_TIPO_INT TK_MAIN '(' ')' BLOCO
            {
                cout << "/*Compilador CAPY*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.declaracao << $5.traducao << "\treturn 0;\n}" << endl;
            }
            ;

BLOCO       : '{' COMANDOS '}'
            {
                $$.traducao = $2.traducao;
				$$.declaracao = $2.declaracao;
            }
            ;

COMANDOS    : COMANDO COMANDOS
            {
                $$.traducao = $1.traducao + $2.traducao;
				$$.declaracao = $1.declaracao + $2.declaracao;
            }
            |
            {
                $$.traducao = "";
            }
            ;

COMANDO     : E ';'
            {
                $$.traducao = $1.traducao;
            }
            | TK_TIPO_INT TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "int";
				var.temp = genTemp();

                tabelaSimbolos[var.nome] = var;

                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + "\n";
                $$.traducao = "";
            }
            | TK_TIPO_FLOAT TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "float";

                tabelaSimbolos[var.nome] = var;

                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.nome + ";\n";
                $$.traducao = "";
            }
            ;

E           : E '+' E
            {	//diferentes
				if($1.tipo == "int" && $3.tipo == "float"){
					$1.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + $1.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//diferentes
				else if($1.tipo == "float" && $3.tipo == "int"){
					$3.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//NUMERO NUMERO
				if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
					$$.label = genTemp();
                 	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +$1.label + " + " + $3.label + ";\n";
                 	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//VAR NUMERO
				else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
					$$.label = genTemp();
                 	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " + " + $3.label + ";\n";
                 	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//NUMERO VAR
				else if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && !(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
					$$.label = genTemp();
                 	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +$1.label + " + " + tabelaSimbolos[$3.label].temp + ";\n";
                 	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//VAR VAR
				else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
					$$.label = genTemp();
                 	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " + " + tabelaSimbolos[$3.label].temp + ";\n";
                 	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}
				// //normal
				//  else{
				//  	$$.label = genTemp();
                //  	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label  + $1.label + " + " + $3.label + ";\n";
                //  	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				//  }
            }
            | E '-' E
            {	//diferentes
				if($1.tipo == "int" && $3.tipo == "float"){
					$1.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + $1.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//diferentes
				if($1.tipo == "float" && $3.tipo == "int"){
					$3.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//normal
				else{
					$$.label = genTemp();
                	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
                	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}

            }
            | E '/' E
            {	//diferentes
				if($1.tipo == "int" && $3.tipo == "float"){
					$1.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + $1.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//diferentes
				if($1.tipo == "float" && $3.tipo == "int"){
					$3.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//normal
				else{
					$$.label = genTemp();
                	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
                	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}

            }
            | E '*' E
            {	//diferentes
				if($1.tipo == "int" && $3.tipo == "float"){
					$1.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + $1.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//diferentes
				if($1.tipo == "float" && $3.tipo == "int"){
					$3.tipo = "float";
					$$.label = genTemp();
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
					$$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

					$$.label = genTemp();

                	$$.traducao += "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
                	$$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
				}
				//normal
				else{
					$$.label = genTemp();
                	$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
                	$$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
				}

            }
            | TK_ID '=' E 
            {   
                naoDeclarado($1.label);
				//verificaTipo(tabelaSimbolos[$1.label].tipo, $3.tipo);
                $$.traducao = $1.traducao + $3.traducao + "\t" + tabelaSimbolos[$1.label].temp + " = " + $3.label + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao;
            }
            | TK_NUM
            {
                $$.tipo = "int";
                $$.label = genTemp();
                $$.declaracao = "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_REAL 
            {
                $$.tipo = "float";
                $$.label = genTemp();
                $$.declaracao = "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
            }
			| '(' TK_TIPO_FLOAT ')' TK_NUM
            {   
					$$.tipo = "float";
					$$.label = genTemp();
					$$.declaracao = "\t" + $$.tipo + " " + $$.label + ";\n";
					$$.traducao += "\t" + $$.label + " = "  + "(" + $$.tipo + ")"  + $$.label + ";\n";
            }
            | TK_ID
            {
                naoDeclarado($1.label);
                TIPO_SIMBOLO var = tabelaSimbolos[$1.label];
                $$.tipo = var.tipo;
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

void verificaTipo(string tipo1, string tipo2){
	if(tipo1 != tipo2){
		yyerror("Tipos diferentes!");
	}	
}

void verificarTipoIntFloat(atributos& $1, atributos& $3, atributos& $$) {
    if ($1.tipo == "int" && $3.tipo == "float") {
        $1.tipo = "float";
        $$ = atributos();
        $$.label = genTemp();
        $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + $1.tipo + ")" + $1.label + ";\n";
        $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";
    }
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