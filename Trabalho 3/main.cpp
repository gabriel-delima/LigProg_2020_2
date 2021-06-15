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

int main(int argc, char *argv[]){
	
	unsigned numMaxFilmes;
	string nomeArquivo;
	
	if(argc != 3){
    cout << "\n-----------\n"
         << "   Erro\n"
         << "-----------\n" 
         << "Uso: "<< argv[0] <<" <numMaxFilmes> <nomeArquivo>\n\n";
      exit(1);
    }

    numMaxFilmes = (unsigned) stoul(argv[1], NULL, 10);

	if (numMaxFilmes<2){
        cout << "\n-----------\n"
             << "   Erro\n"
             << "-----------\n"
             << "O valor de numMaxFilmes deve ser maior ou igual a 2.\n\n";
        exit(1);
    }

	nomeArquivo = argv[2];
	if(nomeArquivo.substr(nomeArquivo.size()-4,4)!= ".txt"){
		cout << "\n-----------\n"
             << "   Erro\n"
             << "-----------\n"
             << " O arquivo deve ter a extensão .txt .\n\n";
		exit(1);
	}

    Menu menu;
    unsigned escolha_menu;

/////////////////// Inicialização do Catálogo
Catalogo catalogo(numMaxFilmes, nomeArquivo);


/////////////////// Execução do menu com suas respectivas funções
	do {
        filme filmeAux;
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
            // INSERIR UM FILME NO CATÁLOGO
			case 1:         
                filmeAux = menu.retornarFilmeParaAdicionar();
				catalogo+=filmeAux;
                break;

            // REMOVER UM FILME DO CATÁLOGO
			case 2:     
				filmeAux = menu.retornarFilmeParaRemover();
                catalogo-=filmeAux;
				break;

            // BUSCAR UM FILME NO CATÁLOGO
			case 3:    
				filmeAux = menu.retornarFilmeParaBuscar();
                catalogo.mostrarFilmeCadastrado(filmeAux);
				break;
            
            // EDITAR UM FILME NO CATÁLOGO
			case 4: 
                menu.editarFilme(catalogo);
				break;
            
            // MOSTRAR CATÁLOGO
			case 5:
                cout << catalogo;
				break;
            
            // MOSTRAR FILME COM MELHOR AVALIAÇÃO
			case 6:
                catalogo.mostrarFilmeMelhorAvaliado();
				break;

            // MOSTRAR FILME COM PIOR AVALIAÇÃO
			case 7:
                catalogo.mostrarFilmePiorAvaliado();
				break;

            // SAIR DO PROGRAMA
			case 8:
				catalogo.salvarFilmesArquivo(nomeArquivo);
				menu.finalizarPrograma();
                escolha_menu = 9;
				break;

            default:
                escolha_menu = 0;
                cout << "Opção Inválida - Tente Novamente" << endl;
	
	    }

    } while (escolha_menu != 9);

return 0;
}
