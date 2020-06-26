// Sintese
//   objetivo "Grafo com BFS e DFS"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "05/06/2020"
#include <stdio.h>
#include <stdlib.h>

//*** Declaracoes de tipos *****************************************************
struct tVertice {
	char rotulo;
	struct tAresta *arestas;
	char visitado; // 1/0 = V/F
	struct tVertice *prox; // LISTA DE VERTICES
};

struct tAresta {
	int peso;
	struct tVertice *destino;
	struct tAresta *prox; // LISTA DE ARESTAS
};

struct tNoFila {
	struct tVertice *vertice;
	struct tNoFila *prox;
};

struct tFila {
	struct tNoFila *ini;
	struct tNoFila *fim;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializarGrafo(struct tVertice**);
struct tVertice *criarVertice(char);
void incluirVertice(struct tVertice**, struct tVertice*);
struct tVertice *consultarVertice(struct tVertice*, char);
void incluirAresta(struct tVertice*, int, struct tVertice*);
void listarGrafo(struct tVertice*);
void destruirGrafo(struct tVertice**);
void inicializarFila(struct tFila*);
void enqueue(struct tFila*, struct tNoFila*);
struct tNoFila *dequeue(struct tFila*);
int filaVazia(struct tFila);
void destruirFila(struct tFila*);
void bfs(struct tVertice*);
void dfs(struct tVertice*, int);
void limpaBuffer();

//*** Bloco Principal **********************************************************
int main(void) {
	struct tVertice *grafo, *verticeOrigem, *verticeDestino;
	char rotulo;
	int opcao, peso;

	inicializarGrafo(&grafo);
	do {
        opcao = menu();
        switch (opcao) {
               case 1:
                    printf("\n\n*** Inclusao de Vertice ***\n\n");
                    printf("Valor (char): ");
                    limpaBuffer();
                    scanf("%c", &rotulo);
                    incluirVertice(&grafo, criarVertice(rotulo));
	                break;
               case 2:
                    printf("\n\n*** Inclusao de Aresta ***\n\n");
                    printf("Vertice origem (char).: ");
                    limpaBuffer();
                    scanf("%c", &rotulo);
                    verticeOrigem = consultarVertice(grafo, rotulo);
                    printf("Vertice destino (char): ");
                    limpaBuffer();
                    scanf("%c", &rotulo);
                    verticeDestino = consultarVertice(grafo, rotulo);
                    if ((verticeOrigem == NULL) || (verticeDestino == NULL))
                    	printf("Vertice nao localizado!");
                    else {
						printf("Peso..................: ");
	                    scanf("%d", &peso);
	                    incluirAresta(verticeOrigem, peso, verticeDestino);
					}
	                break;
               case 3:
                    printf("\n\n*** Listagem ***\n\n");
                    listarGrafo(grafo);
	                break;
               case 4:
                    printf("\n\n*** Caminhamento BFS ***\n\n");
                    printf("Vertice (char): ");
                    limpaBuffer();
                    scanf("%c", &rotulo);
                    verticeOrigem = consultarVertice(grafo, rotulo);
                    if (verticeOrigem == NULL)
                    	printf("Vertice nao localizado!");
                    else {
                    	verticeDestino = grafo;
						while (verticeDestino != NULL) {
							verticeDestino->visitado = 0;
							verticeDestino = verticeDestino->prox;
						}
	                    bfs(verticeOrigem);
					}
					break;
                case 5:
                    printf("\n\n*** Caminhamento DFS ***\n\n");
                    printf("Vertice (char): ");
                    limpaBuffer();
                    scanf("%c", &rotulo);
                    verticeOrigem = consultarVertice(grafo, rotulo);
                    if (verticeOrigem == NULL)
                    	printf("Vertice nao localizado!");
                    else {
                    	verticeDestino = grafo;
						while (verticeDestino != NULL) {
							verticeDestino->visitado = 0;
							verticeDestino = verticeDestino->prox;
						}
	                    dfs(verticeOrigem, 0);
					}

        }
    } while (opcao != 0);
	destruirGrafo(&grafo);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Inclusao de vertice\n");
    printf("2. Inclusao de aresta\n");
    printf("3. Listar\n");
    printf("4. Caminhamento BFS\n");
    printf("5. Caminhamento DFS\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Inicializar Grafo ********************************************************
void inicializarGrafo(struct tVertice **grf) {
	(*grf) = NULL;
}

//*** Criar vertice ************************************************************
struct tVertice *criarVertice(char rotulo) {
	struct tVertice *novo = malloc(sizeof(struct tVertice));
	novo->rotulo = rotulo;
	novo->arestas = NULL;
	return novo;
}

//*** Incluir vertice **********************************************************
void incluirVertice(struct tVertice **grf, struct tVertice *novo) {
	struct tVertice *p = *grf;
	if (*grf == NULL)
		(*grf) = novo;
	else {
		while (p->prox != NULL)
			p = p->prox;
		p->prox = novo;
	}
	novo->prox = NULL;
}

//*** Consultar vertice ********************************************************
struct tVertice *consultarVertice(struct tVertice *grf, char rotulo) {
	struct tVertice *vertice = grf;
	while (vertice != NULL) {
		if (vertice->rotulo == rotulo)
			return vertice;
		vertice = vertice->prox;
	}
}

//*** Incluir aresta ***********************************************************
void incluirAresta(struct tVertice *origem, int peso, struct tVertice *destino) {
	struct tAresta *p = origem->arestas;
	struct tAresta *novo = malloc(sizeof(struct tAresta));
	novo->peso = peso;
	novo->destino = destino;

	if (origem->arestas == NULL)
		origem->arestas = novo;
	else {
		while (p->prox != NULL)
			p = p->prox;
		p->prox = novo;
	}
	novo->prox = NULL;
}

//*** Listar Grafo *************************************************************
void listarGrafo(struct tVertice *grf) {
	struct tVertice *vertice = grf;
	struct tAresta *aresta;
	while (vertice != NULL) {
		printf("%c(", vertice->rotulo);
		aresta = vertice->arestas;
		while (aresta != NULL) {
			printf(" %c[%d]", aresta->destino->rotulo, aresta->peso);
			aresta = aresta->prox;
		}
		printf(" ) ");
		vertice = vertice->prox;
	}
}

//*** Destruir Grafo ***********************************************************
void destruirGrafo(struct tVertice **grf) {
	struct tVertice *vertice = (*grf), *verticeAux;
	struct tAresta *aresta, *arestaAux;
	while (vertice != NULL) {
		aresta = vertice->arestas;
		while (aresta != NULL) {
			arestaAux = aresta;
			aresta = aresta->prox;
			free(arestaAux);
		}
		verticeAux = vertice;
		vertice = vertice->prox;
		free(verticeAux);
	}
}

//*** Inicializar Fila ********************************************************
void inicializarFila(struct tFila *desc) {
	(*desc).ini = NULL;
	(*desc).fim = NULL;
}

//*** Enqueue *******************************************************************
void enqueue(struct tFila *desc, struct tNoFila *novo) {
	if ((*desc).ini == NULL) // vazia
		(*desc).ini = novo;
	else
		(*desc).fim->prox = novo;
	(*desc).fim = novo;
	novo->prox = NULL;
}

//*** Dequeue ******************************************************************
struct tNoFila *dequeue(struct tFila *desc) {
	struct tNoFila *p = (*desc).ini;
	if (p != NULL) {
		(*desc).ini = p->prox;
		if ((*desc).ini == NULL)
			(*desc).fim = NULL;
	}
	return p;
}

//*** Fila vazia ***************************************************************
int filaVazia(struct tFila desc) {
	if (desc.ini == NULL)
		return 1;
	return 0;
}

//*** Destruir Fila ************************************************************
void destruirFila(struct tFila *desc) {
	struct tNoFila *p = (*desc).ini, *q;
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializarFila(desc);
}

//*** Caminhamento BFS *********************************************************
void bfs(struct tVertice *vertice) {
	struct tFila fila;
	struct tNoFila *noFila;
	struct tVertice *cara;
	struct tAresta *aresta;

	inicializarFila(&fila);
    vertice->visitado = 1;
    noFila = malloc(sizeof(struct tNoFila));
    noFila->vertice = vertice;
    enqueue(&fila, noFila);
    while (!filaVazia(fila)) {
    	noFila = dequeue(&fila);
    	cara = noFila->vertice;
    	free(noFila);
    	printf("%c, ", cara->rotulo);
		aresta = cara->arestas;
		while (aresta != NULL) {
	        if (!aresta->destino->visitado) {
			    noFila = malloc(sizeof(struct tNoFila));
			    noFila->vertice = aresta->destino;
			    enqueue(&fila, noFila);
				aresta->destino->visitado = 1;
	        }
			aresta = aresta->prox;
		}
	}
}

//*** Caminhamento DFS *********************************************************
void dfs(struct tVertice *vertice, int nivel) {
    struct tVertice *cara = vertice;
    struct tAresta *aresta;
    int novoNivel, i;

    if (!cara->visitado) {
        cara->visitado = 1;
        printf("DFS(%c)\n", cara->rotulo);
        aresta = cara->arestas;
        while (aresta != NULL) {
            //if (!aresta->destino->visitado) {
                for (i = 0; i <= nivel; i++) {
                    printf("  ");
                }
                novoNivel = nivel + 1;
                dfs(aresta->destino, novoNivel);
                aresta->destino->visitado = 1;
            //}
            aresta = aresta->prox;
        }
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
