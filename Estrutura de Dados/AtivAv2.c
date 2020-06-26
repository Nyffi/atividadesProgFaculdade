// Sintese
//   objetivo "Gincana.Modalidade Programação. Nível júnior. 2a Fase de 2011."
//   site "https://olimpiada.ic.unicamp.br/pratique/pj/2011/f2/gincana/"
//   Requisito "1-Lista de lista"
//   autor "Paulo César de Lima Rocha"
//   data "24/06/2020"

#include <stdio.h>
#include <stdlib.h>

// Tipo de variável ***********************************************************
struct tNo {
    int aluno;
    struct tNo *prox;
    struct tNo *time;
};

// Declaração de funções ******************************************************
void atualizaLista (struct tNo **, struct tNo *);
struct tNo *criarNo (int);
int defineAmizade (struct tNo **, int, int);
void listagem (struct tNo *);
int montaTimes (struct tNo *, int, int *);

// Protótipo de função ********************************************************
int main(void) {
    int nAlunos, mLista, validacao, *repete;
    struct tNo *lista = NULL;
    int iAluno, jAluno, times=0, i;

    //printf("Digite o numero de alunos e o numero de linhas na lista: ");
    scanf("%d %d", &nAlunos, &mLista);

    repete = malloc(sizeof(int) * 5000);

    for (i = 0; i < nAlunos; i++) {
        atualizaLista(&lista, criarNo(i+1));
    }

    for (i=0; i<mLista; i++) {
        do {
            //printf("Amizade No %d: ", i + 1);
            scanf("%d %d", &iAluno, &jAluno);
            validacao = defineAmizade(&lista, iAluno, jAluno);
            if (validacao) {
                printf("Um desses alunos nao existe. Tente novamente.\n");
            }
        } while (validacao);
    }

    //listagem(lista);
    //printf("\n\n");
    times = montaTimes(lista, 0, repete);
    times++;

    printf("%d", times);
    return 0;
}
//*** FIM *********************************************************************

void atualizaLista (struct tNo **lista, struct tNo *novo) {
    struct tNo *p = (*lista);

    if ((*lista) == NULL) {
        (*lista) = novo;
    } else {
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = novo;
    }
    novo->prox = NULL;
}

struct tNo *criarNo (int idAluno) {
    struct tNo *novo = malloc(sizeof(struct tNo));

    novo->aluno = idAluno;
    novo->time = NULL;
    return novo;
}

int defineAmizade (struct tNo **lista, int iAluno, int jAluno) {
    struct tNo *p = (*lista), *iA, *aux, *jA, *novo = malloc(sizeof(struct tNo));

    iA = jA = p;

    while (iA->aluno != iAluno) {
        iA = iA->prox;
        if (iA == NULL) {
            return 1;
        }
    }

    aux = iA->time;

    while (jA->aluno != jAluno) {
        jA = jA->prox;
        if (jA == NULL) {
            return 1;
        }
    }

    novo->aluno = jA->aluno;

    if (iA->time == NULL) {
        iA->time = novo;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    novo->prox = NULL;

    return 0;
}

void listagem (struct tNo *lista) {
    struct tNo *p = lista, *q;

    while (p != NULL) {
        printf("%d(", p->aluno);
        q = p->time;
        while (q != NULL) {
            printf(" %d", q->aluno);
            q = q->prox;
        }
        printf(" ) ");
        p = p->prox;
    }
}

/*int montaTimes (struct tNo *lista, int mLista) {
    int *timeAmigos, *timeSemAmigos, qntTime, i, j, aux;
    struct tNo *p = lista, *q;

    i = j = qntTime = aux = 0;
    timeAmigos = malloc (sizeof(int) * 5000);
    timeSemAmigos = malloc (sizeof(int) * 5000);

    if (timeAmigos == NULL || timeSemAmigos == NULL) {
        printf("Nao foi possivel alocar os valores. Tente novamente.");
        exit(1);
    }

    do (
        if (p->time != NULL) {
            if (timeAmigos[0] == NULL) {
                timeAmigos[0] = p->aluno;
            } else {

            }

            i++;
            q = p->time;
            do {

            } while (q != NULL);
        } else {
            timeSemAmigos[j] = p->aluno;
            j++;
        }
        p = p->prox;
    ) while (p != NULL);

    qntTime++;

    free(timeAmigos);
    free(timeSemAmigos);
    return qntTime;
} */

int montaTimes (struct tNo *lista, int i, int *repete) {
    int aux = 0;
    struct tNo *p = lista;

    for (aux = 0; aux < i; aux++) {
        if (p->aluno == repete[aux]) {
            return 1;
        }
    }
    repete[i] = p->aluno;
    p = p->time;
    if (p == NULL) {
        return 0;
    }

    return 1 + montaTimes(p, i+1, repete);
}
