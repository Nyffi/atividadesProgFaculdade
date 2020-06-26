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
	int qntCarac; // chave de ordenação
	int index;
};

struct tNo {
	struct tCalculo dado;
	struct tNo *prox;
};

struct tDescritor {
    struct tCalculo escopo;
    char expressao[31];
    struct tNo *ini;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tDescritor*);
void push(struct tDescritor*, struct tNo *);
struct tNo* pop(struct tNo**);
void separaEscopo(struct tDescritor*);
int validaExpressao(struct tDescritor);
void listar(struct tDescritor topo);
void destruir(struct tDescritor*);
void limpaBuffer();

//*** Bloco Principal **********************************************************
int main(void) {
	struct tNo *p;
	struct tDescritor pilha;
	int opcao;

	inicializar(&pilha);
    opcao = menu();
    switch (opcao) {
        case 1:
            printf("\n\n*** Parte 1 ***\n\n");
            printf("Digite a expressao (30 carac.): ");
            limpaBuffer();
            fgets(pilha.expressao, 31, stdin);
            pilha.escopo.qntCarac = strlen(pilha.expressao);
            switch (validaExpressao(pilha)) {
                case 0:
                    printf("\nA expressao e valida.");
                    break;
                case 1:
                    printf("\n[ERRO] A expressao possui um final de parentese precedendo um inicio.");
                    break;
                case 2:
                    printf("\n[ERRO] A expressao possui uma quantia desigual de parenteses.");
            }
            break;
        case 2:
            printf("\n\n*** Parte 2 ***\n\n");
            printf("Digite a expressao (30 carac.): ");
            limpaBuffer();
            fgets(pilha.expressao, 31, stdin);
            pilha.escopo.qntCarac = strlen(pilha.expressao);
            separaEscopo(&pilha);
            listar(pilha);
            break;
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
    (*topo).escopo.qntCarac = (*topo).escopo.index = 0;
    (*topo).expressao[0] = '\n';
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

//*** Separa Escopos ************************************************************
void separaEscopo(struct tDescritor *topo) {
    int aux, i, j;
    struct tNo *p = (*topo).ini, *q;
    bool confEsc;

    aux = i = j = 0;

    for (i = 0; i < (*topo).escopo.qntCarac; i++) {
        confEsc = false;
        if ((*topo).expressao[i] == '(') {
            for (j = i+1; j < (*topo).escopo.qntCarac && confEsc == false; j++) {
                switch((*topo).expressao[j]) {
                    case '(':
                        aux++;
                        break;
                    case ')':
                        if (aux > 0) {
                            aux--;
                        } else {
                            q = malloc(sizeof(struct tNo));
                            q->dado.index = i;
                            q->dado.qntCarac = j - i;
                            push(topo, q);
                            confEsc = true;
                            break;
                        }
                }
            }
        }
    }
}

//*** Valida Expressão *********************************************************
int validaExpressao(struct tDescritor topo) {
    int i, cmpParenteses;
    int valido = 0; //Valor começa sendo considerado válido.

    i = cmpParenteses = 0;

    for (i = 0; i < topo.escopo.qntCarac; i++) {
        switch(topo.expressao[i]) {
            case '(':
                cmpParenteses++;
                break;
            case ')':
                cmpParenteses--;
                break;
        }
        if (cmpParenteses < 0) {
            valido = 1; //Invalidez graças a um ')' precedendo um '('.
            break;
        }
    }
    if (cmpParenteses > 0) {
        valido = 2; //Invalidez graças a uma quantia desigual de parenteses.
    }

    return valido;
}

//*** Listar *******************************************************************
void listar(struct tDescritor topo) {
    int i, j;
    struct tNo *p = topo.ini;
    char escopo[31];

    while (p != NULL) {
        j = 0;

        for (i = p->dado.index; i <= p->dado.index + p->dado.qntCarac; i++) {
            escopo[j] = topo.expressao[i];
            escopo[j+1] = '\0';
            j++;
        }
        printf("%d - %d = %s\n", p->dado.index, p->dado.qntCarac, escopo);
        p = p->prox;
    }
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
