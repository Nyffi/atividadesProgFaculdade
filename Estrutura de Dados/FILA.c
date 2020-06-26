// Sintese
//   objetivo "Fila"
//   autor "Edson F. da Fonseca"
//   data "28/04/2020"
#include <stdio.h>
#include <stdlib.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

struct tDescritor {
	struct tNo *ini;
	struct tNo *fim;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tDescritor*);
void enqueue(struct tDescritor*, struct tNo *);
struct tNo *dequeue(struct tDescritor*);
void listar(struct tDescritor);
void destruir(struct tDescritor*);

//*** Bloco Principal **********************************************************
int main(void) {
	struct tDescritor fila;
	struct tNo *p;
	int opcao;

	inicializar(&fila);
	do {
        opcao = menu();
        switch (opcao) {
               case 1:
                    printf("\n\n*** Enfileirar ***\n\n");
                    p = malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    fflush(stdin);
                    gets(p->dado.descricao);
                    enqueue(&fila, p); // Incluir o no com produto criado na lista
	                break;
               case 2:
                    printf("\n\n*** Desinfileirar ***\n\n");
                    p = dequeue(&fila);
                    if (p != NULL) {
                    	printf("Desinfileirou: %s\n", p->dado.descricao);
                    	free(p);
					}
                    else
                    	printf("Fila estava vazia!\n");
	                break;
               case 3:
                    printf("\n\n*** Listagem ***\n\n");
                    listar(fila); // Listar (mostrar na tela) todos os produtos
        }
    } while (opcao != 0);
	destruir(&fila);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Enfileirar\n");
    printf("2. Desinfileirar\n");
    printf("3. Listagem\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Inicializar **************************************************************
void inicializar(struct tDescritor *desc) {
	(*desc).ini = NULL;
	(*desc).fim = NULL;
}

//*** Enqueue *******************************************************************
void enqueue(struct tDescritor *desc, struct tNo *novo) {
	if ((*desc).ini == NULL) // vazia
		(*desc).ini = novo;
	else
		(*desc).fim->prox = novo;
	(*desc).fim = novo;
	novo->prox = NULL;
}

//*** Dequeue ******************************************************************
struct tNo * dequeue(struct tDescritor *desc) {
	struct tNo *p = (*desc).ini;
	if (p != NULL) {
		(*desc).ini = p->prox;
		if ((*desc).ini == NULL)
			(*desc).fim = NULL;
	}
	return p;
}

//*** Listar *******************************************************************
void listar(struct tDescritor desc) {
	struct tNo *p = desc.ini;
	while (p != NULL) {
		printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
		p = p->prox;
	}
}

//*** Destruir *****************************************************************
void destruir(struct tDescritor *desc) {
	struct tNo *p = (*desc).ini, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(desc);
}

//*** FIM **********************************************************************
