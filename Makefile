# make -f Makefile 
# ./Executaval_Principal

all: Executaval_Principal
Executaval_Principal: Estruturas_de_Dados.o main.o 
	gcc -o Executaval_Principal Estruturas_de_Dados.o main.o

Estruturas_de_Dados.o: Estruturas_de_Dados.c
	gcc -o Estruturas_de_Dados.o -c Estruturas_de_Dados.c -W

main.o: main.c Estruturas_de_Dados.h
	gcc -o main.o -c main.c -W
