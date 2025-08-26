#include <iostream>
#include <cstdlib>
#include <time.h>
//github.com/alexandrezamberlan/algoritmos

using namespace std;

void popular (int vetor[], int quantidade, int tamanho) {
    if(quantidade > tamanho) {
        cout << "Não é possivel...";
        return; //forcando a saida do metodo
    }
    srand(time (NULL));
    for(int i = 0; i<quantidade; i++) {
        vetor[i] = rand() % 100;
    }
}

void exibir(string frase, int vetor[], int quantidade, int tamanho) {
    if(quantidade > tamanho) {
        cout << "Essa quantidade não é possivel...";
        return;
    }
    cout << frase << endl;
    for(int i=0; i<quantidade; i++) {
        cout << vetor[i] << endl;
    }
}


void menorElemento(int vetor[], int quantidade, int tamanho) {
    int menor = vetor[0];

    if(quantidade > tamanho) {
        cout << "impossivel continuar...";
        return;
    }
    for(int i=1; i<quantidade; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
}
void ordenar(int vetor[], int quantidade, int tamanho) {
    
}