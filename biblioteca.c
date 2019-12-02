#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
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

char* cadastrarNascimentoCliente(){
	char dataDeAniversario[50];
	do{
		printf("\nDigite a data de nascimento:\n");
		gets(dataDeAniversario);
	}while (ehValidaData(dataDeAniversario)!=true);
	
	return dataDeAniversario;
}

bool ehValidaData(char *dataDeAniversario) {
	int diaInt, mesInt, anoInt;
	char data[10];
	data = dataDeAniversario;
	char dia[1], mes[1], ano[3];
	int i, tamanho;
	tamanho = strlen(data);
	if (tamanho != 10) {
		printf("\nData inválida, digite 10 caracteres DD/MM/AAAA");
		return false;
	}
	if (data[2] != '/' || data[5] != '/') {
		printf("\nData inválida, digite / no 3o. e 6o. caracteres DD/MM/AAAA");
		return false;
	}
	if(data[0]<'0' && data[0]>'9'){
		printf("\nOs dias da data nao possuem numeros.");
		return false;
	} else if (data[1]<'0' && data[1]>'9'){
		printf("\nOs dias da data nao possuem numeros.");
		return false;		
	} else if (data[3]<'0' && data[3]>'9'){
		printf("\nO mes da data nao possuem numeros.");
		return false;			
	} else if (data[4]<'0' && data[4]>'9'){
		printf("\nO mes da data nao possuem numeros.");
		return false;
	} else if (data[6]<'0' && data[6]>'9'){
		printf("\nO ano da data nao possuem numeros.");
		return false;
	} else if (data[7]<'0' && data[7]>'9'){
		printf("\nO ano da data nao possuem numeros.");
		return false;
	} else if (data[8]<'0' && data[8]>'9'){
		printf("\nO ano da data nao possuem numeros.");
		return false;
	} else if (data[9]<'0' && data[9]>'9'){
		printf("\nO ano da data nao possuem numeros.");
		return false;
	} else {
		dia[0] = data[0];
		dia [1] = data[1];
		mes[0] = data[3];
		mes[1] = data[4];
		ano[0] = data[6];
		ano[1] = data[7];
		ano[2] = data[8];
		ano[3] = data[9];
		
		diaInt = strtonum(dia);
		mesInt = strtonum(mes);
		anoInt = strtonum(ano);
		
		if (anoInt < 1919 || anoInt > 2001) {
			printf("\nData inválida, você precisa ter 18 anos ou mais e com idade menor que 100 anos.");
			return false;
		}
		if (mesInt < 1 || mesInt > 12){
			printf("\nData inválida, digite mes entre 1 e 12.");
		}
		if (diaInt < 1 || diaInt > 31) {
			printf("\nData inválida, digite dia entre 1 e 31");
			return false;
		}		
		if (mesInt == 2 && diaInt >28){
			printf("\nData inválida, para fevereiro, digite dia entre 1 e 28");
			return false;			
		} else if (mesInt == 2 && diaInt >29 && anoInt%4==0){
			printf("\nData inválida, para fevereiro de ano bissexto, digite dia entre 1 e 29");
			return false;
		}
		if ((mesInt == 4 || mesInt == 6 || mesInt == 9 || mesInt == 11) && diaInt > 30) {
			printf("\nData inválida, para meses 4,6,9 e 11, digite dia entre 1 e 30");
			return false;
		}
	}
	return true;
}

int idadeStringToInteger(char *dataNascimento){
	int idade=0, anoInt;
	char data[10];
	data = dataNascimento;
	char ano[3];
	
	ano[0] = data[6];
	ano[1] = data[7];
	ano[2] = data[8];
	ano[3] = data[9];
		
	anoInt = strtonum(ano);
	idade = anoInt-2019;
	return idade;
}

void cadastrarLimite(float *limite){
	
	char tipo = cadastrarTipo();	
	//int idade =   
	
	if(tipo = 'U'){
		if(idade > 18 && idade < 40){
			*limite = 10000;
		}
		else if(idade > 41 && idade < 60){
			*limite = 15000
		}
		else if(idade > 61 && idade < 75){
			*limite = 5000;
		}
		else if(idade > 75){	
			*limite = 2500;
		}
	}
	else if(tipo = 'N'){
		if(idade > 18 && idade < 40){
			*limite = 10000 + (10000 * 0,05);
		}
		else if(idade > 41 && idade < 60){
			*limite = 15000 + (15000 * 0,05);
		}
		else if(idade > 61 && idade < 75){
			*limite = 5000 + (5000* 0.05);
		}
		else if(idade > 75){	
			*limite = 2500 + (2500 * 0.05) ;
		}
	}
	else if(tipo = 'I'){
		
		if(idade > 18 && idade < 40){
			*limite = 10000 + (10000 * 0,2);
		}
		else if(idade > 41 && idade < 60){
			*limite = 15000 + (15000 * 0,2);
		}
		else if(idade > 61 && idade < 75){
			*limite = 5000 + (5000* 0.2);
		}
		else if(idade > 75){	
			*limite = 2500 + (2500 * 0.2) ;
		}
	}
	
}

char cadastrarTipo(){
	
	char tipo;
	printf("Digite qual o TIPO do cartao desejado: ")
		+("U - Universitario")
		+("N - Nacional")
		+("I - Internacional");
	scanf(tipo);
	
	return tipo;
	
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
	char codigoDependente[100];
	codigoDependente = codigoCliente;
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
