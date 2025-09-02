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

void escreverSeValida(int dia, int mes, int ano) {
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;

    }else if (dia >= 29 && mes == 2) {
       cout << "Data invalida" << endl; 
    }   
    else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}


void escreverSeValida2(string data) {
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));
}

bool verificarDataValida(string data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }    
    int dia = stoi(data.substr(0,2)); //(posição e comprimento respectivamente)
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));

    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        return false;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        return false;
    } else if (dia > 29 && mes == 2) {
        return false;
    } else {
        return true;
    }
}