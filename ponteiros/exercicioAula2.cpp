#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAM 10
using namespace std;

void popula(int *v, int n) {
    // seed uma vez (pode ficar aqui se chamar popula apenas 1 vez)
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 20; // 0..19
    }
}

void mostra(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << endl;
    }
}

void paresImpares(int *vetor, int tam, int *par, int *impar) {
    *par = 0;
    *impar = 0;
    for (int i = 0; i < tam; i++) {
        if (vetor[i] % 2 == 0)
            (*par)++;
        else
            (*impar)++;
    }
    
}

void substituiZero(int *vetor, int tam, int *zeros) {
    *zeros = 0;
    for (int i = 0; i < tam; i++) {
        if (vetor[i] % 2 == 0) {
            vetor[i] = 0;
            (*zeros)++;        // incrementa o valor apontado por zeros
        }
    }
   
}

int main() {
    int vetor[TAM];
    int par, impar, zeros;

    popula(vetor, TAM);
    cout << "Vetor original:\n";
    mostra(vetor, TAM);

    paresImpares(vetor, TAM, &par, &impar);
    cout << "Total de pares: " << par << endl;
    cout << "Total de impares: " << impar << endl;
    substituiZero(vetor, TAM, &zeros);

    cout << "\nVetor apos substituir pares por zero:\n";
    mostra(vetor, TAM);
    cout << "Total de zeros: " << zeros << endl;

    return 0;
}
