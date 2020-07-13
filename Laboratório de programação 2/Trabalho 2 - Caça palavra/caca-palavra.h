	//Funcao aloca matriz
char **aloca_matriz(int m, int n);
	//Funcao preenche matriz
void preenche_matriz(int linha, int coluna, char **mat);
	//Funcao que imprime matriz
void imprime_matriz(int lin, int col, char **mat);
	//Funcao verifica tamanho da palavra
int verifica_tam_palavra(char *palavra);
	//Funcao libera matriz
void free_matriz(int lin, char **mat);
	//Funcao libera palavra
void free_palavra(char *palavra);


	//Funcao que verifica em toda matriz se palavra existe
void verificar_matriz(char **mat, char *palavra, int linhas, int colunas);


	//Funcao que verifica se palavra esta na HD
int horizontal_direta(char **mat, char *vet, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na HR
int horizontal_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na VD
int vertical_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na VR
int vertical_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na DPD
int diagonal_principal_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na DPR
int diagonal_principal_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na DSD
int diagonal_secundaria_direta(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
	//Funcao que verifica se palavra esta na DSR
int diagonal_secundaria_reversa(char **mat, char *palavra, int lin, int col, int tam_p, int linhas, int colunas);
