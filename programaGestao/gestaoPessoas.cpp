#include <iostream>
#include <string>
#define tam 1000

using namespace std;

typedef struct
{
    string nome;
    string email;
} Pessoa;

#include "modulo.h"


int main() {
    Pessoa vetor[tam];
    int quanti_pessoas;
    string baseDados = "base.csv";

    quanti_pessoas = conectarBase(baseDados, vetor, tam);
    menu(vetor, tam, quanti_pessoas, baseDados);

    for(int i = 0; i < quanti_pessoas; i++) {
        cout << vetor[i].nome << endl;
    }
    return 1;
}