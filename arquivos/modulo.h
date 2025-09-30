#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std;

int contarVogais(string frase) {
    int totalVogal = 0;

    for (int i = 0; i < frase.size(); i++) {
        if(frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' ||
            frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
            totalVogal++;
    }
    return totalVogal;
}

string trocarLetra(string frase, char letra) {
    for(int i=0; i < frase.size(); i++) {
        if(toupper(frase[i]) == toupper(letra)) {
            frase[i] = '@';
        }
    }
    return frase;
}
string trocarLetraOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for(int i=0; i < frase.size(); i++) {
        if(toupper(frase[i]) == toupper(letraOrigem)) {
            frase[i] = letraDestino;
        }
    }
    return frase;
}

string maiusculo(string frase) {
    for(int i=0; i < frase.size(); i++) {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

int contaPalavra(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;

    while (stream >> palavra)
    {
        contagem++;
    }
    return contagem;
}

bool existeArquivo(string nomeArquivo) {

   ifstream procuradorArquivo; //tipo de arquivo para leitura
   procuradorArquivo.open(nomeArquivo); 
   
   if (procuradorArquivo) { //caso arquivo exista
    procuradorArquivo.close();
    return true;
   } 
   return false; //caso nao exista
}

string copiaArquivoString(string nomeArquivo) {
    
   ifstream procuradorArquivo; //tipo de arquivo para leitura
   procuradorArquivo.open(nomeArquivo); 
   
   string resposta = "";
   string linha;
   while (!procuradorArquivo.eof()) {
    getline(procuradorArquivo,linha);
    resposta = resposta + linha + "\n";
   }

   procuradorArquivo.close();

   return resposta;
}