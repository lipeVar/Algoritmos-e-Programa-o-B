#include <iostream>
#include <string>
#define N 5

using namespace std;

void lerNomes(string vetorNome[], int n) {
    for(int i = 1; i < n; i++) {
        cout << "Digte um nome completo: ";
        getline(cin, vetorNome[i]);
    }
}
void ordenaNome(string vetor[], int n) {

}

void exibirNome(string vetor[], int n) {
    for(int i=0; i<n; i++) {
        cout << "nome:"<<vetor[i] << ". Tamanho: " <<vetor[i].length() << "caracteres: " << endl;
    }
}

int main() {
    string nomes[N];

    lerNomes(nomes, N);
    ordenaNome(nomes, N);
    exibirNome(nomes, N);


    return 1;
}