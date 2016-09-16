#include <stdio.h>
#include <stdlib.h>
#include "Estruturas_de_Dados.h"
#include "Simulador.h"

void Carrega_Fila_com_os_Dados(TipoFila *Fila){
	FILE *fp=NULL;
	int andar_maximo, numero_de_eventos, carga_maxima;
	TipoItem Info;

	fp = fopen("arquivo_com_as_entradas.txt","r");
	if(fp == NULL){
		printf("Erro ao tentar abrir o arquivo\n");
	}
	fscanf(fp,"%d %d %d", &andar_maximo, &numero_de_eventos, &carga_maxima);

	while(numero_de_eventos>0){

		fscanf(fp,"%d %d %d",&Info.andar_de_origem, &Info.andar_de_destino, &Info.tempo_de_chamada);
		Enfileira(Info, Fila);
		numero_de_eventos--;
	}

}

int Chamou_Elevador_FIFO(TipoFila *Fila, int Linha_Do_Tempo, int Andar_inicial){
	
	TipoItem Info;
	int tempo_de_espera, tempo_dentro_do_elevador, Andar_Atual, Tempo_Atual;
	
	if(Vazia(*Fila)){
		return 0;
	}
	
	Desenfileira(Fila, &Info);
	
	tempo_de_espera = (Info.andar_de_origem - Andar_inicial);
	/*Tempo para o elevador sair do local onde estava ate o andar chamado*/  
	
	tempo_de_espera = Modulo(tempo_de_espera);
	/*Garante que vai ser positivo*/
	
	if((Info.tempo_de_chamada < Linha_Do_Tempo)) tempo_de_espera += Linha_Do_Tempo - Info.tempo_de_chamada;
	/*Caso alguem chame o elevador antes dele deixar quem chamou antes no seu destino é necessário adicionar esse valor*/
	
	tempo_dentro_do_elevador = Info.andar_de_origem - Info.andar_de_destino;
	/*Tempo entre o andar chamado até o andar de destino*/
	
	tempo_dentro_do_elevador = Modulo(tempo_dentro_do_elevador);
	/*Garante que vai ser positivo*/

	Andar_Atual = Info.andar_de_destino;

	Tempo_Atual = (Info.tempo_de_chamada+tempo_dentro_do_elevador+tempo_de_espera+2);

	printf("Tempo de espera: %d Zepslons\t Tempo dentro do elevador: %d Zepslons\n", tempo_de_espera, tempo_dentro_do_elevador);
	return Chamou_Elevador_FIFO(Fila,Tempo_Atual,Andar_Atual);
	/*O segundo arguemto é a linha do tempo, existe esse +2 pois tem q ser levado em consideração aqui o tempo da pessoa
	entrar e sair do elevador (2 zepslons) esse tempo não altera o tempo de espera ou o tempo dentro do elevador, mas 
	interfere no tempo de espera das outras pessoas que chamem o elevador enquanto ele leva outro passageiro.*/
}
