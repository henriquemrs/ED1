#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define RANDOMICO rand()% 1000
#define MAX 2

struct cliente {
	char nome [50];
	char codigo[100];
	char dataNascimento[10];
	float limite;
	char tipoDeCartao;
	int dependentes;
	struct cliente *proximo;
};

struct dependente{
    char nome[50];
    char codigo[100];
    char dataNascimento[10];
    char tipoDep;
    struct dependente *anterior;
	struct dependente *proximo;
};

typedef struct cliente cliente;
typedef struct dependente dependente;

void cadastrarNome(char *nome);
char* cadastrarNascimento();
void cadastrarLimite(float *limite);
char cadastrarTipo();
void cadastrarTipoDependente(char *tipoDependente);
char* gerarCodigoCliente(char *nome, char *dataNascimento, cliente *lista);
char* gerarCodigoDependente(char *codigo);

cliente* inserirSimplismenteEncPeloFimCliente(cliente *lista);
cliente* excluirCliente(cliente* lista, int codigo);
dependente* inserirDuplamenteEncPeloInicioDependente(dependente* lista);
dependente* excluirDependente(dependente *lista, int codigo);

#endif
