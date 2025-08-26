#include <iostream>
#define TAM 1000

#include "metodos.h"

using namespace std;


int main() {
    int vetor[TAM];
    int quantidade = 10;

    //metodo que popule o vetor com n elementos (Aleatorios)  desde que menor que TAM
    popular (vetor, quantidade, TAM);

    //metodo que exiba o vetor
    exibir("a", vetor, quantidade, TAM);

    //metodo que receva um vetor, quantidade e seu tamanho; e exiba o menor elemento
    menorElemento(vetor, quantidade, TAM);
    
    //metodo que recebe um vetor, quantidade e seu tamanho e ordene o vetor - bolha 
    ordenar(vetor, quantidade, TAM);

    return 1;
}