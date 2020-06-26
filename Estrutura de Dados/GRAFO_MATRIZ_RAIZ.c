#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define SIZE 5

struct tGrafo {
    int matriz[SIZE][SIZE];
};

struct tNoFila {
	char rotulo;
	struct tNoFila *prox;
};

struct tFila {
	struct tNoFila *ini;
	struct tNoFila *fim;
};

int menu(void);
void preencherMatriz(struct tGrafo **);
void listarMatriz(struct tGrafo *);
int converteRotulo (char);
void inicializarFila(struct tFila *);
void inicializarPilha(struct tNoFila **);
void enqueue(struct tFila*, struct tNoFila*);
struct tNoFila *dequeue(struct tFila*);
void push(struct tNoFila**, struct tNoFila *);
struct tNoFila* pop(struct tNoFila**);
int filaVazia(struct tFila);
void destruirFila(struct tFila*);
void bfs (struct tGrafo *, char, int [SIZE]);
void dfs(struct tGrafo *, char, int [SIZE]);
void limpaBuffer();

int main(void) {
    struct tGrafo *matrix;
    char rotulo;
    int opcao, visitados[SIZE], i;


    preencherMatriz(&matrix);

    do {
        opcao = menu();
        switch (opcao) {
            case 1:
                printf("\n\n*** Listagem ***\n\n");
                listarMatriz(matrix);
                break;
            case 2:
                printf("\n\n*** Caminhamento BFS ***\n\n");
                printf("Vertice (char): ");
                limpaBuffer();
                scanf("%c", &rotulo);
                rotulo = toupper(rotulo);
                if (rotulo >= 'A' && rotulo < (65 + SIZE)){
                    for (i = 0; i < SIZE; i++) {
                        visitados[i] = 0;
                    }
                    bfs(matrix, rotulo, visitados);
                } else {
                    printf("Vertice nao localizado!");
                }
                break;
            case 3:
                printf("\n\n*** Caminhamento DFS ***\n\n");
                printf("Vertice (char): ");
                limpaBuffer();
                scanf("%c", &rotulo);
                rotulo = toupper(rotulo);
                if (rotulo >= 'A' && rotulo < (65 + SIZE)){
                    for (i = 0; i < SIZE; i++) {
                        visitados[i] = 0;
                    }
                    dfs(matrix, rotulo, visitados);
                } else {
                    printf("Vertice nao localizado!");
                }
        }
    } while (opcao != 0);

    return 0;
}

int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Listar\n");
    printf("2. Caminhamento BFS\n");
    printf("3. Caminhamento DFS\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

void preencherMatriz(struct tGrafo **matriz) {
    int i, j, val;
    struct tGrafo *mat = (*matriz);

    srand (time(NULL));

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            mat->matriz[i][j] = rand() % 2;
        }
    }
}

void listarMatriz(struct tGrafo *matriz) {
    int i, j;
    struct tGrafo *mat = matriz;

    printf("  A B C D E\n");

    for (i = 0; i < SIZE; i++) {
        printf("%c ", 65 + i);
        for (j = 0; j < SIZE; j++) {
            printf("%d ", mat->matriz[i][j]);
        }
        printf("\n");
    }
}

int converteRotulo (char rotulo) {
    int val;

    switch (rotulo) {
        case 'A':
            val = 0;
            break;
        case 'B':
            val = 1;
            break;
        case 'C':
            val = 2;
            break;
        case 'D':
            val = 3;
            break;
        case 'E':
            val = 4;
            break;
    }

    return val;
}

void inicializarFila(struct tFila *desc) {
	(*desc).ini = NULL;
	(*desc).fim = NULL;
}

void enqueue(struct tFila *desc, struct tNoFila *novo) {
	if ((*desc).ini == NULL) // vazia
		(*desc).ini = novo;
	else
		(*desc).fim->prox = novo;
	(*desc).fim = novo;
	novo->prox = NULL;
}

struct tNoFila *dequeue(struct tFila *desc) {
	struct tNoFila *p = (*desc).ini;
	if (p != NULL) {
		(*desc).ini = p->prox;
		if ((*desc).ini == NULL)
			(*desc).fim = NULL;
	}
	return p;
}

int filaVazia(struct tFila desc) {
	if (desc.ini == NULL)
		return 1;
	return 0;
}

void destruirFila(struct tFila *desc) {
	struct tNoFila *p = (*desc).ini, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializarFila(desc);
}

void inicializarPilha(struct tNoFila **topo) {
	(*topo) = NULL;
}

void push(struct tNoFila **topo, struct tNoFila *novo) {
	novo->prox = (*topo);
	(*topo) = novo;
}


struct tNoFila *pop(struct tNoFila **topo) {
	struct tNoFila *p = (*topo);
	if (p != NULL)
		(*topo) = p->prox;
	return p;
}

/*void bfs (struct tGrafo *mat, char rotulo) {
    int vertice, i, j, listaAux = 0, verificaLista, repetido = 0, quebraLoop = 0;
    char lista[SIZE];

    vertice = converteRotulo(rotulo);
    lista[0] = 65 + vertice;
    verificaLista = listaAux;

    for (i = 0; i < SIZE || !quebraLoop; i++) {
        i = lista[i] - 65;
        for (j = 0; j < SIZE || !quebraLoop; j++) {
            if (mat->matriz[i][j]) {
                listaAux++;
                verificaLista = listaAux;
                do {
                    if (mat->matriz[i][j] == lista[verificaLista]) {
                        repetido = 1;
                    }
                    verificaLista--;
                } while (verificaLista >= 0);

                if (strlen(lista) == SIZE) {
                    quebraLoop = 1;
                    break;
                }

                if (!repetido) {
                    lista[listaAux] = 65 + j;
                }
            }
        }
    }

    printf("A ordem de percurso foi: %s\n\n", lista);
} */

void bfs(struct tGrafo *mat, char rotulo, int visitados[SIZE]) {
	struct tFila fila;
	struct tNoFila *noFila, *p = fila.ini;
	char lista[SIZE];
	int cara, i, j, listaAux = 0, verificaLista, repetido = 0;

	inicializarFila(&fila);
    noFila = malloc(sizeof(struct tNoFila));
    noFila->rotulo = rotulo;
    enqueue(&fila, noFila);
    lista[0] = rotulo;
    printf("A ordem de percurso foi: ");

	while (!filaVazia(fila)) {
        noFila = dequeue(&fila);
    	cara = noFila->rotulo;
    	i = cara - 65;
    	free(noFila);
    	printf("%c", cara);
    	for (j = 0; j < SIZE; j++) {
            if (strlen(lista) >= SIZE) {
                break;
            }
            if (mat->matriz[i][j] && j != i) {
                listaAux++;
                verificaLista = listaAux;
                do {
                    repetido = 0;
                    if (j+65 == lista[verificaLista]) {
                        repetido = 1;
                    }
                    verificaLista--;
                } while (verificaLista >= 0);

                if (!repetido) {
                    noFila = malloc(sizeof(struct tNoFila));
                    noFila->rotulo = j + 65;
                    enqueue(&fila, noFila);
                    lista[listaAux] = j + 65;
                }
	        }
    	}
	}
	destruirFila(&fila);
}

/*void dfs(struct tGrafo *mat, char rotulo, int visitados[SIZE]) {
    struct tNoFila *pilha, *p;
    char lista[SIZE];
    int cara, i, j, listaAux = 0, verificaLista, repetido = 0;

    lista[0] = rotulo;
    p = malloc(sizeof(struct tNoFila));
    p->rotulo = rotulo;
    push(&pilha, p);

    while(pilha != NULL) {
        p = pop(&pilha);
        cara = p->rotulo;
        i = cara - 65;
        free(p);
        printf("Lista = %s\n", lista);
        printf("DFS(%c)\n", cara);
        for(j = 0; j < SIZE; j++) {
            if (strlen(lista) >= SIZE) {
                break;
            }

            if (mat->matriz[i][j]) {
                listaAux++;
                verificaLista = listaAux;
                do {
                    repetido = 0;
                    if (j+65 == lista[verificaLista]) {
                        repetido = 1;
                    }
                    verificaLista--;
                } while (verificaLista >= 0);

                if (!repetido) {
                    p = malloc(sizeof(struct tNoFila));
                    p->rotulo = j + 65;
                    push(&pilha, p);
                    lista[listaAux] = j + 65;
                    break;
                } else {
                    listaAux--;
                }
            }
        }
    }
}*/

void dfs(struct tGrafo *mat, char rotulo, int visitados[SIZE]) {
    int i, val;

    val = rotulo - 65;

    if (visitados[val]) {
        return;
    }

    visitados[val] = 1;
    printf("%c, ", rotulo);
	for (i=0; i<SIZE; i++) {
        if (mat->matriz[val][i]) {
            dfs(mat, i + 65, visitados);
        }
	}
}

void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
