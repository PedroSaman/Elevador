/*Código usado apenas para gerar os dados de entrada das simulações, gera um arquivo texto com a seguinte configuração:
	1º coluna -> andar chamado			2º coluna -> tempo de chamada
	cada linha é um evento independente, a ordem do arquivo texto é indiferente, o que importa é o tempo de chamada				*/

#include <stdio.h>
#include <stdlib.h>

#define int ANDAR_MAXIMO 100
#define int NUMERO_DE_PESSOAS_MAXIMO 10
#define int NUMERO_DE_EVENTOS 5
/* Constantes auto explicativas, NUMERO_DE_EVENTOS dita quantas pessoas vão chamar o elevador na simulação
	 melhor começar com valores pequenos para facilitar a depuração*/

int main(){
	
	FILE *fp
	int andar_chamado, tempo_de_chamada;
	/* O tempo de chamada de cada pessoa é limitado ao momento 1000 da simulação*/
	
	fp = fopen("arquivo_com_as_entradas.txt","w");
	
	while(numero_de_eventos>0){
		/* Gera um número aleatório para o andar que foi chamado entre o intervalo [1,ANDAR_MAXIMO] */
		andar_chamado = (rand() % ANDAR_MAXIMO) +1;
		tempo_de_chamada = rand() % 1000;
		fwrite(andar_chamado,1,sizeof(int),fp);
		fwrite(tempo_de_chamada,1,sizeof(int),fp);
	}

return 0;
}
