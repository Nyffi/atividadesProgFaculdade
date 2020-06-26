#include <stdio.h>
#include <stdlib.h>

// Declaracao de tipo
struct tProduto {
	int codigo;
	char descricao[20];
	float valor;
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

// Prototipos de funcao
int menu(void);

//--- Main ---------------------------------------------------------------
int main(void) {
	struct tNo *lista=NULL;
	struct tNo *p;
	int opcao;
	int codPesq;
	do {
		opcao = menu();
		switch (opcao) {
			case 1:
				printf("\n\n*** Inserir ***\n");
				p = malloc(sizeof(struct tNo));
				
				printf("Digite o codigo do produto...: ");
				scanf("%d", &( (*p).dado.codigo ));
				printf("Digite a descricao do produto: ");
				fflush(stdin);
				gets( (*p).dado.descricao );
				printf("Digite o valor do produto....: ");
				scanf("%f", &((*p).dado.valor) );
				
				if (lista == NULL) // lista vazia
					(*p).prox = NULL;
				else  // lista NAO vazia
					(*p).prox = lista;
				lista = p;

				break;
			case 2:
				printf("\n\n*** Listagem ***\n");
				p = lista;
				while (p != NULL) {
					printf("Cod --> %d\n", (*p).dado.codigo);
					printf("Desc --> %s\n", (*p).dado.descricao);
					printf("Val --> RS %.2f\n\n", (*p).dado.valor);
					p = (*p).prox;
				}
				break;
			case 3:
				printf("\n\n*** Consultar ***\n");
		}
	} while (opcao != 0);
	return 0; // fim sem erro!
}

//--- Menu ---------------------------------------------------------------
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Inclusao\n");
	printf("2. Listagem\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//------------------------------------------------------------------------
