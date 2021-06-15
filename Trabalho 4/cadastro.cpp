/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: cadastro.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "cadastro.h"

Cadastro::Cadastro(){}

void Cadastro::insere(Paciente pacienteInserir){
    No<Paciente> *ponteiroAux = arvorePacientes+=pacienteInserir;
    if ((ponteiroAux)==nullptr){
        throw pacienteJaInserido();
    }
    else{
        cout << "\n USUÁRIO ADICIONADO COM SUCESSO \n \n";
    }
}


void Cadastro::busca(string nomeBusca){

    Paciente pacienteAux(nomeBusca, 0 , "");

    No<Paciente> *ponteiroAux = arvorePacientes(pacienteAux);

    if (ponteiroAux == nullptr){
        throw pacienteNaoEncontrado();
    }
    else{
        cout << "\n------------------------------------- USUÁRIO ENCONTRADO";
        cout << ponteiroAux->valor;
    }
}


void Cadastro::imprime(){
    cout << arvorePacientes;
}

