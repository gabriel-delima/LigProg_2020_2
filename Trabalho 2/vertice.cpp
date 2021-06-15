/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: vertice.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "vertice.h"

Vertice::Vertice(){
    setPalavra("");
    setFrequencia(1);
}
void Vertice::setPalavra(string palavra_vertice){
    palavra = palavra_vertice;
}

string Vertice::getPalavra(){
    return palavra;
}

void Vertice::setFrequencia(unsigned frequencia_vertice){
    frequencia = frequencia_vertice;
}

unsigned Vertice::getFrequencia(){
    return frequencia;
}

void Vertice::mostrarVerticeNaTela(){
    cout << "("
    << getFrequencia()
    << ")  "
    << getPalavra() << endl;

}