#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //semeadora

    int numeroSorteado = rand() % 100; //sorteando um numero entre 0 a 100
    printf("%d\n", numeroSorteado);

    return 1;
}