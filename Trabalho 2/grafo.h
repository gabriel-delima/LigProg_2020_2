/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: grafo.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include <vector>
#include <fstream>
#include <algorithm>

#include "aresta.h"

#ifndef GRAFO_H
#define GRAFO_H

class Grafo{
    public:
        int procurarVertice(string palavra_vertice);
        int procurarAresta(Aresta aresta);
        void adicionarAresta(Aresta aresta);
        void adicionarVertice(string palavra_vertice);
        void mostrarArestas();
        void mostrarVertices();
        void mostrarVerticeMaiorFrequencia();
        void preencherGrafo();
        void mostrarMaiorSequenciaDuasPalavras();
        void mostrarMaiorSequenciaNPalavras(unsigned n);
    private:
        vector <Aresta> arestas;
        vector <Vertice> vertices;
        vector <pair<Aresta, unsigned>> arestas_repetidas;
};

#endif