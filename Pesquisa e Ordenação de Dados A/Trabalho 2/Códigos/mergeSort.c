#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>


void merge_sort(int *vet, int inicio, int fim);
void merge(int *vet, int inicio, int meio, int fim);
void imprime_vetor(int *vet, int tam);


int main(){
	clock_t t1, t2;
	t1 = clock();
	
	const int tamanho = 1000;
	int aux = 0;	
	FILE *pont_arq = fopen("1mil-10milhao.txt", "r");	
	int *vetor=(int*)malloc(tamanho*sizeof(int));
	
	
	if(tamanho){
		while(aux<tamanho){
			fscanf(pont_arq, "%d", &vetor[aux]);
			aux++;
			
		}
	}else{
		printf("Arquivo vazio");
		
	}		
	fclose(pont_arq);
	
	printf("NAO ORDENADOS\n");
	//imprime_vetor(vetor, tamanho);	
	printf("\n\nORDENADOS\n\n");	
	merge_sort(vetor, 0, tamanho-1);	
	//imprime_vetor(vetor, tamanho);
	printf("\nFIM!\n");
	
	
	t2 = clock();	
	//float diferenca = (((float)t2 - (float)t1)/ 1000000.0F);
	double diferenca = ((t2 - t1)*1000.0/CLOCKS_PER_SEC);
	printf("\nTempo de execucao: %g ms", diferenca);
	
	return(0);
	
}

void merge_sort(int *vet, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim)/2);
		merge_sort(vet, inicio, meio);
		merge_sort(vet, meio+1, fim);
		merge(vet, inicio, meio, fim);
	}
}

void merge(int *vet, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j, k;
	int fim1=0, fim2=0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int*)malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i=0; i<tamanho; i++){
			if(!fim1 && !fim2){
				if(vet[p1] < vet[p2]){
					temp[i] = vet[p1++];
					
				}else{
					temp[i] = vet[p2++];
					
				}
				if(p1 > meio){ fim1 = 1; }
				if(p2 > fim){ fim2 = 1; }
			
			}else{
				if(!fim1){
					temp[i] = vet[p1++];
					
				}else{
					temp[i] = vet[p2++];
					
				}
			}
		}
		for(j=0, k=inicio; j<tamanho; j++, k++){
			vet[k] = temp[j];
			
		}
	}
	free(temp);
}

void imprime_vetor(int *vet, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("[%d]-> %d\n", i, vet[i]);
		
	}
}
