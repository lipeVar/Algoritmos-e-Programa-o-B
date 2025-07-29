#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main() {
    int vetor[TAM];

    srand(time(NULL));
    int numero;
    int posiUltimoNumInserido = 0;
    int jaInserido;

    for(int i = 0; i< TAM; i++) {
        numero = rand() % 10;
        jaInserido = 0;
        for(int j = 0; j <= posiUltimoNumInserido; j++) {
            if(numero == vetor[j]) {
                jaInserido = 1; //quando ja esta no vetor
                printf("\nnumero repetido gerado em [%d]\n", i);
                break;
            }
        }
        if(jaInserido == 0) {
            vetor[posiUltimoNumInserido] = numero;
            posiUltimoNumInserido++;
        }
    }

    for (int i = 0; i < posiUltimoNumInserido; i++) {
        printf("vetor[%d] = %d\t", i, vetor[i]);
    }
    printf("\n");

    return 1;
}