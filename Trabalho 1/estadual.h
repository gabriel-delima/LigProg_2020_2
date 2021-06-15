/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: estadual.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Estadual{
    public:
        Estadual(string,string);

        void setNome(string);
        string getNome(); 
        void setArquivoObitos(string);
        string getArquivoObitos();
        void setVetorObitos();
        vector <unsigned> getVetorObitos();
        void mostrarVetorObitosNaTela();
        vector <unsigned> calcularMediaMovel();
        float calcularEstabilidade();
        unsigned calcularObitosAcumulados();

    private:
        string nome;
        string arquivoObitos;
        vector <unsigned> vetorObitos;


};