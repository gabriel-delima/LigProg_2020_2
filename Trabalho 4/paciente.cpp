/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: paciente.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "paciente.h"


////////////////////// PACIENTE BASE 

Paciente::Paciente(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada){
    nome = nomeEntrada;
    idade = idadeEntrada;
    descricao = descricaoEntrada;
}

Paciente::Paciente(){}

string Paciente::getNome(){
    return nome;
}

unsigned int Paciente::getIdade(){
    return idade;
}

string Paciente::getDescricao(){
    return descricao;
}

string Paciente::getTipo(){
    return tipo;
}

void Paciente::setNome(string nomeEntrada){
    nome = nomeEntrada;
}

void Paciente::setIdade(unsigned int idadeEntrada){
    idade = idadeEntrada;
}

void Paciente::setDescricao(string descricaoEntrada){
    descricao = descricaoEntrada;
}

void Paciente::setTipo(string tipoEntrada){
    tipo = tipoEntrada;
}

ostream &operator<<(ostream &out, Paciente &pacienteImprimir){
    pacienteImprimir.mostrarPaciente();
    return out;
}

void Paciente::mostrarPaciente(){
    cout <<"\n\n   PACIENTE CADASTRADO PARA " << getTipo();
    cout <<"\n\n   Nome: " << getNome();

    if (getIdade() == 1) {
        cout <<"\n   Idade: 1 ano";
    }
    else {
        cout <<"\n   Idade: " << getIdade() << " anos";
    }     
    cout <<"\n   Descrição: " << getDescricao();
    cout <<"\n-------------------------------------";
}


bool Paciente::operator>(Paciente const &pacienteComparacao){
    if((this->nome) > (pacienteComparacao.nome)){
        return true;
    }
    return false;
}

bool Paciente::operator<(Paciente const &pacienteComparacao){
    if((this->nome) < (pacienteComparacao.nome)){
        return true;
    }
    return false;
}

bool Paciente::operator==(Paciente const &pacienteComparacao){
    if((this->nome) == (pacienteComparacao.nome)){
        return true;
    }
    return false;
}

////////////////////// PACIENTE INTERNACAO
Paciente_Internacao::Paciente_Internacao(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada, unsigned int diasInternadosEntrada){
    setNome(nomeEntrada);
    setIdade(idadeEntrada);
    setDescricao(descricaoEntrada);
    diasInternados = diasInternadosEntrada;
    setTipo("INTERNAÇÃO");
}

Paciente_Internacao::Paciente_Internacao(){
    setTipo("INTERNAÇÃO");
}

unsigned int Paciente_Internacao::getDiasInternados(){
    return diasInternados;
}

void Paciente_Internacao::setDiasInternados(unsigned int diasInternadosEntrada){
    diasInternados = diasInternadosEntrada;
}

void Paciente_Internacao::mostrarPaciente(){
    cout <<"\n\n   PACIENTE CADASTRADO PARA " << getTipo();
    cout <<"\n\n   Nome: " << getNome();

    if (getIdade() == 1) {
        cout <<"\n   Idade: 1 ano";
    }
    else {
        cout <<"\n   Idade: " << getIdade() << " anos";
    }     
    cout <<"\n   Descrição: " << getDescricao();
    if (getDiasInternados() == 1) {
        cout <<"\n   Dias Internados: 1 dia";
    }
    else {
        cout <<"\n   Dias Internados: " << getDiasInternados() << " dias";
    }   
    cout <<"\n-------------------------------------";
}



////////////////////// PACIENTE CONSULTA
Paciente_Consulta::Paciente_Consulta(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada, unsigned int numConsultasEntrada){
    setNome(nomeEntrada);
    setIdade(idadeEntrada);
    setDescricao(descricaoEntrada);
    numConsultas = numConsultasEntrada;
    setTipo("CONSULTA");
}

Paciente_Consulta::Paciente_Consulta(){
    setTipo("CONSULTA");
}
unsigned int Paciente_Consulta::getNumConsultas(){
    return numConsultas;
}

void Paciente_Consulta::setNumConsultas(unsigned int numConsultasEntrada){
    numConsultas = numConsultasEntrada;
}

void Paciente_Consulta::mostrarPaciente(){
    cout <<"\n\n   PACIENTE CADASTRADO PARA " << getTipo();
    cout <<"\n\n   Nome: " << getNome();

    if (getIdade() == 1) {
        cout <<"\n   Idade: 1 ano";
    }
    else {
        cout <<"\n   Idade: " << getIdade() << " anos";
    }     
    cout <<"\n   Descrição: " << getDescricao();
    if (getNumConsultas() == 1) {
        cout <<"\n   Número de Consultas realizadas: 1 consulta";
    }
    else {
        cout <<"\n   Número de Consultas realizadas: " << getNumConsultas() << " consultas";
    }   
    cout <<"\n-------------------------------------";
}



////////////////////// PACIENTE EXAME
Paciente_Exame::Paciente_Exame(string nomeEntrada, unsigned int idadeEntrada, string descricaoEntrada, string nomeExameEntrada, bool exameRealizadoEntrada){
    setNome(nomeEntrada);
    setIdade(idadeEntrada);
    setDescricao(descricaoEntrada);
    nomeExame = nomeExameEntrada;
    exameRealizado = exameRealizadoEntrada;
    setTipo("EXAME");
}

Paciente_Exame::Paciente_Exame(){
    setTipo("EXAME");
}

string Paciente_Exame::getNomeExame(){
    return nomeExame;
}

bool Paciente_Exame::getExameRealizado(){
    return exameRealizado;
}

void Paciente_Exame::setNomeExame(string nomeExameEntrada){
    nomeExame = nomeExameEntrada;
}

void Paciente_Exame::setExameRealizado(bool exameRealizadoEntrada){
    exameRealizado = exameRealizadoEntrada;
}

void Paciente_Exame::mostrarPaciente(){
    cout <<"\n\n   PACIENTE CADASTRADO PARA " << getTipo();
    cout <<"\n\n   Nome: " << getNome();

    if (getIdade() == 1) {
        cout <<"\n   Idade: 1 ano";
    }
    else {
        cout <<"\n   Idade: " << getIdade() << " anos";
    }     
    cout <<"\n   Descrição: " << getDescricao()
         <<"\n   Nome do Exame: "<< getNomeExame();
    if (getExameRealizado() == true){
        cout <<"\n   (..EXAME JÁ REALIZADO..)";
    }
    else{
        cout <<"\n   (..EXAME AINDA NÃO FOI REALIZADO..)";
    }
    cout <<"\n-------------------------------------";
}