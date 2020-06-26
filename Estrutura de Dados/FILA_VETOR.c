// Sintese
//   objetivo "Fila"
//   autor "Edson F. da Fonseca"
//   data "28/04/2020"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
};

struct tDescritor {
	struct tNo ini[30];
	int fim;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tDescritor*);
void enqueue(struct tDescritor*, struct tNo *);
void dequeue(struct tDescritor*);
void listar(struct tDescritor);
void limpaBuffer();

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
                    limpaBuffer();
                    fgets(p->dado.descricao, 30, stdin);
                    enqueue(&fila, p); // Incluir o no com produto criado na lista
	                break;
               case 2:
                    printf("\n\n*** Desinfileirar ***\n\n");
                    dequeue(&fila);
	                break;
               case 3:
                    printf("\n\n*** Listagem ***\n\n");
                    listar(fila); // Listar (mostrar na tela) todos os produtos
        }
    } while (opcao != 0);
	if (p != NULL)
        free(p);
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
	int i;

	for(i=0;i<30;i++) {
        (*desc).ini[i].dado.codigo = -1;
        strcpy((*desc).ini[i].dado.descricao, "NULL");
	}
	(*desc).fim = 0;
}

//*** Enqueue *******************************************************************
void enqueue(struct tDescritor *desc, struct tNo *novo) {
	int i = (*desc).fim;

    (*desc).ini[i].dado.codigo = novo->dado.codigo;
    strcpy((*desc).ini[i].dado.descricao, novo->dado.descricao);

    (*desc).fim++;
}

//*** Dequeue ******************************************************************
void dequeue(struct tDescritor *desc) {
	int i = 0;
	struct tNo p;

	p.dado.codigo = (*desc).ini[0].dado.codigo;
	strcpy(p.dado.descricao, (*desc).ini[0].dado.descricao);

    if (p.dado.codigo >= 0) {
        do {
            if (i == 29) {
            (*desc).ini[i].dado.codigo = -1;
            strcpy((*desc).ini[i].dado.descricao, "NULL");
            }
            (*desc).ini[i].dado.codigo = (*desc).ini[i+1].dado.codigo;
            strcpy((*desc).ini[i].dado.descricao, (*desc).ini[i+1].dado.descricao);
            i++;
        } while ((*desc).ini[i].dado.codigo != -1 && i < 30);
	}

	(*desc).fim--;

	printf("O valor %d foi desenfileirado com sucesso.\n", p.dado.codigo);
}

//*** Listar *******************************************************************
void listar(struct tDescritor desc) {
	int i = desc.fim, j;
	for (j = 0; j < i; j++) {
		printf("%d - %s\n", desc.ini[j].dado.codigo, desc.ini[j].dado.descricao);
	}
	if (desc.ini[0].dado.codigo == -1) {
        printf("A fila esta vazia.\n");
	}
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
