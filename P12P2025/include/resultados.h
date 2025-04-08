//Luis Alberto Valenzuela Aguilar 9959-24-12583
#ifndef RESULTADOS_H
#define RESULTADOS_H
#include <vector>
#include <string>
#include <iostream>
#include <matriz.h>
#define RONDAS 4
#define VOTOS_AFILIADOS 1000

class resultados
{
    public:
        resultados();
        ~resultados();

        void imprimirMatrizLinea();
        void contarVotos(const std::vector<std::vector<std::vector<int>>> &matrizVotos, std::vector<std::vector<int>> &conteo, int numeroCandidatos);
        void imprimirResultados(std::vector<std::vector<int>> &conteo, std::vector<std::string> &nombre);
        void determinarGanadorYPerdedor(std::vector<std::vector<int>> &conteo, std::vector<std::string> &nombre);

    protected:

    private:
};

#endif // RESULTADOS_H
