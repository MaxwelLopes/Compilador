#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef struct{
    string nome;
    string tipo;
} TIPO_SIMBOLO;

unordered_map<string, TIPO_SIMBOLO> tabelaSimbolos;

void identifica_chave(string chave){
    if (tabelaSimbolos.count(chave) > 0) {
        string tipo = tabelaSimbolos[chave].tipo;
        cout << tipo << " " << chave << endl;
    } else {
        cout << "Chave não encontrada" << endl;
    }
}

int main(){
    TIPO_SIMBOLO variavel1, variavel2;
    variavel1.nome = "a";
    variavel1.tipo = "int";

    variavel2.nome = "b";
    variavel2.tipo = "float";
    
    tabelaSimbolos[variavel1.nome] = variavel1;
    tabelaSimbolos[variavel2.nome] = variavel2;

    string chave1 = "hugo";
    string chave2 = "b";
    string chave3 = "a";

    identifica_chave(chave1);
    identifica_chave(chave2);
    identifica_chave(chave3);


    TIPO_SIMBOLO variavel3;
    variavel3.nome = "hugo";
    variavel3.tipo = "estranho";
    tabelaSimbolos[variavel3.nome] = variavel3;
    
    tabelaSimbolos.erase(chave2);

    identifica_chave(chave1);
    identifica_chave(chave2);
    identifica_chave(chave3);

    return 0;
}