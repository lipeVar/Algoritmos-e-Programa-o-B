#include <iostream>
#include <string>


#include "metodos.h"

using namespace std;

int contaVogal(string frase) {
    int totalVogal = 0;

    for (int i = 0; i < frase.size(); i++) {
        if(frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u' ||
            frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'i' || frase[i] == 'O' || frase[i] == 'U') 
            {
                totalVogal++;
            }
    }

    return totalVogal;
}

int main() {
    string frase;

    cout << "Digite uma frase qualquer: " << endl;
    getline(cin, frase);

    contaVogal(frase);

    cout << "O total de vogais da frase '" << frase << "' é: " << contaVogal(frase);
}
    