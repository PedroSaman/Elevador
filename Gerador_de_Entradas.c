/*Código usado apenas para gerar os dados de entrada das simulações, gera um arquivo texto com a seguinte configuração:
	A primeira linha tem na respectiva ordem: andar máximo, número de eventos e carga máxima
	As próximas linhas serão da seguinte forma: 
	1ª coluna -> andar de origem    	2ª coluna -> andar de destino 		3ª coluna -> tempo de chamada
	cada linha é um evento independente, a ordem do arquivo texto é indiferente, o que importa é o tempo de chamada				*/

#include <stdio.h>
#include <stdlib.h>

#define ANDAR_MAXIMO 25
#define NUMERO_DE_EVENTOS 100
#define CARGA_MAXIMA 5 /*5 pessoas*/

/* Constantes auto explicativas, NUMERO_DE_EVENTOS dita quantas pessoas vão chamar o elevador na simulação
	 melhor começar com valores pequenos para facilitar a depuração*/

int main(){
	
	FILE *fp=NULL;
	int andar_de_origem, andar_de_destino, tempo_de_chamada, pessoas_a_entrar;

	/* O tempo de chamada de cada pessoa é limitado ao momento 1000 da simulação*/
	
	fp = fopen("arquivo_com_as_entradas.txt","w+");
	fprintf(fp,"%d %d %d\n", ANDAR_MAXIMO, NUMERO_DE_EVENTOS, CARGA_MAXIMA);
	pessoas_a_entrar = NUMERO_DE_EVENTOS;
	while(pessoas_a_entrar>0){
		/* Gera um número aleatório para o andar que foi chamado entre o intervalo [1,ANDAR_MAXIMO] */
		andar_de_origem = (rand() % ANDAR_MAXIMO) +1;
		do {
			
			andar_de_destino = (rand() % ANDAR_MAXIMO) +1;
		}while(andar_de_origem==andar_de_destino);

		tempo_de_chamada = rand() % 1000;

		fprintf(fp,"%d %d %d\n", andar_de_origem, andar_de_destino, tempo_de_chamada);
		
		pessoas_a_entrar--;
	}
	
	fclose(fp);	
return 0;
}
