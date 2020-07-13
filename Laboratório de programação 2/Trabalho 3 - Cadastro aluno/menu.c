#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "listas.h"

void menu(Disciplina *di, Turma *tu, Aluno *al, Matricula *ma){
	int op=0, sair=0, cod_disciplina=0, cod_turma=0; 
	int mat_aluno=0, turma=0, matricula_aluno=0;
	
		printf("##############\n");
		printf("Cadastro aluno\n");
		printf("#### Menu ####\n");
		printf("\n");
	while(sair!=22){
		int valida=0;
		printf("1 - Cadastrar disciplina\n");	
		printf("2 - Cadastrar turma\n");
		printf("3 - Cadastrar aluno\n");
		printf("-------------------------------------\n");
		printf("4 - Excluir disciplina\n");
		printf("5 - Excluir turma\n");
		printf("6 - Excluir aluno\n");
		printf("-------------------------------------\n");
		printf("7 - Listar todas as disciplinas\n");
		printf("8 - Listar todas as turmas\n");	
		printf("9 - Listar todos os alunos\n");	
		printf("--------------------------------------------\n");
		printf("0 - Matricular aluno em alguma turma\n");	
		printf("10 - Excluir matricula de aluno\n");
		printf("11 - Listar todos alunos matriculados\n");
		printf("---------------------------------------------------------\n");
		printf("12 - Lista nominal dos alunos matriculados por turma [R1]\n");
		printf("13 - Quantidade de turmas em cada disciplina [R2]\n");
		printf("14 - Nomes das disciplinas que o aluno cursa [R3]\n");
		printf("15 - Quantidade de alunos matriculados por turma [R4]\n");
		printf("16 - Turmas que estao lotadas [R5]\n");
		printf("----------------------------------------------------------\n");
		scanf("%d", &op);
		printf("\n\n");
		
		switch (op){
			case 1:
				di = cadastrar_disciplina(di);
				break;
				
			case 2:
				tu = cadastrar_turma(tu, di);
				break;
				
			case 3:
				al = cadastrar_aluno(al);
				break;
				
			case 4:
				printf("Informe o codigo da disciplina a ser excluida: ");
				scanf("%d", &cod_disciplina);	
				ma = buscar_matricula_turma_disciplina(ma, tu, cod_disciplina);
				di = buscar_disciplina(di, cod_disciplina);
				tu = buscar_turma_disciplina(tu, cod_disciplina);								
				break;
				
			case 5:
				printf("Informe o codigo da turma a ser excluida: ");
				scanf("%d", &cod_turma);
				tu = buscar_turma(tu, di, cod_turma);
				ma = buscar_matricula_turma(ma, cod_turma);
				break;
				
			case 6:
				printf("Informe a matricula do aluno a ser excluido: ");
				scanf("%d", &mat_aluno);
				al = buscar_aluno(al, mat_aluno);
				ma = buscar_matricula_aluno(ma, tu, mat_aluno);				
				break;
				
			case 7:
				imprimir_disciplina(di);
				break;
				
			case 8:
				imprimir_turma(tu);
				break;
					
			case 9:
				imprimir_aluno(al);
				break;	
				
			case 0:
				ma = matricular_aluno(ma, tu, al);
				break;
				
			case 10:
				ma = excluir_matricula(ma, tu);
				break;
				
			case 11:
				imprimir_matriculas(ma);
				break;
				
			case 12:
				printf("Informe o codigo da turma: ");
				scanf("%d", &turma);
				lista_nominal(ma, al, turma);
				break;
								
			case 13:
				total_turmas_por_disciplina(di);
				break;
				
			case 14:
				printf("Informe a matricula do aluno: ");
				scanf("%d", &matricula_aluno);
				ma = discliplina_do_aluno1(ma, tu, di, matricula_aluno);
				break;
				
			case 15:
				total_alunos_por_turma(tu);
				break;
			
			case 16:
				turma_lotadas(tu);
				break;
				
			default:
				printf("Codigo invalido!\n");
				
		}
		printf("\n[22] para sair ou [33] para continuar--> ");
		scanf("%d", &sair);
		printf("\n");
		
	}	
}
