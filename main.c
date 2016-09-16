#include <stdio.h>
#include <stdlib.h>
#include "Estruturas_de_Dados.h"
#include "Simulador.h"

int main (){

	int andar_maximo,numero_de_eventos,carga_maxima, Linha_Do_Tempo = 0, Andar_Inicial = 1;
	TipoFila Fila;

	Faz_Fila_Vazia(&Fila);
	Carrega_Fila_com_os_Dados(&Fila);

	Chamou_Elevador_FIFO(&Fila,Linha_Do_Tempo, Andar_Inicial);

	return 0;
}
