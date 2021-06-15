/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: menu.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include <iostream>
#include <string>

#include "filmes.h"
#include "catalogo.h"

using namespace std;

class Menu {
    public:
        void mostrarMenuPrincipal();
        unsigned receberOpcaoMenu();
        void finalizarPrograma();
        filme inicializarFilme();
        filme inicializarFilmeSomenteComNome();
        filme retornarFilmeParaAdicionar();
        filme retornarFilmeParaRemover();
        filme retornarFilmeParaBuscar();
        void editarFilme(Catalogo &catalogo);
};