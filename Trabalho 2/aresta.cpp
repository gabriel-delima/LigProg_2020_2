/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: aresta.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "aresta.h"

Aresta::Aresta(Vertice vertice_1, Vertice vertice_2, int peso){
    vertice1 = vertice_1;
    vertice2 = vertice_2;
    setPeso(peso);
}

string Aresta::getVertice1(){
    return vertice1.getPalavra();
}

string Aresta::getVertice2(){
    return vertice2.getPalavra();
}

void Aresta::setPeso(int peso_aresta){
    peso = peso_aresta;
}

unsigned Aresta::getPeso(){
    return peso;
}

void Aresta::mostrarArestaNaTela(){
    cout << vertice1.getPalavra() 
         << " -> "
         << peso 
         << " -> "
         << vertice2.getPalavra() 
         << "\n";
}