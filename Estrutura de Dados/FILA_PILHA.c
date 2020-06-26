// Sintese
//   objetivo "Pilhas agindo como Fila"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "02/06/2020"
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

struct tFila {
    struct tNo* pilhaI;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void enqueue(struct tFila*, struct tNo*);
struct tNo *dequeue(struct tFila*);
void push(struct tNo**, struct tNo *);
struct tNo* pop(struct tNo**);
void listar(struct tFila *);
void destruir(struct tFila **);
void limpaBuffer();

//*** Bloco Principal **********************************************************
int main(void) {
	struct tFila *q = (struct tFila*)malloc(sizeof(struct tFila));
	struct tNo *p;
	int opcao;

	do {
        opcao = menu();
        switch (opcao) {
               case 1:
                    printf("\n\n*** Enfileirar ***\n\n");
                    p = malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    limpaBuffer();
                    fgets(p->dado.descricao, 30, stdin);
                    enqueue(q, p); // Incluir o no com produto criado na lista
                    free(p);
	                break;
               case 2:
                    printf("\n\n*** Desinfileirar ***\n\n");
                    p = dequeue(q);
                    if (p != NULL) {
                    	printf("Desinfileirou: %s\n", p->dado.descricao);
                    	free(p);
					}
                    else
                    	printf("Fila estava vazia!\n");
	                break;
                case 3:
                    printf("\n\n*** Listagem ***\n\n");
                    listar(q); // Listar (mostrar na tela) todos os produtos
        }
    } while (opcao != 0);
	destruir(&q);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Enfileirar\n");
    printf("2. Desinfileirar\n");
    printf("3. Listar\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Enqueue *******************************************************************
void enqueue(struct tFila *fila, struct tNo *novo) {
	push(&fila->pilhaI, novo);
}

//*** Dequeue ******************************************************************
struct tNo *dequeue(struct tFila *fila) {
	struct tNo *res, *temp;

	if (fila->pilhaI == NULL) {
        return NULL;
	} else if (fila->pilhaI->prox == NULL) {
        return pop(&fila->pilhaI);
	} else {
        temp = pop(&fila->pilhaI);
        res = dequeue(fila);
        push(&fila->pilhaI, temp);
        return res;
	}

}

//*** Push **********************************************************************
void push(struct tNo **topo, struct tNo *novo) {
	struct tNo *novoNo = (struct tNo*)malloc(sizeof(struct tNo));

	novoNo->dado = novo->dado;
	novoNo->prox = (*topo);
	(*topo) = novoNo;
}

//*** Pop ***********************************************************************
struct tNo *pop(struct tNo **topo) {
	struct tNo *p = (*topo);
	if (p != NULL)
		(*topo) = p->prox;
	return p;
}

//*** Destruir *****************************************************************
void destruir(struct tFila **fila) {
	struct tNo *p = (*fila)->pilhaI, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
}

//*** Listar *******************************************************************
void listar(struct tFila *fila) {
	struct tNo *p = fila->pilhaI, *q, *aux = fila->pilhaI;

    if (p == NULL) {
        return;
    }
	while (aux->prox != NULL) {
        aux = aux->prox;
	}
    q = aux->prox;
	do {
        q = p;
        while (q->prox != aux) {
            q = q->prox;
        }
        printf("%d - %s\n", aux->dado.codigo, aux->dado.descricao);
        aux = q;
	} while (q != p);
	printf("%d - %s\n", aux->dado.codigo, aux->dado.descricao);
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
