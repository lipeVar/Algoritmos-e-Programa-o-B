#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include <limits>

#include "modulo.h"

using namespace std;

int main() {

    Pet vetor[tam];
    int quanti = 0;
    string base = "pets.csv";

    quanti = conectarBase(base, vetor, tam);

    menu(vetor, tam, quanti, base);

    return 0;
}

