/*Faça um programa que leia a base e a altura de um retângulo (tipo Retângulo). A seguir, chame uma
função que calcule e mostre na tela o perímetro e a área deste retângulo.
Sugestão para a definição do tipo Retangulo:
struct retangulo
{
float base;
float altura;
float perimetro;
float area;
};
typedef struct retangulo Retangulo;
Considere um vetor de 5 retângulos.
Sugestão para o protótipo da função: void calculaPeriArea (Retangulo ret);*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
	float base;
	float altura;
	float perimetro;
	float area;
} retangulo;
retangulo Retangulo[3];

void atribuir(){
	int i;
	for(i=0; i<3; i++){
		printf("Qual base do retangulo %d: ", i);
		scanf("%f", &Retangulo[i].base);
		printf("Qual altura do retangulo %d: ", i);
		scanf("%f", &Retangulo[i].altura);
	}
}
void calcula_peri_area(){
	int i;
	for(i=0; i<3; i++){
		Retangulo[i].area = Retangulo[i].base*Retangulo[i].altura;
		Retangulo[i].perimetro = 2*(Retangulo[i].altura+Retangulo[i].base);
	}
}
void imprimir_retangulo(){
	int i;
	for(i=0; i<3; i++){
		printf("\nArea do retangulo %d: %.2f\n", i, Retangulo[i].area);
		printf("Perimetro do retangulo %d: %.2f\n\n", i, Retangulo[i].perimetro);
	}
}
int main(){
	atribuir();
	calcula_peri_area();
	imprimir_retangulo();
	return 0;
}

