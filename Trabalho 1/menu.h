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
#include <iomanip>

using namespace std;

#include "nacional.h"

class Menu {
    public:
        void mostrarMenuPrincipal();
        unsigned receberOpcaoMenu();
        void finalizarPrograma();
        void mostrarMediasMoveis(Nacional);
        void mostrarTotalDeObitos(Nacional);
        void mostrarMaiorMenorMedia(Nacional);
        void mostrarEtabilidadeEstados(Nacional);
        void mostrarEstabilidadePais(Nacional);
};