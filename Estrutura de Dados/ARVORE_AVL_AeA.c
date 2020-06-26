// Sintese
//   objetivo "Arvore AVL / Atividade em Aula"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "27/05/2020"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
void representar (struct tNo *, int);
void limpaBuffer();

int ativAulaMenu(void);
bool ativAulaI(struct tNo *, struct tNo *);
bool ativAulaII(struct tNo *, struct tNo *);
bool ativAulaIII(struct tNo *, struct tNo *);
int ativAulaIVeV(struct tNo *, struct tNo *);
int ativAulaVIeVII(struct tNo *);
bool ativAulaVIII(struct tNo *);

// *** main ********************************************************************
int main(void) {
	int op, opLista, valor, valFilhoNeto = 0;
	struct tNo *p, *arvore, *valNoI, *valNoII;
	bool verdade;

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
                representar(arvore, 0);
                printf("\n");
                break;
            case 6:
                if (arvore == NULL) {
                    printf("A arvore esta vazia.\n");
                    break;
                }
                do {
                    printf("\n\n*** Atividade em Aula ***\n\n");
                    valFilhoNeto = 0;
                    opLista = ativAulaMenu();
                    switch (opLista) {
                        case 1:
                        case 2:
                        case 3:
                            printf("Digite o valor do primeiro no: ");
                            scanf("%d", &valor);
                            valNoI = consultar(arvore, valor);

                            printf("Digite o valor do segundo no: ");
                            scanf("%d", &valor);
                            valNoII = consultar(arvore, valor);

                            if (valNoI == NULL || valNoII == NULL) {
                                printf("Um dos nos e vazio. Tente novamente.\n");
                                break;
                            }

                            switch (opLista) {
                                case 1:
                                    verdade = ativAulaI(valNoI, valNoII);
                                    switch(verdade) {
                                        case true:
                                            printf("O primeiro no e pai do segundo no.\n");
                                            break;
                                        case false:
                                            printf("O primeiro no nao e o pai do segundo no.\n");
                                    }
                                    break;
                                case 2:
                                    verdade = ativAulaII(valNoI, valNoII);
                                    switch(verdade) {
                                        case true:
                                            printf("O primeiro no e filho do segundo no.\n");
                                            break;
                                        case false:
                                            printf("O primeiro no nao e o filho do segundo no.\n");
                                    }
                                    break;
                                case 3:
                                    verdade = ativAulaIII(valNoI, valNoII);
                                    switch(verdade) {
                                        case true:
                                            printf("O primeiro no e neto do segundo no.\n");
                                            break;
                                        case false:
                                            printf("O primeiro no nao e o neto do segundo no.\n");
                                    }
                            }
                            break;
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                            printf("Digite o valor do no: ");
                            scanf("%d", &valor);
                            valNoI = consultar(arvore, valor);

                            if (valNoI == NULL || valNoII == NULL) {
                                printf("Um dos nos e vazio. Tente novamente.\n");
                                break;
                            }
                            switch (opLista) {
                                case 4:
                                    printf("O no fornecido esta no nivel %d.\n", ativAulaIV(arvore, valNoI));
                                    break;
                                case 5:
                                    printf("O no fornecido tem %d niveis de profundidade.\n", ativAulaIV(arvore, valNoI));
                                    break;
                                case 6:
                                    printf("O grau do no fornecido e %d", ativAulaVIeVII(valNoI));
                                    break;
                                case 7:
                                    printf("O grau da raiz e %d", ativAulaVIeVII(arvore));
                                    break;
                                case 8:
                                    if (ativAulaVIII(valNoI) == true) {
                                        printf("O no fornecido e uma folha.\n");
                                    } else {
                                        printf("O no fornecido nao e uma folha.\n");
                                    }
                                    break;
                            }
                            break;
                    }
				} while (opLista != 0);
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
	printf("6. Atividade em Aula\n");
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

//*** ativAula-menu *********************************************************************
int ativAulaMenu(void) {
	int op;
	printf("1. O primeiro e pai do segundo?\n");
	printf("2. O primeiro e filho do segundo?\n");
	printf("3. O primeiro e neto do segundo?\n");
	printf("4. Nível do no\n");
	printf("5. Profundidade do no\n");
	printf("6. Grau do no\n");
	printf("7. Grau da arvore\n");
	printf("8. O no e folha?\n");
	printf("0. Sair\n\n");
	printf("Digite sua opcao: ");
	scanf("%d", &op);
	return op;
}

bool ativAulaI(struct tNo *noI, struct tNo *noII) {
    if (noI->dir == noII || noI->esq == noII) {
        return true;
    }
    return false;
}

bool ativAulaII(struct tNo *noI, struct tNo *noII) {
    if (noII->dir == noI || noII->esq == noI) {
        return true;
    }
    return false;
}

bool ativAulaIII(struct tNo *noI, struct tNo *noII) {
    if (noII->esq != NULL) {
		if (noII->esq->esq == noI || noII->esq->dir == noI) {
			return 1;
		}
	}

	if (noII->dir != NULL) {
		if (noII->dir->esq == noI || noII->dir->dir == noI) {
			return 1;
		}
	}

	return 0;
}

int ativAulaIVeV(struct tNo *raiz, struct tNo *valNo) {
    return altura(raiz) - altura(valNo);
}

int ativAulaVIeVII(struct tNo *valNo) {
    return grau(valNo);
}

bool ativAulaVIII(struct tNo *valNo) {
    if (valNo->dir == NULL && valNo->esq == NULL) {
        return true;
    }
    return false;
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
	if (raiz->esq != NULL && valor < raiz->dado.codigo)
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

void representar(struct tNo *arvore, int depth){
    if(arvore == NULL)
        return;

    int newDepth = depth+1;

    while(depth--) printf("  ");

    printf(" %d: [%d|%d]\n", arvore->dado.codigo, altura(arvore), fb(arvore));
    representar(arvore->esq, newDepth);
    representar(arvore->dir, newDepth);
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
