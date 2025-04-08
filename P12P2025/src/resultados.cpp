//Luis Alberto Valenzuela Aguilar 9959-24-12583
#include "resultados.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

resultados::resultados(){}

void resultados::imprimirMatrizLinea() { //ajuste general
    cout << "+----------";
    for (int x = 0; x <= RONDAS; x++) {
        cout << "+-----------";
    }
    cout << "+\n";
}

void resultados::contarVotos(const std::vector<std::vector<std::vector<int>>> &matrizVotos, std::vector<std::vector<int>> &conteo, int numeroCandidatos) {
    for (int y = 0; y < numeroCandidatos; y++) {
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            conteo[y][ronda] = 0;
            for (int x = 0; x < VOTOS_AFILIADOS; x++) {
                conteo[y][ronda] += matrizVotos[y][ronda][x];
            }
        }
    }
}

void resultados::imprimirResultados(std::vector<std::vector<int>> &conteo, std::vector<std::string> &nombre) {
    std::vector<int> totalVotos(nombre.size(), 0);
    for (size_t i = 0; i < nombre.size(); i++) { // conteos
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            totalVotos[i] += conteo[i][ronda];
        }
    }
    cout << "\nResultados de la votacion de los años 2017, 2019, 201 y 2023\n" << endl;
    cout << "Partido   Candidato 1   Candidato 2   Candidato 3   Candidato 4    Candidato 5    Total" << endl;
    imprimirMatrizLinea();
    for (size_t i = 0; i < nombre.size(); i++) {
        cout << "!" << setw(8) << nombre[i] <<setw(4) << "!";
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            cout << setw(8) << conteo[i][ronda] << setw(4) << " !";
        }
        cout << setw(8) << totalVotos[i] << " !\n";
        imprimirMatrizLinea();
    }
}

void resultados::determinarGanadorYPerdedor(vector<vector<int>> &conteo, vector<string> &nombre) {
    vector<int> totalVotos(nombre.size(), 0);
    for (size_t i = 0; i < nombre.size(); i++) {
        for (int ronda = 0; ronda < RONDAS; ronda++) {
            totalVotos[i] += conteo[i][ronda];
        }
    }
    int maxVotos = totalVotos[0], minVotos = totalVotos[0];
    string ganador = nombre[0], perdedor = nombre[0];
    for (size_t i = 1; i < nombre.size(); i++) {
        if (totalVotos[i] > maxVotos) {
            maxVotos = totalVotos[i];
            ganador = nombre[i];
        }
        if (totalVotos[i] < minVotos) {
            minVotos = totalVotos[i];
            perdedor = nombre[i];
        }
    }
    cout << "\nEl partido con mas votos es: " << ganador << " con " << maxVotos << " votos." << endl;
    cout << "El partido con menos votos es: " << perdedor << " con " << minVotos << " votos.\n" << endl;
}

resultados::~resultados() {}
