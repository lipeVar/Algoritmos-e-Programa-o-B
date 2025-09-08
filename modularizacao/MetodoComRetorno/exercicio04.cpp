#include <iostream>
#include <string>
#include <cctype>


#include "metodos.h"

using namespace std;

int main() {
    string frase;

    cout << "Digite uma frase: " << endl;
    getline(cin, frase);

    string  resultado = fraseMaiuscula(frase);
    cout << "Em Maiusculas: " << resultado << endl;

    return 1;
}
   