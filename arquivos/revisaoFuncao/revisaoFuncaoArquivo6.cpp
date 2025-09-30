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

   char letraOrigem;
   cout << "Digite a letra origem: ";
   cin >> letraOrigem;

   char letraDestino;
   cout << "Digite a letra destino: ";
   cin >> letraDestino;

   string respostaAlterada = trocarLetraOrigemDestino(resposta, letraOrigem, letraDestino);

   cout << "resposta alterada: " << respostaAlterada << endl;

    return 1;
}