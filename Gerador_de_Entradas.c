/*  Código usado apenas para gerar os dados de entrada das simulações, gera um arquivo texto com a seguinte configuração:
	A primeira linha tem na respectiva ordem: andar máximo, número de eventos e carga máxima
	As próximas linhas serão da seguinte forma: 
	1ª coluna -> andar de origem    	2ª coluna -> andar de destino 		3ª coluna -> tempo de chamada
	cada linha é um evento independente, a ordem do arquivo texto é indiferente, o que importa é o tempo de chamada				*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANDAR_MAXIMO 12
#define NUMERO_DE_EVENTOS 25
#define CARGA_MAXIMA 5 /*5 pessoas*/

/* Constantes auto explicativas, NUMERO_DE_EVENTOS dita quantas pessoas vão chamar o elevador na simulação
	 melhor começar com valores pequenos para facilitar a depuração*/

/*Função serve apenas para ordenar o vetor de tempo de chamadas para facilitar implementação do simulador*/
void quick(int vet[], int esq, int dir){
    int pivo = esq,i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vet[j] < vet[pivo]){
         ch = vet[j];
         while(j > pivo){    
            vet[j] = vet[j-1];
            j--;
         }
         vet[j] = ch;
         pivo++;        
        }  
    }
    if(pivo-1 >= esq){
        quick(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quick(vet,pivo+1,dir);
    }
 }

int main(){
	
	FILE *fp=NULL;
	int i,andar_de_origem, andar_de_destino, tempo_de_chamada[NUMERO_DE_EVENTOS+1], pessoas_a_entrar;

	/* O tempo de chamada de cada pessoa é limitado ao momento 1000 da simulação*/

	fp = fopen("arquivo_com_as_entradas.txt","w+");
	fprintf(fp,"%d %d %d\n", ANDAR_MAXIMO, NUMERO_DE_EVENTOS, CARGA_MAXIMA);
	pessoas_a_entrar = NUMERO_DE_EVENTOS;

	srand(time(NULL));

	for (i=0;i<pessoas_a_entrar;i++){
		tempo_de_chamada[i] = rand() % 1000;
	} /*Serve para gerar tempos de chamada, facilitando a ordenação para q o menor tempo venha primeiro*/
	
	quick(tempo_de_chamada,0,NUMERO_DE_EVENTOS);
	i=0;
	while(pessoas_a_entrar>0){
		/* Gera um número aleatório para o andar que foi chamado entre o intervalo [1,ANDAR_MAXIMO] */
		andar_de_origem = (rand() % ANDAR_MAXIMO) +1;
		do {
			
			andar_de_destino = (rand() % ANDAR_MAXIMO) +1;
		}while(andar_de_origem==andar_de_destino);

		fprintf(fp,"%d %d %d\n", andar_de_origem, andar_de_destino, tempo_de_chamada[i]);
		
		i++;
		pessoas_a_entrar--;
	}
	
	fclose(fp);	
return 0;
}
