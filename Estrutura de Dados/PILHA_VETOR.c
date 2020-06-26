// Sintese
//   objetivo "Pilha com Vetor"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "02/05/2020"
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
void push(struct tDescritor*, struct tNo *);
void pop(struct tDescritor*);
void listar(struct tDescritor);
void limpaBuffer();

//*** Bloco Principal **********************************************************
int main(void) {
	struct tNo *p;
	struct tDescritor pilha;
	int opcao;

	inicializar(&pilha);
	do {
        opcao = menu();
        switch (opcao) {
               case 1:
                    printf("\n\n*** Empilhar ***\n\n");
                    p = malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    limpaBuffer();
                    fgets(p->dado.descricao, 30, stdin);
                    push(&pilha, p);
	                break;
               case 2:
                    printf("\n\n*** Desempilhar ***\n\n");
                    pop(&pilha);
	                break;
               case 3:
                    printf("\n\n*** Listagem ***\n\n");
                    listar(pilha); // Listar (mostrar na tela) todos os produtos
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
    printf("1. Empilhar\n");
    printf("2. Desempilhar\n");
    printf("3. Listagem\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Inicializar **************************************************************
void inicializar(struct tDescritor *topo) {
	int i;

	for(i=0;i<30;i++) {
        (*topo).ini[i].dado.codigo = -1;
        strcpy((*topo).ini[i].dado.descricao, "NULL");
	}
	(*topo).fim = 0;
}

//*** Push **********************************************************************
void push(struct tDescritor *topo, struct tNo *novo) {
	int i = (*topo).fim;

    (*topo).ini[i].dado.codigo = novo->dado.codigo;
    strcpy((*topo).ini[i].dado.descricao, novo->dado.descricao);

    (*topo).fim++;
}

//*** Pop ***********************************************************************
void pop(struct tDescritor *topo) {
	int i = (*topo).fim, aux = (*topo).ini[i-1].dado.codigo;

    if ((*topo).ini[0].dado.codigo != -1) {
        (*topo).ini[i-1].dado.codigo = -1;
        strcpy((*topo).ini[i].dado.descricao, "NULL");
        (*topo).fim--;
        printf("O valor %d foi desenfileirado com sucesso.\n", aux);
    } else
        printf("A pilha ja esta vazia.");

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
