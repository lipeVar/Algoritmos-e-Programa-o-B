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

int conectarBase(string baseDados, Garagem vetor[], int tamanho) {
    int quant_Carros = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados); 

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    } 
    if(quant_Carros == tamanho) {
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
        vetor[quant_Carros].placa = vetorLinha[0];
        vetor[quant_Carros].carro = vetorLinha[1];
        quant_Carros++;
	}

	procuradorArquivo.close();

    return quant_Carros;
}

void listasPessoas(Garagem vetor[], int quant_Carros) {
    cout << "Lista de Carros\n";
    for(int i = 0;i<quant_Carros; i++) {
        cout << "Placa: " << vetor[i].placa << ". Carro: " << vetor[i].carro << endl;
    }
    cout << "__________________\n";
    cout << "Total de registros: " << quant_Carros << endl;
}

void gravarCarroBase(string placa, string carro, string baseDados) {
    ofstream procuradorArquivos;
    procuradorArquivos.open(baseDados, ios::out | ios::app);

    procuradorArquivos << "\n" << placa << "," << carro;

    procuradorArquivos.close();
}

int cadastrarPessoas(Garagem vetor[], int quant_Carros, int tamanho, string baseDados) {
    if(tamanho == quant_Carros) {
        cout << "Base de dados lotada...\n";
        return quant_Carros;
    }
    cout << "Cadastrar Carros na garagem\n";
    string placa;
    string carro

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa o buffer
    cout << "Placa: ";
    getline(cin, placa);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa o buffer
    cout << "Carro: ";
    cin >> carro;

    //validar se nome e email entao no vetor

    vetor[quant_Carros].placa = placa;
    vetor[quant_Carros].carro = carro;
    quant_Carros++;

    gravarPessoaBase(placa, carro, baseDados);

    return quant_Carros;
}

void menu(Garagem vetor[], int tamanho, int quant_Carros, string baseDados) {
    int opcao;
    do
    {
        cout << "------------MENU------------\n";
        cout << "1- Listar carros na Garagem\n";
        cout << "2- Entrada de novo carro\n";
        cout << "3- Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
        case 1:
            listasCarros(vetor, quant_Carros);
            break;
        case 2:
            quant_Carros = cadastrarCarros(vetor, quant_Carros, tamanho, baseDados);
            break;
        case 3:
            break;    
        default:
            cout << "Opcao invalida...\n";
        }

    } while (opcao != 3);
    
}