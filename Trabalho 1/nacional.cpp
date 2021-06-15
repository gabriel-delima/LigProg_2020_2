/*
 * Universidade Federal do Rio de Janeiro
 * EEL670 - Linguagens de Programação
 * Prof.: Miguel Elias Mitre Campista
 * 
 * Arquivo: nacional.cpp
 * Autor: Gabriel de Lima Moura - 118045099 
*/

#include "nacional.h"

Nacional::Nacional(string nome_pais){
    setNome(nome_pais);
}

void Nacional::setNome(string nome_pais){
    nome = nome_pais;
}

string Nacional::getNome(){
    return nome;
}

// adiciona um estado no vetor de estados
void Nacional::adicionarEstado(string nome_estado, string arquivo_obitos){
    if (procuraEstadoNoVetor(nome_estado) == true) {
        cout << "\n ERRO - "<<nome_estado<<" já pertence aos Estados de "<<nome<<".";
    }
    else {
        Estadual estado(nome_estado,arquivo_obitos);
        vetorEstados.push_back(estado);
    }
}

// retorna true se existir um estado com esse nome e falso caso contrário
bool Nacional::procuraEstadoNoVetor(string nome_estado){
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        if (vetorEstados.at(i).getNome() == nome_estado){
            return true;
        }
    } 
    return false;
}

// Procura um estado com esse nome no vetor de estados e o remove
void Nacional::removerEstado(string nome_estado){
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        if (vetorEstados.at(i).getNome() == nome_estado){
            vetorEstados.erase (vetorEstados.begin() + i);
            i = vetorEstados.size();
        }
        else{
            cout << "\n ERRO - "<<nome_estado<<" não pertence aos Estados de "<<nome<<".";
        }

    }
}

// retorna o vetor de estados
vector <Estadual> Nacional::getVetorEstados(){
    return vetorEstados;
}

// retorna o vetor de óbitos
vector <unsigned> Nacional::getVetorObitos(){
    return vetorObitos;
}

// Atualiza o vetor contendo os óbitos diários do país decorrente do somatório dos óbitos diários dos estados
void Nacional::atualizarVetorObitos(){
    vector <unsigned> vetorAux;
    unsigned soma = 0;
    for (unsigned i = 0; i < vetorEstados.at(0).getVetorObitos().size(); i++){
        soma = 0;
        for (unsigned j = 0; j < vetorEstados.size(); j++){
            soma += vetorEstados.at(j).getVetorObitos().at(i);
        }
        vetorAux.push_back(soma);
    }
    vetorObitos = vetorAux;
}

// Retorna um vetor no seguinte formato:
//   índice 0 -> vetor com todos os estados em alta, ele estará no formato: 
//                          índice 0 -> indica a posição do estado em questão no vetor de estados desse país
//                          índice 1 -> indica a estabilidade atual desse estado em %
//
//   índice 1 -> vetor com todos os estados estáveis, seguindo o formato mostrado.
//  
//   índice 2 -: vetor com todos os estados em baixa, seguindo o formato mostrado.
// 
// A divisão das categorias é dada através de:      alta -> no mínimo 10% a mais na média móvel atual
//                                                  estável -> entre -10% e +10% na média móvel atual
//                                                  baixa  > no mínimo 10% a menos na média móvel atual
vector <vector < vector <float>>> Nacional::calcularEstabilidadeEstados(){
    float estabilidade;
    vector <vector < vector <float>>> vetorEstabilidades;
    vector <vector <float>> vetorAlta, vetorEstavel, vetorBaixa;
    vector <float> vetorAux;

    for (unsigned i = 0; i < vetorEstados.size(); i++){
        estabilidade = vetorEstados.at(i).calcularEstabilidade();
        vetorAux.clear();
        vetorAux.push_back(i);

        // Caso em que o estado está em alta (ao menos 10% maior)
        if (estabilidade >= 1.1){
            vetorAux.push_back((estabilidade - 1)*100);
            vetorAlta.push_back(vetorAux);
        }

        // Caso em que o estado está estável ( variação menor que 10%)
        else if (estabilidade < 1.1 && estabilidade > 0.9){
            if (estabilidade>1){
                vetorAux.push_back((estabilidade - 1)*100);
            }
            else{
                vetorAux.push_back((1 - estabilidade)*-100);
            }
            vetorEstavel.push_back(vetorAux);
        }

        // Caso em que o estado está em baixa (ao menos 10% menor)
        else if (estabilidade <= 0.9){
            vetorAux.push_back((1 - estabilidade)*-100);
            vetorBaixa.push_back(vetorAux);
        }
    }
    vetorEstabilidades.push_back(vetorAlta);
    vetorEstabilidades.push_back(vetorEstavel);
    vetorEstabilidades.push_back(vetorBaixa);
    return vetorEstabilidades;
}

// retorna a estabilidade atual do país considerando as 2 últimas médias móveis
float Nacional::calcularEstabilidade(){
    vector <unsigned> mediaMovel = calcularMediaMovelPais();

    float estabilidade = ((float) mediaMovel.at(0)) /  ((float) mediaMovel.at(1));

    return estabilidade;
}

// Retorna um vetor com as médias móveis no país. O vetor seguirá o formato:
//      índice 0 -> média móvel do último dia
//      índice 1 -> média móvel do penúltimo dia
//      índice 2 -> média móvel do antepenúltimo dia
vector <unsigned> Nacional::calcularMediaMovelPais(){
    unsigned somaUltimoDia = 0, somaPenultimoDia = 0, somaAntePenultimoDia = 0;

    for (unsigned i = 0; i < vetorObitos.size(); i++){

        if (i<7){
            somaUltimoDia += vetorObitos.at(i);
        }
        
        if (i>0 && i<8){
            somaPenultimoDia += vetorObitos.at(i);
        }

        if (i>1 && i<9){
            somaAntePenultimoDia += vetorObitos.at(i);
        }

        if (i>=9){
            i = vetorObitos.size();
        }
    }
    unsigned mediaUltimoDia = somaUltimoDia/7;
    unsigned mediaPenultimoDia = somaPenultimoDia/7;
    unsigned mediaAntePenultimoDia = somaAntePenultimoDia/7;
    
    vector <unsigned> vetorRetorno;
    
    vetorRetorno.push_back(mediaUltimoDia);
    vetorRetorno.push_back(mediaPenultimoDia);
    vetorRetorno.push_back(mediaAntePenultimoDia);

    return vetorRetorno;
}

// retorna o somatório de todas as mortes no país
unsigned Nacional::calcularTotalObitos(){
    unsigned soma = 0;
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        soma += vetorEstados.at(i).calcularObitosAcumulados();
    }
    return soma;
}

// retorna o estado com a maior media móvel atual
Estadual Nacional::maiorMediaMovelAtual(){
    unsigned maiorMedia, index = 0;
    maiorMedia = vetorEstados.at(0).calcularMediaMovel().at(1);
    
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        if(vetorEstados.at(i).calcularMediaMovel().at(1) > maiorMedia){
            maiorMedia = vetorEstados.at(i).calcularMediaMovel().at(1);
            index = i;
        }
    }

    return vetorEstados.at(index);
}

// retorna o estado com a menor media móvel atual
Estadual Nacional::menorMediaMovelAtual(){
    unsigned menorMedia, index = 0;
    menorMedia = vetorEstados.at(0).calcularMediaMovel().at(1);
    
    for (unsigned i = 0; i < vetorEstados.size(); i++){
        if(vetorEstados.at(i).calcularMediaMovel().at(1) < menorMedia){
            menorMedia = vetorEstados.at(i).calcularMediaMovel().at(1);
            index = i;
        }
    }

    return vetorEstados.at(index);
}