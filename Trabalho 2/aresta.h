/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: aresta.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "vertice.h"

#ifndef ARESTA_H
#define ARESTA_H

class Aresta{
    public:
        Aresta(Vertice vertice1, Vertice vertice2, int peso);
        void setPeso(int peso_aresta);
        unsigned getPeso();
        string getVertice1();
        string getVertice2();
        void mostrarArestaNaTela();

    private:
        Vertice vertice1;
        Vertice vertice2;
        unsigned peso;
};

#endif