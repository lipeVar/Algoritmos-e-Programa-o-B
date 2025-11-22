#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <limits>

using namespace std;

#define tam 1000

typedef struct
{
    string raca;
    string cor;
    string nome_dono;
    string horario;

} Pet;


int contarVogais(string frase) {
    int totalVogal = 0;

    for (int i = 0; i < frase.size(); i++) {
        char c = frase[i];
        if (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||
            c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
            totalVogal++;
    }
    return totalVogal;
}

void exibirListaNomes(string listaNmes[], int quantidadeNomes) {
    for (int i = 0; i < quantidadeNomes; i++) {
        cout << listaNmes[i] << endl;
    }
}

bool inserirLista(string nome, string listaNomes[], int *quantidadeNomes, int tamanho) {
    if (*quantidadeNomes == tamanho)
        return false;

    for (int i = 0; i < *quantidadeNomes; i++) {
        if (listaNomes[i] == nome)
            return false;
    }

    listaNomes[*quantidadeNomes] = nome;
    (*quantidadeNomes)++;

    return true;
}

string trocarLetra(string frase, char letra) {
    for (char &c : frase) {
        if (toupper(c) == toupper(letra))
            c = '@';
    }
    return frase;
}

string trocarLetraOrigemDestino(string frase, char letraOrigem, char letraDestino) {
    for (char &c : frase) {
        if (toupper(c) == toupper(letraOrigem))
            c = letraDestino;
    }
    return frase;
}

string maiusculo(string frase) {
    for (char &c : frase)
        c = toupper(c);
    return frase;
}

int contaPalavra(string& frase) {
    istringstream stream(frase);
    string palavra;
    int contagem = 0;

    while (stream >> palavra)
        contagem++;

    return contagem;
}

bool existeArquivo(string nomeArquivo) {
    ifstream arquivo(nomeArquivo);
    return arquivo.is_open();
}

string copiaArquivoString(string nomeArquivo) {
    ifstream arq(nomeArquivo);
    string conteudo = "", linha;

    while (getline(arq, linha))
        conteudo += linha + "\n";

    return conteudo;
}

void split(string vetor[], string str, string deli = " ") {
    int start = 0;
    int end = str.find(deli);
    int i = 0;

    while (end != -1) {
        vetor[i++] = str.substr(start, end - start);
        start = end + deli.size();
        end = str.find(deli, start);
    }
    vetor[i] = str.substr(start);
}

int conectarBase(string baseDados, Pet vetor[], int tamanho) {
    ifstream arq(baseDados);
    int quanti = 0;

    if (!arq.is_open()) {
        cout << "Base não encontrada. Criando nova...\n";
        return 0;
    }

    string linha;
    while (getline(arq, linha) && quanti < tamanho) {

        if (linha.empty()) continue;

        stringstream ss(linha);
        string r, c, d, h;

        getline(ss, r, ',');
        getline(ss, c, ',');
        getline(ss, d, ',');
        getline(ss, h, ',');

        vetor[quanti].raca = r;
        vetor[quanti].cor = c;
        vetor[quanti].nome_dono = d;
        vetor[quanti].horario = stoi(h);

        quanti++;
    }

    return quanti;
}

void salvarBase(string baseDados, Pet vetor[], int quantidade) {

    ofstream arq(baseDados);

    for (int i = 0; i < quantidade; i++) {

        arq << vetor[i].raca << ","
            << vetor[i].cor << ","
            << vetor[i].nome_dono << ","
            << vetor[i].horario;

        if (i < quantidade - 1)
            arq << "\n";
    }

    arq.close();
}

void listarPets(Pet vetor[], int quantidade) {

    cout << "\n=== LISTA DE PETS ===\n";

    if (quantidade == 0) {
        cout << "Nenhum pet cadastrado.\n";
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        cout << i << " - Raça: " << vetor[i].raca
             << " | Cor: " << vetor[i].cor
             << " | Dono: " << vetor[i].nome_dono
             << " | Horário: " << vetor[i].horario << endl;
    }
}

int cadastrarPet(Pet vetor[], int quantidade, int tamanho, string baseDados) {

    if (quantidade == tamanho) {
        cout << "Base cheia!\n";
        return quantidade;
    }

    cin.ignore();

    cout << "Raça: ";
    getline(cin, vetor[quantidade].raca);

    cout << "Cor: ";
    getline(cin, vetor[quantidade].cor);

    cout << "Nome do Dono: ";
    getline(cin, vetor[quantidade].nome_dono);

    cout << "Horário (somente numeros): ";
    getline(cin, vetor[quantidade].horario);     

    quantidade++;

    salvarBase(baseDados, vetor, quantidade);

    cout << "Pet cadastrado!\n";
    return quantidade;
}

void editarPet(Pet vetor[], int quantidade, string baseDados) {

    listarPets(vetor, quantidade);
    if (quantidade == 0) return;

    int id;
    cout << "\nDigite o ID do pet para editar: ";
    cin >> id;

    if (id < 0 || id >= quantidade) {
        cout << "ID inválido.\n";
        return;
    }

    cin.ignore();

    cout << "Nova raça: ";
    getline(cin, vetor[id].raca);

    cout << "Nova cor: ";
    getline(cin, vetor[id].cor);

    cout << "Novo nome do dono: ";
    getline(cin, vetor[id].nome_dono);

    cout << "Novo horário: ";
    cin >> vetor[id].horario;

    salvarBase(baseDados, vetor, quantidade);

    cout << "Pet atualizado!\n";
}



// ------------------------
//        EXCLUIR
// ------------------------
int excluirPet(Pet vetor[], int quantidade, string baseDados) {

    listarPets(vetor, quantidade);
    if (quantidade == 0) return quantidade;

    int id;
    cout << "\nDigite o ID para excluir: ";
    cin >> id;

    if (id < 0 || id >= quantidade) {
        cout << "ID inválido.\n";
        return quantidade;
    }

    for (int i = id; i < quantidade - 1; i++)
        vetor[i] = vetor[i + 1];

    quantidade--;

    salvarBase(baseDados, vetor, quantidade);

    cout << "Pet excluído!\n";
    return quantidade;
}



// ------------------------
//            MENU
// ------------------------
void menu(Pet vetor[], int tamanho, int quantidade, string baseDados) {

    int opcao;

    do {
        cout << "\n===== MENU PET SHOP =====\n";
        cout << "1 - Listar Pets\n";
        cout << "2 - Cadastrar Pet\n";
        cout << "3 - Editar Pet\n";
        cout << "4 - Excluir Pet\n";
        cout << "5 - Sair\n";
        cout << "Opção: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (opcao) {

            case 1:
                listarPets(vetor, quantidade);
                break;

            case 2:
                quantidade = cadastrarPet(vetor, quantidade, tamanho, baseDados);
                break;

            case 3:
                editarPet(vetor, quantidade, baseDados);
                break;

            case 4:
                quantidade = excluirPet(vetor, quantidade, baseDados);
                break;

            case 5:
                cout << "Encerrando...\n";
                break;

            default:
                cout << "Opção inválida.\n";
        }

    } while (opcao != 5);
}

