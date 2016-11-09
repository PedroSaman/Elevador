#ifndef Simulador
#define Simulador

void Chamou_Elevador_B(TipoFila *Fila, int carga_maxima);
int Chamou_Elevador_FIFO(TipoFila *Fila,int Tempo_Atual,int Andar_Atual);
void Carrega_Fila_com_os_Dados(TipoFila *Fila, char Qual_Arquivo[],int *andar_maximo,int *numero_de_eventos,int *carga_maxima);

#endif
