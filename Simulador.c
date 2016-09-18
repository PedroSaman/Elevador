#include <stdio.h>
#include <stdlib.h>
#include "Estruturas_de_Dados.h"
#include "Simulador.h"

void Chamou_Elevador_Inteligente(TipoFila *Fila, int carga_maxima){

	TipoItem Info, DadoDeSaida;
	TipoFila Fila_de_Espera;
	Apontador AUX;
	int carga_atual, contador, Tempo_Atual=0, Andar_Atual=1, tempo_dentro_do_elevador, tempo_de_espera, var_aux_andar;


	Faz_Fila_Vazia(&Fila_de_Espera);
	carga_atual=0;
	/* Enquanto a fila com os dados de entrada não for vazia */
	while(!(Vazia(*Fila))){
		/* Enquanto a carga dentro do elevador não for máxima */
		while(carga_atual != carga_maxima){
			/* Sair se a fila acabar antes de lotar o elevador */
			if(Vazia(*Fila)){
				break;
			}

			Desenfileira(Fila, &Info);
			carga_atual+=1;

			if(Info.tempo_de_chamada > Tempo_Atual){
				Info.tempo_que_entrou = Modulo(Info.andar_de_origem - Andar_Atual) + Info.tempo_de_chamada;
			}else {
				Info.tempo_que_entrou = Modulo(Info.andar_de_origem - Andar_Atual) 
													+ Info.tempo_de_chamada + (Tempo_Atual - Info.tempo_de_chamada);
			}
			
			Andar_Atual = Info.andar_de_origem;
			Tempo_Atual = Info.tempo_que_entrou+1;
			/* Coloca o passageiro dentro da fila de prioridade para atendimento */
			Enfileira(Info,&Fila_de_Espera);
			
			/* Esta parte do código é a chave para o funcionamento da lógica proposta */
			if((Fila->Frente->Prox)!=NULL){
				/* A variável contador serve para contar o tempo que levaria para levar todos os passageiros atuais */
				/* aos seus andares de destino. A variável var_aux_andar atualiza o andar que o elevador estaria se */ 
				/* fosse deixar os passageiros atuais em seus andares de destino.                                   */
				contador = 0;
				var_aux_andar = Andar_Atual;
				/* Loop que roda em toda a fila Fila_de_Espera */
				for(AUX=Fila_de_Espera.Frente->Prox; AUX!=NULL; AUX=AUX->Prox){
					contador+=(Modulo(AUX->Item.andar_de_destino - var_aux_andar) + 1);
					var_aux_andar = AUX->Item.andar_de_destino;
				}
					/* Comparação crucial, ela vai decidir o que é mais rápido, deixar todos passageiros em seus */ 
					/* andares de destino ou pegar o próximo passageiro. 										 */
					if(Fila->Frente->Prox->Item.tempo_de_chamada > Tempo_Atual+contador){ 
						break;
					}
			}
		}
		carga_atual=0;
		/* Entra aqui quando ou a carga é máxima, ou é mais vantajoso sair antes ou a fila acaba */
		while(!(Vazia(Fila_de_Espera))){
			/* Lida apenas com a fila de espera, o primeiro que entrou é o primeiro a sair */
			Desenfileira(&Fila_de_Espera, &DadoDeSaida);
 			tempo_dentro_do_elevador = Modulo(DadoDeSaida.tempo_que_entrou - Tempo_Atual)
 																 + Modulo(Andar_Atual - DadoDeSaida.andar_de_destino);
			tempo_de_espera = Modulo(DadoDeSaida.tempo_que_entrou - DadoDeSaida.tempo_de_chamada);
			Tempo_Atual +=  (Modulo(Andar_Atual - DadoDeSaida.andar_de_destino) + 1);
			Andar_Atual = DadoDeSaida.andar_de_destino;
			printf("Tempo de espera: %d Zepslons\t Tempo dentro do elevador: %d Zepslons\t Tempo Total: %d\n\n", tempo_de_espera, tempo_dentro_do_elevador,(tempo_de_espera+tempo_dentro_do_elevador));
		}
	}
}

void Carrega_Fila_com_os_Dados(TipoFila *Fila, char Qual_Arquivo[],int *andar_maximo,int *numero_de_eventos,int *carga_maxima){
	FILE *fp=NULL;
	TipoItem Info;
	int numero;

	fp = fopen(Qual_Arquivo ,"r");
	if(fp == NULL){
		printf("Erro ao tentar abrir o arquivo\n");
	}
	
	fscanf(fp,"%d %d %d", andar_maximo, numero_de_eventos, carga_maxima);
	
	numero = *numero_de_eventos;
	
	while(numero>0){

		fscanf(fp,"%d %d %d",&Info.andar_de_origem, &Info.andar_de_destino, &Info.tempo_de_chamada);
		Enfileira(Info, Fila);
		numero--;
	}
	fclose(fp);
}

/* Função recursiva */
int Chamou_Elevador_FIFO(TipoFila *Fila,int Tempo_Atual,int Andar_Atual){
	
	TipoItem Info;
	int tempo_de_espera, tempo_dentro_do_elevador;
	
	if(Vazia(*Fila)){
		return 0;
	}
	
	Desenfileira(Fila, &Info);
	
	tempo_de_espera = Modulo(Info.andar_de_origem - Andar_Atual);
	/*Tempo para o elevador sair do local onde estava ate o andar chamado*/  
	
	if((Info.tempo_de_chamada < Tempo_Atual)) tempo_de_espera += Tempo_Atual - Info.tempo_de_chamada;
	/*Caso alguem chame o elevador antes dele deixar no seu destino quem chamou antes, é necessário adicionar esse valor*/
	
	tempo_dentro_do_elevador = Modulo(Info.andar_de_origem - Info.andar_de_destino);
	/*Tempo entre o andar chamado até o andar de destino*/

	Andar_Atual = Info.andar_de_destino;

	Tempo_Atual = (Info.tempo_de_chamada+tempo_dentro_do_elevador+tempo_de_espera+2);

	printf("Tempo de espera: %d Zepslons\t Tempo dentro do elevador: %d Zepslons\t Tempo Total: %d\n\n", tempo_de_espera, tempo_dentro_do_elevador,(tempo_de_espera+tempo_dentro_do_elevador+2));
	return Chamou_Elevador_FIFO(Fila,Tempo_Atual,Andar_Atual);
	/*Existe esse +2 pois tem q ser levado em consideração aqui o tempo da pessoa entrar e sair do elevador (2 zepslons) 
	  esse tempo não altera o tempo de espera ou o tempo dentro do elevador, mas interfere no tempo de espera das outras
	  pessoas que chamem o elevador enquanto ele leva outro passageiro.*/
}
