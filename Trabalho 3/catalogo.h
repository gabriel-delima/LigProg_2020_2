/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: catalogo.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/
#include <fstream>
#include "filmes.h"

using namespace std;

#ifndef CATALOGO_H
#define CATALOGO_H


// classe
class Catalogo{
    public:
        Catalogo(unsigned numMaxFilmesEnt, string nomeArquivo );
        void inicializarFilmesArquivo(string nomeArquivo);
        void salvarFilmesArquivo(string nomeArquivo);
        void mostrarFilmeCadastrado(filme filmeBusca);
        void mostrarFilmeMelhorAvaliado();
        void mostrarFilmePiorAvaliado();
        friend ostream &operator<<(ostream &out, const Catalogo &catalogo); 
        void operator+=(filme filme);
        void operator-=(filme filme);
        filme *operator()(filme filmeBusca);
        filme *operator()(filme filmeBusca,string produtora);
        filme *operator()(filme filmeBusca,double nota);

    private:
        unsigned numMaxFilmes;
        vector<filme> vetorFilmes;
        
};



#endif