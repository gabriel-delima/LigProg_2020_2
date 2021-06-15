/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: paciente.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/
#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Paciente{

    public:
        Paciente(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada);
        Paciente();
        string       getNome();
        unsigned int getIdade();
        string       getDescricao();
        string       getTipo();
        void setNome(string nomeEntrada);
        void setIdade(unsigned int idadeEntrada);
        void setDescricao(string descricaoEntrada);
        void setTipo(string tipoEntrada);

        // imprimir os pacientes na tela (Foi usada uma função virtual para que possa ser adaptada)
        friend ostream &operator<<(ostream &out, Paciente &pacienteImprimir);
        virtual void mostrarPaciente();

        // Definir resultado das comparações entre pacientes
        bool  operator>(Paciente const &pacienteComparacao);
        bool  operator<(Paciente const &pacienteComparacao); 
        bool operator==(Paciente const &pacienteComparacao); 

    private:
        string nome;
        unsigned int idade;
        string descricao;
        string tipo;
};



class Paciente_Internacao : public Paciente{

    public:
        Paciente_Internacao(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada, unsigned int diasInternadosEntrada);
        Paciente_Internacao();
        void mostrarPaciente() override;
        unsigned int getDiasInternados();
        void setDiasInternados(unsigned int diasInternadosEntrada);
    private:
        unsigned int diasInternados;
};



class Paciente_Consulta : public Paciente{

    public:
        Paciente_Consulta(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada, unsigned int numConsultasEntrada);
        Paciente_Consulta();
        void mostrarPaciente() override;
        unsigned int getNumConsultas();
        void setNumConsultas(unsigned int numConsultasEntrada);

    private:
        unsigned int numConsultas;
};



class Paciente_Exame : public Paciente{

    public:
        Paciente_Exame(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada, string nomeExameEntrada, bool exameRealizadoEntrada);
        Paciente_Exame();
        void mostrarPaciente() override;
        string  getNomeExame();
        bool    getExameRealizado();
        void setNomeExame(string nomeExameEntrada);
        void setExameRealizado(bool exameRealizadoEntrada);
        
    private:
        string nomeExame;
        bool exameRealizado;
};


#endif