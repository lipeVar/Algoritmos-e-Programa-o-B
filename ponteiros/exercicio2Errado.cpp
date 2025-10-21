// faça um método que receba o vetor, substitua todos os numeros pares por zero e retorne a quantidade de números que foram substituidos.
// Contudo, não é permitido usar return
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
void substituiZero(int *vetor, int tam, int *zeros) {
    *zeros = 0;
    for (int i=0; i<tam; i++) {
        if( vetor[i] % 2 == 0) {
            vetor[i] = 0;
            (*zeros)++;
        }
    }
    
}

int main() {
    int vetor[TAM];
    popula(vetor, TAM);
    mostra(vetor, TAM);

    int par, impar, zeros;

    paresImpares(vetor, TAM, &par, &impar);
    cout << "Total de pares: " << par << endl;
    cout << "Total de impares: " << impar << endl;
    substituiZero(vetor, TAM, &zeros);
    mostra(vetor, TAM);

    cout << "Total de zeros: " << zeros << endl;
}