//fazer um programa que receba um vetor com N inteiros.
//Criar sorteador de numeros.
//criar um localizar IMPAR PAR
#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAM 10
using namespace std;

void popula(int *v, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20;
    }
}

void mostra(int *vetor, int tam) {
    for(int i=0; i<tam; i++) {
        cout << vetor[i] << endl;
    }
}

void paresImpares(int *vetor, int tam, int *par, int *impar) {
    *par = 0;
    *impar = 0;
    for (int i=0; i<tam; i++) {
        if( vetor[i] % 2 == 0) {
            *par = *par+1;
        } else {
            *impar = *impar+1;
        }
    }
}

int main() {
    int vetor[TAM];
    popula(vetor, TAM);
    mostra(vetor, TAM);

    int par, impar;
    paresImpares(vetor, TAM, &par, &impar);
    cout << "Total de pares: " << par << endl;
    cout << "Total de impares: " << impar << endl;
}