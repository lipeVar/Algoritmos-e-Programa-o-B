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

    cout << "Menor elemento.... " << menor << endl;

}

void escreverSeValida(int dia, int mes, int ano) {
    //meses com 31: 1, 3, 5, 7, 8, 10, 12
    //meses com 30: 2, 4, 6, 9, 11

    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}

void escreverSeValida2(string data) {
    //meses com 31: 1, 3, 5, 7, 8, 10, 12
    //meses com 30: 2, 4, 6, 9, 11

    //data = 01/09/2025
    int dia = stoi(data.substr(0,2));
    int mes = stoi(data.substr(3,2));
    int ano = stoi(data.substr(6,4));
    
    if (dia == 31 && (mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
        cout << "Data invalida" << endl;
    } else if (dia == 29 && mes == 2 && (ano % 4 != 0)) {
        cout << "Data invalida" << endl;
    } else if (dia > 29 && mes == 2) {
        cout << "Data invalida" << endl;
    } else {
        cout << "Data valida" << endl;
    }
}

bool verificarDataValida(string data) {
    if (data.size() != 10 || data[2] != '/' || data[5] != '/') {
        return false;
    }
    int dia = stoi(data.substr(0,2));
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

string fraseMaiuscula(string frase) {
    for(int i=0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool estaOrdenado(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return false; // encontrou fora de ordem
        }
    }
    return true; // está todo ordenado
}

void primeiroNome(string nome){
    cout << "O primeiro nome é: " << nome << endl;
}