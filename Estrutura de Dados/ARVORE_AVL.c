// Sintese
//   objetivo "Arvore AVL"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "20/05/2020"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
 int codigo;
 char descricao[30];
};

struct tNo {
	struct tNo *esq;
	struct tProduto dado;
	struct tNo *dir;
};

// *** Prototipo de funcoes ****************************************************
int menu(void);
int listarMenu(void);
void inicializar(struct tNo**);
void incluir(struct tNo **, struct tNo*);
void emordem(struct tNo *);
void preordem(struct tNo *raiz);
void posordem(struct tNo *raiz);
struct tNo *consultar(struct tNo*, int);
void destruir(struct tNo*);
int grau(struct tNo*);
struct tNo *menor(struct tNo*);
int excluir(struct tNo**, int);
int fb(struct tNo *raiz);
void balancearAVL(struct tNo**);
void rotacaoSD(struct tNo **pai);
void rotacaoSE(struct tNo **pai);
int altura(struct tNo *raiz);
int maior(int a, int b);
void representar (struct tNo *raiz);
void limpaBuffer();

// *** main ********************************************************************
int main(void) {
	int op, opLista, valor;
	struct tNo *p, *arvore;

	inicializar(&arvore);
	do {
		op = menu();
		switch (op) {
			case 1:
                printf("\n\n*** Inclusao ***\n\n");
                p = malloc(sizeof(struct tNo));
                printf("Digite o codigo: ");
                limpaBuffer();
                scanf("%d", &p->dado.codigo);
                printf("Digite a descricao: ");
                limpaBuffer();
                fgets(p->dado.descricao, 30, stdin);
                incluir(&arvore, p);
				break;
			case 2:
				do {
                    printf("\n\n*** Listagem ***\n\n");
                    opLista = listarMenu();
                    switch (opLista) {
                        case 1:
                            emordem(arvore);
                            break;
                        case 2:
                            preordem(arvore);
                            break;
                        case 3:
                            posordem(arvore);
                    }
				} while (opLista > 3 || opLista <= 0);

				break;
			case 3:
				printf("\n\n*** Consulta ***\n\n");
                printf("Digite o codigo: ");
                scanf("%d", &valor);
                if (consultar(arvore, valor) != NULL)
                	printf("Encontrou\n");
                else
                	printf("Nao encontrou!\n");
				break;
			case 4:
				printf("\n\n*** Excluir ***\n\n");
                printf("Digite o codigo: ");
                scanf("%d", &valor);
                if (excluir(&arvore, valor))
                	printf("Excluido\n");
                else
                	printf("Nao encontrou!\n");
                break;
            case 5:
                printf("\n\n*** Representacao ***\n\n");
                representar(arvore);
                printf("\n");
		}
	} while (op != 0);
	destruir(arvore);
	return 0;
}

//*** menu *********************************************************************
int menu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Incluir\n");
	printf("2. Listar\n");
	printf("3. Consultar\n");
	printf("4. Excluir\n");
	printf("5. Representar\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//*** listar-menu *********************************************************************
int listarMenu(void) {
	int op;
	printf("\n\n*** MENU ***\n\n");
	printf("1. Em ordem\n");
	printf("2. Pre-Ordem\n");
	printf("3. Pos-Ordem\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

//*** inicializar **************************************************************
void inicializar(struct tNo **raiz) {
	(*raiz) = NULL;
}

//*** incluir ******************************************************************
void incluir(struct tNo **raiz, struct tNo *novo) {
	if ((*raiz) == NULL) {
		(*raiz) = novo;
		novo->esq = novo->dir = NULL;
	}
	else {
		if (novo->dado.codigo < (*raiz)->dado.codigo)
			incluir(&((*raiz)->esq), novo);
		else
			incluir(&((*raiz)->dir), novo);
	}
	balancearAVL(raiz);
}

//*** em-ordem *****************************************************************
void emordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	emordem(raiz->esq);
	printf("%d - %s\n", raiz->dado.codigo, raiz->dado.descricao);
	emordem(raiz->dir);
}

//*** pré-ordem *****************************************************************
void preordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	printf("%d - %s\n", raiz->dado.codigo, raiz->dado.descricao);
	emordem(raiz->esq);
	emordem(raiz->dir);
}

//*** pós-ordem *****************************************************************
void posordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	emordem(raiz->esq);
	emordem(raiz->dir);
	printf("%d - %s\n", raiz->dado.codigo, raiz->dado.descricao);
}

//*** consultar ****************************************************************
struct tNo *consultar(struct tNo *raiz, int valor) {
	if ((raiz == NULL) || (raiz->dado.codigo == valor))
		return raiz;
	if (raiz->esq != NULL && valor < raiz->esq->dado.codigo)
		return consultar(raiz->esq, valor);
	return consultar(raiz->dir, valor);
}

//*** destruir *****************************************************************
void destruir(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	destruir(raiz->esq);
	destruir(raiz->dir);
	free(raiz);
}

//*** grau *********************************************************************
int grau(struct tNo *raiz) {
	if ((raiz->esq == NULL) && (raiz->dir == NULL))
		return 0;
	if ((raiz->esq != NULL) && (raiz->dir != NULL))
		return 2;
	return 1;
}

//*** menor ********************************************************************
struct tNo *menor(struct tNo *raiz) {
	if ((raiz == NULL) || (raiz->esq == NULL))
		return raiz;
	menor(raiz->esq);
}

//*** excluir ******************************************************************
int excluir(struct tNo **raiz, int valor) {
	struct tNo *p;
	int resp;
	if (*raiz == NULL)
		return 0;
	if ((*raiz)->dado.codigo == valor) {
		if (grau(*raiz) == 0) { // folha
			free(*raiz);
			*raiz = NULL;
		}
		else {
			if (grau(*raiz) == 1) {
				p = *raiz;
				if ((*raiz)->esq != NULL)
					*raiz = (*raiz)->esq;
				else
					*raiz = (*raiz)->dir;
				free(p);
			}
			else { // 2 filhos
				p = menor((*raiz)->dir);
				(*raiz)->dado = p->dado;
				excluir(&((*raiz)->dir), p->dado.codigo);
			}
		}
		return 1;
	}
	if ((*raiz)->esq != NULL && valor < (*raiz)->esq->dado.codigo)
		resp = excluir(&((*raiz)->esq), valor);
	resp = excluir(&((*raiz)->dir), valor);
	balancearAVL(raiz);
	return resp;
}

int fb(struct tNo *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return altura(raiz->dir) - altura(raiz->esq);
}

//*** Balancear Árvore *********************************************************
void balancearAVL(struct tNo **raiz) {
    int fat = fb(*raiz);
    if ((fat != 2) && (fat != -2)){
        return;
    }
    if ((fat == 2) && (fb((*raiz)->dir) == 1)) {
        rotacaoSE(raiz);
    } else {
        if ((fat == -2) && (fb((*raiz)->esq) == -1)) {
            rotacaoSD(raiz);
        } else {
            if ((fat == 2) && (fb((*raiz)->dir) == -1)) {
                rotacaoSD(&((*raiz)->dir));
                rotacaoSE(raiz);
            } else {
                rotacaoSE(&((*raiz)->esq));
                rotacaoSD(raiz);
            }
        }
    }
}

void rotacaoSD(struct tNo **pai){
    struct tNo *filho = (*pai)->esq;

    (*pai)->esq = filho->dir;
    filho->dir = (*pai);
    (*pai) = filho;
}

void rotacaoSE(struct tNo **pai) {
    struct tNo *filho = (*pai)->dir;

    (*pai)->dir = filho->esq;
    filho->esq = (*pai);
    (*pai) = filho;
}

int altura(struct tNo *raiz){
    if(raiz == NULL)
        return -1;

    int raizEsquerda, raizDireita;

    raizEsquerda = altura(raiz->esq);
    raizDireita = altura(raiz->dir);

    if(raizEsquerda > raizDireita)
        return raizEsquerda + 1;
    return raizDireita + 1;
}

int maior(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

void representar (struct tNo *raiz) {
    if(raiz == NULL)
        return;

    representar(raiz->esq);
    printf("(%d [%d|%d] ", raiz->dado.codigo, altura(raiz), fb(raiz));
    representar(raiz->dir);

    printf(")");
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
