// fazer um programa em c ou c++ que preencha um vetor de string com n nomes e exibi-los

#include <iostream> // stdio.h
#include <string> // string.h

#define TAM 4

using namespace std;
int main() {
    cout << "Fazer um programa em C ou C++ que preencha um vetor de string com N nomes e exiba-os" << endl;
    string nomes[TAM];
    int quantidadeInseridos = 0;
    int opcao;
    string nome;
    do {
        cout << "M E N U" << endl;
        cout << "1 - Cadastrar Nomes" << endl;
        cout << "2 - Listar nomes" << endl;
        cout << "3 - Pesquisar nomes" << endl;
        cout << "4 - Ordenar o vetor" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opcão: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            cout << "Cadastrar nomes ..." << endl;
            if (quantidadeInseridos == TAM) {
                cout << "Vetor lotado..." << endl;
            } else {
                string nome;
                for (int i = 0;i < TAM; i++ ) {
                    cout << "Nome: ";
                    getline(cin, nome);
                    fflush(stdin);
                    //rotina que verifica se o nome ja esta no vetor de nomes
                    int repetidos = 0;
                    for(int i = 0; i < quantidadeInseridos; i++) {
                        if(nomes[i] == nome) {
                            repetidos = 1;
                        }
                    }
                    if (repetidos == 1) {
                        cout << "Nome ja cadastrado!!";
                    } else {
                        nomes[quantidadeInseridos] = nome;
                        quantidadeInseridos++;
                    }
                    
                }
            }
            break;
        case 2:
            cout << "Listar nomes ..." << endl;
            if (quantidadeInseridos == 0) {
                cout << "Vetor de nomes vazio, nada a exibir!" << endl;
            }  else {
                for (int i = 0; i < quantidadeInseridos; i++) {
                    cout << "Nome" << (i+1) << ": " << nomes[i] << endl;
                }
                cout << "-----------------" << endl;
                cout << "Total de registros: " << quantidadeInseridos << endl;
            }  
            break;
        case 3:
           cout << "Pesquisar nomes" << endl;
           if (quantidadeInseridos == 0) {
                cout << "Vetor de nome vazio" << endl;
           }  else { 
            cout << "Nome para pesquisa: " << endl;
            getline(cin,nome);
            int quantidadeLocalizados = 0;
            for (int i = 0; i < quantidadeInseridos; i++) {
                if (nomes[i].find(nome)) {
                    cout << nomes[i] << endl;
                    quantidadeLocalizados++;
                }
            }
            cout << "-----------------" << endl;
                cout << "Total de registros: " << quantidadeLocalizados << endl;
           }
            break;
        case 4:
            cout << "Ordenando vetor..." << endl;   
            if (quantidadeInseridos > 1) {
                for( int i = 0; i < quantidadeInseridos - 1; i++) {
                    for (int j = 0; j < quantidadeInseridos - i - 1; j++) {
                        if (nomes[j] > nomes[j+1]) {
                            string tempo = nomes[j];
                            nomes[j] = nomes[j+1];
                            nomes[j+1] = tempo;
                        }
                    }
                }
                cout << "Nomes ordenados!" << endl;
            } 
        case 5:
           cout << "Saindo do programa." << endl;
           break;
        default:
            cout << "Opcão invalida!!" << endl; 
            break;
        }
    }  while (opcao != 5);
    return 1;
}