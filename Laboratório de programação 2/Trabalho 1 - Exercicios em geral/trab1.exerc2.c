/*Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio r. Esta
função deve obedecer ao protótipo: void calc_esfera (float r, float *area, float *volume)
A área da superfície e o volume são dados, respectivamente, por 4r2 e 4r3/3*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define pi 3.14

void calc_esfera(float r, float *area, float *volume){
	printf("Informe o raio: ");
	scanf("%f", &r);

	*area = ((4*pi)*pow(r,2));
	*volume = ((4*pi)*pow(r,3))/3;

	printf("Area da esfera: %.2f\n", *area);
	printf("Volume da esfera: %.2f\n", *volume);
}
int main(){
	float r, area, volume;
	calc_esfera(r, &area, &volume);
}
