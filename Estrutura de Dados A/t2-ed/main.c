#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "t2.h"

int main(int argc, char *argv[]) {
	Banco *bd;
	Pessoa_p* ps;	
	
	bd = alocar_banco(tamanho);
	ps = cria_pessoa();
	
	
	menu(ps, bd);
	
	libera_banco(bd);
	libera_pessoa(ps);
	
	system("PAUSE");
	return 0;
	
}
