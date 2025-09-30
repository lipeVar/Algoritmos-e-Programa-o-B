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

   cout << resposta;

   return 1;
}