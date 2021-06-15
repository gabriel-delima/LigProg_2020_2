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
         << "\n| 1 - INSERIR UM NOVO PACIENTE                   |"
         << "\n|------------------------------------------------|"
         << "\n| 2 - BUSCAR POR UM PACIENTE CADASTRADO          |"
         << "\n|------------------------------------------------|"
         << "\n| 3 - EXIBIR TODOS OS PACIENTES CADASTRADOS      |"
         << "\n|------------------------------------------------|"
         << "\n| 4 - SAIR DO PROGRAMA                           |"
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


void Menu::criarPaciente(Cadastro &cadastro){
    unsigned escolha;
    string nomeEntrada;
    string idadeEntrada;
    unsigned int idade;
    string descricaoEntrada;
    string diasInternadosEntrada;
    unsigned int diasInternados;
    string numConsultasEntrada;
    unsigned int numConsultas;
    string nomeExameEntrada;
    bool entradaInvalida = false;
    string exameRealizadoEntrada;
    bool exameRealizado;

    Paciente_Internacao *pacienteInternacaoAux;
    Paciente_Consulta *pacienteConsultaAux;
    Paciente_Exame *pacienteExameAux;

    do {
        
        cout << "\n|--------------------------------------------------|"
             << "\n|     ESCOLHA O TIPO DE PACIENTE QUE DESEJA CRIAR  |"
             << "\n|--------------------------------------------------|"
             << "\n|  1 - Paciente em Internação                      |"
             << "\n|  2 - Paciente para Consulta                      |"
             << "\n|  3 - Paciente para Exame                         |"
             << "\n|                                                  |"
             << "\n|  4 - CANCELAR OPERAÇÃO                           |"
             << "\n|--------------------------------------------------|\n";
        escolha = receberOpcaoMenu();

        switch (escolha) {
            case 1:
                cout << " Digite o nome do Paciente: ";
                cin.ignore();
                getline(cin, nomeEntrada);
                do{
                    cout << " Digite a idade do Paciente: ";
                    cin >> idadeEntrada;
                    entradaInvalida = false;
                    try{
                        idade = stoul(idadeEntrada); 
                    }
                    catch(...){
                        cout << "\n|------------------------------------------------|"
                             << "\n|     ERRO - IDADE INVÁLIDA, DIGITE NOVAMENTE    |"
                             << "\n|------------------------------------------------|\n\n";
                        entradaInvalida = true;
                    }
                }while (entradaInvalida);  
                cout << " Digite a descrição do Paciente: ";
                cin.ignore();
                getline(cin, descricaoEntrada);
                do{
                    cout << " Digite o número de dias que o paciente está internado: ";
                    cin >> diasInternadosEntrada;
                    entradaInvalida = false;
                    try{
                        diasInternados = stoul(diasInternadosEntrada); 
                    }
                    catch(...){
                        cout << "\n|------------------------------------------------|"
                             << "\n|    ERRO - ENTRADA INVÁLIDA, DIGITE NOVAMENTE   |"
                             << "\n|------------------------------------------------|\n\n";
                        entradaInvalida = true;
                    }
                }while (entradaInvalida);    
                escolha = 5;   
                pacienteInternacaoAux = new Paciente_Internacao; 
                pacienteInternacaoAux->setNome(nomeEntrada);
                pacienteInternacaoAux->setIdade(idade);
                pacienteInternacaoAux->setDescricao(descricaoEntrada);
                pacienteInternacaoAux->setDiasInternados(diasInternados);

                if (pacienteInternacaoAux->getNome() != ""){
					try{
					cadastro.insere(*pacienteInternacaoAux);
                    cout << *pacienteInternacaoAux;
					}
					catch(const pacienteJaInserido &erro){
						cerr << erro.what();
					}
				}
                cout << "\n";

                break;

            case 2:
                cout << " Digite o nome do Paciente: ";
                cin.ignore();
                getline(cin, nomeEntrada);
                do{
                    cout << " Digite a idade do Paciente: ";
                    cin >> idadeEntrada;
                    entradaInvalida = false;
                    try{
                        idade = stoul(idadeEntrada); 
                    }
                    catch(...){
                        cout << "\n|------------------------------------------------|"
                             << "\n|     ERRO - IDADE INVÁLIDA, DIGITE NOVAMENTE    |"
                             << "\n|------------------------------------------------|\n\n";
                        entradaInvalida = true;
                    }
                }while (entradaInvalida);  
                cout << " Digite a descrição do Paciente: ";
                cin.ignore();
                getline(cin, descricaoEntrada);
                do{
                    cout << " Digite o número de consultas que o paciente já realizou: ";
                    cin >> numConsultasEntrada;
                    entradaInvalida = false;
                    try{
                        numConsultas = stoul(numConsultasEntrada); 
                    }
                    catch(...){
                        cout << "\n|------------------------------------------------|"
                             << "\n|    ERRO - ENTRADA INVÁLIDA, DIGITE NOVAMENTE   |"
                             << "\n|------------------------------------------------|\n\n";
                        entradaInvalida = true;
                    }
                }while (entradaInvalida);    
                escolha = 5;   
                pacienteConsultaAux = new Paciente_Consulta; 
                pacienteConsultaAux->setNome(nomeEntrada);
                pacienteConsultaAux->setIdade(idade);
                pacienteConsultaAux->setDescricao(descricaoEntrada);
                pacienteConsultaAux->setNumConsultas(numConsultas);  

                if (pacienteConsultaAux->getNome() != ""){
					try{
					cadastro.insere(*pacienteConsultaAux);
                    cout << *pacienteConsultaAux;
					}
					catch(const pacienteJaInserido &erro){
						cerr << erro.what();
					}
				}
                cout << "\n";

                break;
            

            case 3:
                cout << " Digite o nome do Paciente: ";
                cin.ignore();
                getline(cin, nomeEntrada);
                do{
                    cout << " Digite a idade do Paciente: ";
                    cin >> idadeEntrada;
                    entradaInvalida = false;
                    try{
                        idade = stoul(idadeEntrada); 
                    }
                    catch(...){
                        cout << "\n|------------------------------------------------|"
                             << "\n|     ERRO - IDADE INVÁLIDA, DIGITE NOVAMENTE    |"
                             << "\n|------------------------------------------------|\n\n";
                        entradaInvalida = true;
                    }
                }while (entradaInvalida);  
                cout << " Digite a descrição do Paciente: ";
                cin.ignore();
                getline(cin, descricaoEntrada);
                cout << " Digite o nome do Exame designado: ";
                cin.ignore();
                getline(cin, nomeExameEntrada);
                do{
                    cout << " Digite 1 se o exame já foi realizado e 2 caso contrário: ";
                    cin >> exameRealizadoEntrada;
                    if (exameRealizadoEntrada == "1"){
                        exameRealizado = true;
                        entradaInvalida = false;
                    }
                    else if (exameRealizadoEntrada == "2"){
                        exameRealizado = false;
                        entradaInvalida = false;
                    }
                    else {
                        cout << "\n|------------------------------------------------|"
                             << "\n|     ERRO - OPÇÃO INVÁLIDA, DIGITE NOVAMENTE    |"
                             << "\n|------------------------------------------------|\n\n";
                        entradaInvalida = true;
                    }
                    
                }while (entradaInvalida);    
                escolha = 5;   
                pacienteExameAux = new Paciente_Exame; 
                pacienteExameAux->setNome(nomeEntrada);
                pacienteExameAux->setIdade(idade);
                pacienteExameAux->setDescricao(descricaoEntrada);
                pacienteExameAux->setNomeExame(nomeExameEntrada);
                pacienteExameAux->setExameRealizado(exameRealizado);   

				if (pacienteExameAux->getNome() != ""){
					try{
					cadastro.insere(*pacienteExameAux);
                    cout << *pacienteExameAux;
					}
					catch(const pacienteJaInserido &erro){
						cerr << erro.what();
					}
				}
                cout << "\n";
                break;
                

            case 4:
                escolha = 5;
                cout << "\n|-------------------------------------|"
                     << "\n|         ALTERAÇÃO CANCELADA         |"
                     << "\n|-------------------------------------|\n\n";
                break;

            default:
                escolha = 0;
                cout << "Opção Inválida - Tente Novamente" << endl;
        }

    }while(escolha!=5);
}




string Menu::receberNomeBusca(){
    string nomeEntrada;
    cout << "\n|--------------------------------------------------|"
         << "\n|     ESCOLHA O TIPO DE PACIENTE QUE DESEJA CRIAR  |"
         << "\n|--------------------------------------------------|\n \n";
    cout << "  Digite o nome do Paciente que deseja pesquisar: ";
                cin.ignore();
                getline(cin, nomeEntrada);
    return nomeEntrada;
}


