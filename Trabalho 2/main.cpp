/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: main.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "grafo.h"

#define VALOR_MAXIMO_N      15

int main(int argc, char *argv[]){

    unsigned n;

    if(argc != 2){
    cout << "\n-----------\n"
         << "   Erro\n"
         << "-----------\n" 
         << "Uso: "<< argv[0] <<" <n> \n";
      exit(1);
    }

    n = (unsigned) stoul(argv[1], NULL, 10);

    if ((n<2) || (n > VALOR_MAXIMO_N)){
        cout << "\n-----------\n"
             << "   Erro\n"
             << "-----------\n"
             << "O valor de n deve estar entre 2 e " << VALOR_MAXIMO_N << "\n\n";
        exit(1);
    }

    Grafo grafo;
    grafo.preencherGrafo();

    cout << "\n\n------------------------------------------- \n"
         << " Vértices Registrados:  (<freq>) <palavra> \n"
         << "-------------------------------------------" << endl;
    grafo.mostrarVertices();

    cout << "\n\n---------------------------------------------------------- \n"
         << " Arestas Registradas:  <vertice1> -> <peso> -> <vertice2> \n"
         << "----------------------------------------------------------" << endl;
    grafo.mostrarArestas();

    cout << "\n\n--------------------------- \n"
         << " Palavras mais utilizadas: \n"
         << "---------------------------" << endl;
    grafo.mostrarVerticeMaiorFrequencia();

    cout << "\n\n---------------------------------------- \n"
         << " Sequência de 2 palavras mais utilizada: \n"
         << "----------------------------------------" << endl;
    grafo.mostrarMaiorSequenciaDuasPalavras();

    cout << "\n\n---------------------------------------- \n"
         << " Sequência de "<<n<<" palavras mais utilizada: \n"
         << "----------------------------------------" << endl;
    grafo.mostrarMaiorSequenciaNPalavras(n);

    cout<< "\n\n";

    return 0;
}