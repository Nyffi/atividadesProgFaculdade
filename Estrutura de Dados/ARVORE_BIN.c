// Sintese
//   objetivo "Arvore Binaria de Busca"
//   autor "Edson F. da Fonseca"
//   data "20/05/2020"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*** Declaracoes de tipos *****************************************************
struct tNo {
	struct tNo *esq;
	int dado;
	struct tNo *dir;
};

// *** Prototipo de funcoes ****************************************************
int menu(void);
int listarMenu(void);
void inicializar(struct tNo**);
void incluir(struct tNo **, struct tNo*);
void emordem(struct tNo *);
void preordem(struct tNo *);
void posordem(struct tNo *);
struct tNo *consultar(struct tNo*, int);
void destruir(struct tNo*);
int grau(struct tNo*);
struct tNo *menor(struct tNo*);
int excluir(struct tNo**, int);
void limpaBuffer();

int ativAulaMenu(void);
bool ativAulaI(struct tNo *, struct tNo *);
bool ativAulaII(struct tNo *, struct tNo *);
bool ativAulaIII(struct tNo *, struct tNo *);
bool ativAulaV(struct tNo *, struct tNo *);

// *** main ********************************************************************
int main(void) {
	int op, opLista, valor, valFilhoNeto;
	struct tNo *p, *arvore, *valNoI, *valNoII;
	bool verdade;

	inicializar(&arvore);
	do {
		op = menu();
		switch (op) {
			case 1:
                printf("\n\n*** Inclusao ***\n\n");
                printf("Digite o valor: ");
                scanf("%d", &valor);
                p = malloc(sizeof(struct tNo));
                p->dado = valor;
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
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (consultar(arvore, valor) != NULL)
                	printf("Encontrou\n");
                else
                	printf("Nao encontrou!\n");
				break;
			case 4:
				printf("\n\n*** Excluir ***\n\n");
                printf("Digite o valor: ");
                scanf("%d", &valor);
                if (excluir(&arvore, valor))
                	printf("Excluido\n");
                else
                	printf("Nao encontrou!\n");
                break;
            case 5:
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
                        case 5:
                            printf("Digite o valor do primeiro no: ");
                            scanf("%d", &valor);
                            valNoI = consultar(arvore, valor);

                            printf("Digite o valor do segundo no: ");
                            scanf("%d", &valor);
                            valNoII = consultar(arvore, valor);

                            if (valNoI == NULL || valNoII == NULL) {
                                printf("Um dos nos e vazio. Tente novamente.\n");
                                break;
                            } else if (valNoI->dir == NULL || valNoI->esq == NULL) {
                                valFilhoNeto++;
                                if (valNoI->dir->esq == NULL || valNoI->dir->dir == NULL || valNoI->esq->esq == NULL || valNoI->esq->dir == NULL) {
                                    valFilhoNeto++;
                                }
                            }

                            if (valFilhoNeto == 1) {
                                if (opLista == 1 || opLista == 2) {
                                    printf("Nao ha nos o suficiente para executar essa verificacao.\n");
                                    break;
                                }
                            } else if (valFilhoNeto == 2) {
                                if (opLista == 3) {
                                    printf("Nao ha nos o suficiente para executar essa verificacao.\n");
                                    break;
                                }
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
                                    break;
                                case 5:

                                    break;
                            }
                            break;
                        case 4:
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

                                    break;
                                case 6:

                                    break;
                                case 7:

                                    break;
                                case 8:

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
	printf("5. Atividade em Aula\n");
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
    if (noII->dir->esq == noI || noII->dir->dir == noI || noII->esq->esq == noI || noII->esq->dir == noI) {
        return true;
    }
    return false;
}

bool ativAulaV(struct tNo *noI, struct tNo *noII) {

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
		if (novo->dado < (*raiz)->dado)
			incluir(&((*raiz)->esq), novo);
		else
			incluir(&((*raiz)->dir), novo);
	}
}

//*** em-ordem *****************************************************************
void emordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	emordem(raiz->esq);
	printf("%d - ", raiz->dado);
	emordem(raiz->dir);
}

//*** pré-ordem *****************************************************************
void preordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	printf("%d - ", raiz->dado);
	emordem(raiz->esq);
	emordem(raiz->dir);
}

//*** pós-ordem *****************************************************************
void posordem(struct tNo *raiz) {
	if (raiz == NULL)
		return;
	emordem(raiz->esq);
	emordem(raiz->dir);
	printf("%d - ", raiz->dado);
}

//*** consultar ****************************************************************
struct tNo *consultar(struct tNo *raiz, int valor) {
	if ((raiz == NULL) || (raiz->dado == valor))
		return raiz;
	if (raiz->esq != NULL && valor < raiz->dado)
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
	if (*raiz == NULL)
		return 0;
	if ((*raiz)->dado == valor) {
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
				excluir(&((*raiz)->dir), p->dado);
			}
		}
		return 1;
	}
	if ((*raiz)->esq != NULL && valor < (*raiz)->dado)
		return excluir(&((*raiz)->esq), valor);
	return excluir(&((*raiz)->dir), valor);
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
