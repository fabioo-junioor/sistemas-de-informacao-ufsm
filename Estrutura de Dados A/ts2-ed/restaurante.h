	//struct mesas do restaurante
struct restaurante{
	int num_mesa;
	int lugares_acupados;
	int comanda_mesa;
	int mesa_livre;
	
};
typedef struct restaurante Restaurante;

	//Fila de espera cliente
struct lista_espera_cliente{
	int senha_grupo;
	int tam_grupo;
	struct lista_espera_cliente* prox;
	
};
typedef struct lista_espera_cliente Lista_espera_cliente;

struct fila_espera_cliente{
	Lista_espera_cliente* ini;
	Lista_espera_cliente* fim;
	
};
typedef struct fila_espera_cliente Fila_espera_cliente;


	//Pilha cliente
struct lista_pilha_cliente{
	int senha;
	int tam_grupo;
	struct lista_pilha_cliente* prox;
	
};
typedef struct lista_pilha_cliente Lista_pilha_cliente;

struct pilha_cliente{
	Lista_pilha_cliente* prim;

};
typedef struct pilha_cliente Pilha_cliente;


	//Pilha cliente auxiliar
struct lista_pilha_cliente_aux{
	int senha;
	int tam_grupo;
	struct lista_pilha_cliente_aux* prox;
	
};
typedef struct lista_pilha_cliente_aux Lista_pilha_cliente_aux;

struct pilha_cliente_aux{
	Lista_pilha_cliente_aux* prim;

};
typedef struct pilha_cliente_aux Pilha_cliente_aux;


	//Fila do estacionamento
struct lista_estacionamento{
	int ticket_id;
	char placa_carro[8];
	struct lista_estacionamento* prox;
	
};
typedef struct lista_estacionamento Lista_estacionamento;

struct fila_estacionamento{
	Lista_estacionamento* ini;
	Lista_estacionamento* fim;
	
};
typedef struct fila_estacionamento Fila_estacionamento;


	//Pilha do estacionamento
struct lista_pilha_estacionamento{
	int ticket_id;
	char placa_carro[8];
	struct lista_pilha_estacionamento* prox;
	
};
typedef struct lista_pilha_estacionamento Lista_pilha_estacionamento;

struct pilha_estacionamento{
	Lista_pilha_estacionamento* prim;

};
typedef struct pilha_estacionamento Pilha_estacionamento;


	//Pilha do estacionamento auxiliar
struct lista_pilha_estacionamento_aux{
	int ticket_id;
	char placa_carro[8];
	struct lista_pilha_estacionamento_aux* prox;
	
};
typedef struct lista_pilha_estacionamento_aux Lista_pilha_estacionamento_aux;

struct pilha_estacionamento_aux{
	Lista_pilha_estacionamento_aux* prim;

};
typedef struct pilha_estacionamento_aux Pilha_estacionamento_aux;

/*###################################################################################*/
	
	//Funcao cria fila espera cliente
Fila_espera_cliente* fila_espera_cliente_cria(void);
	//Funcao cria fila estacionamento
Fila_estacionamento* fila_estacionamento_cria(void);
	//Funcao cria pilha cliente
Pilha_cliente* pilha_cliente_cria(void);
	//Funcao cria pilha cliente auxiliar
Pilha_cliente_aux* pilha_cliente_aux_cria(void);
	//Funcao cria pilha estacionamento
Pilha_estacionamento* pilha_estacionamento_cria(void);
	//Funcao cria pilha estacionamento auxiliar
Pilha_estacionamento_aux* pilha_estacionamento_aux_cria(void);
	//Funcao cria matriz
Restaurante** aloca_matriz(int linha, int coluna);


	//Funcao que inicializa matriz
void preencher_matriz(struct restaurante** res, int linha, int coluna);


	//Funcao insere na fila de espera
void insere_fila_espera(Fila_espera_cliente* f, int tam_grupo, int senha);
	//Funcao insere na pilha cliente
void insere_pilha_cliente(Pilha_cliente* pc, int senha, int tamanho);
	//Funcao insere na pilha cliente auxiliar
void insere_pilha_cliente_aux(Pilha_cliente_aux* pcx, int senha, int tamanho);
	//Funcao insere na fila do estacionamento
void insere_fila_estacionamento(Fila_estacionamento* e, int ticket);
	//Funcao insere na pilha do estacionamento
void insere_pilha_estacionamento(Pilha_estacionamento* pe, int ticket, char* placa);
	//Funcao insere na pilha do estacionamento auxiliar
void insere_pilha_estacionamento_aux(Pilha_estacionamento_aux* pex, int ticket, char* placa);


	//Funcao que realoca fila do estacionamento
void realoca_fila_estacionamento(Fila_estacionamento* e, int ticket, char* placa);
	//Funcao aloca cliente na mesa
void aloca_cliente(struct restaurante** res, int linha, int coluna, int grupo, Fila_espera_cliente* f);
	//Funcao que libera mesa acupada
void liberar_mesa(struct restaurante** res, int linha, int coluna, int codigo_mesa);
	//Funcao que que verifica tamanho do primeiro grupo da fila de espera
void chama_fila_espera(Fila_espera_cliente* f, struct restaurante** res, int linha, int coluna);
	//Funcao que aloca cliente na mesa a partir da fila de espera
void insere_fila_mesa(struct restaurante** res, int linha, int coluna, int codigo);


	//Funcao que chama pilha cliente se grupo desiste da fila de espera
void grupo_desiste_fila_espera(Fila_espera_cliente* f, Pilha_cliente* pc, int codigo);
	//Funcao que chama pilha auxiliar para inverter ordem das posicoes
void atualiza_pilha_cliente(Pilha_cliente_aux* pcx, Pilha_cliente* pc);
	//Funcao que realoca cliente na fila a partir da pilha auxiliar
void atualiza_fila_espera(Pilha_cliente_aux* pcx, Fila_espera_cliente* f);
	
	
	//Funcao que chama pilha estacionamento se carro sair
void retirada_de_carro(Fila_estacionamento* e, Pilha_estacionamento* pe, int codigo);
	//Funcao que chama pilha auxiliar para inverter ordem das posicoes	
void atualiza_pilha_estacionamento(Pilha_estacionamento_aux* pex, Pilha_estacionamento* pe);
	//Funcao que realoca carros na fila a partir da pilha auxiliar
void atualiza_fila_estacionamento(Pilha_estacionamento_aux* pex, Fila_estacionamento* e);


	//Funcao que atualiza se mesa esta livre = 0 ou nao = 1
void atualiza_mesas_livres(struct restaurante** res, int linha, int coluna);


	//Funcao que verifica se a lugares livres
int verifica_lugares_livres(struct restaurante **res, int linha, int coluna);
	//Funcao que verifica o tamanho do grupo
int verifica_tam_grupo();
	//Funcao que verifica se codigo do grupo existe
int verifica_codigo_grupo_existe(Fila_espera_cliente* f, int codigo);
	//Funcao que verifica se ticket do estacionamento ja existe
int verifica_ticket_existe(Fila_estacionamento* e, int codigo);
	//Funcao que retorna ultimo codigo de grupo
int contador_fila_senha(Fila_espera_cliente* f);
	//Funcao que verifica se ah vagas no estacionamento
int verifica_vagas_estacionamento(Fila_estacionamento* e);



	//Funcao que imprime lugares acupados de determinada mesa
void consulta_mesa_qtd(struct restaurante** res, int linha, int coluna);
	//Funcao que imprime lugares de todas as mesas
void consulta_mesa_todas(struct restaurante** res, int linha, int coluna);
	//Funcao que imprime fila de espera de cliente
void consulta_fila_espera(Fila_espera_cliente* f);
	//Funcao que imprime fila do estacionamento
void consulta_estacionamento_carro(Fila_estacionamento* e);
	//Funcao que imprime a matriz
void imprimir_matriz(struct restaurante** res, int linha, int coluna);


void imprime_fila_espera(Fila_espera_cliente* f);
void imprime_pilha_cliente(Pilha_cliente* pc);
void imprime_pilha_cliente_aux(Pilha_cliente_aux* pcx);
void imprime_fila_estacionamento(Fila_estacionamento* e);
void imprime_pilha_estacionamento(Pilha_estacionamento* pe);
void imprime_pilha_estacionamento_aux(Pilha_estacionamento_aux* pex);


	//Funcao exclui primeira posicao da fila de espera
void exclui_fila_cliente(Fila_espera_cliente* f);


	//Funcao que libera a matriz
void free_matriz(struct restaurante** res, int m);
	//Funcao que libera fila espera cliente
void libera_fila_espera_cliente(Fila_espera_cliente* f);
	//Funcao que libera pilha cliente
void libera_pilha_cliente(Pilha_cliente* pc);
	//Funcao que libera pilha cliente auxiliar
void libera_pilha_cliente_aux(Pilha_cliente_aux* pcx);
	//Funcao que libera fila estacionamento
void libera_fila_estacionamento(Fila_estacionamento* e);
	//Funcao que libera pilha estacionamento
void libera_pilha_estacionamento(Pilha_estacionamento* pe);
	//Funcao que libera pilha estacionamento auxiliar
void libera_pilha_estacionamento_aux(Pilha_estacionamento_aux* pex);
