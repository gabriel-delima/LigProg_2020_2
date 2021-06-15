# Sistema de Gerenciamento de Pacientes Hospitalares

## Projeto

O programa consiste em um sistema simples para gerenciamento de Pacientes que podem ser divididos em 3 categorias: Internação, Consulta e Exame. Os pacientes foram definidos como uma classe genérica que é usada como padrão para classes de pacientes derivados. Eles são armazenados na classe cadastro, que utiliza uma estrutura de árvore binária para armazenar todos os pacientes. A árvore foi definida como uma classe template que pode armazenar nós de qualquer tipo de dado ( no nosso caso, pacientes ). Além disso, os nós foram definidos como uma struct e a relação entre eles é dada através de ponteiros.

As classes Cadastro, Paciente, Árvore, Menu e a struct Nó foram implementadas em arquivos separados e toda a usabilidade do programa foi mapeada no arquivo main.cpp . 

O programa permite a inserção de um novo paciente, a busca por um paciente já cadastrado e a exibição de todos os pacientes cadastrados no momento.

## Como utilizar
Para gerar o executável, é necessário fazer a compilação dos arquivos através do makefile e, depois, basta executar o programa pela linha de comando e, através do menu, executar os comandos desejados.

Para testar o programa basta seguir os passos:

 - Abra o terminal nessa pasta e utilize o comando "make" para gerar o executável.

 - Execute o programa através do comando "./main".

 - Interaja com o menu e realize as operações desejadas.

Caso queira remover os arquivos .o e o executável basta realizar o comando "make clean".
