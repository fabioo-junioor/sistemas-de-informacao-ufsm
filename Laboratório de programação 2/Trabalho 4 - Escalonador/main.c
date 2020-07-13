#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "escalonador.h"

int main() {
	int op=1, temp=0, cont_t_chegada=0;
	
	Fila* f;
	Pilha* p;
	Fila_processados* fp;
	Pilha_aux* px;
	Fila_aux* fx;
	
	f = fila_cria();
	p = pilha_cria();
	fp = fila_processados_cria();
	px = pilha_aux_cria();
	fx = fila_aux_cria();
	
	while(op){
		cont_t_chegada += 1;
		insere_fila(f, cont_t_chegada);
		printf("\n");
		printf("0 - sair, 1 - continuar-> ");
		scanf("%d", &op);
		printf("\n");
		
	}
	printf("Informe o tempo fixo (TP): ");
	scanf("%d", &temp);
	
		
	busca(f, p, temp, cont_t_chegada, fp, px, fx);
		
	printf("\n");
	imprime_fila_processados(fp);	
	
	libera_fila(f);
	libera_pilha(p);	
	//libera_fila_aux(fx);
	//libera_pilha_aux(px);
	libera_fila_processados(fp);
	
	system("PAUSE");
	return 0;
	
}
