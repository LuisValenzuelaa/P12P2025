//Luis Alberto Valenzuela Aguilar 9959-24-12583
#include "matriz.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <vector>

matriz::matriz(){}

int matriz::busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() % (maximo - minimo + 1);
}

void matriz::llenarMatriz(std::vector<std::vector<std::vector<int>>> &matriz, int numeroCandidatos, int ronda) {
    for (int y = 0; y < numeroCandidatos; y++) {
        fill(matriz[y][ronda].begin(), matriz[y][ronda].end(), 0);
    }
    for (int i = 0; i < VOTOS_AFILIADOS; i++) {
        int candidato = busquedaAleatorios(0, numeroCandidatos - 1);
        matriz[candidato][ronda][i] = 1;
    }
}


matriz::~matriz() {}


