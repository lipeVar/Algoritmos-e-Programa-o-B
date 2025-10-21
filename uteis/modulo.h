#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <limits>

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

/* int conectarBase(string listaNomes[], string nomeBanco, int tamanho) {
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
} */

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

void split(string vetor[], string str, string deli = " ")
{        
    int start = 0;
    int end = str.find(deli);
    int i = 0;
    while (end != -1) {
        vetor[i] = str.substr(start, end - start);
        i++;
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start, end - start);
}

int conectarBase(string baseDados, Pessoa vetor[], int tamanho) {
    int quant_pessoas = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados); 

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    } 
    if(quant_pessoas == tamanho) {
        cout << "Arquivo lotado. Programa encerrado." << endl;
        exit(0);
    }

    string linha;
    string vetorLinha[2];
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		// procuradorArquivo >> frase; //lendo palavra por palavra da linha 
		split(vetorLinha, linha, ",");
        // vetorLinha[0] = "alexandre Zamberlan"
        // vetorLinha[1] = "alexz@ufn.edu.br"
        vetor[quant_pessoas].nome = vetorLinha[0];
        vetor[quant_pessoas].email = vetorLinha[1];
        quant_pessoas++;
	}

	procuradorArquivo.close();

    return quant_pessoas;
}

void listasPessoas(Pessoa vetor[], int quant_pessoas) {
    cout << "Listar Pessoas\n";
    for(int i = 0;i<quant_pessoas; i++) {
        cout << "Nome: " << vetor[i].nome << ". Email: " << vetor[i].email << endl;
    }
    cout << "__________________\n";
    cout << "Total de registros: " << quant_pessoas << endl;
}

void gravarPessoaBase(string nome, string email, string baseDados) {
    ofstream procuradorArquivos;
    procuradorArquivos.open(baseDados, ios::out | ios::app);

    procuradorArquivos << "\n" << nome << "," << email;

    procuradorArquivos.close();
}

int cadastrarPessoas(Pessoa vetor[], int quant_pessoas, int tamanho, string baseDados) {
    if(tamanho == quant_pessoas) {
        cout << "Base de dados lotada...\n";
        return quant_pessoas;
    }
    cout << "Cadastrar Pessoas\n";
    string nome;
    string email;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa o buffer
    cout << "Nome: ";
    getline(cin, nome);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa o buffer
    cout << "Email: ";
    cin >> email;

    //validar se nome e email entao no vetor

    vetor[quant_pessoas].nome = nome;
    vetor[quant_pessoas].email = email;
    quant_pessoas++;

    gravarPessoaBase(nome, email, baseDados);

    return quant_pessoas;
}

void menu(Pessoa vetor[], int tamanho, int quant_pessoas, string baseDados) {
    int opcao;
    do
    {
        cout << "------------MENU------------\n";
        cout << "1- Listar pessoas\n";
        cout << "2- Cadastrar pessoa\n";
        cout << "3- Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            listasPessoas(vetor, quant_pessoas);
            break;
        
        case 2:
            quant_pessoas = cadastrarPessoas(vetor, quant_pessoas, tamanho, baseDados);
            break;
        case 3:
            break;    
        default:
            cout << "Opcao invalida...\n";
        }

    } while (opcao != 3);
    
}