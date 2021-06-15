# Sistema de Dados - COVID-19

## Projeto

O programa consiste em um sistema simples para visualização de informações referentes aos dados da Covid-19.

## Armazenamento dos Dados
Para o programa funcionar, ele precisa receber dados referentes aos óbitos diários decorrentes da COVID-19.
Os dados são armazenados na pasta dados_obitos em arquivos no formato txt.  

 - Cada estado a ser criado deve ter seu próprio arquivo.

 - Cada linha do arquivo deve indicar o número de óbitos obtidos naquele dia.

 - A primeira linha indica o último dia coletado, a segunda linha indica o penúltimo e assim por diante.

 - O número de dias coletados (linhas no arquivo) deve ser igual para todos os estados.


## Como utilizar
Para realizar os testes, foram escolhidos 8 estados brasileiros e seus respectivos arquivos .txt foram preenchidos com dados reais referentes a 10 dias do mês de abril. (Fonte: https://especiais.g1.globo.com/bemestar/coronavirus/estados-brasil-mortes-casos-media-movel/).

Além disso, foi criada uma classe extra(menu) para utilização visual das funções das classes nacional e estadual permitindo uma melhor interação com o usuário.

Para testar o programa basta seguir os passos:

 - Abra o terminal nessa pasta e utilize o comando "make" para gerar o executável.

 - Execute o programa através de "./main"

 - Escolha a função desejada através do menu digitando o número escolhido

Caso queira remover os arquivos .o e o executável basta realizar o comando "make clean".
