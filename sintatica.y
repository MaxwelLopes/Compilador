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
    int atribuido;
} TIPO_SIMBOLO;

// Criando tabela de símbolos usando Hash (key: 'string', valor: 'struct')
unordered_map<string, TIPO_SIMBOLO> tabelaSimbolos;
int temp;

int yylex(void);
void yyerror(string);
%}

%token TK_NUM TK_REAL TK_TRUE TK_FALSE TK_CHAR
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_CAST_FLOAT TK_CAST_INT TK_CAST_BOOL TK_TIPO_CHAR
%token TK_FIM TK_ERROR 

%start S

%left AND OR NO
%left '>' '<' EQ NE GE LE
%left '+' '-'
%left '*' '/'

%nonassoc TK_CAST_FLOAT TK_CAST_INT TK_CAST_CHAR

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
                var.atribuido = 0;
				
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
                var.atribuido = 0;
				
				var.temp = genTemp();

                tabelaSimbolos[var.nome] = var;

                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + "\n";
                $$.traducao = "";
            }
            | TK_TIPO_CHAR TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "char";
                var.atribuido = 0;
				
				var.temp = genTemp();

                tabelaSimbolos[var.nome] = var;

                $$.tipo = var.tipo;
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + "\n";
                $$.traducao = "";
            }
			| TK_TIPO_BOOL TK_ID ';'
            {
                declarado($2.label);
                TIPO_SIMBOLO var;
                var.nome = $2.label;
                var.tipo = "bool";
                var.atribuido = 0;
				
				var.temp = genTemp();

                tabelaSimbolos[var.nome] = var;

                $$.tipo = "int";
                $$.declaracao = "\t" + $$.tipo + " " + var.temp + ";    " + var.temp + " = " + var.nome + "\n";
                $$.traducao = "";
            }
            ;

E		   : E '>' E
            {	
				operacao($$,$1,$2,$3, ">");
            }
			| E '<' E
            {	
				operacao($$,$1,$2,$3, "<");
            }
			| E EQ E
            {	
				operacao($$,$1,$2,$3, "==");
            }
			| E NE E
            {	
				operacao($$,$1,$2,$3, "!=");
            }
			| E GE E
            {	
				operacao($$,$1,$2,$3, ">=");
            }
			| E LE E
            {	
				operacao($$,$1,$2,$3, "<=");
            }
			| E AND E
            {	
				operacao($$,$1,$2,$3, "&&");
            }
			| E OR E
            {	
				operacao($$,$1,$2,$3, "||");
            }
            | NO E
            {	
                //VAR
                if($2.tipo == "int" || $2.tipo == "float"){
                    yyerror("ERRO: Operadores Lógicos só aceitam tipos Booleanos!");
                }
                if(!(tabelaSimbolos.find($2.label) == tabelaSimbolos.end())){
                    $$.label = genTemp();
                    $$.tipo = "bool";
                    $$.declaracao += $1.declaracao + $2.declaracao + "\t" + $2.tipo + " " + $$.label + ";\n";
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = " + "!" + tabelaSimbolos[$2.label].temp + ";\n";
                }else{
                    //NAO VAR
                    $$.label = genTemp();
                    $$.tipo = "bool";
                    $$.declaracao += $1.declaracao + $2.declaracao + "\t" + $2.tipo + " " + $$.label + ";\n";
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = " + "!" + $2.label + ";\n";
                }
            }
			| E '+' E
            {	
				operacao($$,$1,$2,$3, "+");
            }
            | E '-' E
            {
				operacao($$,$1,$2,$3, "-");
            }
            | E '*' E
            {
				operacao($$,$1,$2,$3, "*");
            }
			| E '/' E
            {
				operacao($$,$1,$2,$3, "/");
            }
            | TK_ID '=' E
            {   
                naoDeclarado($1.label);
                //E -> VAR
                tabelaSimbolos[$1.label].atribuido = 1;
                if(!(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
                    if(tabelaSimbolos[$1.label].tipo == "bool" && tabelaSimbolos[$3.label].tipo != "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(tabelaSimbolos[$1.label].tipo != "bool" && tabelaSimbolos[$3.label].tipo == "bool"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(tabelaSimbolos[$1.label].tipo == "char" && tabelaSimbolos[$3.label].tipo != "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                    if(tabelaSimbolos[$1.label].tipo != "char" && tabelaSimbolos[$3.label].tipo == "char"){
                        yyerror("ERRO: Tipos difentes!");
                    }
                }
                else{
                //E -> NUM
                if(tabelaSimbolos[$1.label].tipo == "bool" && $3.tipo != "bool"){
					yyerror("ERRO: Tipos difentes!");
				} 
				if(tabelaSimbolos[$1.label].tipo != "bool" && $3.tipo == "bool"){
					yyerror("ERRO: Tipos difentes!");
				}
                if(tabelaSimbolos[$1.label].tipo == "char" && $3.tipo != "char"){
					yyerror("ERRO: Tipos difentes!");
				}
				if(tabelaSimbolos[$1.label].tipo != "char" && $3.tipo == "char"){
					yyerror("ERRO: Tipos difentes!");
				}
                }

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
            | TK_CHAR 
            {
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + $1.label + ";\n";
            }
			| TK_FALSE
            {
                string valor = " 0";
                string tipo = "int ";
                $$.tipo = "bool";
                $$.label = genTemp();
                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + valor + ";\n";
            }
			| TK_TRUE
            {
                string valor = " 1";
                string tipo = "int ";
                $$.tipo = "bool";
                $$.label = genTemp();
                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + valor + ";\n";
            }
			| TK_CAST_FLOAT E
            {   
                $$.tipo = "float";
                $$.label = genTemp();

                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

                //CAST VAR
                if(!(tabelaSimbolos.find($2.label) == tabelaSimbolos.end()))
                {
                    $$.traducao += "\t" + $$.label + " = "  + "(float)"  + tabelaSimbolos[$2.label].temp + ";\n";
                }
                //CAST NUM
                else if(tabelaSimbolos.find($2.label) == tabelaSimbolos.end())
                {
                    $$.declaracao += $1.declaracao + $2.declaracao;
                $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = "  + "(float)"  + $2.label + ";\n";
                }
            }
            | TK_CAST_INT E
            {   
                $$.tipo = "int";
                $$.label = genTemp();

                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

                //CAST VAR
                if(!(tabelaSimbolos.find($2.label) == tabelaSimbolos.end()))
                {
                    $$.traducao += "\t" + $$.label + " = "  + "(int)"  + tabelaSimbolos[$2.label].temp + ";\n";
                }
                //CAST NUM
                else if(tabelaSimbolos.find($2.label) == tabelaSimbolos.end())
                {
                    $$.declaracao += $1.declaracao + $2.declaracao;
                $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = "  + "(int)"  + $2.label + ";\n";
                }
            }
            | TK_CAST_CHAR E
            {   
                $$.tipo = "char";
                $$.label = genTemp();

                $$.declaracao += "\t" + $$.tipo + " " + $$.label + ";\n";

                //CAST VAR
                if(!(tabelaSimbolos.find($2.label) == tabelaSimbolos.end()))
                {
                    $$.traducao += "\t" + $$.label + " = "  + "(char)"  + tabelaSimbolos[$2.label].temp + ";\n";
                }
                //CAST NUM
                else if(tabelaSimbolos.find($2.label) == tabelaSimbolos.end())
                {
                    $$.declaracao += $1.declaracao + $2.declaracao;
                    $$.traducao += $1.traducao + $2.traducao + "\t" + $$.label + " = "  + "(char)"  + $2.label + ";\n";
                }
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
    	yyerror("ERRO: Variável " + chave + " já foi declarada!");
}

void naoDeclarado(string chave){
	if (tabelaSimbolos.find(chave) == tabelaSimbolos.end())
		yyerror("ERRO: Variável " + chave + " não foi declarada!");
}

void operacao(atributos& $$, atributos& $1, atributos& $2, atributos& $3, string operador){
    string tipo = "int ";
    if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end())){
        if (tabelaSimbolos[$1.label].atribuido == 0){
            yyerror("ERRO: Variável sem valor atribuido!");
        }
    }
    if(!(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
        if (tabelaSimbolos[$1.label].atribuido == 0){
            yyerror("ERRO: Variável sem valor atribuido!");
        }
    }
    if(operador == "||" || operador == "&&"){
        if($1.tipo == "int" || $1.tipo == "float" || $3.tipo == "int" || $3.tipo == "float"){
            yyerror("ERRO: Operadores Lógicos só aceitam tipos Booleanos!");
        }
    }
    if(operador == ">" || operador == "<" || operador == ">=" || operador == "<="){
        if($1.tipo == "bool" ||  $3.tipo == "bool"){
            yyerror("ERRO: Operadores Relacionais não aceitam tipos Booleanos!");
        }
    }
    if (operador == "+" || operador == "-" || operador == "*" || operador == "/"){
        if($1.tipo == "bool" || $3.tipo == "bool"){
            yyerror("Erro: operações aritiméticas não aceitam booleanos!");
        }
    }
    if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!="){
        //NUMERO NUMERO
        if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
            if($1.tipo == "int" && $3.tipo == "float"){
                $1.tipo = "float";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $1.label + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
            }
            else if($1.tipo == "float" && $3.tipo == "int"){
                $3.tipo = "float";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $1.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + $1.label + " " + operador + " " + aux + ";\n";
            }
            else if($1.tipo != $3.tipo){
                $$.label = genTemp();
                $$.tipo = "bool";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + $3.label + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
            }
        }
        //VAR NUMERO
        else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
            if(tabelaSimbolos[$1.label].tipo == "int" && $3.tipo == "float"){
                tabelaSimbolos[$1.label].tipo = "float";
                $$.label = genTemp();
                $$.tipo = "float";
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $3.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
            }
            else if(tabelaSimbolos[$1.label].tipo == "float" && $3.tipo == "int"){
                $3.tipo = "float";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tabelaSimbolos[$1.label].tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $3.tipo + ")" + $3.label + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + aux + ";\n";
            }
            else{
                $$.label = genTemp();
                $$.tipo = "bool";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + $3.label + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tabelaSimbolos[$1.label].tipo + " " + $$.label + ";\n";
            }
        }
        //NUMERO VAR
        else if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && !(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
            if($1.tipo == "int" && tabelaSimbolos[$3.label].tipo == "float"){
                $1.tipo = "float";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + tabelaSimbolos[$3.label].tipo + ")" + $1.label + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            }
            else if($1.tipo == "float" && tabelaSimbolos[$3.label].tipo == "int"){
                $$.tipo = "float";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$3.label].temp + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + tipo + " " + $$.label + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + $1.label + " " + operador + " " + aux + ";\n";
            }
            else{
                $$.label = genTemp();
                $$.tipo = "bool";
                $$.traducao = $1.traducao + $3.traducao + "\t" + tipo + " = " + $1.label + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
            }
        }
        //VAR VAR
        else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
            if(tabelaSimbolos[$1.label].tipo == "int" && tabelaSimbolos[$3.label].tipo == "float"){
                $$.tipo = "float";
                $$.label = genTemp(); 
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool"; 

                $$.declaracao += "\t" + $$.tipo + " " + tipo + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            }
            else if(tabelaSimbolos[$1.label].tipo == "float" && tabelaSimbolos[$3.label].tipo == "int"){
                $$.tipo = "float"; 
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$3.label].temp + ";\n";

                string aux = $$.label;
                $$.label = genTemp();
                $$.tipo = "bool";

                $$.declaracao += "\t" + $$.tipo + " " + tipo + ";\n"; 
                $$.traducao += "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + aux + ";\n";
            }
            else{
                $$.label = genTemp();
                $$.tipo = "bool";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $$.tipo + " " + $$.label + ";\n";
            }
        }
    }
    else if(operador == "&&" || operador == "||"){
        //NUM NUM
        if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
            $$.label = genTemp();
            $$.tipo = "bool";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + $3.label + ";\n";
        }
        //VAR VAR
        if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
            $$.label = genTemp();
            $$.tipo = "bool";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
        }
        //VAR NUM
        if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
            $$.label = genTemp();
            $$.tipo = "bool";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + $3.label + ";\n";
        }
        //NUM VAR
        if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && !(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
            $$.label = genTemp();
            $$.tipo = "bool";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
        }
    }
    //CHAR
    else if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
        //NUMERO NUMERO
        if($1.tipo == "char" && ($3.tipo == "int" || $3.tipo == "float")){
            $$.tipo = "char";
            $$.label = genTemp();
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $3.label + ";\n";
    
            string aux = $$.label;

            $$.label = genTemp();

            $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }
        else if($3.tipo == "char" && ($1.tipo == "int" || $1.tipo == "float")){
            $$.tipo = "char";
            $$.label = genTemp();
            $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";
    
            string aux = $$.label;

            $$.label = genTemp();

            $$.declaracao += "\t" + $2.tipo + " " + $$.label + ";\n";
            $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
        }

        // VAR VAR
        else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
            if(tabelaSimbolos[$1.label].tipo == "char" && (tabelaSimbolos[$3.label].tipo == "int" || tabelaSimbolos[$3.label].tipo == "float")){
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";
        
                string aux = $$.label;

                $$.label = genTemp();

                $$.declaracao += "\t" + tabelaSimbolos[$1.label].tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$1.label].temp + ";\n";
            }
            else if(tabelaSimbolos[$3.label].tipo == "char" && (tabelaSimbolos[$1.label].tipo == "int" || tabelaSimbolos[$1.label].tipo == "float")){
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";
        
                string aux = $$.label;

                $$.label = genTemp();

                $$.declaracao += "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            }
            else{
                $$.label = genTemp();
                $$.tipo = "char";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $$.tipo + " " + $$.label + ";\n";
            }
        }
        //VAR NUM
        else if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
            if(tabelaSimbolos[$1.label].tipo == "char" && ($3.label == "int" || $3.tipo == "float")){
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";
                string aux = $$.label;

                $$.label = genTemp();
                $$.label = "char";

                $$.declaracao += "\t" + tabelaSimbolos[$1.label].tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$1.label].temp + ";\n";
            }
            else if($3.tipo == "char" && (tabelaSimbolos[$1.label].tipo == "int" || tabelaSimbolos[$1.label].tipo == "float")){
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + tabelaSimbolos[$1.label].temp + ";\n";
        
                string aux = $$.label;

                $$.label = genTemp();

                $$.declaracao += "\t" + $3.tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $3.label + ";\n";
            }
            //IGUAIS
            else {
                $$.label = genTemp();
                $$.tipo = tabelaSimbolos[$1.label].tipo;
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + tabelaSimbolos[$1.label].temp + " " + operador + " " + $3.label + ";\n";
                $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
            }
        }
        // NUM VAR

        else if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && !(tabelaSimbolos.find($3.label) == tabelaSimbolos.end())){
            if($1.tipo == "char" && (tabelaSimbolos[$3.label].tipo == "int" || tabelaSimbolos[$3.label].tipo == "float")){
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";
        
                string aux = $$.label;

                $$.label = genTemp();

                $$.declaracao += "\t" + $1.tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + $1.label + ";\n";
            }
            else if(tabelaSimbolos[$3.label].tipo == "char" && ($1.tipo == "int" || $1.tipo == "float")){
                
                $$.tipo = "char";
                $$.label = genTemp();
                $$.declaracao = $1.declaracao + $3.declaracao + "\t" + $$.tipo + " " + $$.label + ";\n";
                $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " +"(" + $$.tipo + ")" + $1.label + ";\n";
        
                string aux = $$.label;

                $$.label = genTemp();

                $$.declaracao += "\t" + tabelaSimbolos[$3.label].tipo + " " + $$.label + ";\n";
                $$.traducao += "\t" + $$.label + " = " + aux + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            }
            else {
            $$.label = genTemp();
            $$.tipo = tabelaSimbolos[$3.label].tipo;
            $$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = " + $1.label + " " + operador + " " + tabelaSimbolos[$3.label].temp + ";\n";
            $$.declaracao = $1.declaracao + $3.declaracao +"\t" + $1.tipo + " " + $$.label + ";\n";
            }
        }
    }
    //  NUM NUM
    if(tabelaSimbolos.find($1.label) == tabelaSimbolos.end() && tabelaSimbolos.find($3.label) == tabelaSimbolos.end() && (operador != ">" && operador != "<" && operador != ">=" && operador != "<=" && operador != "==" && operador != "!=" && operador != "&&" && operador != "||")){
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

        //VAR NUMERO
        if(!(tabelaSimbolos.find($1.label) == tabelaSimbolos.end()) && tabelaSimbolos.find($3.label) == tabelaSimbolos.end()){
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