#define tamanho 50	//tamanho da 'arvore de prioridade' e 'banco de dados'
	//struct salvar a prioridade da pessoa
struct pessoa{
	int dado;
	int rg;
	
};
typedef struct pessoa_p Pessoa_p;

struct pessoa_p{
	int quantidade;
	struct pessoa tam[tamanho];
	
};


	//struct salvar dados da pessoa
struct banco{
	int prioridade;
	int rg;
	int idade;
	char nome[20];
		
};
typedef struct banco Banco;



	//Funcao cria arvore de prioridade
Pessoa_p* cria_pessoa();
	//Funcao insere pessoa na arvore de prioriade
void insere_pessoa(Pessoa_p* ps, int dado, int rg);
	//Funcao que arruma dado da arvore arrecem incerido
void arruma_dado_inserido(Pessoa_p* ps, int qtd);

	//Funcao que remove dado de maior prioridade da arvore
void remove_pessoa(Pessoa_p* ps);
	//Funcao que organiza arvore *coloca no topo o dado de maior prioridade
void organiza_heap(Pessoa_p* ps, int pai);

	//Funcao que busca prioridade que esta no topo
void busca_proximo(Pessoa_p* ps, struct banco* bd, int m);
	//Funcao que imprime toda arvore de prioridade
void imprime_pessoa(Pessoa_p* ps);



	//Funcao cria banco de dados e a inicializa
Banco* alocar_banco(int m);
	//Funcao insere dados no banco de dados
void preencher_banco(struct banco* bd, int m, int prio, int idade, int rg, char* nome);
	
	//Funcao que imprime todo banco de dados
void imprimir_banco(struct banco* bd, int m);
	//Funcao que imprime dados do banco conforme maior prioridade
void imprime_proximo(struct banco* bd, int m, int prio, int rg);
	
	//Funcao que remove dados referente remocao da arvore
void remove_banco(struct banco* bd, int m, int prio, int rg);
	//Funcao que verifica se RG ja existe
int verificar_rg(struct banco* bd, int m, int codigo);
	//Funcao que informa a prioridade para o usuario
void informacao_prio();


	//Funcao libera banco de dados
void libera_banco(struct banco* bd);
	//Funcao libera arvore de prioridade
void libera_pessoa(Pessoa_p* ps);
