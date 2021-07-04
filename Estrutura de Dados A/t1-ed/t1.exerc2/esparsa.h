	//Struct guarda a linha/coluna e valor da matriz
struct lista{
	int linha;
	int coluna;
	int info;
	struct lista *prox;
};
typedef struct lista Lista;
	//Struct guarda quantidade de linhas/colunas da matriz
struct esparsa{
	int linhas;
	int colunas;
	struct lista *prim;
};
typedef struct esparsa Esparsa;


	//Funcao que cria a esparsa
Esparsa *cria_esparsa(int lin, int col);

	//Funcao que aloca a esparsa
Esparsa* aloca_esparsa(Esparsa* es, Lista *li, int lin, int col);

	//Funcao que aloca matriz
int **aloca_matriz(int lin, int col);

	//Funcao que zera a matriz
void zerar_matriz(int **mat, int lin, int col);

	//Funcao que preenche a matriz
void preenche_matriz(int **mat, int lin, int col);

	//Funcao que verifica os numeros da matriz
int verifica_matriz(int **mat, int lin, int col, Esparsa *es);

	//Funcao que insere os numeros verificados pela matriz na lista
void preenche_lista(Esparsa *es, int lin, int col, int valor);

	//Funcao que imprime a esparsa
void imprimir_esparsa(Esparsa* es);

	//Funcao que imprime determinada posicao da matriz
void imprime_matriz_pos(int linha, int coluna, Esparsa* es);

	//Funcao que imprime o somatorio de determinada linha da matriz
void somatorio_matriz(int lin, Esparsa* es);

	//Funcao que conta quantos valores diferentes de 0 contem na matriz
int percentual_nao_nulos(Esparsa* es);

	//Funcao que recebe a quantidade de valores diferentes e calcula o percentual
void calcula_percentual(int qtd, int lin, int col);

	//Funcao que libera a matriz
void free_matriz(int m, int **mat);

	//Funcao que libera as listas
void esparsa_free(Esparsa *es);
