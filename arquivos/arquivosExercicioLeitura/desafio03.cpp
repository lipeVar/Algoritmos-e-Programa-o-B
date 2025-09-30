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
    string tmp;
    bool houveTroca;

    do {
        houveTroca = false;
        for (int i = 0; i < n-1; i++) {
            if (vetor[i] > vetor[i+1]) {
                houveTroca = true;
                tmp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = tmp;
            }
        }
    } while (houveTroca);

}

void exibirNome(string vetor[], int n) {
    for(int i=1; i<n; i++) {
        cout << "nome:"<<vetor[i] << ". Tamanho: " <<vetor[i].length() << " caracteres" << endl;
    }
}

int main() {
    string nomes[N];

    lerNomes(nomes, N);
    ordenaNome(nomes, N);
    exibirNome(nomes, N);


    return 1;
}