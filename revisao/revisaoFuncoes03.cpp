#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "meusMetodos.h"

int main() {
    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    string fraseMaiusculo = maiusculo(frase);
    cout << "A frase em maiusculo: " << fraseMaiusculo << endl;

    int quantidadePalavra = contaPalavra(frase);
    cout << "Total de palavras da frase: " << quantidadePalavra << endl;
}