#include <iostream>
#include <string>
 
using namespace std;

#include "metodos.h"
 
int main() {
    int dia, mes, ano;
    
    do {
        cout << "Informe Dia: ";
        cin >> dia;
        if (dia < 1 || dia > 31) {
            cout << "Dia fora da faixa permitida... " << endl;
        }
    } while (dia < 1 || dia > 31);

    do {
        cout << "Informe Mes: ";
        cin >> mes;
        if (mes < 1 || mes > 12) {
            cout << "Mes fora da faixa permitida... " << endl;
        }
    } while (mes < 1 || mes > 10);

    do {
        cout << "Informe Ano(1980-2025): ";
        cin >> ano;
        if (ano < 1980 || ano > 2025) {
            cout << "Ano fora da faixa permitida... " << endl;
        }
    } while (ano < 1980 || ano > 2025);

    escreverSeValida(dia, mes, ano);
  
    // while (true) {
    //     cout << "Informe um número entre 1 e 10: ";
    //     cin >> numero;
    //     if (numero < 1 || numero > 10) {
    //         cout << "Numero fora da faixa permitida... " << endl;
    //     } else {
    //         break;
    //     }
    // }
 
    return 1;
}