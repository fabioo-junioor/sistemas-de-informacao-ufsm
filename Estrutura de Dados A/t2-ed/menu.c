#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "t2.h"

void menu(Pessoa_p* ps, Banco* bd){
	int gestante=0, d_fisico=0, idade=0, rg=0;
	int verif_rg=0;
	int op=0, sair=1;
	char nome[20];
	
	while(sair!=0){
		printf("-----------------------------------\n");
		printf("1 - Inserir pessoa!\n");
		printf("-----------------------------------\n");
		printf("2 - Imprimir toda arvore e filhos!\n");
		printf("-----------------------------------\n");
		printf("3 - Imprimir todo banco de dados!\n");
		printf("-----------------------------------\n");
		printf("4 - Buscar proximo a ser chamado!\n");
		printf("-----------------------------------\n");
		printf("5 - Chamar proxima pessoa!\n");
		printf("-----------------------------------\n");
		printf("10 - Sair!\n");
		printf("-----------------------------------\n");
		scanf("%d", &op);
		printf("\n");
		switch(op){
			case 1:
				informacao_prio();
				printf("informe o nome: ");
				scanf(" %[^\n]", nome);
				printf("informe a idade: ");
				scanf("%d", &idade);
				printf("informe o RG: ");
				scanf("%d", &rg);
				printf("Possui deficiencia fisica? 1-SIM / 2-NAO: ");
				scanf("%d", &d_fisico);
				printf("Gestante? 1-SIM / 2-NAO: ");
				scanf("%d", &gestante);
				
				verif_rg = verificar_rg(bd, tamanho, rg);				
				if(verif_rg){
					if(((gestante==1) || (gestante==2)) && ((d_fisico==1) || (d_fisico==2))){
						if(idade>=60){
							preencher_banco(bd, tamanho, 5, idade, rg, nome);
							insere_pessoa(ps, 5, rg);
						
						}else if((idade<60) && (idade>10)){	
							if((gestante==1) && (d_fisico==1)){
								preencher_banco(bd, tamanho, 4, idade, rg, nome);
								insere_pessoa(ps, 4, rg);
													
							}else if((gestante==1) && (d_fisico==2)){
								preencher_banco(bd, tamanho, 4, idade, rg, nome);
								insere_pessoa(ps, 4, rg);
								
							}else if((gestante==2) && (d_fisico==1)){
								preencher_banco(bd, tamanho, 3, idade, rg, nome);
								insere_pessoa(ps, 3, rg);
								
							}else if((gestante==2) && (d_fisico==2)){
								preencher_banco(bd, tamanho, 1, idade, rg, nome);
								insere_pessoa(ps, 1, rg);
														
							}							
						}else{
							if(d_fisico==1){
								preencher_banco(bd, tamanho, 3, idade, rg, nome);
								insere_pessoa(ps, 3, rg);
													
							}else{
								preencher_banco(bd, tamanho, 2, idade, rg, nome);
								insere_pessoa(ps, 2, rg);
							}
						}
					}else{
						printf("\nCodigo 'gestante' ou 'deficiente fisico' incorreto!\n");
						
					}
					
				}else{
					printf("\nRg ja existe!\n");
					
				}
				
				break;
			
			case 2:
				imprime_pessoa(ps);
				break;
			
			case 3:
				imprimir_banco(bd, tamanho);
				break;
			
			case 4:
				busca_proximo(ps, bd, tamanho);
				break;
				
			case 5:
				remove_banco(bd, tamanho, ps->tam[0].dado, ps->tam[0].rg);
				remove_pessoa(ps);				
				break;
					
			case 10:
				sair = 0;
				break;	
				
			default:
				printf("Numero invalido\n");
				
		}
		printf("\n");			
	}		
}
