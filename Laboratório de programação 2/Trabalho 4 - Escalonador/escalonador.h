	//Fila de processos
struct lista_fila{
	char id[3];
	int temp_chegada;
	int temp_execucao;
	char tipo[8];
	struct lista_fila* prox;
	
};
typedef struct lista_fila Lista_fila;

struct fila{
	Lista_fila* ini;
	Lista_fila* fim;
	
};
typedef struct fila Fila;


	//Pilha de processos
struct lista_pilha{
	char id[3];
	int temp_chegada;
	int temp_execucao;
	char tipo[8];
	struct lista_pilha* prox;
	
};
typedef struct lista_pilha Lista_pilha;

struct pilha{
	Lista_pilha* prim;

};
typedef struct pilha Pilha;


	//Fila ja processados
struct lista_processados{
	char id[3];
	int temp_chegada;
	int temp_execucao;
	char tipo[8];
	struct lista_processados* prox;
	
};
typedef struct lista_processados Lista_processados;

struct fila_processados{
	Lista_processados* ini;
	Lista_processados* fim;
	
};
typedef struct fila_processados Fila_processados;


	//Fila auxiliar de processos
struct lista_fila_aux{
	char id[3];
	int temp_chegada;
	int temp_execucao;
	char tipo[8];
	struct lista_fila_aux* prox;
	
};
typedef struct lista_fila_aux Lista_fila_aux;

struct fila_aux{
	Lista_fila_aux* ini;
	Lista_fila_aux* fim;
	
};
typedef struct fila_aux Fila_aux;


	//Pilha auxiliar de processos
struct lista_pilha_aux{
	char id[3];
	int temp_chegada;
	int temp_execucao;
	char tipo[8];
	struct lista_pilha_aux* prox;
	
};
typedef struct lista_pilha_aux Lista_pilha_aux;

struct pilha_aux{
	Lista_pilha_aux* prim;

};
typedef struct pilha_aux Pilha_aux;


	//Funcao cria fila de processos
Fila* fila_cria(void);
	//Funcao cria pilha de processos
Pilha* pilha_cria(void);
	//Funcao cria fila ja processados
Fila_processados* fila_processados_cria(void);
	//Funcao cria pilha auxiliar de processos
Pilha_aux* pilha_aux_cria(void);
	//Funcao cria fila auxiliar de processos
Fila_aux* fila_aux_cria(void);


	//Funcao que insere conteudo na fila de processos
void insere_fila(Fila* f, int cont_t_chegada);
	//Funcao que insere conteudo na pilha de processos
void insere_pilha(Pilha* p, char* id, int chegada, int tempo, char* tipo);
	//Funcao que insere conteudo no fim da fila de processos
void insere_fila_temp_execusao(Fila* f, char* id, int chegada, int tempo, char* tipo, int cont_t_chegada);
	//Funcao que insere conteudo na fila ja processados
void insere_fila_processados(Fila_processados* fp, char* id, int chegada, int tempo, char* tipo);
	//Funcao que insere conteudo na pilha auxiliar de processos
void insere_pilha_aux(Pilha_aux* px, char* id, int chegada, int tempo, char* tipo);
	//Funcao que insere conteudo na fila auxiliar de processos
void insere_fila_aux(Fila_aux* fx, char* id, int chegada, int tempo, char* tipo);

	//Funcao que insere na fila de processos
//void realoca_fila_insere(Fila* f, char* id, int chegada, int tempo, char* tipo);

	//Funcao que insere conteudo na fila de processos
void realoca_fila_insere_1(Fila* f, char* id, int chegada, int tempo, char* tipo);
	//Funcao que insere conteudo na fila de processos
void realoca_fila_insere_2(Fila* f, char* id, int chegada, int tempo, char* tipo);


	//Funcao que empilha processos na busca por 'sistema'
	//Funcao que insere na fila de processados 'caso seja sistema'
	//Funcao que insere no final na fila de processos 'caso temp_execucao > TP'
	//Funcao libera fila auxiliar de processos
	//Funcao libera pilha auxiliar de processos
void busca(Fila* f, Pilha* p, int temp, int cont_t_chegada, Fila_processados* fp, Pilha_aux* px, Fila_aux* fx);


	//Funcao que insere na fila de processados 'caso seja usuario'
	//Funcao que insere no final na fila de processos 'caso temp_execucao > TP'
void processa(Fila* f, Fila_processados* fp, int temp, int cont_t_chegada, int aux2);


	//Funcao realoca conteudo da pilha auxiliar para fila de processos
void realoca_fila_1(Pilha_aux* px, Fila* f);
	//Funcao realoca conteudo da fila auxiliar para fila de processos
void realoca_fila_2(Fila_aux* fx, Fila* f);


	//Funcao que insere na pilha auxiliar de processos o conteudo da pilha de processos
void busca_pilha(Pilha* p, Pilha_aux* px);
	//Funcao que insere na fila auxiliar de processos o conteudo da fila de processos
void busca_fila(Fila* f, Fila_aux* fx);


	//Funcao que verifica se do tipo 'sistema'
int procura_processo(Fila* f, int codigo);
	//Funcao que verifica as palavras 'usuario' e 'sistema' estao corretas 
int valida_processo(char* processo);
	//Funcao que verifica se o tempo de execucao eh maior que TP
int valida_tem_exe(Fila* f, int codigo, int temp);


	//Funcao verifica quando fila esta vazia
int verifica_fila_vazia(Fila* f);
	//Funcao verifica qual o ultimo tempo de chegada
int contador_fila(Fila* f);


	//Funcao exclui primeira posicao da fila de processos
void exclui_fila(Fila* f);
	//Funcao exclui topo da pilha de processos
void exclui_pilha(Pilha* p);
	//Funcao exclui topo da pilha auxiliar de processos
void exclui_pilha_aux(Pilha_aux* px);
	//Funcao exclui primeira posicao da fila auxiliar de processos
void exclui_fila_aux(Fila_aux* fx);


	//Funcao imprime fila de processos
void imprime_fila(Fila* f);
	//Funcao imprime pilha de processos
void imprime_pilha(Pilha* p);
	//Funcao imprime fila ja processados
void imprime_fila_processados(Fila_processados* fp);
	//Funcao imprime pilha auxiliar de processos
void imprime_pilha_aux(Pilha_aux* px);
	//Funcao imprime fila auxiliar de processos
void imprime_fila_aux(Fila_aux* fx);


	//Funcao libera fila de processos
void libera_fila(Fila* f);
	//Funcao libera pilha de processos
void libera_pilha(Pilha* p);
	//Funcao libera fila auxiliar de processos
void libera_fila_aux(Fila_aux* fx);
	//Funcao libera pilha auxiliar de processos
void libera_pilha_aux(Pilha_aux* px);
	//Funcao libera fila ja processados
void libera_fila_processados(Fila_processados* fp);
