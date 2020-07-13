struct disciplina{
	int codigo_disc;
	char nome[30];
	int creditos;
	int qtd_turmas;
	struct disciplina* prox;

};
typedef struct disciplina Disciplina;

struct turma{
	int codigo_turma;
	int codigo_disc;
	int qtd_vagas;
	int qtd_vagas_acupadas;
	char dia[10];
	char hora[10];
	char sala[10];
	struct turma* prox;
	
};
typedef struct turma Turma;

struct aluno{
	int matricula_aluno;
	char nome[30];
	char fone[15];
	struct aluno* prox;
	
};
typedef struct aluno Aluno;

struct matricula{
	int mat_aluno;
	int codigo_turma;
	char data_mat[10];
	struct matricula* prox;
	
};
typedef struct matricula Matricula;


//	Funcao cria lista disciplina e retorna null
Disciplina *cria_disciplina(void);
//	Funcao cria lista turma e retorna null
Turma *cria_turma(void);
//	funcao cria lista aluno e retorna null
Aluno *cria_aluno(void);
//	funcao cria lista matricula e retorna null
Aluno *cria_matricula(void);


//	Funcao cadastrar disciplina
Disciplina* cadastrar_disciplina(Disciplina* di);
//	Funcao cadastrar turma
Turma* cadastrar_turma(Turma* tu, Disciplina *di);
//	Funcao cadastrar aluno
Aluno* cadastrar_aluno(Aluno* al);
//	Funcao matricular aluno em alguma turma
Matricula* matricular_aluno(Matricula* ma, Turma* tu, Aluno* al);


//	Funcao que faz a busca por disciplina
Disciplina* buscar_disciplina(Disciplina* di, int codd);
//	Funcao que faz a busca por turma
Turma* buscar_turma(Turma *tu, Disciplina* di, int codd);
//	Funcao que faz a busca por aluno
Aluno* buscar_aluno(Aluno *al, int codd);


//	Funcao que faz a busca por uma turma referente a alguma disciplina
Turma* buscar_turma_disciplina(Turma *tu, int codd);
//	Funcao que faz a busca por uma matricula referente a alguma turma
Matricula* buscar_matricula_turma(Matricula *ma, int codd);
//	Funcao que faz a busca por uma matricula referente a algum aluno
Matricula* buscar_matricula_aluno(Matricula *ma, Turma *tu, int codd);
//	Funcao que faz a busca por uma matricula referente a alguma turma referente a algum aluno
Matricula* buscar_matricula_turma_disciplina(Matricula *ma, Turma *tu, int codd);
//	Funcao que verifica se a turma pertence a disciplina
int verifica_matricula_turma_disciplina(Turma *tu, int cod_dis, int cod_tur);


//	Funcao que faz a exclusao da disciplina
Disciplina* excluir_disciplina(Disciplina* di, int codd);
//	Funcao que faz a exclusao da turma
Turma* excluir_turma(Turma* tu, int codd);
//	Funcao que faz a exclusao do aluno
Aluno* excluir_aluno(Aluno* al, int codd);
//	Funcao que faz a exclusao da matricula
Matricula* excluir_matricula(Matricula* ma, Turma* tu);


//	Funcao que faz a exclusao de uma turma referente a alguma disciplina
Turma* excluir_turma_disciplina(Turma* tu, int cod);
//	Funcao que faz a exclusao de uma matricula referente a alguma turma
Matricula* excluir_matricula_turma(Matricula* ma, int codd);
//	Funcao que faz a exclusao de uma matricula referente a algum aluno
Matricula* excluir_matricula_aluno(Matricula* ma, int codd);


//	Funcao para imprimir todas as disciplina
void imprimir_disciplina(Disciplina* di);
//	Funcao para imprimir todas as turmas
void imprimir_turma(Turma* tu);
//	Funcao para imprimir todos os alunos
void imprimir_aluno(Aluno* al);
//	Funcao para imprimir todas as matriculas
void imprimir_matriculas(Matricula* ma);


//	Funcao que verifica se a disciplina existe
int verifica_disciplina_existe(Disciplina* di, int codd);
//	Funcao que verifica se a turma existe
int verifica_turma_existe(Turma* tu, int codd);
//	Funcao que verifica se o aluno existe
int verifica_aluno_existe(Aluno* di, int codd);


//	Funcao que verifica se a disciplina existe "para nao repitir codigo disciplina"
int verifica_disiplina(Disciplina* di, int codd);
//	Funcao que verifica se a turma existe "para nao repitir codigo turma"
int verifica_turma(Turma* tu, int codd);
//	Funcao que verifica se o aluno existe "para nao repitir matricula aluno"
int verifica_aluno(Aluno* al, int codd);
//	Funcao que verifica se o aluno ja esta matriculado na turma
int verifica_aluno_e_matricula(Matricula* ma, int cod_mat, int cod_tur);


//	Funcao que incrementa "vagas acupadas" a cada matricula feita
void atualiza_vagas_soma(Turma* tu, int codd);
//	Funcao que decrementa "vagas acupadas" a cada matricula excluida
//	Funcao que decrementa "vagas acupadas" a cada aluno excluida
void atualiza_vagas_subtrai(Turma* tu, int codd);
//	Funcao que incrementa "qtd_turmas" a cada turma cadastrada
void atualiza_qtd_turmas_soma(Disciplina* di, int codd);
//	Funcao que decrementa "qtd_turmas" a cada turma excluida
void atualiza_qtd_turmas_subtrai(Disciplina* di, int codd);


//	Funcao que busca todos os aluno referente a alguma turma
void lista_nominal(Matricula *ma, Aluno *al, int codd);
//	Funcao que imprime o nome dos aluno referente a alguma turma
void imprimir_lista_nominal(Aluno* al, int codd);


//	Funcao que busca o aluno atraves da matricula
Matricula* discliplina_do_aluno1(Matricula *ma, Turma *tu, Disciplina *di, int codd);
//	Funcao que faz a busca pela turma e retorna o codigo da disciplina
int discliplina_do_aluno2(Turma *tu, int codd);
//	Funcao que imprime o nome da disciplina que aluno cursa
void discliplina_do_aluno3(Disciplina *di, int codd);


//	Funcao imprime quantas turmas existem em cada disciplina
void total_turmas_por_disciplina(Disciplina *di);
//	Funcao que imprime todos alunos em determinada turma
void total_alunos_por_turma(Turma *tu);
//	Funcao imprime todas turmas lotadas
void turma_lotadas(Turma *tu);


//	Funcao que libera lista disciplina
Disciplina* free_list1(Disciplina* di);
//	Funcao que libera lista turma
Turma* free_list2(Turma* tu);
//	Funcao que libera lista aluno
Aluno* free_list3(Aluno* al);
//	Funcao que libera lista matricula
Matricula* free_list4(Matricula* al);
