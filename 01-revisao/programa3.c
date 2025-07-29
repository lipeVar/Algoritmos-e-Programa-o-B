#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int idade;
    int tempoSono;

    printf("DIgite sua idade: ");
    scanf("%d", &idade);

    tempoSono = (int)(idade/3); //convertendo para inteiro

    printf("VOce ja domiu %d anos\n", tempoSono);
    return 1;
}
// cd 01-revisao/ para entrar no arquivo
//ls para ver oq tem no arquivo depois (gcc programa3.c -o programa) para compilar