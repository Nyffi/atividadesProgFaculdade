// Sintese
//   objetivo "Lista Circular"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "29/04/2020"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
	struct tProduto dado;
	struct tNo *prox;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tNo **);
void incluir(struct tNo **, struct tNo *);
void excluir(struct tNo **, struct tNo *);
struct tNo *consultar(struct tNo *, int);
void listar(struct tNo *);
void destruir(struct tNo **);
void limpaTela();
void limpaBuffer();

//*** Bloco Principal **********************************************************
int main(void) {
	struct tNo *lista, *p;
	int opcao, codigo;

	inicializar(&lista);
	do {
        opcao = menu();
        switch (opcao) {
               case 1:
                    printf("\n\n*** Inclusao ***\n\n");
                    p = malloc(sizeof(struct tNo)); // Criar um no
                    printf("Digite o codigo...: ");
                    scanf("%d", &(p->dado.codigo));
                    printf("Digite a descricao: ");
                    limpaBuffer();
                    fgets(p->dado.descricao, 30, stdin);
                    incluir(&lista, p); // Incluir o no com produto criado na lista
	                break;
               case 2:
                    printf("\n\n*** Consulta ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(lista, codigo);
                    if (p != NULL) {
                        if (p->dado.codigo >= 0)
                          printf("Encontrou: %s\n", p->dado.descricao);
                        else
                          p->dado.codigo = p->dado.codigo + 1000000000;
                    } else
                        printf("Codigo nao encontrado!\n");
	                break;
               case 3:
                    printf("\n\n*** Listagem ***\n\n");
                    listar(lista); // Listar (mostrar na tela) todos os produtos
	                break;
               case 4:
                    printf("\n\n*** Alteracao ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(lista, codigo);
                    if (p != NULL) {
                        if (p->dado.codigo >= 0)
                          printf("Encontrou: %s\n", p->dado.descricao);
                        else {
                          p->dado.codigo = p->dado.codigo + 1000000000;
                          p = p->prox;
                        }
                    	printf("Descricao atual........: %s\n", p->dado.descricao);
	                    printf("Digite a nova descricao: ");
	                    limpaBuffer();
	                    fgets(p->dado.descricao, 30, stdin);
					}
                    else
                    	printf("Codigo nao encontrado!\n");
	                break;
               case 5:
                    printf("\n\n*** Exclusao ***\n\n");
                    printf("Digite o codigo: ");
                    scanf("%d", &codigo);
                    p = consultar(lista, codigo);
                    if (p != NULL) {
                        if (p->dado.codigo >= 0)
                          printf("Encontrou: %s\n", p->dado.descricao);
                        else {
                          p->dado.codigo = p->dado.codigo + 1000000000;
                          p = p->prox;
                        }
                    	excluir(&lista, p);
                    } else
                    	printf("Codigo nao encontrado!\n");
	                break;
        }
    } while (opcao != 0);
	destruir(&lista);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** MENU ***\n\n");
    printf("1. Inclusao\n");
    printf("2. Consulta\n");
    printf("3. Listagem\n");
    printf("4. Alteracao\n");
    printf("5. Exclusao\n");
    printf("0. Sair\n\n");
    printf("Escolha sua opcao: ");
    scanf("%d", &op);
    return op;
}

//*** Inicializar **************************************************************
void inicializar(struct tNo **lst) {
	(*lst) = NULL;
}

//*** Incluir ******************************************************************
void incluir(struct tNo **lst, struct tNo *novo) {
    struct tNo *q = (*lst), *p;
    if ((*lst) == NULL) { // Lista vazia
        novo->prox = novo;
        (*lst) = novo;
    }
    else { // meio
        p = (*lst)->prox;
        while ((novo->dado.codigo < (*lst)->dado.codigo) && (p->dado.codigo < novo->dado.codigo)) {
            q = p;
            p = p->prox;
        }
        if(novo->dado.codigo == q->dado.codigo) {
          while ((novo->dado.codigo == p->dado.codigo)) {
            q = p;
            p = p->prox;
            if (p->prox == (*lst) && novo->dado.codigo == (*lst)->dado.codigo)
              break;
          }
        }
        q->prox = novo;
        novo->prox = p;
        if (novo->dado.codigo >= (*lst)->dado.codigo)
          (*lst) = novo;
    }
}

//*** Excluir ******************************************************************
void excluir(struct tNo **lst, struct tNo *vitima) {
	struct tNo *p = (*lst);
	if (vitima == vitima->prox) // Unico
		(*lst) = NULL;
	else { // "meio"
		while (p->prox != vitima)
			p = p->prox;
		p->prox = vitima->prox;
		if ((*lst) == vitima) // Ultimo
			(*lst) = p;
	}
	free(vitima);
}

//*** Consultar ****************************************************************
struct tNo *consultar(struct tNo *lst, int codigo) {
    struct tNo *p = lst, *q;

    if (p == NULL)
        return NULL;
    do {
        p = p->prox;
        q = p->prox;
        //printf("[DEBUG] p >> %d - %s\n[DEBUG] q >> %d - %s\n\n", p->dado.codigo, p->dado.descricao, q->dado.codigo, q->dado.descricao);
        if (p->dado.codigo == codigo) {
            if (q->dado.codigo == codigo) {
                printf("Dois ou mais valores iguais foram encontrados\n\n");
                do {
                    //printf("[DEBUG] lst = %d - %s\n", lst->dado.codigo, lst->dado.descricao);
                    printf("%d - %s\n", p->dado.codigo, p->dado.descricao);
                    p = p->prox;
                    //printf("[DEBUG] Valor p avançou\n");
                    q = p->prox;
                    //printf("[DEBUG] Valor q avançou\n");
                    //printf("[DEBUG] Ponteiros atualizados\n");
                } while(p->dado.codigo == codigo ); //&& q->dado.codigo != lst->dado.codigo
                q->dado.codigo = q->dado.codigo - 1000000000;
                return q;
            }
                return p;
        }
    } while (p != lst);
    //printf("[DEBUG] Val nao encontrado\n");
    return NULL;
}

//*** Listar *******************************************************************
void listar(struct tNo *lst) {
	struct tNo *p = lst;
	if (p == NULL)
		return;
	do {
		p = p->prox;
		printf("%d - %s >> %d - %s\n", p->dado.codigo, p->dado.descricao, p->prox->dado.codigo, p->prox->dado.descricao);
	} while (p != lst);
}

//*** Destruir *****************************************************************
void destruir(struct tNo **lst) {
	struct tNo *p = (*lst), *q;
	if (p != NULL) {
		q = p;
		p = p->prox;
		q->prox = NULL;
	}
	while (p != NULL) {
		q = p;
		p = p->prox;
		free(q);
	}
	inicializar(lst);
}

void limpaTela() {
	#ifdef _WIN32
        system("cls");
    #endif

	#ifdef linux
        system("clear");
    #endif
}

void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*** FIM **********************************************************************
