/*Código usado apenas para gerar os dados de entrada das simulações, gera um arquivo binário com as informações: andar e tempo
de chamada, para ler a informação deve-se usar while fread != 0 e ler dois inteiros um de cada vez em que o primeiro será 
o andar e o segundo o tempo de chamada. */

#include <stdio.h>
#include <stdlib.h>

#define ANDAR_MAXIMO 100
#define NUMERO_DE_PESSOAS_MAXIMO 10
#define NUMERO_DE_EVENTOS 5
/* Constantes auto explicativas, NUMERO_DE_EVENTOS dita quantas pessoas vão chamar o elevador na simulação
melhor começar com valores pequenos para facilitar a depuração	*/

int main(){
	
	FILE *fp;
	int andar_chamado, tempo_de_chamada, pessoas_a_entrar;
	/* O tempo de chamada de cada pessoa é limitado ao momento 1000 da simulação*/
	
	fp = fopen("arquivo_com_as_entradas.txt","w");
	pessoas_a_entrar = NUMERO_DE_EVENTOS;
	while(pessoas_a_entrar>0){
		/* Gera um número aleatório para o andar que foi chamado entre o intervalo [1,ANDAR_MAXIMO] */
		andar_chamado = (rand() % ANDAR_MAXIMO) +1;
		tempo_de_chamada = rand() % 1000;
		fwrite(&andar_chamado,sizeof(int),1,fp);
		fwrite(&tempo_de_chamada,sizeof(int),1, fp);
		pessoas_a_entrar--;
	}
	
	fclose(fp);	
return 0;
}
