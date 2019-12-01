#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca.h"

void menu(){
	cliente *listaCliente = NULL,
		  	*ultimoCliente = NULL;	
	
	dependente 	*listaDependente = NULL,
				*ultimoDependente = NULL;
				
	char op = 'G';
	int opcao = 0;

	while (op != 'E'){

		printf("\nA - Inserir."
				"\nB - Excluir."
				"\nC - Relatorios."
				"\nD - Finalizar."
				"\nDigite sua opcao: ");
		fflush(stdin);
		scanf("%c", &op);
		op = toupper(op);

		switch (op) {
		case 'E' :
			printf("\nPrograma finalizado com sucesso.");
			break;
		case 'A':
			printf("\n1 – Efetuar inclusao de cliente."
					"\n2 – Efetuar inclusao de dependente."
					"\n3 - Finalizar."
					"\nDigite sua opcao: ");
			fflush(stdin);
			scanf("%i", &opcao);
			if (opcao == 1){
				
			} else if (opcao == 2){
				listaDependente = inserirDuplamenteEncPeloInicioDependente(listaDependente);
			} else if (opcao == 3){
				op = 'E';
			} else {
				printf("\nOpcao invalida.");
			}			
			break;
		case 'B':
			printf("\n1 – Efetuar exclusão de cliente."
					"\n2 – Efetuar exclusão de dependente."
					"\n3 - Finalizar."
					"\nDigite sua opcao: ");
			fflush(stdin);
			scanf("%i", &opcao);
			if (opcao == 1){
					
			} else if (opcao == 2){
			printf("\nRemover pelo código indicado.");
			int codigo = -1;
			while (codigo < 0) {
				printf("\nDigite o código a ser excluído: ");
				scanf("%d", &codigo);
			}
			listaDependente =  excluirDependente(listaDependente, codigo);	
			} else if (opcao == 3){
				op = 'E';
			} else {
				printf("\nOpcao invalida.");
			}	
			break;
		case 'C':
			printf("\n1 – Listar todos os dados dos clientes cadastrados e exibir a media dos limites."
					"\n2 – Listar todos os dados de um cliente por código."
					"\n3 - Listar clientes por tipo de cartão."
					"\n4 - Finalizar."
					"\nDigite sua opcao: ");
			fflush(stdin);
			scanf("%i", &opcao);
			if (opcao == 1){
				
			} else if (opcao == 2){
				
			} else if (opcao == 3){
				
			} else if (opcao == 4){
				op = 'E';	
			} else {
				printf("\nOpcao invalida.");
			}	
			break;
		default :
			printf("\nOpção invalida.");
			break;
		}
	}
}

void cadastrarNome(char *nome){
	int i, tamanho;
	tamanho = strlen(nome);
	
	for (i=0; nome[i]!='\0'; i++){
		if ((nome[i]>='a' && nome[i]<='z') || (nome[i]>='A' && nome[i]<='Z') || (nome[i] == ' ')){
			printf("\nNome Valido!");
		} else {
			printf("\nNome nao Valido!");
		}
	}
	
	for (i=0; nome[i]!='\0'; i++){
		if (nome[i] == ' ' && nome[i+1] == ' '){
			nome[i] = nome[i+1];
		}
	}
	
	if (nome[0]>='a' && nome[0]<='z'){
		nome[i]=nome[i]-32;
	}	

	for(i=tamanho; nome[i]!=nome[0]; i--){
		if (nome[i] == ' '){
			if ((nome[i+1]>='A' && nome[i+1]<='Z')){
				nome[i+1] = nome[i+1]+32;
			} else {
				break;
			}
		}
	}
}

char* cadastrarNascimento(){
	
}

void cadastrarLimite(float *limite){
	
}

char cadastrarTipo(){
	
}

cliente* inserirSimplismenteEncPeloFimCliente(cliente *lista){
	*novo = (cliente*) malloc (sizeof(cliente));
	novo->proximo = NULL;
	//printf("\nDigite o nome do dependente: \n");
	//gets(novo->nome);
	//novo->nome = cadastrarNome(novo->nome);
	novo->codigo = gerarCodigo();
	

	if (lista == NULL){
		return novo;
	} else {
		cliente *tmp = lista;
		while (tmp->proximo != NULL) {
			tmp = tmp->proximo;
		}
		tmp->proximo = novo;
		return lista;
	}
}

dependente* inserirDuplamenteEncPeloInicioDependente(dependente* lista){
	dependente *novo = (dependente*) malloc (sizeof(dependente));

	novo->anterior = NULL;
	novo->proximo = lista;

	if (lista != NULL){
		lista->anterior = novo;
	}

	return novo;
}

dependente* excluirDependente(dependente *lista, char *codigo){
	dependente *tmp = lista;

	while (tmp != NULL) {
		if (tmp->codigo == codigo){
			if (tmp->anterior == NULL){
				lista = lista->proximo;
				if (lista != NULL){
					lista->anterior = NULL;
				}
				free(tmp);
				return lista;
			} else {
				tmp->anterior->proximo = tmp->proximo;
				if (tmp->proximo != NULL){
					tmp->proximo->anterior = tmp->anterior;
				}
				free(tmp);
				return lista;
			}
		}
		tmp = tmp->proximo;
	}
	printf("\nCodigo nao encontrado.\n");
	return lista;
}

cliente* excluirCliente(cliente* lista, char *codigo){
	cliente	*anterior = NULL,
		  	*tmp = lista;
	int i=0;

	while (tmp != NULL){
		if (codigo == tmp->codigo) {
			if (anterior == NULL){
				lista = lista->proximo;
				if (tmp.dependente>0){
					for (i=0; i <= tmp.dependente; i++){
						excluirDependente(dependente lista, codigo+i);					
					}
				}
				free(tmp);
				return lista;
			} else {
				anterior->proximo = tmp->proximo;
				if (tmp.dependente>0){
					for (i=0; i <= tmp.dependente; i++){
						excluirDependente(dependente lista, codigo+i);					
					}
				}
				free(tmp);
				return lista;
			}
		}
		anterior = tmp;
		tmp = tmp->proximo;
	}
	printf("\nCódigo não encontrado.");
	return lista;
}

char* gerarCodigoCliente(cliente *lista){
	cliente *tmp = lista;
	char codigoCliente[100];
	int i, tamanho, count = 0;
	tamanho = strlen(tmp->nome);
	codigoCliente[0]= tmp->nome[0];
	
	for(i=tamanho; tmp->nome[i]!=tmp->nome[0]; i--){
		if (tmp->nome[i] == ' '){
			codigoCliente[1] = tmp->nome[i+1];
			break;
		}
	}
	
	codigoCliente[2]= RANDOMICO();
		
	count++;
	
	for (i=0; codigoCliente[i]!='\0'; i++){
		if (codigoCliente[i+1] == '\0'){
			codigoCliente[i+1] = count;
			break;
		}
	}
	
	return codigoCliente;
}

char* gerarCodigoDependente(char *codigoCliente){
	char codigoDependente[100] = codigoCliente;
	int i, count = 0;
	
	for(i=0; codigoDependente[i]!='\0'; i++){
		if (codigoDependente[i+1] == '\0'){
			codigoDependente[i+1] = count;
			break;
		}
	}
		
	count++;
	
	return codigoDependente;
}
