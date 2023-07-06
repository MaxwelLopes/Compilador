#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct
{
    string nome;
    string tipo;
	string temp;
    int atribuido;
} TIPO_SIMBOLO;

vector<unordered_map<string, TIPO_SIMBOLO>> pilha; 

void imprimirPilha() {
    int nivel = pilha.size() - 1;
    for (int i = nivel; i >= 0; i--) {
        cout << "############################\n";
        cout << "Nível " << i << ":" << endl;
        const auto& tabela = pilha[i];
        for (const auto& par : tabela) {
            const string& chave = par.first;
            const TIPO_SIMBOLO& simbolo = par.second;

            cout << "Chave: " << chave << endl;
            cout << "Nome: " << simbolo.nome << endl;
            cout << "Tipo: " << simbolo.tipo << endl;
            cout << endl;
        }
        cout << endl;
    }
}

void cria_tabela(string tipo){
    
    pilha.push_back(unordered_map<string, TIPO_SIMBOLO>());

    int indice = pilha.size() - 1;
    
    TIPO_SIMBOLO var;
    var.nome = "a";
    var.tipo = tipo;
    pilha[indice]["a"] = var;
    
    var.nome = "b";
    var.tipo = tipo;
    pilha[indice]["b"] = var;

    var.nome = "c";
    var.tipo = tipo;
    pilha[indice]["d"].tipo = "oi";
}

int main() { 
    cria_tabela("int");
    cria_tabela("float");
    cria_tabela("bool");
    //pilha.pop_back();
    cout << pilha.size() << "\n";
    return 0;
}

/*

int a;
int b;
int d;
if(djhdfe){
    float a;
    float b;
    float c;
    if(fknhdjfh){
        bool a;
        bool b;
        bool c;
        print(d)
    }
}

*/