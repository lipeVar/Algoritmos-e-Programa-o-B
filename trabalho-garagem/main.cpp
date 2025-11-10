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
    Garagem vetor[tam];
    int quanti_Carros;
    string baseDados = "base.csv";

    quanti_Carros = conectarBase(baseDados, vetor, tam);
    menu(vetor, tam, quanti_Carros, baseDados);
    
    return 0;
}
