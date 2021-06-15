/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: cadastro.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#ifndef CADASTRO_H
#define CADASTRO_H

#include <string>

#include "arvore.h"
#include "paciente.h"
#include "excecao.h"

using namespace std;


class Cadastro : public Arvore <Paciente *>{
    
    public:
        Cadastro();
        void insere(Paciente pacienteInserir);
        void busca(string nomeBusca);
        void imprime();

    private:
        Arvore <Paciente> arvorePacientes;
};

#endif