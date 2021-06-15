# Sistema de Gerenciamento de Filmes

## Projeto

O programa consiste em um sistema simples para gerenciamente de Filmes onde cada filme é armazenado com o seu nome, produtora e uma nota de avaliação correspondente.

As classes Catálogo, Menu e a struct filme foram implementadas e toda a usabilidade do programa foi mapeada no arquivo main.cpp . 

O programa pode armazenar os filmes em um arquivo txt no seguinte formato:

  - nomeFilme1

  - produtoraFilme1

  - notaFilme1

  -

  - nomeFilme2

  - ...

Onde cada linha armazena um atributo e os dados devem ser armazenados na sequência nome, produtora, double. Além disso, deve-se pular uma linha entre cada filme. Quando o programa é iniciado, o programa lê o arquivo e inicia os filmes válidos contidos nele. E quando o programa é encerrado, ele salva os filmes cadastrados no arquivo.

obs.: As notas deveme estar entre 0 e 10.

## Como utilizar
Com o arquivo de texto pronto, é necessário fazer a compilação dos arquivos através do makefile e, depois, basta executar o programa pela linha de comando informando qual o valor de n (quantas palavras em sequência serão analisadas).

Para testar o programa basta seguir os passos:

 - Abra o terminal nessa pasta e utilize o comando "make" para gerar o executável.

 - Execute o programa através do comando "./main <numeroMaximoFilmes>  <nomeArquivo>". Substitua numeroMaximoFilmes por um valor maior do que 2 e nomeArquivo por uma string contendo um caminho para o arquivo txt referente aos filmes. 

Caso queira remover os arquivos .o e o executável basta realizar o comando "make clean".
