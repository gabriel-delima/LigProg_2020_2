/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: vertice.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/
#include <iostream>
#include <string>

#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

class Vertice{
    public:
        Vertice();
        void setPalavra(string palavra_vertice);
        string getPalavra();
        void setFrequencia(unsigned frequencia_vertice);
        unsigned getFrequencia();
        void mostrarVerticeNaTela();

    private:
        string palavra;
        unsigned frequencia;
};

#endif