#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include <fstream>

using namespace std;

#include "modulo.h"

int main() {
    string nomeArquivo;
   cout << "Digite o caminho e nome do arquivo: ";
   cin >> nomeArquivo;

   if(existeArquivo(nomeArquivo)) {
    cout << "Arquivo localizado com sucesso\n";
   } else {
    cout << "Arquivo não localizado\n";
    exit(0);
   }

   string resposta = copiaArquivoString(nomeArquivo);

   cout << resposta << endl;

   string respostaMaiuscula = maiusculo(resposta);
   cout << "Arquivo todo em Maiusculo: \n" << respostaMaiuscula << endl;

   int quantidade_de_palavras = contaPalavra(resposta);
   cout << "Quantidade de palavras do arquivo: " << quantidade_de_palavras << endl;

    return 1;
}