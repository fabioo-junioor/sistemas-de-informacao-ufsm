#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "esparsa.h"

Lista *cria_lista(void){
	return NULL;
}

Esparsa *cria_esparsa(int lin, int col){
	Esparsa* e = (Esparsa*)malloc(sizeof(Esparsa));
	e->linhas = lin;
	e->colunas = col;
	e->prim = NULL;
	return e;
}

int **aloca_matriz(int lin, int col){
	int i, **mat;
	mat = (int**)malloc(lin*sizeof(int*));
	for(i=0; i<lin; i++){
		mat[i] = (int*)malloc(col*sizeof(int));
	}
	if(mat==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
	}
	return mat;
}

void zerar_matriz(int **mat, int lin, int col){
	int i=0, j=0;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			mat[i][j] = 0;
		}
    }
}

void preenche_matriz(int **mat, int lin, int col){
	int op=1, linha=0, coluna=0, valor=0;
	printf("> Insercao de valores apartir da linha e coluna <\n");
	while(op){
		printf("Informe a linha que deseja inserir o valor? ");
		scanf("%d", &linha);
		printf("Informe a coluna que deseja inserir o valor? ");
		scanf("%d", &coluna);
		printf("Informe o valor a ser inserido? ");
		scanf("%d", &valor);
		printf("\n");
		
		if((linha>=0) && (linha<=(lin-1))){
			if((coluna>=0) && (coluna<=(col-1))){
				mat[linha][coluna] = valor;
				
			}else{
				printf("Coluna nao existe 'Informe o numero da coluna entre [%d] e [%d]'\n", 0, (col-1));
			}
		}else{
			printf("Linha nao existe 'Informe o numero da linha entre [%d] e [%d]'\n", 0, (lin-1));
		}
		printf("0 - Sair 1 - Continuar: ");
		scanf("%d", &op);
		printf("\n");
	}
}

int verifica_matriz(int **mat, int lin, int col, Esparsa *es){
	int i=0, j=0, valor=0;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			if(mat[i][j]!=0){
				valor = mat[i][j];
				preenche_lista(es, i, j, valor);
				valor = 0;
			}
		}
	}
	return 1;
}

void preenche_lista(Esparsa *es, int lin, int col, int valor){
	Lista *ponteiro, *ant;
	ant = NULL;
	
	ponteiro = (Lista*)malloc(sizeof(Lista));	
	ponteiro->linha = lin;
	ponteiro->coluna = col;
	ponteiro->info = valor;
	
	if(es->prim==NULL){
		es->prim = ponteiro;
		
	}else{
		Lista *atual = es->prim;
		while(atual->prox!=NULL){
			atual = atual->prox;
		}
		atual->prox = ponteiro;
		
	}
}

void imprimir_esparsa(Esparsa* es){
	Lista* ponteiro;
	if(ponteiro==NULL){
		printf("Lista vazia\n\n");
		return;
		
	}
	printf("> Esparsa <\n");
	printf("[%d] linhas [%d] colunas [%d] prim\n", es->linhas, es->colunas, es->prim->info);
	for(ponteiro=es->prim; ponteiro!=NULL; ponteiro=ponteiro->prox){
		printf("Linha [%d] coluna [%d] valor [%d]", ponteiro->linha, ponteiro->coluna, ponteiro->info);
		printf("\n");
		
	}
	printf("\n");
}

void imprime_matriz_pos(int linha, int coluna, Esparsa* es){
	Lista* ponteiro;
	if((linha>=0 && linha<es->linhas) && (coluna>=0 && coluna<es->colunas)){
		for(ponteiro=es->prim; ponteiro!=NULL; ponteiro=ponteiro->prox){
			if((ponteiro->linha==linha) && (ponteiro->coluna==coluna)){
				printf("Valor: [%d] \n", ponteiro->info);
				return;
				
			}
		}
		printf("Valor 0! (nao salvo na lista)\n");
		
	}else{
		printf("Linha ou coluna incorreta!\n");
		
	}
}

void somatorio_matriz(int lin, Esparsa* es){
	int i=0, j=0, soma=0;
	Lista* ponteiro;
	if((lin>=0) && (lin<es->linhas)){
		for(ponteiro=es->prim; ponteiro!=NULL; ponteiro=ponteiro->prox){
			if(ponteiro->linha==lin){
				soma += ponteiro->info;
								
			}
		}
		printf("Somatorio da linha [%d] eh [%d]\n", lin, soma);
	}else{
		printf("Linha incorreta!\n");
		
	}
}

int percentual_nao_nulos(Esparsa* es){
	int cont=0;
	Lista* ponteiro;
	for(ponteiro=es->prim; ponteiro!=NULL; ponteiro=ponteiro->prox){
		cont += 1;
			
	}
	return cont;
}

void calcula_percentual(int qtd, int lin, int col){
	float percentual;
	percentual = qtd*100;
	percentual = percentual/(lin*col);
	
	printf("%.2f por cento de elementos nao nulos", percentual);
	printf("\n\n");
}

void free_matriz(int m, int **mat){
    int i=0;
    for(i=0; i<m; i++){
        free(mat[i]);
    }
    free(mat);
}

void esparsa_free(Esparsa *es){
	Lista *ponteiro = es->prim;
	while(ponteiro!=NULL){
		Lista *t = ponteiro->prox;
		free(ponteiro);
		ponteiro = t;
	}
	free(es);
}
