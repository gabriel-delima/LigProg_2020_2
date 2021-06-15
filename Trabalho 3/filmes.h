/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: filmes.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

#ifndef FILMES_H
#define FILMES_H


// estrutura do filme
struct filme{
    string nome;
    string produtora;
    double nota;
};


// operadores 
bool operator==(filme filme1, filme filme2);
bool operator<(filme filme1, filme filme2);
bool operator>(filme filme1, filme filme2);
vector<filme> operator+=(vector<filme> vetorFilmes,filme filme);
vector<filme> operator+=(vector<filme> vetorDestino, vector<filme> vetorInserir);
vector<filme> operator-=(vector<filme> vetorDestino,filme filme);
vector<filme> operator-=(vector<filme> vetorDestino, vector<filme> vetorInserir);
ostream &operator<<(ostream &out, filme &filme);


#endif