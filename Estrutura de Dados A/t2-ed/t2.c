#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "t2.h"

Pessoa_p* cria_pessoa(){
	Pessoa_p* ps;
	ps = (Pessoa_p*)malloc(sizeof(struct pessoa_p));
	if(ps != NULL){
		ps->quantidade = 0;
		
	}
	return ps;
}

void insere_pessoa(Pessoa_p* ps, int dado, int rg){
	if(ps==NULL){
		return;
		
	}
	if(ps->quantidade==tamanho){
		return;
		
	}
	ps->tam[ps->quantidade].rg = rg;
	ps->tam[ps->quantidade].dado = dado;	
	arruma_dado_inserido(ps, ps->quantidade);
	ps->quantidade += 1;
	
}

void arruma_dado_inserido(Pessoa_p* ps, int filho){
	int pai;
	struct pessoa aux;
	pai = (filho-1)/2;
	while((filho > 0) && (ps->tam[pai].dado < ps->tam[filho].dado)){
		aux = ps->tam[filho];
		ps->tam[filho] = ps->tam[pai];
		ps->tam[pai] = aux;
		
		filho = pai;
		pai = (pai-1)/2;	
	}
	
}

void remove_pessoa(Pessoa_p* ps){
	if(ps==NULL){
		return;
		
	}
	if(ps->quantidade==0){
		return;
		
	}
	ps->quantidade -= 1;
	ps->tam[0] = ps->tam[ps->quantidade];
	ps->tam[ps->quantidade].dado = 0;
	ps->tam[ps->quantidade].rg = 0;
	organiza_heap(ps, 0);
	
}

void organiza_heap(Pessoa_p* ps, int pai){
	struct pessoa aux;
	int filho;
	filho = (2*pai)+1;
	while(filho < ps->quantidade){
		if(filho < ps->quantidade-1){
			if(ps->tam[filho].dado < ps->tam[filho+1].dado){
				filho += 1;
				
			}
		}
		if(ps->tam[pai].dado >= ps->tam[filho].dado){
			break;
			
		}
		aux = ps->tam[pai];
		ps->tam[pai] = ps->tam[filho];
		ps->tam[filho] = aux;
		
		pai = filho;
		filho = (2*pai)+1;
	}
}

void busca_proximo(Pessoa_p* ps, struct banco* bd, int m){
	if((ps==NULL) || (ps->quantidade==0)){
		return;
		
	}
	printf("Proximo a ser chamado\n");
	imprime_proximo(bd, m, ps->tam[0].dado, ps->tam[0].rg);
	
}

void imprime_pessoa(Pessoa_p* ps){
	int i=0;
	if((ps==NULL) || (ps->quantidade==0)){
		return;
		
	}
	printf("Arvore de prioridade\n");
	while(i!=ps->quantidade){
		printf("Prioridade-> [%d]\n", ps->tam[i].dado);
		printf("Filho esquerda-> [%d] / Filho direita-> [%d]\n", ps->tam[(2*i)+1].dado, ps->tam[(2*i)+2].dado);
		printf("\n");
		i++;
		
	}
}

Banco* alocar_banco(int m){
	int i=0;
	Banco *bd;
	bd = (Banco*)malloc(m*sizeof(Banco));
	
	if(bd==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
		
	}else{
		for(i=0; i<m; i++){
			bd[i].idade = 0;
			bd[i].prioridade = 0;
			bd[i].rg = 0;
		}
		
	}
	return bd;
}

void preencher_banco(struct banco* bd, int m, int prio, int idade, int rg, char* nome){
	int i=0;
	for(i=0; i<m; i++){
		if(bd[i].prioridade==0){
			bd[i].prioridade = prio;
			bd[i].idade = idade;
			bd[i].rg = rg;
			strcpy(bd[i].nome, nome);
			break;
			
		}
	}	
}

int verificar_rg(struct banco* bd, int m, int codigo){
	int i=0;
	for(i=0; i<m; i++){
		if(bd[i].rg==codigo){
			return 0;
			
		}
	}
	return 1;
}

void informacao_prio(){
	printf("Nivel de prioridades\n");
	printf("********************\n");
	printf("Nivel [5] - Idoso mais de '60' anos\n");
	printf("Nivel [4] - Gestante\n");
	printf("Nivel [3] - Deficiencia fisica\n");
	printf("Nivel [2] - Crianca menos de '10' anos\n");
	printf("Nivel [1] - Pessoas em geral\n");
	printf("\n");
}

void imprimir_banco(struct banco* bd, int m){
	int i=0;
	printf("Banco de dados\n");
	for(i=0; i<m; i++){
		if(bd[i].prioridade!=0){
			printf("Nome: %s\n", bd[i].nome);
			printf("Idade: %d anos\n", bd[i].idade);
			printf("Rg: %d\n", bd[i].rg);
			printf("Prioridade: [%d]\n", bd[i].prioridade);
			printf("\n");
		}
	}
}

void imprime_proximo(struct banco* bd, int m, int prio, int rg){
	int i=0;
	for(i=0; i<m; i++){
		if((bd[i].prioridade==prio) && (bd[i].rg==rg)){
			printf("Prioridade: [%d]\n", bd[i].prioridade);
			printf("Nome: %s\n", bd[i].nome);
			printf("Idade: %d anos\n", bd[i].idade);
			printf("Rg: %d\n", bd[i].rg);
			printf("\n");
			break;
		}
	}
}

void remove_banco(struct banco* bd, int m, int prio, int rg){
	int i=0;
	for(i=0; i<m; i++){
		if((bd[i].prioridade == prio) && (bd[i].rg == rg)){
			bd[i].idade = 0;
			bd[i].prioridade = 0;
			bd[i].rg = 0;
			printf("Pessoa foi chamada!\n");
			break;
			
		}
	}
}

void libera_banco(struct banco* bd){
	free(bd);
	
}

void libera_pessoa(Pessoa_p* ps){
	free(ps);
	
}
