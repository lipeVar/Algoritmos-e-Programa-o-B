#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

#include "modulo.h"

int main() {
    //abrir um arquivo texto e exibir seu conteudo na tela

    //solicita pro usuario nome do arquivo origem
	//char nomeArquivo[200];
    string nomeArquivo;
	cout << "Informe nome do arquivo que recebera os nomes: ";
	cin >> nomeArquivo;
    fflush(stdin);

    //abrir arquivo para leitura
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ofstream procuradorArquivo; //tipo de arquivo para escrita do ZERO
    //procuradorArquivo.open(nomeArquivo); <- arquivo para leitura 
    //arquivo sendo aberto para append 
    procuradorArquivo.open(nomeArquivo, ios::out | ios::app);

    while (true) {
        string nome;
        cout << "Inserir nome em arquivo ou fim para encerrar: ";
        getline(cin, nome);

        nome = maiusculo(nome);
        if(nome == "FIM") {
            break;
        }

        procuradorArquivo << nome << endl;
    }
	procuradorArquivo.close();
    return 1;
}