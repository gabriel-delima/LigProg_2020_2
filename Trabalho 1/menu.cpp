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
         << "\n| 1 - MOSTRAR EVOLUÇÃO DO NÚMERO DE ÓBITOS       |"
         << "\n|------------------------------------------------|"
         << "\n| 2 - ESTABILIDADE ATUAL DOS ESTADOS             |"
         << "\n|------------------------------------------------|"
         << "\n| 3 - ESTABILIDADE ATUAL DO PAÍS                 |"
         << "\n|------------------------------------------------|"
         << "\n| 4 - ESTADOS COM MAIOR E MENOR ESTABILIDADE     |"
         << "\n|------------------------------------------------|"
         << "\n| 5 - NÚMERO DE ÓBITOS ACUMULADOS                |"
         << "\n|------------------------------------------------|"
         << "\n| 6 - SAIR DO PROGRAMA                           |"
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

// Função criada para mostrar as médias móveis do país e dos estados
void Menu::mostrarMediasMoveis(Nacional pais){
    vector <Estadual> vetorEstados = pais.getVetorEstados();
    string nome;
    vector <unsigned> vetorAux;
    vector <unsigned>vetorMMPais;

    cout << "\n|----------------------------------------------------|"
         << "\n|              Média Móvel Total (país)              |"
         << "\n|----------------------------------------------------|\n\n";
    vetorMMPais = pais.calcularMediaMovelPais();
    cout <<pais.getNome()<< " :\t \t \t        último dia: " << vetorMMPais.at(0) << " mortes.\n";
    cout <<" \t \t \t \t     penúltimo dia: " << vetorMMPais.at(1) << " mortes.\n";
    cout <<" \t \t \t \t antepenúltimo dia: " << vetorMMPais.at(2) << " mortes.\n";

    cout << "\n|----------------------------------------------------|"
         << "\n|           Médias Móveis Por Estado                 |"
         << "\n|----------------------------------------------------|\n\n";
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        nome = vetorEstados.at(i).getNome();
        vetorAux = vetorEstados.at(i).calcularMediaMovel();       
        cout <<nome<< " :\t \t \t \t \túltimo dia: " << vetorAux.at(0) << " mortes.\n";
        cout <<" \t \t \t \t     penúltimo dia: " << vetorAux.at(1) << " mortes.\n";
        cout <<" \t \t \t \t antepenúltimo dia: " << vetorAux.at(2) << " mortes.";
        cout << "\n---------------------------------------------------- \n";
    }

}

// Função criada para mostrar o total de mortes pela Covid no país e em cada estado
void Menu::mostrarTotalDeObitos(Nacional pais){
    vector <Estadual> vetorEstados = pais.getVetorEstados();

    cout << "\n|----------------------------------------------------|"
         << "\n|              TOTAL DE ÓBITOS NO PAÍS               |"
         << "\n|----------------------------------------------------|\n\n"
         << pais.getNome() << " :" << pais.calcularTotalObitos() << "  mortes.\n"
         << "\n|----------------------------------------------------|"
         << "\n|        TOTAL DE ÓBITOS SEPARADO POR ESTADO         |"
         << "\n|----------------------------------------------------|\n\n";
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        cout << vetorEstados.at(i).getNome() << " :" << vetorEstados.at(i).calcularObitosAcumulados() << " mortes.\n";
    }
    
}

// Função criada para mostrar os estados com a maior e a menor média móvel atual
void Menu::mostrarMaiorMenorMedia(Nacional pais){
    vector <Estadual> vetorEstados = pais.getVetorEstados();
    cout << "\n|----------------------------------------------------|"
         << "\n|        ESTADO COM A MAIOR MÉDIA MÓVEL ATUAL        |"
         << "\n|----------------------------------------------------|\n"
         << "    "
         << pais.maiorMediaMovelAtual().getNome() << " ---- "
         << pais.maiorMediaMovelAtual().calcularMediaMovel().at(1)
         << " mortes.  \n";

    
    cout << "\n|----------------------------------------------------|"
         << "\n|       ESTADO COM A MENOR MÉDIA MÓVEL ATUAL         |"
         << "\n|----------------------------------------------------|\n"
         << "    "
         << pais.menorMediaMovelAtual().getNome() << " ---- "
         << pais.menorMediaMovelAtual().calcularMediaMovel().at(1)
         << " mortes.  \n\n\n";
}

// Função criada para mostrar as estabilidades dos estados dividos em alta, estável e baixa
void Menu::mostrarEtabilidadeEstados(Nacional pais){
    vector <Estadual> vetorEstados = pais.getVetorEstados();
    vector <vector < vector <float>>> vetorEstabilidades = pais.calcularEstabilidadeEstados();
    string nome;
    float estabilidade;
    unsigned indice;

    // Mostrando estados em alta
    cout << "\n|----------------------------------------------------|"
         << "\n|                 Estados em Alta                    |"
         << "\n|----------------------------------------------------|\n";
    for (unsigned i=0; i<vetorEstabilidades.at(0).size();i++){
        indice = (unsigned) vetorEstabilidades.at(0).at(i).at(0);
        estabilidade = vetorEstabilidades.at(0).at(i).at(1);
        nome = vetorEstados.at(indice).getNome();
        cout << "   "
             <<nome
             << " :\t  estabilidade atual: " << setprecision(2) << fixed << estabilidade << "% maior.\n";
        cout << " ---------------------------------------------------- \n";
    }

    // Mostrando estados em estabilidade
    cout << "\n|----------------------------------------------------|"
         << "\n|              Estados em Estabilidade               |"
         << "\n|----------------------------------------------------|\n"; 
    for (unsigned i=0; i<vetorEstabilidades.at(1).size();i++){
        indice = (unsigned) vetorEstabilidades.at(1).at(i).at(0);
        estabilidade = vetorEstabilidades.at(1).at(i).at(1);
        nome = vetorEstados.at(indice).getNome();
        cout << "   "
             <<nome;
        if (estabilidade<0){
            cout << " :\t  estabilidade atual: " << setprecision(2) << fixed << estabilidade*-1 << "% menor.\n";
        }
        else{
            cout << " :\t  estabilidade atual: " << setprecision(2) << fixed << estabilidade << "% maior.\n";
        }
        cout << " ---------------------------------------------------- \n";
    } 

    // Mostrando estados em baixa
    cout << "\n|----------------------------------------------------|"
         << "\n|                 Estados em Baixa                   |"
         << "\n|----------------------------------------------------|\n";
    for (unsigned i=0; i<vetorEstabilidades.at(2).size();i++){
        indice = (unsigned) vetorEstabilidades.at(2).at(i).at(0);
        estabilidade = vetorEstabilidades.at(2).at(i).at(1);
        nome = vetorEstados.at(indice).getNome();
        cout << "   "
             <<nome
             <<" :\t  estabilidade atual: " << setprecision(2) << fixed << estabilidade * -1 << "%  menor.\n";
        cout << " ---------------------------------------------------- \n";
    }
}

// Função criada para mostrar a estabilidade do país e sua categoria
void Menu::mostrarEstabilidadePais(Nacional pais){
    float estabilidade = pais.calcularEstabilidade();
    cout << "\n|----------------------------------------------------|"
         << "\n|            Estabilidade atual do país              |"
         << "\n|----------------------------------------------------|\n\n";
    // caso em que o país está em alta
    if (estabilidade >= 1.1){
        cout << "    "
             << pais.getNome()
             << " está em alta com "
             << setprecision(2) << fixed << (estabilidade -1)*100
             << "% a mais na média móvel atual. \n\n";
    }

    // caso em que o país estável
    else if (estabilidade < 1.1 && estabilidade > 0.9 ){
        if(estabilidade>0.9 && estabilidade<1){
        cout << pais.getNome()
             << " está estável com "
             << setprecision(2) << fixed << (1 - estabilidade)*100
             << "% a menos na média móvel atual. \n\n";
        }
        else{
        cout << pais.getNome()
             << " está estável com "
             << setprecision(2) << fixed << (estabilidade -1)*100
             << "% a mais na média móvel atual. \n\n";
        }
    }

    // caso em que o país está em baixa
    else if (estabilidade <= 0.9){
        cout << pais.getNome()
             << " está em baixa com "
             << setprecision(2) << fixed << (1 - estabilidade)*100
             << "% a menos na média móvel atual. \n\n";
        
    }
}