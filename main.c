#include <stdio.h>
#include <stdlib.h>
#include "Estruturas_de_Dados.h"
#include "Simulador.h"

int main (){

	FILE *fp=NULL;
	int andar_maximo,numero_de_eventos,carga_maxima, Linha_Do_Tempo = 0, Andar_Inicial = 1;
	TipoFila Fila;
	TipoItem Info;

	Faz_Fila_Vazia(&Fila);
	fp = fopen("arquivo_com_as_entradas.txt","r");

	if(fp == NULL){
		printf("Erro ao tentar abrir o arquivo\n");
	}

	fscanf(fp,"%d %d %d", &andar_maximo,&numero_de_eventos,&carga_maxima);

	while(numero_de_eventos>0){

		fscanf(fp,"%d %d %d",&Info.andar_de_origem,&Info.andar_de_destino,&Info.tempo_de_chamada);
		Enfileira(Info, &Fila);
		numero_de_eventos--;
	}

	Chamou_Elevador_FIFO(&Fila,Linha_Do_Tempo, Andar_Inicial);

	return 0;
}
