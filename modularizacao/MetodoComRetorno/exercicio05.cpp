#include <iostream>
#include <string>
 
using namespace std;

#include "metodos.h"


int main(){
    int numeros[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    if (estaOrdenado(numeros, tamanho)) {
        cout << "O vetor esta ordenado." << endl;
    } else {
        cout << "O vetor NAO esta ordenado." << endl;
    }

   return 1;
}