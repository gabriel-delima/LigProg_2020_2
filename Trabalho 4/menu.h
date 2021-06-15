/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: menu.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

#include "cadastro.h"
#include "excecao.h"

using namespace std;

class Menu {
    public:
        void mostrarMenuPrincipal();
        unsigned receberOpcaoMenu();
        void finalizarPrograma();
        void criarPaciente(Cadastro &cadastro);
        string receberNomeBusca();
};

#endif