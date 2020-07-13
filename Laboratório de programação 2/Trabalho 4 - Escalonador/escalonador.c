#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "escalonador.h"

Fila* fila_cria(void){
	Fila* f = (Fila*)malloc(sizeof(Fila));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

Pilha* pilha_cria(void){
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

Fila_processados* fila_processados_cria(void){
	Fila_processados* fp = (Fila_processados*)malloc(sizeof(Fila_processados));
	fp->ini = NULL;
	fp->fim = NULL;
	return fp;
}

Pilha_aux* pilha_aux_cria(void){
	Pilha_aux* px = (Pilha_aux*)malloc(sizeof(Pilha_aux));
	px->prim = NULL;
	return px;
}

Fila_aux* fila_aux_cria(void){
	Fila_aux* fx = (Fila_aux*)malloc(sizeof(Fila_aux));
	fx->ini = NULL;
	fx->fim = NULL;
	return fx;
}

void insere_fila(Fila* f, int cont_t_chegada){
	char processo[8], id[3];
	int vl_processo=0, temp=0;
	
	printf("Informe o id: ");
	scanf(" %[^\n]", id);
	printf("Informe  o tempo de execucao: ");
	scanf("%d", &temp);
	printf("Informe o tipo ' sistema/usuario ': ");
	scanf(" %[^\n]", processo);
		
	vl_processo = valida_processo(processo);
	if(vl_processo){	
		Lista_fila* n = (Lista_fila*)malloc(sizeof(Lista_fila));
		strcpy(n->id, id);
		n->temp_chegada = cont_t_chegada;
		n->temp_execucao = temp;
		strcpy(n->tipo, processo);
		
		n->prox = NULL;	
		
		if(f->fim != NULL){
			f->fim->prox = n;
			
		}else{
			f->ini = n;
					
		}
		
		f->fim = n;
		
	}else{
		printf("Tipo invalido!\n");
		exit(1);
		
	}
}

void insere_pilha(Pilha* p, char* id, int chegada, int tempo, char* tipo){
	Lista_pilha* n = (Lista_pilha*)malloc(sizeof(Lista_pilha));
	strcpy(n->id, id);
	n->temp_chegada = chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	n->prox = p->prim;
	p->prim = n;
	
}

void insere_fila_temp_execusao(Fila* f, char* id, int chegada, int tempo, char* tipo, int cont_t_chegada){
	Lista_fila* n = (Lista_fila*)malloc(sizeof(Lista_fila));
	strcpy(n->id, id);
	n->temp_chegada = cont_t_chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	n->prox = NULL;		
	if(f->fim != NULL){
		f->fim->prox = n;
		
	}else{
		f->ini = n;	
		
	}
	
	f->fim = n;
	
}

void insere_fila_processados(Fila_processados* fp, char* id, int chegada, int tempo, char* tipo){
	Lista_processados* n = (Lista_processados*)malloc(sizeof(Lista_processados));
	strcpy(n->id, id);
	n->temp_chegada = chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	
	n->prox = NULL;		
	if(fp->fim != NULL){
		fp->fim->prox = n;
		
	}else{
		fp->ini = n;
				
	}
	
	fp->fim = n;
	
}

void insere_pilha_aux(Pilha_aux* px, char* id, int chegada, int tempo, char* tipo){
	Lista_pilha_aux* n = (Lista_pilha_aux*)malloc(sizeof(Lista_pilha_aux));
	strcpy(n->id, id);
	n->temp_chegada = chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	n->prox = px->prim;
	px->prim = n;
	
}

void insere_fila_aux(Fila_aux* fx, char* id, int chegada, int tempo, char* tipo){
	Lista_fila_aux* n = (Lista_fila_aux*)malloc(sizeof(Lista_fila_aux));
	strcpy(n->id, id);
	n->temp_chegada = chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	
	n->prox = NULL;		
	if(fx->fim != NULL){
		fx->fim->prox = n;
		
	}else{
		fx->ini = n;
				
	}
	
	fx->fim = n;
	
}

void realoca_fila_insere_1(Fila* f, char* id, int chegada, int tempo, char* tipo){
	Lista_fila* n = (Lista_fila*)malloc(sizeof(Lista_fila));
	strcpy(n->id, id);
	n->temp_chegada = chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	n->prox = NULL;		
	if(f->fim != NULL){
		f->fim->prox = n;
		
	}else{
		f->ini = n;	
		
	}
	
	f->fim = n;
	
}

void realoca_fila_insere_2(Fila* f, char* id, int chegada, int tempo, char* tipo){
	Lista_fila* n = (Lista_fila*)malloc(sizeof(Lista_fila));
	strcpy(n->id, id);
	n->temp_chegada = chegada;
	n->temp_execucao = tempo;
	strcpy(n->tipo, tipo);
	
	n->prox = NULL;		
	if(f->fim != NULL){
		f->fim->prox = n;
		
	}else{
		f->ini = n;	
		
	}
	
	f->fim = n;
	
}

void busca(Fila* f, Pilha* p, int temp, int cont_t_chegada, Fila_processados* fp, Pilha_aux* px, Fila_aux* fx){
	int valida_processo=0, valida_exec=0, aux=0, cont=0, verifica_fila=1;
	cont = cont_t_chegada;
	Lista_fila* n;
	
	while(verifica_fila!=0){
		aux = 0;
		valida_processo = 0;
		valida_exec = 0;
		for(n=f->ini; n!=NULL; n=n->prox){
			valida_processo = procura_processo(f, n->temp_chegada);
			valida_exec = valida_tem_exe(f, n->temp_chegada, temp);
			if(valida_processo){
					insere_pilha(p, n->id, n->temp_chegada, n->temp_execucao, n->tipo);
					exclui_fila(f);					
				
			}else{
				if(valida_exec){
					insere_fila_processados(fp, n->id, n->temp_chegada, n->temp_execucao, n->tipo);
					exclui_fila(f);
					busca_fila(f, fx);
					break;		
				
				}else{
					aux = n->temp_execucao - temp;
					cont += 1;
					insere_fila_temp_execusao(f, n->id, n->temp_chegada, aux, n->tipo, cont);
					insere_fila_processados(fp, n->id, n->temp_chegada, (n->temp_execucao - aux), n->tipo);
					exclui_fila(f);
					busca_fila(f, fx);
					break;
					
				}		
			}
		}
		imprime_pilha(p);		
		
		busca_pilha(p, px);
		libera_pilha(p);
		p = pilha_cria();
		
		libera_fila(f);
		f = fila_cria();

		realoca_fila_1(px, f);		
		realoca_fila_2(fx, f);
				
		
		if(valida_processo){
			processa(f, fp, temp, cont, aux);
		
		}
		
		verifica_fila = verifica_fila_vazia(f);
		
		libera_fila_aux(fx);
		fx = fila_aux_cria();	
		
		libera_pilha_aux(px);
		px = pilha_aux_cria();
				
	}
}

void processa(Fila* f, Fila_processados* fp, int temp, int cont_t_chegada, int aux2){
	int valida_exec=0, aux=0, verifica_fila=0;
	Lista_fila* n;
	for(n=f->ini; n!=NULL; n=n->prox){
		valida_exec = valida_tem_exe(f, n->temp_chegada, temp);
		if(valida_exec){
			insere_fila_processados(fp, n->id, n->temp_chegada, (n->temp_execucao - aux2), n->tipo);
			exclui_fila(f);
			break;
			
		}else{
			aux = n->temp_execucao - temp;
			verifica_fila = contador_fila(f);
			insere_fila_temp_execusao(f, n->id, n->temp_chegada, aux, n->tipo, (verifica_fila + 1));
			insere_fila_processados(fp, n->id, n->temp_chegada, (n->temp_execucao - aux), n->tipo);
			exclui_fila(f);
			break;
			
		}	
	}
}

void realoca_fila_1(Pilha_aux* px, Fila* f){
	Lista_pilha_aux* n;
	for(n=px->prim; n!=NULL; n=n->prox){
		realoca_fila_insere_1(f, n->id, n->temp_chegada, n->temp_execucao, n->tipo);
		exclui_pilha_aux(px);
				
	}
}

void realoca_fila_2(Fila_aux* fx, Fila* f){
	Lista_fila_aux* n;
	for(n=fx->ini; n!=NULL; n=n->prox){
		realoca_fila_insere_2(f, n->id, n->temp_chegada, n->temp_execucao, n->tipo);
		exclui_fila_aux(fx);
				
	}
}

void busca_pilha(Pilha* p, Pilha_aux* px){
	Lista_pilha_aux* n;
	for(n=p->prim; n!=NULL; n=n->prox){
		insere_pilha_aux(px, n->id, n->temp_chegada, n->temp_execucao, n->tipo);
		exclui_pilha(p);
		
	}
}

void busca_fila(Fila* f, Fila_aux* fx){
	Lista_fila* n;
	for(n=f->ini; n!=NULL; n=n->prox){
		insere_fila_aux(fx, n->id, n->temp_chegada, n->temp_execucao, n->tipo);
		exclui_fila(f);
		
	}
}

int procura_processo(Fila* f, int codigo){
	Lista_fila* n;
	for(n=f->ini; n!=NULL; n=n->prox){
		if(n->temp_chegada==codigo){
			if(!strcmp(n->tipo, "sistema")){
				return 0;
				
			}
		}
	}
	return 1;
}

int valida_processo(char* processo){
	if((!strcmp(processo, "sistema")) || (!strcmp(processo, "usuario"))){
		return 1;
			
	}
	return 0;
}

int valida_tem_exe(Fila* f, int codigo, int temp){
	Lista_fila* n;
	for(n=f->ini; n!=NULL; n=n->prox){
		if(n->temp_chegada==codigo){
			if(n->temp_execucao>temp){
				return 0;
			}
		}
	}
	return 1;
}

int verifica_fila_vazia(Fila* f){
	Lista_fila* n;
	int cont=0;
	for(n=f->ini; n!=NULL; n=n->prox){
		cont += 1;
	}
	return cont;
}

int contador_fila(Fila* f){
	Lista_fila* n;
	int cont=0;
	for(n=f->ini; n!=NULL; n=n->prox){
		cont = 0;
		cont = n->temp_chegada;
	}
	return cont;
}

void exclui_fila(Fila* f){
	Lista_fila* t;
	t = f->ini;
	f->ini = t->prox;
	if(f->fim==NULL){
		f->fim = NULL;
	}
	free(t);
	
}

void exclui_pilha(Pilha* p){
	Lista_pilha* t;
	t = p->prim;
	p->prim = t->prox;
	free(t);
}

void exclui_pilha_aux(Pilha_aux* px){
	Lista_pilha_aux* t;
	t = px->prim;
	px->prim = t->prox;
	free(t);
}

void exclui_fila_aux(Fila_aux* fx){
	Lista_fila_aux* t;
	t = fx->ini;
	fx->ini = t->prox;
	if(fx->fim==NULL){
		fx->fim = NULL;
	}
	free(t);
	
}
/*
void imprime_fila(Fila* f){
	Lista_fila* n;
	printf("Fila\n");
	for(n=f->ini; n!=NULL; n=n->prox){
		printf("id-> %s\n", n->id);
		printf("chegada-> %d\n", n->temp_chegada);
		printf("execucao-> %d\n", n->temp_execucao);
		printf("tipo-> %s\n", n->tipo);
		printf("\n");
		
	}
}
*/
void imprime_pilha(Pilha* p){
	Lista_pilha* n;
	printf("> Pilha <\n");
	for(n=p->prim; n!=NULL; n=n->prox){
		printf("%s, ", n->id);
		
	}
	printf("\n\n");
}

void imprime_fila_processados(Fila_processados* fp){
	Lista_processados* n;
	printf("Fila ja processados\n");
	for(n=fp->ini; n!=NULL; n=n->prox){
		printf("%s", n->id);		
		printf("(%d) - ", n->temp_execucao);
		//printf("chegada-> %d\n", n->temp_chegada);
		//printf("tipo-> %s\n", n->tipo);
		
	}
	printf("\n\n");
}
/*
void imprime_pilha_aux(Pilha_aux* px){
	Lista_pilha_aux* n;
	printf("Pilha auxiliar\n");
	for(n=px->prim; n!=NULL; n=n->prox){
		printf("id-> %s", n->id);
		printf("chegada-> %d\n", n->temp_chegada);
		printf("\n");
	}
}
*/
/*
void imprime_fila_aux(Fila_aux* fx){
	Lista_fila_aux* n;
	printf("Fila auxiliar\n");
	for(n=fx->ini; n!=NULL; n=n->prox){
		printf("id-> %s ", n->id);
		//printf("chegada-> %d\n", n->temp_chegada);
		//printf("(%d)\n", n->temp_execucao);
		//printf("tipo-> %s\n", n->tipo);
		printf("\n");
	}
}
*/
void libera_fila(Fila* f){
	Lista_fila* n = f->ini;
	while(n!=NULL){
		Lista_fila* t = n->prox;
		free(n);
		n = t;
	}
	free(f);
}

void libera_pilha(Pilha* p){
	Lista_pilha* n = p->prim;
	while(n!=NULL){
		Lista_pilha* t = n->prox;
		free(n);
		n = t;
	}
	free(p);
}

void libera_fila_aux(Fila_aux* fx){
	Lista_fila_aux* n = fx->ini;
	while(n!=NULL){
		Lista_fila_aux* t = n->prox;
		free(n);
		n = t;
	}
	free(fx);
}

void libera_pilha_aux(Pilha_aux* px){
	Lista_pilha_aux* n = px->prim;
	while(n!=NULL){
		Lista_pilha_aux* t = n->prox;
		free(n);
		n = t;
	}
	free(px);
}

void libera_fila_processados(Fila_processados* fp){
	Lista_processados* n = fp->ini;
	while(n!=NULL){
		Lista_processados* t = n->prox;
		free(n);
		n = t;
	}
	free(fp);
}
