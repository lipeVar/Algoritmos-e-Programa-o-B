#include <iostream> // <stdio.h>
#include <string>
#define TAM 4
using namespace std;

// #include "meusIncludes.h"

typedef struct {
string nome;
string celular;
string data;
string descricao;
} Emprestimo;

int main()
{
int opcao;
Emprestimo meusItens[TAM];
Emprestimo item;
int qtdEmprestimos = 0;

do
{
    cout << "M E N U" << endl;
    cout << "1 - Emprestar" << endl;
    cout << "2 - Devolver" << endl;
    cout << "3 - Listar emprestimos" << endl;
    cout << "4 - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        cout << "AREA DE EMPRESTIMO" << endl;
        if (qtdEmprestimos == TAM) {
            cout << "Voce nao tem mais itens para emprestar..." << endl;
        } else {

        }
        break;
    case 2:
        cout << "AREA DE DEVOLUCAO" << endl;
        if (qtdEmprestimos == 0) {
            cout << "Nenhum item esta emprestado" << endl;
        } else {

        }
        break;
    case 3:
        cout << "LISTAGEM DE EMPRESTIMOS" << endl;
        if (qtdEmprestimos == 0) {
            cout << "Nenhum item esta emprestado" << endl;
        } else {

        }
        break;
    case 4:
        cout << "Voce esta encerrando o programa...." << endl;
        break;
    default:
        cout << "Opcao invalida...." << endl;
        break;
    }
} while (opcao != 4);
cout << "Programa encerrado....\\n";
return 1;
}
