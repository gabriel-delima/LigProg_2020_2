/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: nacional.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "estadual.h"

class Nacional{
    public:
        Nacional(string);
        void setNome(string);
        string getNome(); 
        void adicionarEstado(string, string);
        void removerEstado(string);
        bool procuraEstadoNoVetor(string);
        vector <Estadual> getVetorEstados();
        vector <unsigned> getVetorObitos();
        void atualizarVetorObitos();
        vector <vector < vector <float>>> calcularEstabilidadeEstados();
        float calcularEstabilidade();

        vector <unsigned> calcularMediaMovelPais();
        unsigned calcularTotalObitos();
        vector <unsigned> calcularObitosPorDia();
        Estadual maiorMediaMovelAtual();
        Estadual menorMediaMovelAtual();
        

    private:
        vector <Estadual> vetorEstados;
        vector <unsigned> vetorObitos;
        string nome;
};