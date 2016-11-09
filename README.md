Simulador de elevador
Projeto realizado para a matéria de Estrutura de Dados na Universidade de Brasília.

Autores:
	
	Pedro Saman Diogenes Nogueira Cesarino – 15/0144890
	Gabriel Fernandes de Sousa – 15/0126344
	
Objetivos:
 
	Projetar e programar dois simuladores, usando TADs, para um elevador.
 
Descrição:
	O programa foi implementado em módulos. Existem duas lógicas de Funcionamento do elevador, sendo um “First in first out” (FIFO) e outra criada por nós. Foi utilizado um tipo abstrato de dados (TAD), e foi utilizada uma fila para armazenar os dados do arquivo de entradas gerado, e para manipulá-los foram usadas suas respectivas funções (enfileira, desenfileira, etc). Os dados de entrada gerados foram ordenados quanto ao tempo de chamada por meio do Quicksort e só depois foram enfileirados.
	Para a lógica FIFO, o elevador é inicializado no andar um, e então busca o primeiro passageiro que chamou, o deixa em seu andar de destino e só depois busca o próximo passageiro. Após deixar o passageiro no seu destino, ele é retirado da fila e o espaço liberado. Já para a segunda lógica, o elevador pega o máximo de pessoas permitido antes de deixar as pessoas em seus andares de destino, porém se o tempo que o elevador demoraria a deixar todos que já estão dentro for menor que o tempo de chamada do próximo passageiro ele fará isto. Com essa lógica se espera diminuir o tempo de espera de cada passageiro apesar de aumentar o tempo dentro do elevador.
	A segunda lógica, chamada de Lógica B, ficaria completa se os passageiros pudessem descer, enquanto ele enche, quando o andar de saída de um dos passageiros coincidisse com o andar de chamada de um passageiro que está entrando.A medida de tempo para a simulação é o zepslon e equivale a um instante da simulação. O tempo de espera e o tempo dentro do elevador são calculados usando as informações de origem e destino, levando em consideração que o elevador demora um zepslon para percorrer cada andar e que cada passageiro leva um zepslon para entrar e um para sair de dentro do elevador. Os valores calculados são impressos no terminal. O procedimento é repetido até que a fila fique vazia.
	Foi usada a função  getopt para passar argumentos pelo terminal e escolher qual lógica seria executada pelo programa e qual o nome do arquivo com os dados de entrada. 

Módulos:
1) Estrutura_de_dados.c
2) Estrutura_de_dados.h
3) Main.c
4) Makefile
5) Simulador.c
6) Simulador.h
	Foram utilizados três módulos para esse programa, o main com a chamada das funções secundárias e montagem, o “Estrutura_de_dados” é o TAD com as funções, estruturas da fila e o “Simulador” que tem as duas funções com a lógica do elevador e uma função que lê e monta a fila que será usada. Os módulos são integrados utilizando “makefile”. Além desses três módulos existe o “Gerador_de_entradas” que é responsável por gerar os dados utilizados no programa.

TADs:
	Foi utilizada uma fila por meio de apontadores para os dois simuladores utilizados. Em uma fila o item a ser retirado é sempre o primeiro adicionado e a implementação da fila foi feita possuindo uma célula¬ cabeça para facilitar a manipulação da fila. Foi definida também uma função “Módulo” que retorna o valor absoluto do valor dado de parâmetro.
 
Entrada de Dados:
	A entrada de dados é feita por meio de um arquivo gerado pelo módulo ”Gerador_de_entradas”. Nele, é definido o número de andares, a capacidade máxima do elevador e o número de eventos (número de pessoas que utilizarão o elevador), estes ocupando a primeira linha do arquivo de entrada. Restringindo assim, a geração de entradas de modo que uma pessoa não possa chamar o elevador para ir a andares maiores que o andar máximo.
	Cada linha do arquivo de entrada representa um evento, com exceção da primeira linha, como dito acima. Além disso, existem três colunas separadas por espaço à cada linha, a primeira é o andar de origem, a segunda é o andar de destino e a terceira é o tempo de chamada. Os dados foram gerados de modo aleatório usando a função rand, para o tempo de chamada foi imposto um valor superior máximo de 1500. Os andares de origem e destino não podem ser iguais, se forem, já que é gerado aleatoriamente, são gerados novos valores.
	Após gerar os valores de chamada estes são guardados em um vetor de inteiros e esse vetor é ordenado em ordem crescente para só então ser guardados no arquivo texto, o tempo de chamada, andar de origem e andar de destino isto facilita o uso das filas nos simuladores. Para usar outros valores de entradas com configurações diferentes para os simuladores só é necessário mudar as constantes deste arquivo, andar máximo, número de eventos e carga máxima e compilar o programa. 
 
Exemplo:
6 25 5

1 6 1

5 4 3 
...

Significa:
6 é o andar máximo, 25 eventos (pessoas), capacidade máxima 5.
Primeiro evento: andar chamado: 1, andar de destino: 6, no tempo: 1
Segundo evento: andar chamado: 5, andar de destino: 4, no tempo: 3
 
Saída de Dados:
	O programa obterá como resultado o tempo dentro do elevador, de espera e o tempo total de cada passageiro, todos em Zepslons. Ao final do programa, depois que todos os eventos tenham sido processados, será impresso o tempo de execução em segundos e a memória utilizada em Kbytes. Esses resultados serão exibidos no terminal, no formato do exemplo abaixo.

Exemplo:
Tempo de espera: 11 Zepslons Tempo dentro do elevador: 3 Zepslons Tempo 
total: 14 Zepslons
Memória usada em Kbytes: 3140
Tempo de execução: 0.0001700s
 
Como utilizar:

As regras de compilação estão contidas no Makefile, portanto, para compilar só é necessário escrever o seguinte comando no terminal:
➢ make ¬f Makefile

Para compilar o gerador de entradas, basta digitar o seguinte comando:
➢ gcc Gerador_de_entradas.c

Executando¬-se o gerador de entradas, obtém-¬se o arquivo de entrada. Já tendo o executável principal criado, é possível executar o programa usando o comando:
➢ ./Executavel_Principal ¬a nome_do_arquivo.txt ¬t nome_da_logica

Onde  “nome_da_logica” pode ser FIFO ou B. Além disso, pode¬-se usar -¬h para obter ajuda.
 
Ex:
./Executavel_Principal ¬a arquivo_de_entradas.txt ¬t FIFO

Nesse caso, a lógico escolhida foi FIFO e o arquivo que possui os dados de entrada chama-se “arquivo_de_entradas.txt”.
