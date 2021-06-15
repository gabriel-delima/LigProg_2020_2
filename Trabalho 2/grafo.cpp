/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: grafo.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "grafo.h"

int Grafo::procurarVertice(string palavra_vertice){
    for (unsigned i=0; i<vertices.size(); i++){
        if (vertices.at(i).getPalavra() == palavra_vertice){
            return i;
        }
    }
    return -1;
}

void Grafo::adicionarVertice(string palavra_vertice){
    int index = procurarVertice(palavra_vertice);
    
    if (index >= 0){
        unsigned freq_atual = vertices.at(index).getFrequencia();
        vertices.at(index).setFrequencia(freq_atual+1);
    }
    else{
        Vertice vertice;
        vertice.setPalavra(palavra_vertice);
        vertices.push_back(vertice);
    }
}

int Grafo::procurarAresta(Aresta aresta){
    string vertice1 = aresta.getVertice1();
    string vertice2 = aresta.getVertice2();

    for (unsigned i=0; i<arestas.size(); i++){
        if ((arestas.at(i).getVertice1() == vertice1) && 
            (arestas.at(i).getVertice2() == vertice2)){
            return i;
        }
    }
    return -1;
}

void Grafo::adicionarAresta(Aresta aresta){
    int index = procurarAresta(aresta);

    if (index >= 0){
        unsigned peso_atual = arestas.at(index).getPeso();
        arestas.at(index).setPeso(peso_atual+1);
    }
    else{
        arestas.push_back(aresta);
    }   
}

void Grafo::mostrarArestas(){
    for (unsigned i = 0; i<arestas.size();i++){
    arestas.at(i).mostrarArestaNaTela();
    }
}

void Grafo::mostrarVertices(){
    for (unsigned i = 0; i<vertices.size();i++){
        vertices.at(i).mostrarVerticeNaTela();
    }
}

void Grafo::mostrarVerticeMaiorFrequencia(){
    unsigned maior_freq = 0, freq_aux = 0;
 
    for (unsigned i = 0; i<vertices.size();i++){
        freq_aux = vertices.at(i).getFrequencia();
        if (freq_aux > maior_freq){
            maior_freq = freq_aux;
        }
    }
    cout << "------MAIOR FREQUÊNCIA = " << maior_freq << "\n\n";
    for (unsigned i = 0; i<vertices.size();i++){

        if (vertices.at(i).getFrequencia() == maior_freq){
            vertices.at(i).mostrarVerticeNaTela();
        }
    }
}

void Grafo::mostrarMaiorSequenciaDuasPalavras(){
    unsigned maior_peso = 0, peso_aux = 0;
 
    for (unsigned i = 0; i<arestas.size();i++){
        peso_aux = arestas.at(i).getPeso();
        if (peso_aux > maior_peso){
            maior_peso = peso_aux;
        }
    }
    cout << "------MAIOR SEQUÊNCIA = " << maior_peso << "\n\n";
    for (unsigned i = 0; i<arestas.size();i++){

        if (arestas.at(i).getPeso() == maior_peso){
            arestas.at(i).mostrarArestaNaTela();
        }
    }
}

void Grafo::preencherGrafo(){
    fstream arquivo;
    string palavra;
    string nome_arquivo = "texto.txt";
    arquivo.open(nome_arquivo.c_str());
    if (!arquivo.is_open()){
        cout << "Arquivo nao existe. \n";
    }
    else{
        vector <string> vetorAuxPalavras;
        unsigned n =2;
        while (arquivo>>palavra)
        {   
            /* Remover pontuações e deixar todas as letras minúsculas*/
            palavra.erase(remove(palavra.begin(), palavra.end(), ','), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), ';'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), '.'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), '!'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), '?'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), ':'), palavra.end());
            for (unsigned i = 0; i < palavra.size(); i++) {
                palavra.at(i) = tolower(palavra.at(i));
            }   
            
            adicionarVertice(palavra);

            if (vetorAuxPalavras.size() < n){
               vetorAuxPalavras.push_back(palavra);
            }
            
            if (vetorAuxPalavras.size() == n){

                Vertice vertice1, vertice2;
                vertice1.setPalavra(vetorAuxPalavras.at(0));
                vertice2.setPalavra(vetorAuxPalavras.at(1));

                Aresta aresta(vertice1,vertice2,1);
                adicionarAresta(aresta);
                vetorAuxPalavras.erase(vetorAuxPalavras.begin());
            }            
        }
    } 
    arquivo.close();
}

void Grafo::mostrarMaiorSequenciaNPalavras(unsigned n){
    fstream arquivo;
    string palavra;
    string nome_arquivo = "texto.txt";
    
    vector <pair<vector<string>,unsigned>> vetorSequencias; 
    /* Cada item de vetorSequencias possui um vetor com as palavras em questão e um unsigned indicando a frequencia dessa sequencia*/
    
    arquivo.open(nome_arquivo.c_str());
    if (!arquivo.is_open()){
        cout << "Arquivo nao existe. \n";
    }
    else{
        vector <string> vetorAuxPalavras;
        while (arquivo>>palavra)
        {   
            /* Remover pontuações e deixar todas as letras minúsculas*/
            palavra.erase(remove(palavra.begin(), palavra.end(), ','), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), ';'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), '.'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), '!'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), '?'), palavra.end());
            palavra.erase(remove(palavra.begin(), palavra.end(), ':'), palavra.end());
            for (unsigned i = 0; i < palavra.size(); i++) {
                palavra.at(i) = tolower(palavra.at(i));
            }   
            

            if (vetorAuxPalavras.size() < n){
               vetorAuxPalavras.push_back(palavra);
            }
            
            if (vetorAuxPalavras.size() == n){
                bool sequenciaRepetida = false;
                unsigned indiceSequenciaRepetida ;
                pair<vector<string>,unsigned> parAux;
                
                parAux.first = vetorAuxPalavras;
                parAux.second = 1;

                for (unsigned i=0; i < vetorSequencias.size(); i++){
                    unsigned somaIguais = 0;
                    for (unsigned j=0; j < n; j++){
                        
                        if (vetorSequencias.at(i).first.at(j) == vetorAuxPalavras.at(j)){
                            somaIguais++;
                        }
                    }
                    if (somaIguais == n){
                        indiceSequenciaRepetida = i;
                        sequenciaRepetida = true;
                    }
                }
                if (sequenciaRepetida){
                    vetorSequencias.at(indiceSequenciaRepetida).second++;
                }
                else {
                    vetorSequencias.push_back(parAux);
                }
                vetorAuxPalavras.erase(vetorAuxPalavras.begin());
            }            
        }
    } 
    arquivo.close();

    /* Calcular a maior frequencia */ 
    unsigned maior_freq = 0, freq_aux = 0;
    for (unsigned i=0; i < vetorSequencias.size(); i++){
        freq_aux = vetorSequencias.at(i).second;
        if (freq_aux > maior_freq){
            maior_freq = freq_aux;
        }
    }

    /* Mostrar sequencias com freq == maior_freq */
    cout << "------MAIOR SEQUÊNCIA = " << maior_freq << "\n\n";
    for (unsigned i=0; i < vetorSequencias.size(); i++){
        if (vetorSequencias.at(i).second == maior_freq){
            cout << "("
             << vetorSequencias.at(i).second
             << ") :";
            for (unsigned j=0; j < n; j++){
                if (j != n-1){
                    cout << vetorSequencias.at(i).first.at(j) << " -> ";
                }
                else{
                    cout << vetorSequencias.at(i).first.at(j) << endl;
                }
            } 
        }
    }
}