#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	FILE *arquivo;
	char nome[10];
	int quantidade, i;
	
	printf("Digite o nome do arquivo:");
	scanf("%s", nome);
	printf("Digite a quantidade de numeros:");
	scanf("%d", &quantidade);
	
	arquivo = fopen(nome, "w");
	
	if (arquivo==NULL) {
		printf("Falha ao criar o arquivo.");
		exit(1);
	}
	else {
		//srand(time(NULL));
		for (i=1;i<=quantidade;i++) 
			fprintf(arquivo, "%d\n", rand()%quantidade);
	}
	fclose(arquivo);
	return 0;
}
