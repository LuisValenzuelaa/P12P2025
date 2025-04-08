//Luis Alberto Valenzuela Aguilar 9959-24-12583
#ifndef MATRIZ_H
#define MATRIZ_H
#include <vector>
#define RONDAS 4
#define VOTOS_AFILIADOS 1000
using namespace std;

class matriz
{
    public:
        vector<vector<vector<int>>> matrizVotos;
        matriz();
        int busquedaAleatorios(int minimo, int maximo);
        void llenarMatriz(vector<vector<vector<int>>> &matriz, int numeroCandidatos, int ronda);
        ~matriz();

    protected:

    private:
};

#endif // MATRIZ_H
