#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "meusMetodos.h"

int main() {
    string frase;
    char letra;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    cout << "Digite a letra de pesquisa: ";
    //CHAR porque é apenas um caracter
    cin >> letra;

    string fraseResultado = trocarLetra(frase, letra);

    cout << "Frase alterada: " << fraseResultado << endl;
}