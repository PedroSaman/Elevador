#include <stdio.h>
#include <stdlib.h>
#include "Estruturas_de_Dados.h"

/*Implementação para funções da fila*/

void Faz_Fila_Vazia(TipoFila *Fila){
	/*Recebe como argumento o nome de uma fila*/
	
	Fila->Frente = (Apontador) malloc(sizeof(Celula));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
}

int Vazia(TipoFila Fila){
	/*Testa se a fila é ou não vazia, retorna 1 se está vazia e 0 se não*/

	return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila){
	/*Recebe de argumento um item x para enfileirar e em qual fila*/
	
	Fila->Tras->Prox = (Apontador) malloc(sizeof(Celula));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->Item = x;
	Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item){
	/*Recebe de argumento de qual fila está esvaziando e uma variavel para armazenar o valor desenfileirado*/
	Apontador q;

	if (Vazia(*Fila)) { 
		printf("Erro fila está vazia\n");
	return;}

	q = Fila->Frente;
	Fila->Frente = Fila->Frente->Prox;
	*Item = Fila->Frente->Item;
	free(q);
}

/*Implementaão de funções extras*/

int Modulo(int Numero){
	/*Retorna o módulo do número dado*/
	if(Numero<0){
		return Numero*=-1;
	}else return Numero;
}
