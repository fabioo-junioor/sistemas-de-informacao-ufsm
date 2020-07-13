#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>
#include "listas.h"

int main() {
	Disciplina* di;
	Turma* tu;
	Aluno* al;
	Matricula* ma;
	
	di = cria_disciplina();
	tu = cria_turma();
	al = cria_aluno();
	ma = cria_matricula();
	
	menu(di, tu, al, ma);
	
	free_list1(di);
	free_list2(tu);
	free_list3(al);
	free_list4(ma);
	
	system("PAUSE");
	return 0;
	
}
