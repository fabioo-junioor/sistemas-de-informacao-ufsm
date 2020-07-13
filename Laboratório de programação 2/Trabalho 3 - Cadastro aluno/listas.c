#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "listas.h"

Disciplina *cria_disciplina(void){
    return NULL;
}

Turma *cria_turma(void){
    return NULL;
}

Aluno *cria_aluno(void){
    return NULL;
}

Aluno *cria_matricula(void){
    return NULL;
}

Disciplina* cadastrar_disciplina(Disciplina* di){
	int valida_disc=0;
	Disciplina *ponteiro, *ant;
	ponteiro = di;
	ant = NULL;
	
	printf("Informe o codigo da disciplina: ");
	scanf("%d", &valida_disc);
	valida_disc = verifica_disciplina(di, valida_disc);
	if(valida_disc){
		
		while(ponteiro!=NULL){
			ant = ponteiro;
			ponteiro = ponteiro->prox;
		}
		ponteiro  = (Disciplina*)malloc(sizeof(Disciplina));
		printf("Informe o nome da disciplina: ");
		scanf(" %[^\n]", ponteiro->nome);
		printf("Informe quantos creditos tem a disciplina: ");
		scanf("%d", &ponteiro->creditos);
		
		ponteiro->codigo_disc = valida_disc;
		ponteiro->qtd_turmas = 0;
		
		if(ant==NULL){
			ponteiro->prox = di;
			di = ponteiro;
		}else{
			ponteiro->prox = ant->prox;
			ant->prox = ponteiro;
		}
	}else{
		printf("Codigo da disciplina ja existe\n");
	}
	
	return di;	
}

Turma* cadastrar_turma(Turma* tu, Disciplina *di){
	int valida_turma=0, valida_disc=0;
	Turma *ponteiro, *ant;
	ponteiro = tu;
	ant = NULL;	
	
	printf("Informe o codigo da disciplina que essa turma pertence: ");
	scanf("%d", &valida_disc);
	valida_disc = verifica_disciplina_existe(di, valida_disc);
	if(valida_disc){
		
		printf("Informe o codigo da turma: ");
		scanf("%d", &valida_turma);	
		valida_turma = verifica_turma(tu, valida_turma);
		if(valida_turma){
			
			while(ponteiro!=NULL){
				ant = ponteiro;
				ponteiro = ponteiro->prox;
			}
			
			ponteiro  = (Turma*)malloc(sizeof(Turma));		
			printf("Informe a quantidade de vagas: ");
			scanf("%d", &ponteiro->qtd_vagas);
			printf("Informe o dia da aula: ");
			scanf(" %[^\n]", ponteiro->dia);
			printf("Informe a hora da aula: ");
			scanf(" %[^\n]", ponteiro->hora);
			printf("Informe a sala da aula: ");
			scanf(" %[^\n]", ponteiro->sala);
			
			ponteiro->codigo_disc = valida_disc;
			ponteiro->codigo_turma = valida_turma;
			atualiza_qtd_turmas_soma(di, valida_disc);	
				
			if(ant==NULL){
				ponteiro->prox = tu;
				tu = ponteiro;
			}else{
				ponteiro->prox = ant->prox;
				ant->prox = ponteiro;
			}
		}else{
			printf("codigo da turma ja existe\n");
		}
		
	}else{
		printf("disciplina nao existe\n");
	}
	
	return tu;

}

Aluno* cadastrar_aluno(Aluno* al){
	int valida_aluno=0;
	Aluno *ponteiro, *ant;
	ponteiro = al;
	ant = NULL;
	
	printf("Informe a matricula do aluno: ");
	scanf("%d", &valida_aluno);
	valida_aluno = verifica_aluno(al, valida_aluno);
	if(valida_aluno){
		
		while(ponteiro!=NULL){
			ant = ponteiro;
			ponteiro = ponteiro->prox;
		}
		
		ponteiro  = (Aluno*)malloc(sizeof(Aluno));
		printf("Informe o nome do aluno: ");
		scanf(" %[^\n]", ponteiro->nome);
		printf("Informe o telefone do aluno: ");
		scanf(" %[^\n]", ponteiro->fone);
		
		ponteiro->matricula_aluno = valida_aluno;
			
		if(ant==NULL){
			ponteiro->prox = al;
			al = ponteiro;
		}else{
			ponteiro->prox = ant->prox;
			ant->prox = ponteiro;
		}
	}else{
		printf("Numero de matricula ja existe\n");
	}
	
	return al;	
}

Matricula* matricular_aluno(Matricula* ma, Turma* tu, Aluno* al){
	int valida_mat=0, valida_tur=0, valida_vagas=0, valida_aluno_e_matricula=0;
	Matricula *ponteiro, *ant;
	ponteiro = ma;
	ant = NULL;	
	
	printf("Informe a matricula do aluno: ");
	scanf("%d", &valida_mat);
	valida_mat = verifica_aluno_existe(al, valida_mat);	
	if(valida_mat){
		
		printf("Informe o codigo da turma: ");
		scanf("%d", &valida_tur);
		valida_tur = verifica_turma_existe(tu, valida_tur);
		if(valida_tur){
			
			valida_aluno_e_matricula = verifica_aluno_e_matricula(ma, valida_mat, valida_tur);
			if(valida_aluno_e_matricula){
				
				valida_vagas = verifica_vagas_existe(tu, valida_tur);			
				if(valida_vagas){
					
					while(ponteiro!=NULL){
						ant = ponteiro;
						ponteiro = ponteiro->prox;
					}
					
					ponteiro  = (Matricula*)malloc(sizeof(Matricula));
					printf("Informe o dia da matricula: ");
					scanf(" %[^\n]", ponteiro->data_mat);
					
					ponteiro->mat_aluno = valida_mat;
					ponteiro->codigo_turma = valida_tur;
					
					atualiza_vagas_soma(tu, valida_tur);
						
					if(ant==NULL){
						ponteiro->prox = ma;
						ma = ponteiro;
					}else{
						ponteiro->prox = ant->prox;
						ant->prox = ponteiro;
					}
				}else{
					printf("Nao a vagas disponiveis\n");
				}
			}else{
				printf("Esse aluno ja esta matriculado nesta turma\n");
			}
		}else{
			printf("Turma nao existe\n");
		}
	}else{
		printf("Aluno nao existe\n");
		
	}
	
	return ma;	
	
}

Disciplina* buscar_disciplina(Disciplina *di, int codd){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			di = excluir_disciplina(di, codd);
			printf("Disciplina excluida\n");
			
		}
	}
	return di;
}

Turma* buscar_turma(Turma *tu, Disciplina* di, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			atualiza_qtd_turmas_subtrai(di, ponteiro->codigo_disc);
			tu = excluir_turma(tu, codd);
			printf("Turma excluida\n");			
		
		}
	}
	
	return tu;
	
}

Aluno* buscar_aluno(Aluno *al, int codd){
	Aluno *ponteiro;
	for(ponteiro=al; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->matricula_aluno==codd){
			al = excluir_aluno(al, codd);
			printf("Aluno excluido\n");
			
		}
	}
	
	return al;
	
}

Turma* buscar_turma_disciplina(Turma *tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			tu = excluir_turma_disciplina(tu, codd);
		
		}
	}
	
	return tu;
	
}

Matricula* buscar_matricula_turma(Matricula *ma, int codd){
	Matricula *ponteiro;
	for(ponteiro=ma; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			ma = excluir_matricula_turma(ma, codd);
		
		}
	}
	
	return ma;
	
}

Matricula* buscar_matricula_aluno(Matricula *ma, Turma *tu, int codd){
	Matricula *ponteiro;
	for(ponteiro=ma; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->mat_aluno==codd){
			atualiza_vagas_subtrai(tu, ponteiro->codigo_turma);
			ma = excluir_matricula_aluno(ma, codd);			
			
		}
	}
	
	return ma;
	
}

Matricula* buscar_matricula_turma_disciplina(Matricula *ma, Turma *tu, int codd){
	int valida=0;
	Matricula *ponteiro;
	for(ponteiro=ma; ponteiro!=NULL; ponteiro=ponteiro->prox){
		valida =  verifica_matricula_turma_disciplina(tu, codd, ponteiro->codigo_turma);
		if(valida){
			ma = buscar_matricula_turma(ma, ponteiro->codigo_turma);
		}
	}
	
	return ma;
	
}

int verifica_matricula_turma_disciplina(Turma *tu, int cod_dis, int cod_tur){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if((cod_dis==ponteiro->codigo_disc) && (cod_tur==ponteiro->codigo_turma)){
			return 1;
		}
	}
	
	return 0;
	
}

Disciplina* excluir_disciplina(Disciplina* di, int codd){
	Disciplina *ponteiro, *ant;
	ponteiro = di;
	ant = NULL;	
		
	while(ponteiro!=NULL && ponteiro->codigo_disc!=codd){
		ant = ponteiro;
		ponteiro = ponteiro->prox;
	}
		if(ponteiro==NULL){
			return di;
		}
		if(ant==NULL){
			di = ponteiro->prox;
							
		}else{
			ant->prox = ponteiro->prox;
		}
	free(ponteiro);
	return di;
	
}

Turma* excluir_turma(Turma* tu, int codd){
	Turma *ponteiro, *ant;
	ponteiro = tu;
	ant = NULL;
	
	while(ponteiro!=NULL && ponteiro->codigo_turma!=codd){
		ant = ponteiro;
		ponteiro = ponteiro->prox;
	}
		if(ponteiro==NULL){
			return tu;
		}
		if(ant==NULL){
			tu = ponteiro->prox;
							
		}else{
			ant->prox = ponteiro->prox;
		}
	free(ponteiro);
	return tu;
	
}

Aluno* excluir_aluno(Aluno* al, int codd){
	Aluno *ponteiro, *ant;
	ponteiro = al;
	ant = NULL;
	
	while(ponteiro!=NULL && ponteiro->matricula_aluno!=codd){
		ant = ponteiro;
		ponteiro = ponteiro->prox;
	}
		if(ponteiro==NULL){
			return al;
		}
		if(ant==NULL){
			al = ponteiro->prox;
							
		}else{
			ant->prox = ponteiro->prox;
		}
	free(ponteiro);
	return al;
	
}

Matricula* excluir_matricula(Matricula* ma, Turma* tu){
	int mat_ex=0, cod_ex=0;
	Matricula *ponteiro, *ant;
	ponteiro = ma;
	ant = NULL;
	
	if(ponteiro==NULL){
		return ma;
	}
	printf("Informe a matricula do aluno: ");
	scanf("%d", &mat_ex);
	printf("Informe o codigo da turma: ");
	scanf("%d", &cod_ex);
	
	while(ponteiro!=NULL){
		if((ponteiro->mat_aluno==mat_ex) && (ponteiro->codigo_turma==cod_ex)){
			if(ponteiro==ma){
				ma = ma->prox;
				free(ponteiro);
				atualiza_vagas_subtrai(tu, cod_ex);
				printf("Matricula excluida\n");
				
			}else{
				ant->prox = ponteiro->prox;
				free(ponteiro);
				atualiza_vagas_subtrai(tu, cod_ex);
				printf("Matricula excluida\n");
				
			}
		}else{
			ant = ponteiro;
			ponteiro = ponteiro->prox;
		}	
	}
		
	return ma;
	
}

Turma* excluir_turma_disciplina(Turma* tu, int codd){
	Turma *ponteiro, *ant;
	ponteiro = tu;
	ant = NULL;
	
	while(ponteiro!=NULL && ponteiro->codigo_disc!=codd){
		ant = ponteiro;
		ponteiro = ponteiro->prox;
	}
		if(ponteiro==NULL){
			return tu;
		}
		if(ant==NULL){
			tu = ponteiro->prox;
							
		}else{
			ant->prox = ponteiro->prox;
		}
	free(ponteiro);
	return tu;
	
}

Matricula* excluir_matricula_turma(Matricula* ma, int codd){
	Matricula *ponteiro, *ant;
	ponteiro = ma;
	ant = NULL;
	
	while(ponteiro!=NULL && ponteiro->codigo_turma!=codd){
		ant = ponteiro;
		ponteiro = ponteiro->prox;
	}
		if(ponteiro==NULL){
			return ma;
		}
		if(ant==NULL){
			ma = ponteiro->prox;
							
		}else{
			ant->prox = ponteiro->prox;
		}
	free(ponteiro);
	return ma;
	
}

Matricula* excluir_matricula_aluno(Matricula* ma, int codd){
	Matricula *ponteiro, *ant;
	ponteiro = ma;
	ant = NULL;
	
	while(ponteiro!=NULL && ponteiro->mat_aluno!=codd){
		ant = ponteiro;
		ponteiro = ponteiro->prox;
	}
		if(ponteiro==NULL){
			return ma;
		}
		if(ant==NULL){
			ma = ponteiro->prox;
							
		}else{
			ant->prox = ponteiro->prox;
		}
	free(ponteiro);
	return ma;
	
}

void imprimir_disciplina(Disciplina* di){
	Disciplina* ponteiro;
	ponteiro = di;
	if(ponteiro==NULL){
		printf("Lista vazia\n\n");
		return;
		
	}else{
		printf("> Todas as disciplinas <\n");
		while(ponteiro!=NULL){
			printf("Codigo disciplina -> %d\n", ponteiro->codigo_disc);
			printf("Nome da disciplina -> %s\n", ponteiro->nome);
			printf("Creditos -> %d\n", ponteiro->creditos);
			printf("Quantidade de turmas dessa disciplina -> %d\n", ponteiro->qtd_turmas);
			printf("\n");
				
			ponteiro = ponteiro->prox;
		}
	}
}

void imprimir_turma(Turma* tu){
	Turma* ponteiro;
	ponteiro = tu;
	if(ponteiro==NULL){
		printf("Lista vazia\n\n");
		return;
		
	}else{
		printf("> Todas as turmas <\n");
		while(ponteiro!=NULL){
			printf("Codigo da turma -> %d\n", ponteiro->codigo_turma);
			printf("Codigo da disciplina que esta turma pertence -> %d\n", ponteiro->codigo_disc);
			printf("Total de vagas -> %d\n", ponteiro->qtd_vagas);
			printf("Total de vagas ocupadas -> %d\n", ponteiro->qtd_vagas_acupadas);
			printf("Dia da aula -> %s\n", ponteiro->dia);
			printf("Horario da aula -> %s\n", ponteiro->hora);
			printf("Sala -> %s\n", ponteiro->sala);
			printf("\n");
				
			ponteiro = ponteiro->prox;
		}
	}
}

void imprimir_aluno(Aluno* al){
	Aluno* ponteiro;
	ponteiro = al;
	if(ponteiro==NULL){
		printf("Lista vazia\n\n");
		return;
		
	}else{
		printf("> Todos os alunos <\n");
		while(ponteiro!=NULL){
			printf("Numero da matricula -> %d\n", ponteiro->matricula_aluno);
			printf("Nome do aluno -> %s\n", ponteiro->nome);
			printf("Telefone do aluno -> %s\n", ponteiro->fone);
			printf("\n");
				
			ponteiro = ponteiro->prox;
		}
	}
}

void imprimir_matriculas(Matricula* ma){
	Matricula* ponteiro;
	ponteiro = ma;
	if(ponteiro==NULL){
		printf("Lista vazia\n\n");
		return;
		
	}else{
		printf("> Todas as matriculas <\n");
		while(ponteiro!=NULL){
			printf("Matricula -> %d\n", ponteiro->mat_aluno);
			printf("Codigo da turma matriculada -> %d\n", ponteiro->codigo_turma);
			printf("Data da matricula -> %s\n", ponteiro->data_mat);
			printf("\n");
				
			ponteiro = ponteiro->prox;
		}
	}
}

int verifica_disciplina_existe(Disciplina* di, int codd){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			return ponteiro->codigo_disc;		
		}
	}
	
	return 0;
	
}

int verifica_turma_existe(Turma* tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			return ponteiro->codigo_turma;		
		}
	}
	
	return 0;
	
}

int verifica_aluno_existe(Aluno* al, int codd){
	Aluno *ponteiro;
	for(ponteiro=al; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->matricula_aluno==codd){
			return ponteiro->matricula_aluno;		
		}
	}
	
	return 0;

}
int verifica_vagas_existe(Turma* tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			if(ponteiro->qtd_vagas_acupadas<ponteiro->qtd_vagas){
				return 1;
			}		
		}
	}
	
	return 0;
	
}

int verifica_disciplina(Disciplina* di, int codd){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			return 0;		
		}
	}
	
	return codd;
	
}

int verifica_turma(Turma* tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			return 0;		
		}
	}
	
	return codd;
	
}

int verifica_aluno(Aluno* al, int codd){
	Aluno *ponteiro;
	for(ponteiro=al; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->matricula_aluno==codd){
			return 0;		
		}
	}
	
	return codd;
	
}

int verifica_aluno_e_matricula(Matricula* ma, int cod_mat, int cod_tur){
	Matricula *ponteiro;
	for(ponteiro=ma; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if((ponteiro->mat_aluno==cod_mat) && (ponteiro->codigo_turma==cod_tur)){
			return 0;		
		}
	}
	
	return 1;
	
}

void atualiza_vagas_soma(Turma* tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			ponteiro->qtd_vagas_acupadas += 1;
		
		}
	}
}

void atualiza_vagas_subtrai(Turma* tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			ponteiro->qtd_vagas_acupadas -= 1;
		
		}
	}
}

void atualiza_qtd_turmas_soma(Disciplina* di, int codd){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			ponteiro->qtd_turmas += 1;
		
		}
	}
}

void atualiza_qtd_turmas_subtrai(Disciplina* di, int codd){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			ponteiro->qtd_turmas -= 1;
			
		}
	}
}

void lista_nominal(Matricula *ma, Aluno *al, int codd){
	Matricula *ponteiro;
	for(ponteiro=ma; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			imprimir_lista_nominal(al, ponteiro->mat_aluno);
		
		}else{
			//printf("Turma nao existe\n");
		}
	}
}

void imprimir_lista_nominal(Aluno* al, int codd){
	Aluno* ponteiro;
	ponteiro = al;
	if(ponteiro==NULL){
		printf("Lista vazia\n\n");
		return;
		
	}else{
		while(ponteiro!=NULL){
			if(ponteiro->matricula_aluno==codd){
			printf("Nome aluno - %s\n", ponteiro->nome);
			}
			ponteiro = ponteiro->prox;
		}
	}
}

Matricula* discliplina_do_aluno1(Matricula *ma, Turma *tu, Disciplina *di, int codd){
	int disciplina=0;
	Matricula *ponteiro;
	for(ponteiro=ma; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->mat_aluno==codd){
			disciplina = discliplina_do_aluno2(tu, ponteiro->codigo_turma);
			printf("Aluno, matricula [%d] esta matriculado na turma [%d] ofertada pela disciplina", codd, ponteiro->codigo_turma);
			discliplina_do_aluno3(di, disciplina);	
			printf("\n");		
		}
	}
	
	return ma;
	
}

int discliplina_do_aluno2(Turma *tu, int codd){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_turma==codd){
			return ponteiro->codigo_disc;
		
		}
	}
}

void discliplina_do_aluno3(Disciplina *di, int codd){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->codigo_disc==codd){
			printf(" [%s]", ponteiro->nome);
			
		}
	}
}

void total_turmas_por_disciplina(Disciplina *di){
	Disciplina *ponteiro;
	for(ponteiro=di; ponteiro!=NULL; ponteiro=ponteiro->prox){
		printf("A disciplina [%s] tem [%d] turma(s) ofertada(s) ", ponteiro->nome, ponteiro->qtd_turmas);
		printf("\n");
		
	}
}

void total_alunos_por_turma(Turma *tu){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		printf("A turma [%d] tem [%d] aluno(s) matriculado(s)\n", ponteiro->codigo_turma, ponteiro->qtd_vagas_acupadas);
	
	}
}

void turma_lotadas(Turma *tu){
	Turma *ponteiro;
	for(ponteiro=tu; ponteiro!=NULL; ponteiro=ponteiro->prox){
		if(ponteiro->qtd_vagas==ponteiro->qtd_vagas_acupadas){
			printf("A turma [%d] esta lotada ", ponteiro->codigo_turma);
			printf("\n");
		}
	}
}

Disciplina* free_list1(Disciplina* di){
    Disciplina *ponteiro;
    ponteiro = di;
    while(ponteiro!=NULL){
        Disciplina *t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
    }
}

Turma* free_list2(Turma* tu){
    Turma *ponteiro;
    ponteiro = tu;
    while(ponteiro!=NULL){
        Turma *t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
    }
}

Aluno* free_list3(Aluno* al){
    Aluno *ponteiro;
    ponteiro = al;
    while(ponteiro!=NULL){
        Aluno *t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
    }
}

Matricula* free_list4(Matricula* al){
    Matricula *ponteiro;
    ponteiro = al;
    while(ponteiro!=NULL){
        Matricula *t = ponteiro->prox;
        free(ponteiro);
        ponteiro = t;
    }
}
