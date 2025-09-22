#include <iostream>
#include <string>
#include <cctype>

using namespace std;

#include "meusMetodos.h"

int main() {
    string frase;

    cout << "Digite uma frase: ";
    getline(cin, frase);

    int quantidadeVogal = contarVogais(frase);

    if(quantidadeVogal == 1) {
        cout << "A frase tem: " << quantidadeVogal << " vogal";
    } else {
        cout << "A frase tem: " << quantidadeVogal << " vogais";
    }
}