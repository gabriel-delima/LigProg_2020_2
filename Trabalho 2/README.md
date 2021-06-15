# Análise de texto através de grafos

## Projeto

O programa consiste em um sistema simples para montagem de um Grafo contendo as palavras e sequências de palavras retiradas de um arquivo .txt

As classes Grafo, Vertice e Arestas foram implementadas e toda a usabilidade do programa foi mapeada no arquivo main.cpp . 

O texto a ser analisade será retirado de um arquivo .txt e, para isso, deve existir o arquivo com o noeme "texto.txt" na pasta do projeto.

## Como utilizar
Com o arquivo de texto pronto, é necessário fazer a compilação dos arquivos através do makefile e, depois, basta executar o programa pela linha de comando informando qual o valor de n (quantas palavras em sequência serão analisadas).

Para testar o programa basta seguir os passos:

 - Abra o terminal nessa pasta e utilize o comando "make" para gerar o executável.

 - Execute o programa através do comando "./main < n >". Substitua n por um valor inteiro entre 2 e 15. 

Caso queira remover os arquivos .o e o executável basta realizar o comando "make clean".
