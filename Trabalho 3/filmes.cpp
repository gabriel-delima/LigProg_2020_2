/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: filmes.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "filmes.h"

bool operator==(filme filme1, filme filme2){
    if(filme1.nome == filme2.nome){
        return true;
    }
    return false;
}

bool operator>(filme filme1, filme filme2){
    if(filme1.nome > filme2.nome){
        return true;
    }
    return false;
}

bool operator<(filme filme1, filme filme2){
    if(filme1.nome < filme2.nome){
        return true;
    }
    return false;
}

vector<filme> operator+=(vector<filme> vetorFilmes,filme filme){
    for (unsigned i=0; i<vetorFilmes.size() ; i++){
        if(filme < vetorFilmes.at(i)){
            vetorFilmes.insert(vetorFilmes.begin() + i,filme);
            return vetorFilmes;
        }
        else if(filme == vetorFilmes.at(i)){
            cout << "\n|------------------------------------------------|"
                 << "\n|         O FILME JÁ EXISTE NO CATÁLOGO          |"
                 << "\n|------------------------------------------------|\n\n";

            return vetorFilmes;
        }
    }
    vetorFilmes.push_back(filme);
    return vetorFilmes;
}

vector<filme> operator+=(vector<filme> vetorDestino, vector<filme> vetorInserir){
    for(unsigned i=0; i<vetorInserir.size();i++){
            vetorDestino = vetorDestino+=vetorInserir.at(i);
    }
    return vetorDestino;
}

vector<filme> operator-=(vector<filme> vetorFilmes,filme filme){
    for (unsigned i=0; i<vetorFilmes.size() ; i++){
        if(vetorFilmes.at(i) == filme){
            vetorFilmes.erase(vetorFilmes.begin()+i);
            return vetorFilmes;
        }
    }
    return vetorFilmes;
}

vector<filme> operator-=(vector<filme> vetorDestino, vector<filme> vetorInserir){
    for(unsigned i=0; i<vetorInserir.size();i++){
            vetorDestino = vetorDestino-=vetorInserir.at(i);
    }
    return vetorDestino;
}

ostream &operator<<(ostream &out, filme &filme){
    cout << "  Nome: " << filme.nome
         << "\n  Produtora: " << filme.produtora
         << "\n  Nota: " << filme.nota << endl;
    return out;
}


