#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <limits>

using namespace std;

typedef struct
{
    string raça;
    string cor;
    string nome_dono;
    int horario;
} Pet;


int contarVogais(string frase) {
    int totalVogal = 0;

    for (int i = 0; i < frase.size(); i++) {
        if(frase[i] == 'A' || frase[i] == 'E' || frase[i] == 'I' || frase[i] == 'O' || frase[i] == 'U' ||
            frase[i] == 'a' || frase[i] == 'e' || frase[i] == 'i' || frase[i] == 'o' || frase[i] == 'u')
            totalVogal++;
    }
    return totalVogal;
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

int conectarBase(string baseDados, Pet vetor[], int tamanho) {
    int quanti_Animais = 0;
    ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(baseDados); 

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Criando um novo 'base.csv'..." << endl;
        return 0; 
    } 

    string linha;
    string vetorLinha[2];
	while (getline(procuradorArquivo,linha)) {
        
        if (linha.empty()) {
            continue;
        }
        
        if(quanti_Animais == tamanho) {
            cout << "Arquivo lotado. Alguns dados não foram carregados." << endl;
            break; 
        }

		split(vetorLinha, linha, ",");
        vetor[quanti_Animais].placa = vetorLinha[0];
        vetor[quanti_Animais].carro = vetorLinha[1];
        quanti_Animais++;
	}

	procuradorArquivo.close();

    return quanti_Animais;
}

void listasCarros(Garagem vetor[], int quanti_Animais) {
    cout << "Lista de Carros\n";
    if (quanti_Animais == 0) {
        cout << "A garagem esta vazia." << endl;
    } else {
        for(int i = 0;i<quanti_Animais; i++) {
            cout << "Placa: " << vetor[i].placa << ". Carro: " << vetor[i].carro << endl;
        }
    }
    cout << "__________________\n";
    cout << "Total de registros: " << quanti_Animais << endl;
}

void gravarCarroBase(string placa, string carro, string baseDados) {
    ofstream procuradorArquivos;
    procuradorArquivos.open(baseDados, ios::out | ios::app);

    procuradorArquivos.seekp(0, ios::end);
    long pos = procuradorArquivos.tellp(); 
    
    if (pos > 0) {
        procuradorArquivos << "\n"; 
    }
    
    procuradorArquivos << placa << "," << carro;

    procuradorArquivos.close();
}

int cadastrarCarros(Garagem vetor[], int quanti_Animais, int tamanho, string baseDados) {
    if(tamanho == quanti_Animais) {
        cout << "Base de dados lotada...\n";
        return quanti_Animais;
    }
    cout << "Cadastrar Carros na garagem\n";
    string placa;
    string carro; 

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Placa: ";
    getline(cin, placa); 
    
    cout << "Carro: ";
    cin >> carro;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    //validar se nome e email entao no vetor

    vetor[quanti_Animais].placa = placa;
    vetor[quanti_Animais].carro = carro;
    quanti_Animais++;

    gravarCarroBase(placa, carro, baseDados);

    cout << "Pet cadastrado com sucesso!" << endl;
    return quanti_Animais;
}

void menu(Pet vetor[], int tamanho, int quanti_Animais, string baseDados) {
    int opcao;
    do
    {
        cout << "\n------------MENU------------\n";
        cout << "1- Listar animais no Pet-Shop\n";
        cout << "2- Chegada de novo pet\n";
        cout << "3- Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        cout << "\n\n";

        if (cin.fail()) {
            cout << "Entrada invalida. Por favor, digite um numero.\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            opcao = 0; 
        }

        switch (opcao)
        {
        case 1:
            listasCarros(vetor, quanti_Animais);
            break;
        case 2:
            quanti_Animais = cadastrarCarros(vetor, quanti_Animais, tamanho, baseDados);
            break;
        case 3:
            cout << "Encerrando programa..." << endl;
            break;    
        default:
            if (opcao != 0) { 
                cout << "Opcao invalida...\n";
            }
        }

    } while (opcao != 3);
    
}