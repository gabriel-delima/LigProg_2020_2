/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: catalogo.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "catalogo.h"


Catalogo::Catalogo(unsigned numMaxFilmesEnt, string nomeArquivo ){
    numMaxFilmes = numMaxFilmesEnt;
    inicializarFilmesArquivo(nomeArquivo);
}

void Catalogo::inicializarFilmesArquivo(string nomeArquivo){
    ifstream arquivo(nomeArquivo);
    string linha;
    if (!arquivo.is_open()){
        cout << "Arquivo nao existe. \n";
    }
    else{
        filme filmeAux;
        unsigned index = 0;
        while (getline(arquivo,linha)){
            if (linha != ""){
                index++;
                switch (index){
                case 1:
                    filmeAux.nome = linha;
                    break;
                case 2:
                    filmeAux.produtora = linha;
                    break;
                case 3:
                    try{
                        filmeAux.nota = stod(linha);
                        if((filmeAux.nota>=0)&&(filmeAux.nota<=10)){ 
                            (*this)+=filmeAux;
                        }
                        index = 0;
                    }
                    catch(...){
                      index = 0;
                    }
                    break;

                default:
                    index = 0;
                    break;
                }
            }
        }
    }
    arquivo.close();
}


void Catalogo::salvarFilmesArquivo(string nomeArquivo){
    ofstream arquivo(nomeArquivo);
    for (unsigned i=0; i<vetorFilmes.size(); i++){
        arquivo << vetorFilmes.at(i).nome << "\n"
                << vetorFilmes.at(i).produtora << "\n"
                << vetorFilmes.at(i).nota << "\n\n";
    }
    arquivo.close(); 
}


void Catalogo::mostrarFilmeCadastrado(filme filmeBusca){
    filme *ponteiroFilme = (*this)(filmeBusca);

    if (ponteiroFilme == NULL){
        cout << "\n|------------------------------------------------|"
             << "\n|             FILME NÃO ENCONTRADO               |"
             << "\n|------------------------------------------------|\n\n";
    }
    else {
        cout << "\n------------------ Filme Encontrado \n"
             << *ponteiroFilme;
    }
}


void Catalogo::mostrarFilmeMelhorAvaliado(){
    double maiorNota = 0, notaAux = 0;

    for(unsigned i=0; i<vetorFilmes.size();i++){
        notaAux = vetorFilmes.at(i).nota;
        if (notaAux > maiorNota){
            maiorNota = notaAux;
        }
    }
    cout << "\n|----------------------------------------------------|"
         << "\n|          FILMES COM A MELHOR AVALIAÇÃO             |"
         << "\n|----------------------------------------------------|\n\n";
    for (unsigned i=0; i<vetorFilmes.size();i++){

        if (vetorFilmes.at(i).nota == maiorNota){
            cout << vetorFilmes.at(i) << endl;
        }
    }
}


void Catalogo::mostrarFilmePiorAvaliado(){
    double menorNota = 10, notaAux = 0;

    for(unsigned i=0; i<vetorFilmes.size();i++){
        notaAux = vetorFilmes.at(i).nota;
        if (notaAux < menorNota){
            menorNota = notaAux;
        }
    }
    cout << "\n|----------------------------------------------------|"
         << "\n|           FILMES COM A PIOR AVALIAÇÃO              |"
         << "\n|----------------------------------------------------|\n\n";
    for (unsigned i=0; i<vetorFilmes.size();i++){

        if (vetorFilmes.at(i).nota == menorNota){
            cout << vetorFilmes.at(i) << endl;
        }
    }
}


/////////// OPERADORES 
ostream &operator<<(ostream &out, const Catalogo &catalogo){
    cout << "\n|-------------------------------------|"
         << "\n|             CATÁLOGO                |"
         << "\n|-------------------------------------|\n\n";
    
    for (unsigned i=0; i < catalogo.vetorFilmes.size(); i++){
        cout << "------------------ Filme " << i+1 << endl
             << "  Nome: " << catalogo.vetorFilmes.at(i).nome
             << "\n  Produtora: " << catalogo.vetorFilmes.at(i).produtora
             << "\n  Nota: " << catalogo.vetorFilmes.at(i).nota << endl;
    }
    return out;
}


void Catalogo::operator+=(filme filme){
    if(vetorFilmes.size() < numMaxFilmes){
        vetorFilmes = vetorFilmes+=filme;
    }
    else{
        cout << "\n|------------------------------------------------|"
             << "\n|             O CATÁLOGO ESTÁ CHEIO              |"
             << "\n|------------------------------------------------|"
             << "\n|     NÃO É POSSÍVEL ADICIONAR NOVOS FILMES      |"
             << "\n|------------------------------------------------|\n\n";
    }
}


void Catalogo::operator-=(filme filme){
    vetorFilmes = vetorFilmes-=filme;
}


filme *Catalogo::operator()(filme filmeBusca){
    filme *ponteiroAux;

    for(unsigned i=0; i<vetorFilmes.size(); i++){
        if( filmeBusca == vetorFilmes.at(i)){
            ponteiroAux = &vetorFilmes.at(i);
            return ponteiroAux;
        }
    }
    return NULL;
}


filme *Catalogo::operator()(filme filmeBusca,string produtora){
    filme *ponteiroAux;

    for(unsigned i=0; i<vetorFilmes.size(); i++){
        if( filmeBusca == vetorFilmes.at(i)){
            vetorFilmes.at(i).produtora = produtora;
            ponteiroAux = &vetorFilmes.at(i);
            cout << "\n------------------ Filme Editado \n"
                 << *ponteiroAux;
            return ponteiroAux;
        }
    }
    cout << "\n|------------------------------------------------|"
         << "\n|             FILME NÃO ENCONTRADO               |"
         << "\n|------------------------------------------------|\n\n";
    return NULL;
}


filme *Catalogo::operator()(filme filmeBusca,double nota){
    filme *ponteiroAux;

    for(unsigned i=0; i<vetorFilmes.size(); i++){
        if( filmeBusca == vetorFilmes.at(i)){
            vetorFilmes.at(i).nota = nota;
            ponteiroAux = &vetorFilmes.at(i);
            cout << "\n------------------ Filme Editado \n"
                 << *ponteiroAux;
            return ponteiroAux;
        }
    }
    cout << "\n|------------------------------------------------|"
         << "\n|             FILME NÃO ENCONTRADO               |"
         << "\n|------------------------------------------------|\n\n";
    return NULL;
}