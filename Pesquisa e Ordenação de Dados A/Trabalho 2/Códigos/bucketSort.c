#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#define tam_balde 7	//total de elementos maximos por balde
#define tamanho_vet 1000000

struct balde{
	int quantidade;
	int valores[tam_balde];
};

void imprime_vetor(int *vet, int tam);
void bucket_sort(int *vet, int tam_vetor);
void insertionSort(int *vet, int tam_vetor);

int main(){
	clock_t t1, t2;
	t1 = clock();
		
	int aux = 0;
	FILE *pont_arq = fopen("1milhao-10milhao.txt", "r");	
	int *vetor=(int*)malloc(tamanho_vet*sizeof(int));

	if(tamanho_vet){
		while(aux<tamanho_vet){
			fscanf(pont_arq, "%d", &vetor[aux]);
			aux++;
			
		}
	}else{
		printf("Arquivo vazio");
		
	}		
	fclose(pont_arq);
	
	printf(">>NAO ORDENADOS<<\n\n");
	//imprime_vetor(vetor, tamanho_vet);	
	printf(">>ORDENADOS<<\n\n");
	bucket_sort(vetor, tamanho_vet);		
	//imprime_vetor(vetor, tamanho_vet);
	printf("\nFIM!\n");
	
	
	t2 = clock();	
	double diferenca = ((t2 - t1)*1000.0/CLOCKS_PER_SEC);
	printf("\nTempo de execucao: %g ms", diferenca);
	
	return(0);
	
}

void insertionSort(int *vet, int tam_vetor){
	int i, j, aux;
	for(i=1; i<tam_vetor; i++){
		aux = vet[i];
		for(j=i; (j>0) && (aux<vet[j-1]); j--)
			vet[j] = vet[j-1];
			
		vet[j] = aux;
	}
}

void bucket_sort(int *vet, int tam_vetor){
	int i, j, maior, menor, num_baldes, pos;
	struct balde *bd;
	
	//acha maior e menor valor
	maior = menor = vet[0];
	for(i=1; i<tam_vetor; i++){
		if(vet[i] > maior){
			maior = vet[i];
			
		}
		if(vet[i] < menor){
			menor = vet[i];
			
		}
	}
	
	printf("\nMAIOR:[%d]  MENOR:[%d]\n", maior, menor);
	//inicializa baldes
	num_baldes = (maior - menor)/tam_balde+1;
	printf("\nNUMERO DE BALDES %d\n", num_baldes);
	bd = (struct balde *) malloc(num_baldes * sizeof(struct balde));
	for(i=0; i<num_baldes; i++){
		bd[i].quantidade = 0;
		
	}
	
	//distribui os valores nos baldes
	for(i=0; i<tam_vetor; i++){
		pos = (vet[i] - menor)/tam_balde;
		bd[pos].valores[bd[pos].quantidade] = vet[i];
		bd[pos].quantidade++;
		
	}
	
	//ordena baldes e coloca no vetor
	pos = 0;
	for(i=0; i < num_baldes; i++){
		insertionSort(bd[i].valores, bd[i].quantidade);
		for(j=0; j<bd[i].quantidade; j++){
			vet[pos] = bd[i].valores[j];
			pos++;
		}
	}
	free(bd);
}

void imprime_vetor(int *vet, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("[%d]-> %d\n", i, vet[i]);
		
	}
}
