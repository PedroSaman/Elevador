#ifndef EstruturaDaPilha
#define EstruturaDaPilha

/*Definição dos tipos para uma fila usando apontadores*/

typedef struct Celula_str *Apontador;
typedef int TipoChave;

typedef struct TipoItem {
	TipoChave Chave;
} TipoItem;

typedef struct Celula_str {
	TipoItem Item;
	Apontador Prox;
} Celula;

typedef struct TipoFila {
	Apontador Frente, Tras;
} TipoFila;

void Faz_Fila_Vazia(TipoFila *Fila);

int Vazia(TipoFila Fila);

void Enfileira(TipoItem x, TipoFila *Fila);

void Desenfileira(TipoFila *Fila, TipoItem *Item);

#endif
