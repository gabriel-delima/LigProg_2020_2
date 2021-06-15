/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: excecao.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#ifndef EXCECAO_H
#define EXCECAO_H

#include <exception>

using namespace std;

class pacienteJaInserido : public exception{
    public:
        const char *what() const throw(){
            
            const char* msgErro = "\n Erro -- Um paciente com esse nome já está cadastrado \n \n";

            return msgErro;
        }
};

class pacienteNaoEncontrado : public exception{
    public:
        const char *what() const throw(){
            
            const char* msgErro = "\n Erro -- Nenhum paciente com esse nome foi cadastrado \n";

            return msgErro;
        }
};


#endif