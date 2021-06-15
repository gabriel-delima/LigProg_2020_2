/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: menu.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "menu.h"

// Função criada para mostrar as operações disponíveis para o usuário
void Menu::mostrarMenuPrincipal() {
    cout << "\n|------------------------------------------------|"
         << "\n|               MENU PRINCIPAL                   |"
         << "\n|------------------------------------------------|"
         << "\n| 1 - INSERIR UM FILME                           |"
         << "\n|------------------------------------------------|"
         << "\n| 2 - REMOVER UM FILME                           |"
         << "\n|------------------------------------------------|"
         << "\n| 3 - BUSCAR UM FILME                            |"
         << "\n|------------------------------------------------|"
         << "\n| 4 - EDITAR UM FILME                            |"
         << "\n|------------------------------------------------|"
         << "\n| 5 - MOSTRAR CATÁLOGO                           |"
         << "\n|------------------------------------------------|"
         << "\n| 6 - MOSTRAR FILMES COM A MELHOR AVALIAÇÃO      |"
         << "\n|------------------------------------------------|"
         << "\n| 7 - MOSTRAR FILMES COM A PIOR AVALIAÇÃO        |"
         << "\n|------------------------------------------------|"
         << "\n| 8 - SAIR DO PROGRAMA                           |"
         << "\n|------------------------------------------------|\n";
};

// Função criada para receber a opção escolhida pelo usuário
unsigned Menu::receberOpcaoMenu(){
    char entrada_usuario[256];
    unsigned escolhaMenu;
    
    cout << "\n Digite a opção desejada:";
    cin  >> entrada_usuario;

    // vai retornar 0 se entrada_usuario nao for do tipo int
    escolhaMenu = atoi(entrada_usuario);
    
    return escolhaMenu;
};

// Função criada para avisar ao usuário que o programa foi finalizado e terminar a execução
void Menu::finalizarPrograma(){
    cout << "\n|------------------------------------------------|"
         << "\n|                FIM DO PROGRAMA                 |"
         << "\n|------------------------------------------------|\n\n";
};


filme Menu::inicializarFilme(){
    filme filmeAux;
    char notaEntrada[256];
    double nota;
    bool notaInvalida = false;
    
    cout <<"   Digite o nome do filme: ";
    cin.ignore();
    getline(cin, filmeAux.nome);

    cout <<"   Digite o nome da produtora: ";
    cin.ignore();
    getline(cin, filmeAux.produtora);
    
    do{
        cout <<"   Digite a nota da avaliação do filme: ";
        cin.ignore();
        cin >> notaEntrada;
        notaInvalida = false;
        try{
            nota = stod(notaEntrada); 
        }
        catch(...){
            cout << "\n|------------------------------------------------|"
                 << "\n|    ERRO - NOTA INVÁLIDA, DIGITE NOVAMENTE      |"
                 << "\n|------------------------------------------------|\n\n";
            notaInvalida = true;
        }

        if((nota<0)||(nota>10)){ 
            cout << "\n|------------------------------------------------|"
                 << "\n|    ERRO - NOTA INVÁLIDA, DIGITE NOVAMENTE      |"
                 << "\n|------------------------------------------------|\n\n";
            notaInvalida = true;
        }
    }while (notaInvalida);
    filmeAux.nota = nota;
    return filmeAux;
}

filme Menu::inicializarFilmeSomenteComNome(){
    filme filmeAux;
    cin.ignore();
    getline(cin, filmeAux.nome);

    filmeAux.produtora = "";
    filmeAux.nota = 0;
    return filmeAux;
}

filme Menu::retornarFilmeParaAdicionar(){
    cout << "\n|----------------------------------------------------|"
         << "\n|                  ADICIONAR FILME                   |"
         << "\n|----------------------------------------------------|\n\n";
    filme filmeAux = inicializarFilme();
    return filmeAux;
}

filme Menu::retornarFilmeParaRemover(){
    cout << "\n|----------------------------------------------------|"
         << "\n|                   REMOVER FILME                    |"
         << "\n|----------------------------------------------------|\n\n"    
         <<"   Digite o nome do filme que deseja remover: ";
    filme filmeAux = inicializarFilmeSomenteComNome();
    return filmeAux;
}

filme Menu::retornarFilmeParaBuscar(){
    cout << "\n|----------------------------------------------------|"
         << "\n|                   BUSCAR FILME                     |"
         << "\n|----------------------------------------------------|\n\n"    
         <<"   Digite o nome do filme que deseja procurar: ";
    filme filmeAux = inicializarFilmeSomenteComNome();
    return filmeAux;
}

void Menu::editarFilme(Catalogo &catalogo){
    filme filmeAux;
    string novaProdutora;
    char notaEntrada[256];
    double novaNota;
    bool notaInvalida = false;
    cout << "\n|----------------------------------------------------|"
         << "\n|                   EDITAR FILME                     |"
         << "\n|----------------------------------------------------|\n\n";
    
    unsigned escolha;
    do {
        
        cout << "\n|--------------------------------------------|"
             << "\n|     ESCOLHA A OPÇÃO QUE DESEJA ALTERAR     |"
             << "\n|--------------------------------------------|"
             << "\n|  1 - PRODUTORA                             |"
             << "\n|  2 - NOTA                                  |"
             << "\n|                                            |"
             << "\n|  3 - CANCELAR ALTERAÇÃO                    |"
             << "\n|--------------------------------------------|\n";
        escolha = receberOpcaoMenu();

        switch (escolha) {
            case 1:
                cout << " Digite o nome do filme que deseja editar: ";
                filmeAux = inicializarFilmeSomenteComNome();
                cout << " Digite o nome da nova produtora: ";
                getline(cin, novaProdutora);

                catalogo(filmeAux,novaProdutora);
                escolha = 4;    
                break;

            case 2:
                cout << " Digite o nome do filme que deseja editar: ";
                filmeAux = inicializarFilmeSomenteComNome();
                do{
                    cout <<" Digite a nova nota de avaliação: ";
                    cin >> notaEntrada;
                    notaInvalida = false;
                    try{
                        novaNota = stod(notaEntrada); 
                    }
                    catch(...){
                        cout << "\n|------------------------------------------------|"
                             << "\n|    ERRO - NOTA INVÁLIDA, DIGITE NOVAMENTE      |"
                             << "\n|------------------------------------------------|\n\n";
                        notaInvalida = true;
                    }
                }while (notaInvalida);    
                catalogo(filmeAux,novaNota);
                escolha = 4;          
                break;
                

            case 3:
                escolha = 4;
                cout << "\n|-------------------------------------|"
                     << "\n|         ALTERAÇÃO CANCELADA         |"
                     << "\n|-------------------------------------|\n\n";
                break;

            default:
                escolha = 0;
                cout << "Opção Inválida - Tente Novamente" << endl;
        }

    }while(escolha!=4);
}
