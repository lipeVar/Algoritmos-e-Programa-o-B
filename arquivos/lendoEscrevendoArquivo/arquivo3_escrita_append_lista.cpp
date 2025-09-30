#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define TAM 1000
using namespace std; 

#include "modulo.h"

int main() {
    string listaNomes[TAM];
    string nomeBanco = "base.dat";
    //iniciar, conectar com a base e atualizar a lista de nomes
    int quantidadeNomes = conectarBase(listaNomes, nomeBanco, TAM);

    if(quantidadeNomes > 0) {
        exibirListaNomes(listaNomes, quantidadeNomes);
    }

    //abrir arquivo para leitura
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ofstream procuradorArquivo; //tipo de arquivo para escrita do ZERO
    //procuradorArquivo.open(nomeArquivo); <- arquivo para leitura 
    //arquivo sendo aberto para append 
    procuradorArquivo.open(nomeBanco, ios::out | ios::app);

    while (true) {
        string nome;
        cout << "Inserir nome em arquivo ou fim para encerrar: ";
        getline(cin, nome);

        nome = maiusculo(nome);
        if(nome == "FIM") {
            break;
        }

        bool conseguiuInserir = inserirLista(nome, listaNomes, &quantidadeNomes, TAM);

        if(conseguiuInserir) {
            procuradorArquivo << "\n" << nome << endl;
            procuradorArquivo.fflush();
        } else {
            cout << "Nome ja cadastrado!" << endl;
        }
    }
	procuradorArquivo.close();
    return 1;
}