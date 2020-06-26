#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define SIZE 5

struct tGrafo {
    int matriz[SIZE][SIZE];
};

int menu(void);
void preencherMatriz(struct tGrafo **);
void listarMatriz(struct tGrafo *);
int converteRotulo (char);
void bfs (struct tGrafo *, char);
void limpaBuffer();

int main(void) {
    struct tGrafo *matrix;
    char rotulo;
    int opcao;

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
                bfs(matrix, rotulo);
                break;
            //case 3:
                /*printf("\n\n*** Caminhamento DFS ***\n\n");
                printf("Vertice (char): ");
                limpaBuffer();
                scanf("%c", &rotulo);
                rotulo = toupper(rotulo);
                 */
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

void bfs (struct tGrafo *mat, char rotulo) {
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
}

void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}
