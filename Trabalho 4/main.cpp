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
#include "cadastro.h"
#include "excecao.h"

int main() {
    Menu menu;
    unsigned escolha_menu;
	string nomeBusca;

/////////////////// Inicialização do Cadastro
Cadastro cadastro;
Paciente pacienteAux;



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

            // INSERIR UM NOVO PACIENTE
			case 1:  
				menu.criarPaciente(cadastro);
                break;

            // BUSCAR POR UM PACIENTE CADASTRADO 
			case 2:     
				nomeBusca = menu.receberNomeBusca();					
				try{
					cadastro.busca(nomeBusca);
					}
					catch(const pacienteNaoEncontrado &erro){
						cerr << erro.what();
					}
				cout << "\n \n";
				break;

            // EXIBIR TODOS OS PACIENTES CADASTRADOS
			case 3:         
				cout << "\n|--------------------------------------------------|"
             		 << "\n|              PACIENTES CADASTRADOS               |"
             		 << "\n|--------------------------------------------------|\n";
				cadastro.imprime();
				cout << "\n \n";
				break;
            

            // SAIR DO PROGRAMA
			case 4:
				menu.finalizarPrograma();
                escolha_menu = 5;
				break;

            default:
                escolha_menu = 0;
                cout << "Opção Inválida - Tente Novamente" << endl;
            
	    }

    } while (escolha_menu != 5);

return 0;
}
