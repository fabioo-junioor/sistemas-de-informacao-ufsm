	//Struct guarda ordem/valores identidade da matriz
struct identidade{
	int ordem;
	int *v;
	
};
typedef struct identidade Identidade;

	// Funcao que alocar matriz
int **aloca_matriz(int m);

	// Funcao que preenche matriz
void preenche_matriz(int m, int **mat);

	// Funcao que preenche a lista
Identidade preenche_lista(int m, int **mat);

	// Funcao que imprime a lista
void imprimir_identidade(Identidade id, int m);

	// Funcao que verifica diagonal da matriz '=1'
int verifica_matriz_identidade(int **mat, int m);

	// Funcao que verifica os demais posicoes da matriz '=0'
int verifica_matriz_resto(int **mat, int m);

	// Funcao que libera a matriz
void free_matriz(int m, int **mat);
