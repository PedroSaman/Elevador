#include <stdio.h>
#include <stdlib.h>
#include "Estruturas_de_Dados.h"

int main (){

	FILE *fp=NULL;
	int andar_maximo,numero_de_eventos,carga_maxima;
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

	/*CHAMAR O SIMULADOR AQUI, provavelmente vai retornar um arquivo com o tempo de espera e o tempo dentro do elevador 
	para cada passageiro por linha. Aqui deverá ser lido o arquivo*/

	return 0;
}
