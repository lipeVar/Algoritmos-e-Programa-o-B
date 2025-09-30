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

int conectarBase(string listaNomes[], string nomeBanco, int tamanho) {
    ifstream procuradorArquivo; //tipo de arquivo para leitura
   procuradorArquivo.open(nomeBanco); 
   
   string linha;
   int quantidadeNomes = 0;
   while (!procuradorArquivo.eof() && quantidadeNomes < tamanho) {
    getline(procuradorArquivo,linha);
    listaNomes[quantidadeNomes] = linha;
    quantidadeNomes++;
   }

   procuradorArquivo.close();

   return quantidadeNomes;
}

void exibirListaNomes(string listaNmes[], int quantidadeNomes) {
    for (int i = 0; i<quantidadeNomes; i++) {
        cout << listaNmes[i] << endl;
    }
}

bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho) { // * é para relacionar 
    if(*quantidadeNomes == tamanho) {
        return false; //lista lotada
    }
    int i;
    bool encontrou = false;
    for(i = 0; i<*quantidadeNomes; i++) {
        if(nome == listaNomes[i]) {
            encontrou = true;
            break;
        }
    }

    if(encontrou) { //se encontrou o nome retorna falso pq nao inseriu
        return false;
    }

    *quantidadeNomes = *quantidadeNomes + 1;
    listaNomes[*quantidadeNomes] = nome;
    
    //ordenar a lista
    
    return true;
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