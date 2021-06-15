/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: estadual.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "estadual.h"

Estadual::Estadual(string nome_estado, string arquivo_obitos){
    setNome(nome_estado);
    setArquivoObitos(arquivo_obitos);
    setVetorObitos();
}

void Estadual::setNome(string nome_estado){
    nome = nome_estado;
}

string Estadual::getNome(){
    return nome;
}

void Estadual::setArquivoObitos(string arquivo_obitos){
    arquivoObitos = arquivo_obitos;
}

string Estadual::getArquivoObitos(){
    return arquivoObitos;
}

// gera os valores para o vetor de óbitos através do arquivo txt
void Estadual::setVetorObitos(){
    vector <unsigned> vetorAuxiliar;
    string obitos_no_dia;
    fstream file;

    file.open(arquivoObitos, fstream::in);
    if (!file.is_open()){
        cout << "Arquivo nao existe. \n";
    }
    else{
        while (file.good()){
            file >> obitos_no_dia;
            vetorAuxiliar.push_back(stoul(obitos_no_dia));
        }
        vetorObitos = vetorAuxiliar;
    }
    file.close();
}

// retorna o vetor de óbitos
vector <unsigned> Estadual::getVetorObitos(){
    return vetorObitos;
}

// Função auxiliar que mostra os dados do vetor de óbitos
void Estadual::mostrarVetorObitosNaTela(){
    for (unsigned i = 0; i < vetorObitos.size(); i++){
        cout << i <<":  "<< vetorObitos.at(i) << ".\n"; 
    }
}

// Retorna um vetor com as médias móveis no estado. O vetor seguirá o formato:
//      índice 0 -> média móvel do último dia
//      índice 1 -> média móvel do penúltimo dia
//      índice 2 -> média móvel do antepenúltimo dia
vector <unsigned> Estadual::calcularMediaMovel(){
    unsigned somaUltimoDia = 0, somaPenultimoDia = 0, somaAntePenultimoDia = 0;

    for (unsigned i = 0; i < vetorObitos.size(); i++){

        if (i<7){
            somaUltimoDia += vetorObitos.at(i);
        }
        
        if (i>0 && i<8){
            somaPenultimoDia += vetorObitos.at(i);
        }

        if (i>1 && i<9){
            somaAntePenultimoDia += vetorObitos.at(i);
        }

        if (i>=9){
            i = vetorObitos.size();
        }
    }
    unsigned mediaUltimoDia = somaUltimoDia/7;
    unsigned mediaPenultimoDia = somaPenultimoDia/7;
    unsigned mediaAntePenultimoDia = somaAntePenultimoDia/7;
    
    vector <unsigned> vetorRetorno;
    
    vetorRetorno.push_back(mediaUltimoDia);
    vetorRetorno.push_back(mediaPenultimoDia);
    vetorRetorno.push_back(mediaAntePenultimoDia);

    return vetorRetorno;
}

// retorna a estabilidade atual do estado considerando as 2 últimas médias móveis
float Estadual::calcularEstabilidade(){
    vector <unsigned> mediaMovel = calcularMediaMovel();

    float estabilidade = ((float) mediaMovel.at(0)) /  ((float) mediaMovel.at(1));

    return estabilidade;
}

// retorna o somatório de todas as mortes no estado
unsigned Estadual::calcularObitosAcumulados(){
    unsigned soma = 0;
    for (unsigned i = 0; i < vetorObitos.size(); i++){
        soma += vetorObitos.at(i);
    }
    return soma;
}
