#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string nomeCompleto;
    string sobreNome;
} Pessoa;

void lerNomes(string vetorNome[], int n) {
    for(int i = 1; i < n; i++) {
        cout << "Digte um nome completo: ";
        getline(cin, vetorNome[i]);
    }
    for(int i = 1; i < n; i++) {
        cout << "Nome digitado: " << vetorNome[i];
    }
    

}

void lerSobrenome(string nomes, int n) {

}