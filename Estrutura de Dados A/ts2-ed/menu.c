#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "restaurante.h"

void menu(struct restaurante** res, int linha, int coluna, int vagas_estacionamento, Fila_espera_cliente* f, Pilha_cliente* pc, Pilha_cliente_aux* pcx, Fila_estacionamento* e, Pilha_estacionamento* pe,	Pilha_estacionamento_aux* pex){
	int sair=1, op=0, grupo=0, lugares_livres=0, temp=0;
	int codigo_grupo=0, codigo_mesa=0, vagas_ocupadas=0, ticket=0;
	
	while(sair!=0){
		grupo = 0;
		printf("\n");
		printf("--Disposicao das mesas - Numero da mesa | Mx |--\n");
		printf("------------------------------------------------\n");
		imprimir_matriz(res, linha, coluna);
		printf("\n");
		printf("--------------------------------------------------------\n");
		printf("1 - Alocar cliente(s) em mesa!\n");	
		printf("2 - Liberar mesa!\n");
		printf("3 - Grupo desiste da fila de espera!\n");
		printf("--------------------------------------------------------\n");	
		printf("4 - Inserir veiculo no estacionamento!\n");
		printf("5 - Saida de veiculo!\n");
		printf("--------------------------------------------------------\n");
		printf("6 - Consulta quantidade pessoas em uma determinada masa!\n");
		printf("7 - Consulta quantidade pessoas em todas as masas!\n");
		printf("--------------------------------------------------------\n");
		printf("8 - Consulta quantidade de pessoas na fila de espera!\n");
		printf("9 - Consulta quantidade de carros no estacionamento!\n");
		printf("--------------------------------------------------------\n");
		printf("10 - Sair!\n");
		printf("--------------------------------------------------------\n");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				grupo = verifica_tam_grupo();
				aloca_cliente(res, linha, coluna, grupo, f);
				break;
				
			case 2:
				lugares_livres = verifica_lugares_livres(res, linha, coluna);
				printf("Informe o numero da mesa: ");
				scanf("%d", &codigo_mesa);
				
				if((codigo_mesa>=1) && (codigo_mesa<=(linha*coluna))){
					liberar_mesa(res, linha, coluna, codigo_mesa);
				
				}else{
					printf("Codigo da mesa nao existe!\n");
					
				}
				
				if(!lugares_livres){
					chama_fila_espera(f, res, linha, coluna);
					
				}
				break;
				
			case 3:
				printf("Informe o codigo do grupo: ");
				scanf("%d", &codigo_grupo);
				codigo_grupo = verifica_codigo_grupo_existe(f, codigo_grupo);
				if(codigo_grupo){
					pc = pilha_cliente_cria();
					pcx = pilha_cliente_aux_cria();
					grupo_desiste_fila_espera(f, pc, codigo_grupo);
				
					libera_fila_espera_cliente(f);
					f = fila_espera_cliente_cria();
				
					atualiza_pilha_cliente(pcx, pc);
					libera_pilha_cliente(pc);
				
					atualiza_fila_espera(pcx, f);				
					libera_pilha_cliente_aux(pcx);
					
				}else{
					printf("Codigo do grupo nao existe!\n");
					
				}
				break;
			
			case 4:
				printf("Informe o ticket: ");
				scanf("%d", &ticket);
				vagas_ocupadas = verifica_vagas_estacionamento(e);
				temp = verifica_ticket_existe(e, ticket);
				
				if(temp==0){
					if(vagas_ocupadas < vagas_estacionamento){				
						insere_fila_estacionamento(e, ticket);
					
					}else{
						printf("Nao ah mais vagas no estacionamento!\n");
					
					}
				}else{
					printf("Ticket do carro ja existe!\n");
					
				}
				break;
			
			case 5:
				printf("Informe o ticket do carro: ");
				scanf("%d", &ticket);
				ticket = verifica_ticket_existe(e, ticket);
				if(ticket){
					pe = pilha_estacionamento_cria();
					pex = pilha_estacionamento_aux_cria();
					
					retirada_de_carro(e, pe, ticket);
					
					libera_fila_estacionamento(e);
					e = fila_estacionamento_cria();
					
					atualiza_pilha_estacionamento(pex, pe);
					atualiza_fila_estacionamento(pex, e);
					
					libera_pilha_estacionamento(pe);
					libera_pilha_estacionamento_aux(pex);
					
				}else{
					printf("Numero de ticket nao existe!\n");
					
				}
				break;	
			
			case 6:
				consulta_mesa_qtd(res, linha, coluna);
				break;	
			
			case 7:
				consulta_mesa_todas(res, linha, coluna);
				break;
				
			case 8:
				consulta_fila_espera(f);
				break;
				
			case 9:
				consulta_estacionamento_carro(e);
				break;
				
			case 10:
				sair = 0;
				break;
						
			default:
				printf("Numero invalido\n");	
	
		
		}
	
		atualiza_mesas_livres(res, linha, coluna);
		
	}
}
