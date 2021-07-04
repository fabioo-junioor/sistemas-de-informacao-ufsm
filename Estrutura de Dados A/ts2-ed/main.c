#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "restaurante.h"


int main() {
	int linha=0, coluna=0, vagas_estacionamento=0;
	
	Restaurante **res;
	
	Fila_espera_cliente* f;
	Fila_estacionamento* e;	
	Pilha_cliente* pc;
	Pilha_cliente_aux* pcx;	
	Pilha_estacionamento* pe;
	Pilha_estacionamento_aux* pex;
	
	f = fila_espera_cliente_cria();
	e = fila_estacionamento_cria();
	
	printf("Qual numero de linhas? ");
	scanf("%d", &linha);
	printf("Qual numero de colunas? ");
	scanf("%d", &coluna);
	printf("Quantas vagas tem no estacionamento? ");
	scanf("%d", &vagas_estacionamento);
	
	res = aloca_matriz(linha, coluna);
	preencher_matriz(res, linha, coluna);
	
	
	menu(res, linha, coluna, vagas_estacionamento, f, pc, pcx, e, pe, pex);
	
	
	free_matriz(res, linha);
	libera_fila_espera_cliente(f);
	libera_fila_estacionamento(e);
	//libera_pilha_cliente(pc);	//libera dentro do menu
	//libera_pilha_cliente_aux(pcx);	//libera dentro do menu
	//libera_pilha_estacionamento(pe);	//libera dentro do menu
	//libera_pilha_estacionamento_aux(pex);	//libera dentro do menu
	
	
	system("PAUSE");
	return 0;
}
