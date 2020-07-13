#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "caca-palavra.h"

char **aloca_matriz(int m, int n){
    int i; 
	char **mat;
    mat = (char**)malloc(m*sizeof(char*));
	for(i=0; i<m; i++){
		mat[i] = (char*)malloc(n*sizeof(char));
	}
	if(mat==NULL){
		printf("\n Erro alocacao");
		system("pause");
		exit(1);
	}
	return mat;
}

void preenche_matriz(int linha, int coluna, char **mat){
	int i=0, j=0;
	srand(time(NULL));
	for(i=0; i<linha; i++){
		for(j=0; j<coluna; j++){
			mat[i][j] = 97 +(char)(rand()%26);
		}
	}
}

void imprime_matriz(int lin, int col, char **mat){
	int i=0, j=0;
	for(i=0; i<lin; i++){
		for(j=0; j<col; j++){
			printf("  %c  ", mat[i][j]);
		}
		printf("\n");
    }
}

int verifica_tam_palavra(char *palavra){
	int tam=0, i=0;
	for(i=0; palavra[i]!='\0'; i++){
		tam += 1;
	}
	return tam;
	
}

void free_matriz(int lin, char **mat){
    int i=0;
    for(i=0; i<lin; i++){
        free(mat[i]);
    }
    free(mat);
}

void free_palavra(char *palavra){
    free(palavra);
    
}

void verificar_matriz(char **mat, char *palavra, int linhas, int colunas){
	int i=0, j=0, z=0, tam_palavra=0;
	int valida=0;
	tam_palavra = verifica_tam_palavra(palavra);
		
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			valida = horizontal_direta(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
				
			valida = horizontal_reversa(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
			
			valida = vertical_direta(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
				
			valida = vertical_reversa(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
				
			valida = diagonal_principal_direta(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
				
			valida = diagonal_principal_reversa(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
				
			valida = diagonal_secundaria_direta(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
				
			valida = diagonal_secundaria_reversa(mat, palavra, i, j, tam_palavra, linhas, colunas);
			if(valida==1){i = linhas; j = colunas; break;}
			
		}
	}
	if(valida==0){
		printf("Palavra [%s] nao encontrada!\n", palavra);
			
	}
}

int horizontal_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
	while((k<tam_p) && (mat[i][j]==palavra[k])){
		fim_i = i;
		fim_j = j;
		k++;
		j++;
		if(j==colunas){
			j = 0;
			
		}
		if(k==tam_p){
			printf("\nA palavra %s ocorre na horizontal direta, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);		
			vl = 1;
		}
	} 
	return vl;   
}

int horizontal_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
    while((k<tam_p) && (mat[i][j]==palavra[k])){
		fim_i = i;
		fim_j = j;
		k++;
		j--;
		if(j<0){
			j = colunas-1;
			
		}
		if(k==tam_p){
    		printf("\nA palavra %s ocorre na horizontal reversa, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);
			vl = 1;
		}
	}
	return vl;
}

int vertical_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
    while((k<tam_p) && (mat[i][j]==palavra[k])){
		fim_i = i;
		fim_j = j;
		k++;
		i++;
		if(i==linhas){
			i = 0;
			
		}
		if(k==tam_p){
    		printf("\nA palavra %s ocorre na vertical direta, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);
			vl = 1;
		}
	}
	return vl;		
}

int vertical_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
    while((k<tam_p) && (mat[i][j]==palavra[k])){
		fim_i = i;
		fim_j = j;
		k++;
		i--;
		if(i<0){
			i = linhas-1;
			
		}
		if(k==tam_p){
    		printf("\nA palavra %s ocorre na vertical reversa, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);
			return 1;
		}
	}
		
}

int diagonal_principal_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, inicio_i=0, inicio_j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
	while((k<tam_p) && (palavra[k]==mat[i][j])){
		fim_i = i;
		fim_j = j;
		k++;
		i++;
		j++;
		if(i==linhas){
			i = 0;
			
		}
		if(j==colunas){
			j = 0;
			
		}
		if(k==tam_p){
			printf("\nA palavra %s ocorre na diagonal principal direta, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);
			vl = 1;
		}
	}
	return vl;		
}

int diagonal_principal_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
	while((k<tam_p) && (palavra[k]==mat[i][j])){
		fim_i = i;
		fim_j = j;
		k++;
		i--;
		j--;
		if(i<0){
			i = linhas-1;
			
		}
		if(j<0){
			j = colunas-1;
			
		}
		if(k==tam_p){
    		printf("\nA palavra %s ocorre na diagonal principal reversa, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, (lin-(tam_p-1)), (col-(tam_p-1)));
			vl = 1;
		}
	}
	return vl;
}

int diagonal_secundaria_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
	while((k<tam_p) && (palavra[k]==mat[i][j])){
		fim_i = i;
		fim_j = j;
		k++;
		i++;
		j--;
		if(i==linhas){
			i = 0;
			
		}
		if(j<0){
			j = colunas-1;
			
		}
		if(k==tam_p){
    		printf("\nA palavra %s ocorre na diagonal secundaria direta, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);
			vl = 1;
		}
	}
	return vl;
}

int diagonal_secundaria_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas){
	int k=0, i=0, j=0, fim_i=0, fim_j=0, vl=0;
	i = lin;
	j = col;
	while((k<tam_p) && (palavra[k]==mat[i][j])){
		fim_i = i;
		fim_j = j;
		k++;
		i--;
		j++;
		if(i<0){
			i = linhas-1;
			
		}
		if(j==colunas){
			j = 0;
			
		}
		if(k==tam_p){
    		printf("\nA palavra %s ocorre na diagonal secundaria direta, iniciando na posicao [%d][%d] e terminando na posicao [%d][%d]\n", palavra, lin, col, fim_i, fim_j);
			vl = 1;
		}
	}
	return vl;
}
