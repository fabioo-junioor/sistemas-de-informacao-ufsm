#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "restaurante.h"

Fila_espera_cliente* fila_espera_cliente_cria(void){
	Fila_espera_cliente* f = (Fila_espera_cliente*)malloc(sizeof(Fila_espera_cliente));
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

Fila_estacionamento* fila_estacionamento_cria(void){
	Fila_estacionamento* e = (Fila_estacionamento*)malloc(sizeof(Fila_estacionamento));
	e->ini = NULL;
	e->fim = NULL;
	return e;
}

Pilha_cliente* pilha_cliente_cria(void){
	Pilha_cliente* pc = (Pilha_cliente*)malloc(sizeof(Pilha_cliente));
	pc->prim = NULL;
	return pc;
}

Pilha_cliente_aux* pilha_cliente_aux_cria(void){
	Pilha_cliente_aux* pcx = (Pilha_cliente_aux*)malloc(sizeof(Pilha_cliente_aux));
	pcx->prim = NULL;
	return pcx;
}

Pilha_estacionamento* pilha_estacionamento_cria(void){
	Pilha_estacionamento* pe = (Pilha_estacionamento*)malloc(sizeof(Pilha_estacionamento));
	pe->prim = NULL;
	return pe;
}

Pilha_estacionamento_aux* pilha_estacionamento_aux_cria(void){
	Pilha_estacionamento_aux* pex = (Pilha_estacionamento_aux*)malloc(sizeof(Pilha_estacionamento_aux));
	pex->prim = NULL;
	return pex;
}

Restaurante** aloca_matriz(int linha, int coluna){
	int i;
	Restaurante **res;
	res = (Restaurante**)malloc(linha*sizeof(Restaurante*));
	for(i=0; i<linha; i++){
		res[i] = (Restaurante*)malloc(coluna*sizeof(Restaurante));
		
	}
	if(res==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
		
	}
	return res;
}

void preencher_matriz(struct restaurante** res, int linha, int coluna){
	int i=0, j=0, aux=0;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			aux += 1;
			res[i][j].lugares_acupados = 0;
			res[i][j].mesa_livre = 0;
			res[i][j].comanda_mesa = 0;
			res[i][j].num_mesa = aux;
			
		}	
	}
}

void insere_fila_espera(Fila_espera_cliente* f, int tam_grupo, int senha){
	Lista_espera_cliente* n = (Lista_espera_cliente*)malloc(sizeof(Lista_espera_cliente));
	n->senha_grupo = senha;
	n->tam_grupo = tam_grupo;	
	n->prox = NULL;		
	
	if(f->fim != NULL){
		f->fim->prox = n;
		
	}else{
		f->ini = n;
				
	}
	
	f->fim = n;
	
}

void insere_pilha_cliente(Pilha_cliente* pc, int senha, int tamanho){
	Lista_pilha_cliente* n = (Lista_pilha_cliente*)malloc(sizeof(Lista_pilha_cliente));
	n->senha = senha;
	n->tam_grupo = tamanho;
	n->prox = pc->prim;
	pc->prim = n;
	
}

void insere_pilha_cliente_aux(Pilha_cliente_aux* pcx, int senha, int tamanho){
	Lista_pilha_cliente_aux* n = (Lista_pilha_cliente_aux*)malloc(sizeof(Lista_pilha_cliente_aux));
	n->senha = senha;
	n->tam_grupo = tamanho;
	n->prox = pcx->prim;
	pcx->prim = n;
	
}

void insere_fila_estacionamento(Fila_estacionamento* e, int ticket){
	char placa[8];	
	printf("Informe a placa do carro: ");
	scanf(" %[^\n]", placa);
	
	Lista_estacionamento* n = (Lista_estacionamento*)malloc(sizeof(Lista_estacionamento));
	n->ticket_id = ticket;
	strcpy(n->placa_carro, placa);	
	n->prox = NULL;		
	
	if(e->fim != NULL){
		e->fim->prox = n;
		
	}else{
		e->ini = n;
				
	}
	
	e->fim = n;
	
}

void insere_pilha_estacionamento(Pilha_estacionamento* pe, int ticket, char* placa){
	Lista_pilha_estacionamento* n = (Lista_pilha_estacionamento*)malloc(sizeof(Lista_pilha_estacionamento));
	n->ticket_id = ticket;
	strcpy(n->placa_carro, placa);
	n->prox = pe->prim;
	pe->prim = n;
	
}

void insere_pilha_estacionamento_aux(Pilha_estacionamento_aux* pex, int ticket, char* placa){
	Lista_pilha_estacionamento_aux* n = (Lista_pilha_estacionamento_aux*)malloc(sizeof(Lista_pilha_estacionamento_aux));
	n->ticket_id = ticket;
	strcpy(n->placa_carro, placa);
	n->prox = pex->prim;
	pex->prim = n;
	
}

void realoca_fila_estacionamento(Fila_estacionamento* e, int ticket, char* placa){
	Lista_estacionamento* n = (Lista_estacionamento*)malloc(sizeof(Lista_estacionamento));
	n->ticket_id = ticket;
	strcpy(n->placa_carro, placa);	
	n->prox = NULL;		
	
	if(e->fim != NULL){
		e->fim->prox = n;
		
	}else{
		e->ini = n;
				
	}
	
	e->fim = n;
}

void aloca_cliente(struct restaurante** res, int linha, int coluna, int grupo, Fila_espera_cliente* f){
	int i=0, j=0, aux=0, lugares_livres=0, senha=0;
	aux = grupo;
	
	lugares_livres = verifica_lugares_livres(res, linha, coluna);
	if(lugares_livres){
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(res[i][j].lugares_acupados==0){				
					if((aux>=0) && (aux<=4)){
						res[i][j].lugares_acupados = aux;
						aux = 0;
						
					}else{
						res[i][j].lugares_acupados = 4;
						aux -= 4;
						
					}					
				}
			}
		}
		if(aux>0){
			senha = contador_fila_senha(f);
			insere_fila_espera(f, aux, (senha + 1));
					
		}		
	}else{
		senha = contador_fila_senha(f);
		insere_fila_espera(f, aux, (senha + 1));
		
	}
	
}

void liberar_mesa(struct restaurante** res, int linha, int coluna, int codigo_mesa){
	int i=0, j=0;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(codigo_mesa==res[i][j].num_mesa){
				res[i][j].comanda_mesa = 0;
				res[i][j].lugares_acupados = 0;
				res[i][j].mesa_livre = 0;
				printf("Mesa liberada!\n");
				break;
				
			}
		}
	}	
}

void chama_fila_espera(Fila_espera_cliente* f, struct restaurante** res, int linha, int coluna){
	int lugares_livres=0, aux=0;
	Lista_espera_cliente* n;
	
	lugares_livres = verifica_lugares_livres(res, linha, coluna);
	if(lugares_livres){
		for(n=f->ini; n!=NULL; n=n->prox){
			if(n->tam_grupo<=4){
				aux = n->tam_grupo;
				insere_fila_mesa(res, linha, coluna, aux);
				exclui_fila_cliente(f);
				break;
				
			}else{
				n->tam_grupo -= 4;
				aux = 4;
				insere_fila_mesa(res, linha, coluna, aux);
				break;
				
			}
		}		
	}else{
		printf("Nao ah lugares livres!\n");
		
	}
}

void insere_fila_mesa(struct restaurante** res, int linha, int coluna, int codigo){
	int i=0, j=0;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(res[i][j].lugares_acupados==0){
				res[i][j].lugares_acupados = codigo;
				res[i][j].mesa_livre = 1;
				break;
				
			}
		}
	}
}

void grupo_desiste_fila_espera(Fila_espera_cliente* f, Pilha_cliente* pc, int codigo){
	Lista_espera_cliente* n;
	for(n=f->ini; n!=NULL; n=n->prox){
		if(n->senha_grupo!=codigo){
			insere_pilha_cliente(pc, n->senha_grupo, n->tam_grupo);
			
		}		
	}
}

void atualiza_pilha_cliente(Pilha_cliente_aux* pcx, Pilha_cliente* pc){
	Lista_pilha_cliente* n;
	for(n=pc->prim; n!=NULL; n=n->prox){
		insere_pilha_cliente_aux(pcx, n->senha, n->tam_grupo);
		
	}
}

void atualiza_fila_espera(Pilha_cliente_aux* pcx, Fila_espera_cliente* f){
	Lista_pilha_cliente_aux* n;
	for(n=pcx->prim; n!=NULL; n=n->prox){
		insere_fila_espera(f, n->tam_grupo, n->senha);
		
	}
}

void retirada_de_carro(Fila_estacionamento* e, Pilha_estacionamento* pe, int codigo){
	Lista_estacionamento* n;
	for(n=e->ini; n!=NULL; n=n->prox){
		if(n->ticket_id!=codigo){
			insere_pilha_estacionamento(pe, n->ticket_id, n->placa_carro);
			
		}		
	}
}

void atualiza_pilha_estacionamento(Pilha_estacionamento_aux* pex, Pilha_estacionamento* pe){
	Lista_pilha_estacionamento* n;
	for(n=pe->prim; n!=NULL; n=n->prox){
		insere_pilha_estacionamento_aux(pex, n->ticket_id, n->placa_carro);
		
	}
}

void atualiza_fila_estacionamento(Pilha_estacionamento_aux* pex, Fila_estacionamento* e){
	Lista_pilha_estacionamento_aux* n;
	for(n=pex->prim; n!=NULL; n=n->prox){
		realoca_fila_estacionamento(e, n->ticket_id, n->placa_carro);
		
	}
}

void atualiza_mesas_livres(struct restaurante** res, int linha, int coluna){
	int i=0, j=0;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(res[i][j].lugares_acupados>0){
				res[i][j].mesa_livre = 1;
				
			}else{
				res[i][j].mesa_livre = 0;
					
			}
		}
	}	
}

int verifica_lugares_livres(struct restaurante **res, int linha, int coluna){
	int i=0, j=0;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			if(res[i][j].lugares_acupados==0){
				return 1;
				
			}
		}
	}
	return 0;
}

int verifica_tam_grupo(){
	int grupo=0;
	
	printf("Qual tamanho do grupo? ");
	scanf("%d", &grupo);

	return grupo;
}

int verifica_codigo_grupo_existe(Fila_espera_cliente* f, int codigo){
	Lista_espera_cliente* n;
	for(n=f->ini; n!=NULL; n=n->prox){
		if(n->senha_grupo==codigo){
			return codigo;
			
		}
	}
	return 0;
}

int verifica_ticket_existe(Fila_estacionamento* e, int codigo){
	Lista_estacionamento* n;
	for(n=e->ini; n!=NULL; n=n->prox){
		if(n->ticket_id==codigo){
			return codigo;
			
		}
	}
	return 0;
}

int contador_fila_senha(Fila_espera_cliente* f){
	Lista_espera_cliente* n;
	int cont=0;
	for(n=f->ini; n!=NULL; n=n->prox){
		cont = 0;
		cont = n->senha_grupo;
		
	}
	return cont;
}

int verifica_vagas_estacionamento(Fila_estacionamento* e){
	Lista_estacionamento* n;
	int cont=0;
	for(n=e->ini; n!=NULL; n=n->prox){
		cont += 1;
		
	}
	return cont;
}

void consulta_mesa_qtd(struct restaurante** res, int linha, int coluna){
	int i=0, j=0, num=0;
	printf("Informe o numero da mesa: ");
	scanf("%d", &num);
	
	if((num>0) && (num<=(linha*coluna))){
		printf("> Ocupacao da mesa <\n");
		for(i=0; i<linha; i++){
			for(j=0; j<coluna; j++){
				if(res[i][j].num_mesa==num){
					printf("Mesa [%d] tem um total de [%d] lugares ocupados\n", res[i][j].num_mesa, res[i][j].lugares_acupados);
									
				}	
			}
		}
	}else{
		printf("Numero da mesa nao existe!\n");
		
	}
}

void consulta_mesa_todas(struct restaurante** res, int linha, int coluna){
	int i=0, j=0;		
	printf("> Ocupacao de todas as mesa <\n");
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			printf("Mesa [%d] tem um total de [%d] lugares ocupados\n", res[i][j].num_mesa, res[i][j].lugares_acupados);
						
		}	
		printf("\n");
	}
}

void consulta_fila_espera(Fila_espera_cliente* f){
	int cont_grupos=0, cont_pessoas=0;
	Lista_espera_cliente* n;
	printf("> Fila espera cliente <\n");
	for(n=f->ini; n!=NULL; n=n->prox){
		printf("Grupo numero [%d] aguarda por [%d] lugare(s)!", n->senha_grupo, n->tam_grupo);
		cont_grupos += 1;
		cont_pessoas += n->tam_grupo;
		printf("\n");
		
	}
	printf("Ah [%d] grupo(s) aguardando, e um total de [%d] pessoas!\n", cont_grupos, cont_pessoas);
	
}

void consulta_estacionamento_carro(Fila_estacionamento* e){
	Lista_estacionamento* n;
	int aux=0;
	printf("> Fila estacionamento <\n");
	for(n=e->ini; n!=NULL; n=n->prox){
		aux += 1;
		printf("Carro %d - Placa [%s] / Ticket [%d]", aux, n->placa_carro, n->ticket_id);
		printf("\n");
		
	}
	printf("\n");
}

void imprimir_matriz(struct restaurante** res, int linha, int coluna){
	int i=0, j=0;
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			printf(" | M%d | ", res[i][j].num_mesa);			
			
		}	
		printf("\n");
		printf("\n");
	}
}
/*
void imprime_fila_espera(Fila_espera_cliente* f){
	Lista_espera_cliente* n;
	printf("Fila espera cliente\n");
	for(n=f->ini; n!=NULL; n=n->prox){
		printf("Senha grupo-> %d\n", n->senha_grupo);
		printf("Tamanho grupo-> %d", n->tam_grupo);
		printf("\n");
		printf("\n");
		
	}
}
*/
/*
void imprime_pilha_cliente(Pilha_cliente* pc){
	Lista_pilha_cliente* n;
	printf("Pilha cliente\n");
	for(n=pc->prim; n!=NULL; n=n->prox){
		printf("Senha-> %d\n", n->senha);
		printf("Tamanho grupo-> %d", n->tam_grupo);
		printf("\n");
	}
}
*/
/*
void imprime_pilha_cliente_aux(Pilha_cliente_aux* pcx){
	Lista_pilha_cliente_aux* n;
	printf("Pilha cliente auxiliar\n");
	for(n=pcx->prim; n!=NULL; n=n->prox){
		printf("Senha-> %d\n", n->senha);
		printf("Tamanho grupo-> %d", n->tam_grupo);
		printf("\n");
	}
}
*/
/*
void imprime_fila_estacionamento(Fila_estacionamento* e){
	Lista_estacionamento* n;
	printf("Fila estacionamento\n");
	for(n=e->ini; n!=NULL; n=n->prox){
		printf("Ticket-> %d\n", n->ticket_id);
		printf("Placa carro-> %s", n->placa_carro);
		printf("\n");
		printf("\n");
		
	}
}
*/
/*
void imprime_pilha_estacionamento(Pilha_estacionamento* pe){
	Lista_pilha_estacionamento* n;
	printf("Pilha estacionamento\n");
	for(n=pe->prim; n!=NULL; n=n->prox){
		printf("Ticket-> %d\n", n->ticket_id);
		printf("Placa-> %s", n->placa_carro);
		printf("\n");
	}
}
*/
/*
void imprime_pilha_estacionamento_aux(Pilha_estacionamento_aux* pex){
	Lista_pilha_estacionamento_aux* n;
	printf("Pilha estacionamento auxiliar\n");
	for(n=pex->prim; n!=NULL; n=n->prox){
		printf("Ticket-> %d\n", n->ticket_id);
		printf("Placa-> %s", n->placa_carro);
		printf("\n");
	}
}
*/
void exclui_fila_cliente(Fila_espera_cliente* f){
	Lista_espera_cliente* t;
	t = f->ini;
	f->ini = t->prox;
	if(f->fim==NULL){
		f->fim = NULL;
	}
	free(t);
	
}

void free_matriz(struct restaurante** res, int m){
    int i=0;
    for(i=0; i<m; i++){
        free(res[i]);
    }
    free(res);
}

void libera_fila_espera_cliente(Fila_espera_cliente* f){
	Lista_espera_cliente* n = f->ini;
	while(n!=NULL){
		Lista_espera_cliente* t = n->prox;
		free(n);
		n = t;
	}
	free(f);
}

void libera_pilha_cliente(Pilha_cliente* pc){
	Lista_pilha_cliente* n = pc->prim;
	while(n!=NULL){
		Lista_pilha_cliente* t = n->prox;
		free(n);
		n = t;
	}
	free(pc);
}

void libera_pilha_cliente_aux(Pilha_cliente_aux* pcx){
	Lista_pilha_cliente_aux* n = pcx->prim;
	while(n!=NULL){
		Lista_pilha_cliente_aux* t = n->prox;
		free(n);
		n = t;
	}
	free(pcx);
}

void libera_fila_estacionamento(Fila_estacionamento* e){
	Lista_estacionamento* n = e->ini;
	while(n!=NULL){
		Lista_estacionamento* t = n->prox;
		free(n);
		n = t;
	}
	free(e);
}

void libera_pilha_estacionamento(Pilha_estacionamento* pe){
	Lista_pilha_estacionamento* n = pe->prim;
	while(n!=NULL){
		Lista_pilha_estacionamento* t = n->prox;
		free(n);
		n = t;
	}
	free(pe);
}

void libera_pilha_estacionamento_aux(Pilha_estacionamento_aux* pex){
	Lista_pilha_estacionamento_aux* n = pex->prim;
	while(n!=NULL){
		Lista_pilha_estacionamento_aux* t = n->prox;
		free(n);
		n = t;
	}
	free(pex);
}
