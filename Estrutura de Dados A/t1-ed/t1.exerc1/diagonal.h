struct diagonal{
	int ordem;
	int *v;
	
};
typedef struct diagonal Diagonal;

	//Funcao que aloca matriz
int **aloca_matriz(int m);

	//Funcao que preenche a matriz
void preenche_matriz(int m, int **mat);

	//Funcao que preenche a lista
Diagonal preenche_lista(Diagonal di, int m, int **mat);

	//Funcao que imprime a lista
void imprimir_diagonal(Diagonal di, int m);

	//Funcao que imprime determinada posicao da matriz
void imprime_matriz_pos(Diagonal di, int lin, int col, int tam);

	//Funcao que verifica sa a matriz eh diagonal
int verifica_matriz_diagonal(int **mat, int m);

	//Funcao que libera a matriz
void free_matriz(int m, int **mat);

