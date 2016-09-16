#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estruturas_de_Dados.h"
#include "Simulador.h"

int main(int argc, char *argv[]){

	int andar_maximo,numero_de_eventos,carga_maxima, Linha_Do_Tempo = 0, Andar_Inicial = 1, x;
	TipoFila Fila;
	struct rusage uso_inicio, uso_final;    
	struct timeval inicio, fim;             /*Variáveis para calcular tempo de execução e uso de memória*/

	getrusage(RUSAGE_SELF, &uso_inicio);
	gettimeofday(&inicio, NULL);

	Faz_Fila_Vazia(&Fila);
	
	while((x = getopt(argc, argv, "a:t:h"))!=-1){
		switch(x){
			case 'a':
					Carrega_Fila_com_os_Dados(&Fila,optarg);
				break;
			case 't':
					if (strcmp (optarg,"FIFO") == 0){
						printf("------------------ Você escolheu o Simulador FIFO -------------------\n\n");
						Chamou_Elevador_FIFO(&Fila,Linha_Do_Tempo, Andar_Inicial);
					}/*else if(optarg == 'OUTRO') FUNCAO COM A LÓGICA OUTRO*/
				break;
			case 'h':
					printf("***************************************************\n***********************Ajuda***********************\n***************************************************\n");
					printf("\t -t Para escolher qual simulador usar. EX: -f FIFO\t");
					printf("Disponiveis: FIFO e OUTRO\n");
					printf("\t -a Para escolher qual arquivo.txt com os dados de entrada. EX: -a nome_do_arquivo ");
					printf("OBS: O arquivo tem que estar no mesmo diretório\n");
					printf("\t -h Para mostrar ajuda\n");
				break;			
			default:
                printf("Opção invalida ou faltando argumento, digite -h para mostrar ajuda\n") ;
                return -1 ;
		}	
	}
	getrusage(RUSAGE_SELF, &uso_final);
	gettimeofday(&fim, NULL);
	printf("\n\n\tMemória usada em Kbytes: %ld\n", uso_final.ru_maxrss);
	printf("\tTempo de execução %.7lfs\n", difftime(fim.tv_sec, inicio.tv_sec)
									+ (double) (fim.tv_usec - inicio.tv_usec)/1000000);

	return 0;
}
