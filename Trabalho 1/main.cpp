/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: main.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include <iostream>
#include <string>
using namespace std;

#include "menu.h"

int main() {
    Menu menu;
    unsigned escolha_menu;

/////////////////// Nomes para os estados e país
string nome_pais = "Brasil";
string nomes_estados[] = {"RJ","SP","BA","MG","ES","GO","PR","SC"};


/////////////////// Inicialização do País e dos Estados com os 10 últimos dados de óbitos

    Nacional pais("Brasil");

    for(unsigned i = 0; i < 8; i++){
       pais.adicionarEstado(nomes_estados[i],"./dados_obitos/"+nomes_estados[i]+".txt");
    }
    pais.atualizarVetorObitos();


/////////////////// Execução do menu com suas respectivas funções
	do {
        
        menu.mostrarMenuPrincipal();
        escolha_menu = menu.receberOpcaoMenu();

        // código extra para limpar o terminal toda vez que o menu é reiniciado
		#ifdef linux
		system("clear");
		#endif
		#ifdef WIN32
		system("cls");
		#endif

		switch (escolha_menu) {
            // MOSTRAR EVOLUÇÃO DO NÚMERO DE ÓBITOS
			case 1:         
                menu.mostrarMediasMoveis(pais);
                break;

            // ESTABILIDADE ATUAL DOS ESTADOS 
			case 2:     
                menu.mostrarEtabilidadeEstados(pais);    
				break;

            // ESTABILIDADE ATUAL DO PAÍS
			case 3:         
                menu.mostrarEstabilidadePais(pais);
				break;
            
            // ESTADOS COM MAIOR E MENOR ESTABILIDADE
			case 4: 
                menu.mostrarMaiorMenorMedia(pais);
				break;
            
            // NÚMERO DE ÓBITOS ACUMULADOS
			case 5:
                menu.mostrarTotalDeObitos(pais);
				break;

            // SAIR DO PROGRAMA
			case 6:
				menu.finalizarPrograma();
                escolha_menu = 7;
				break;

            default:
                escolha_menu = 0;
                cout << "Opção Inválida - Tente Novamente" << endl;
            
	    }

    } while (escolha_menu != 7);

return 0;
}
