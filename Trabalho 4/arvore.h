/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: arvore.h
 * Autor: Gabriel de Lima Moura - 118045099 
*/
#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include <string>

using namespace std;

//////////////////// DEFINIÇÃO DA ESTRUTURA DOS NÓS 
template <class tipoValor>
struct No{
        tipoValor valor;
        No* noEsquerda;
        No* noDireita;
        
        // Construtores
        No();
        No(tipoValor novoValor);
};


//////////////////// DEFINIÇÃO DA CLASSE ÁRVORE
template <class tipoValor> 
class Arvore{

    private:
        No <tipoValor> *raiz;
        No <tipoValor> *insercaoRecursiva(No <tipoValor> *noInicio, const tipoValor &novoValor);  
        No <tipoValor> *buscaRecursiva(No <tipoValor> *noInicio, const tipoValor &valorBusca);
        void printRecursivo(No <tipoValor> *noInicio);
        void remocaoRecursiva(No <tipoValor> *noInicio);

    public:
        Arvore();
        ~Arvore();
        No <tipoValor> *operator+=(const tipoValor &novoValor);
        No <tipoValor> *operator()(const tipoValor &valorBusca);
        
        friend ostream &operator<<(ostream &out, Arvore <tipoValor> &arvoreImprimir){
            if (arvoreImprimir.raiz == nullptr) {
                cout << "A arvore está vazia!" << endl;
            }
            else {
                arvoreImprimir.printRecursivo(arvoreImprimir.raiz);
            }
            return out;
        };
        friend ostream &operator<<(ostream &out, const No <tipoValor>  &noImprimir){
            cout << noImprimir.valor << endl;
            return out;
        };

};
//////////////////// NÓ

//inicialização de um nó vazio
template <class tipoValor>
No<tipoValor>::No(){
    this->valor = NULL;
    this->noEsquerda = nullptr;
    this->noDireita = nullptr;
};

//inicialização de um nó com conteúdo(valor)
template <class tipoValor>
No<tipoValor>::No(tipoValor novoValor){
    this->valor = novoValor;
    this->noEsquerda = nullptr;
    this->noDireita = nullptr;
};



//////////////////// ÁRVORE
template<class tipoValor> 
Arvore<tipoValor>::Arvore() {
    raiz = nullptr;
}

template<class tipoValor> 
Arvore<tipoValor>::~Arvore() {
    if (raiz != nullptr){
        remocaoRecursiva(raiz);
    }
}


template<class tipoValor> 
No <tipoValor> *Arvore<tipoValor>::operator+=(const tipoValor &novoValor){
    
    // Verifica se o nó atual é vazio e, em caso positivo, insere o novo valor aqui
    if (raiz == nullptr){
        raiz = new No <tipoValor>(novoValor);
        return raiz;
    }

    // Caso contrário, executa a função recursiva de inserção
    else{
        return insercaoRecursiva(raiz, novoValor);
    }
}


template<class tipoValor> 
No <tipoValor> *Arvore<tipoValor>::insercaoRecursiva(No <tipoValor> *noInicio, const tipoValor &novoValor){
    
    // verifica se há uma falha (valor já existente neste nó)
    if (noInicio->valor == novoValor){
        return nullptr;
    }

    // caminha para o nó esquerdo
    if (noInicio->valor < novoValor) {
        if (noInicio->noEsquerda == nullptr) {
            noInicio->noEsquerda = new No <tipoValor>(novoValor);
            return noInicio->noEsquerda;
        }
        else {
            return insercaoRecursiva(noInicio->noEsquerda, novoValor);
        }
    }

    // caminha para o nó direito
    else
    {
        if (noInicio->noDireita == nullptr) {
            noInicio->noDireita = new No <tipoValor>(novoValor);
            return noInicio->noDireita;
        }
        else {
            return insercaoRecursiva(noInicio->noDireita, novoValor);
        }
    }
}


template<class tipoValor> 
No <tipoValor> *Arvore<tipoValor>::operator()(const tipoValor &valorBusca){
    return buscaRecursiva(raiz, valorBusca);

}

template<class tipoValor> 
No <tipoValor> *Arvore<tipoValor>::buscaRecursiva(No <tipoValor> *noInicio, const tipoValor &valorBusca){
    // Verifica se o nó atual é vazio e, em caso positivo, retorna um ponteiro vazio
    if (noInicio == nullptr){
        return nullptr;
    }

    // Verifica se o nó procurado é o atual
    else if (noInicio->valor == valorBusca){
        return noInicio;
    }

    // caminha para direita
    else if (noInicio->valor > valorBusca){
        return buscaRecursiva(noInicio->noDireita, valorBusca);
    }
    
    // caminha para esquerda
    else{
        return buscaRecursiva(noInicio->noEsquerda, valorBusca);
    }

}


// faz a impressão dos nós em ordem crescente recursivamente ( considerando noDireito < noAtual < esquerda) 
template<class tipoValor> 
void Arvore<tipoValor>::printRecursivo(No <tipoValor> *noInicio) {

    // verifica se há algum conteúdo menor que o atual (direita)
    if (noInicio->noDireita != nullptr) {
        printRecursivo(noInicio->noDireita);
    }

    std::cout << noInicio->valor;

    // verifica se há algum conteúdo maior que o atual (esquerda)
    if (noInicio->noEsquerda != nullptr) {
        printRecursivo(noInicio->noEsquerda);
    }
}

template<class tipoValor>
void Arvore<tipoValor>::remocaoRecursiva(No <tipoValor> *noInicio){
    if(noInicio->noDireita != nullptr){
        remocaoRecursiva(noInicio->noDireita);
    }
    if(noInicio->noEsquerda != nullptr){
        remocaoRecursiva(noInicio->noEsquerda);
    }
    delete noInicio;
}

#endif