#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <limits>
#define tam 1000

#include "../uteis/modulo.h"

using namespace std;


int main() {
    Pet vetor[tam];
    int quanti_Animais;
    string baseDados = "listaAnimais.csv";

    quanti_Animais = conectarBase(baseDados, vetor, tam);
    menu(vetor, tam, quanti_Animais, baseDados);
    
    return 0;
}
