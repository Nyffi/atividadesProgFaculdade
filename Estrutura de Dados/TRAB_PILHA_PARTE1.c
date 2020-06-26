// Sintese
//   objetivo "Atividade Avaliativa 01"
//   autor "Paulo César de Lima Rocha"
//   data "10/05/2020"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//*** Declaracoes de tipos *****************************************************
struct tCalculo {
    int preferencia; //0 = (); 1 = []; 2 = {}
    int index;
};

struct tNo {
    struct tCalculo dado;
    struct tNo *prox;
};

struct tDescritor {
    char expressao[31];
    struct tNo *ini;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tDescritor *);
void push(struct tDescritor *, struct tNo *);
struct tNo *pop(struct tNo **);
int validaExpressao(struct tDescritor *, int);
void destruir(struct tDescritor *);
void limpaBuffer();

//*** Bloco Principal **********************************************************
int main(void) {
	struct tDescritor pilha;
	int opcao;

	inicializar(&pilha);
    opcao = menu();
    switch (opcao) {
        case 1:
        case 2:
            printf("\n\n*** Parte %d ***\n\n", opcao);
            printf("Digite a expressao (30 carac.): ");
            limpaBuffer();
            fgets(pilha.expressao, 31, stdin);
            break;
        default:
            return 0;
    }
    switch (validaExpressao(&pilha, opcao)) {
        case -1:
          printf("\n[ERRO] A expressao possui ordenacao de escopo. Favor usar a parte 2 caso queira usar colchetes e/ou chaves.");
          break;
        case 0:
          printf("\nA expressao e valida.");
          break;
        case 1:
          printf("\n[ERRO] A expressao possui um final de escopo precedendo um inicio.");
          break;
        case 2:
          printf("\n[ERRO] A expressao possui uma quantia desigual de inicio e final de escopos.");
          break;
        case 3:
          printf("\n[ERRO] A expressao possui um erro de sintaxe.");
      }
	destruir(&pilha);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Parte 1\n");
    printf("2. Parte 2\n\n");
    printf("Digite qualquer outro caractere para Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Inicializar **************************************************************
void inicializar(struct tDescritor *topo) {
    (*topo).ini = NULL;
    (*topo).expressao[0] = '\0';
}

//*** Push **********************************************************************
void push(struct tDescritor *topo, struct tNo *novo) {
    novo->prox = (*topo).ini;
    (*topo).ini = novo;
}

//*** Pop ***********************************************************************
struct tNo *pop(struct tNo **topo) {
    struct tNo *p = (*topo);
    if (p != NULL)
        (*topo) = p->prox;
    return p;
}

//*** Valida Expressão *********************************************************
int validaExpressao(struct tDescritor *topo, int parte) {
    int i = 0, aux = -1;
    struct tNo *p = (*topo).ini, *q;

    for (i = 0; i < strlen((*topo).expressao); i++) {
        q = malloc(sizeof(struct tNo));
        q->dado.preferencia = -1; //Não definido

        switch((*topo).expressao[i]) {
            case '(':
                q->dado.preferencia = 0;
                q->dado.index = i;
                break;
            case '[':
                q->dado.preferencia = 1;
                q->dado.index = i;
                if (parte == 1) {
                    return -1;
                }
                break;
            case '{':
                q->dado.preferencia = 2;
                q->dado.index = i;
                if (parte == 1) {
                    return -1;
                }
                break;
        }

        if (q->dado.preferencia != -1) {
            push(topo, q);
            p = (*topo).ini;
            if (p->prox != NULL && p->dado.preferencia > p->prox->dado.preferencia) {
                return 3;
            }
        } else {
            free(q);
        }

        switch((*topo).expressao[i]) {
            case ')':
                if ((*topo).ini == NULL) {
                    return 1;
                }
                aux = 0;
                break;
            case ']':
                if (parte == 1) {
                    return -1;
                }
                if ((*topo).ini == NULL) {
                    return 1;
                }
                aux = 1;
                break;
            case '}':
                if (parte == 1) {
                    return -1;
                }
                if ((*topo).ini == NULL) {
                    return 1;
                }
                aux = 2;
                 break;
            default:
                aux = -1;
            }

            if (p != NULL) {
                if (aux == p->dado.preferencia) {
                    q = pop(&(*topo).ini);
                    p = (*topo).ini;
                    if (q == NULL) {
                        return 1;
                    }
                    free(q);
                } else {
                    if (aux != -1 && aux != p->dado.preferencia) {
                        return 1;
                    }
                }
            }
        }

    if (aux >= 0 && (*topo).ini != NULL) {
        return 2; //Invalidez graças a uma quantia desigual de limitadores.
    }

    return 0;
}

//*** Destruir *****************************************************************
void destruir(struct tDescritor *topo) {
	struct tNo *p = (*topo).ini, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(topo);
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
