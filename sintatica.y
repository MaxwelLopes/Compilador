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
string genTemp();
void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador);

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
				
				var.temp = genTemp();

                tabelaSimbolos[var.nome] = var;

                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + "\n";
                $$.traducao = "";
            }
            ;

E		   :
			| E '+' E
            {	
				operacao($$,$1,$2,$3, "+");
            }
            | E '-' E
            {
				operacao($$,$1,$2,$3, "-");
            }
            | E '*' E
            {	//diferentes
				operacao($$,$1,$2,$3, "*");
            }
			| E '/' E
            {
				operacao($$,$1,$2,$3, "/");
            }
            | TK_ID '=' E
            {   
                naoDeclarado($1.label);
				if(tabelaSimbolos[$1.label].tipo == "float" && $3.tipo == "int"){
					$3.tipo = "float";
					$$.label = genTemp();
					$$.declaracao += $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
					$$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + $3.tipo + ")" + $3.label + ";\n";
					$$.traducao += "\t" + tabelaSimbolos[$1.label].temp + " = " + $$.label + ";\n";
				}
				else if(tabelaSimbolos[$1.label].tipo == "int" && $3.tipo == "float"){
					$3.tipo = "int";
					$$.label = genTemp();
					$$.declaracao += $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
					$$.traducao += $1.traducao + $3.traducao + "\t" + $$.label + " = " + "(" + $3.tipo + ")" + $3.label + ";\n";
					$$.traducao += "\t" + tabelaSimbolos[$1.label].temp + " = " + $$.label + ";\n";
				}
				//IGUAIS
				else{
					$$.declaracao = $1.declaracao + $3.declaracao;
					$$.traducao = $1.traducao + $3.traducao + "\t" + tabelaSimbolos[$1.label].temp + " = " + $3.label + ";\n";
				}
                
            }
            | TK_NUM
            {
				$$.tipo = "int";
				$$.label = genTemp();
				$$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";
				$$.traducao += "\t" + $$.label + " = " + $1.label + ";\n";
            }
            | TK_REAL 
            {
                $$.tipo = "float";
                $$.label = genTemp();
                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + $1.label + ";\n";
            }
			| '(' TK_TIPO ')' E
            {   
					$$.tipo = $2.tipo;
					
					$$.label = genTemp();
					$$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

					//CAST VAR
					if(!(tabelaSimbolos.find($4.label) == tabelaSimbolos.end()))
					{
						$$.traducao += "\t" + $$.label + " = "  + "(" + $$.tipo + ")"  + tabelaSimbolos[$4.label].temp + ";\n";
					}
					//CAST NUM
					else if(tabelaSimbolos.find($4.label) == tabelaSimbolos.end())
					{
                		$$.declaracao += $1.declaracao + $4.declaracao;
						$$.traducao += $1.traducao + $4.traducao + "\t" + $$.label + " = "  + "(" + $$.tipo + ")"  + $4.label + ";\n";
					}
            }
            | TK_ID
            {
                naoDeclarado($1.label);
                TIPO_SIMBOLO var = tabelaSimbolos[$1.label];
                $$.tipo = var.tipo;
            }
			;
TK_TIPO     : TK_TIPO_FLOAT 
            {
            	$$.tipo = "float";
            }
            | TK_TIPO_INT
            {
              	$$.tipo = "int";  
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

void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador){
    if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
        if($1.tipo == "int" && $3.tipo == "float"){
            $1.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + $1.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        else if($1.tipo == "float" && $3.tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + $1.label + " " + operador + " " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = $1.tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
    //VAR NUMERO
    else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
        if(tabelaSimbolos[$1.label].tipo == "int" && $3.tipo == "float"){
            $$.label = genTemp();
            $$.tipo = "float";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";

            string aux = $$.label;
            
            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
            $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
    }
        else if(tabelaSimbolos[$1.label].tipo == "float" && $3.tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$1.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + $3.label + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
    //NUMERO VAR/*
    else if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && !(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
        if($1.tipo == "int" && tabelaSimbolos[$3.label].tipo == "float"){
            $$.label = genTemp();
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$3.label].tipo+ ")" + $1.label + ";\n";

            string aux = $$.label;
            
            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
        }
        else if($1.tipo == "float" && tabelaSimbolos[$3.label].tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $1.tipo + ")" + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + $1.label + " " + operador + " " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
    //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$3.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
    }
    //VAR VAR
    else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
        if(tabelaSimbolos[$1.label].tipo  == "int" && tabelaSimbolos[$3.label].tipo == "float"){
            $$.label = genTemp();
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$3.label].tipo+ ")" +tabelaSimbolos[$1.label].temp + ";\n";

            string aux = $$.label;
            
            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
        }
        else if(tabelaSimbolos[$1.label].tipo == "float" && tabelaSimbolos[$3.label].tipo == "int"){
            $3.tipo = "float";
            $$.label = genTemp();
            $$.tipo = "float";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$1.label].tipo + ")" + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";

            string aux = $$.label;

            $$.label = genTemp();
            $$.tipo = "float";

            $$.traducao += "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + aux + ";\n";
            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
        }
        //IGUAIS
        else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$1.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
        }
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