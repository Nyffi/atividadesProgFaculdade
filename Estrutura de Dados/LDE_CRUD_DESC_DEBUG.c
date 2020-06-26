// Sintese
//   objetivo "LSE - Lista Simplesmente Encadeada com CRUD e Descritor"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "07/04/2020"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** Declaracoes de tipos *****************************************************
struct tProduto {
	int codigo; // chave de ordenação
	char descricao[30];
};

struct tNo {
    struct tNo *ant;
	struct tProduto dado;
	struct tNo *prox;
};

struct tDescritor {
	struct tNo *ini;
	int qtd;
	struct tNo *fim;
};

//*** Prototipos de funcoes ****************************************************
int menu(void);
void inicializar(struct tDescritor *);
void incluir(struct tDescritor *, struct tNo *);
void excluir(struct tDescritor *, struct tNo *);
struct tNo *consultar(struct tDescritor, int);
void listar(struct tDescritor);
void destruir(struct tDescritor *);
void limpaTela();
void limpaBuffer();
void atualizaFim(struct tDescritor *);

//*** Bloco Principal **********************************************************
int main(void) {
	struct tDescritor lista;
	struct tNo *p;
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
                    if (p != NULL)
                    	printf("Encontrou: %s\n", p->dado.descricao);
                    else
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
                    if (p != NULL)
                    	excluir(&lista, p);
                    else
                    	printf("Codigo nao encontrado!\n");
                    atualizaFim(&lista);
	                break;
        }
    } while (opcao != 0);
	destruir(&lista);
	return 0;
}

//*** Menu *********************************************************************
int menu(void) {
    int op;
    printf("\n\n*** LSE com CRUD e Descritor ***\n\n");
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
void inicializar(struct tDescritor *lst) {
	(*lst).ini = NULL;
	(*lst).fim = NULL;
	lst->qtd = 0;
}

//*** Incluir ******************************************************************
void incluir(struct tDescritor *lst, struct tNo *novo) {
	struct tDescritor *p = lst;
	struct tNo *q, *s = lst->ini;
	if ((lst->ini == NULL) || (novo->dado.codigo < lst->ini->dado.codigo)) { // Lista vazia OU inicio
		novo->prox = lst->ini;
		novo->ant = NULL;
		if (lst->ini != NULL) {
            lst->ini->ant = novo;
		}
		lst->ini = novo;
		if (p->qtd == 0)
            p->fim = novo;
	}
	else { // fim ou meio
		while ((s != NULL) && (s->dado.codigo < novo->dado.codigo)) {
			q = s;
			s = s->prox;
		}
		q->prox = novo;
		novo->prox = s;
		novo->ant = q;
		if (novo->prox == NULL) {
            p->fim = novo;
		}
		if (s != NULL)
            s->ant = q->prox;
	}
    p->qtd = p->qtd + 1;
}

//*** Excluir ******************************************************************
void excluir(struct tDescritor *lst, struct tNo *vitima) {
	struct tNo *p = lst->ini, *q;

	if (lst->ini == vitima) {   // Unico OU Inicio
		lst->ini = vitima->prox;
		lst->ini->ant = NULL;
    }
	else { // fim e meio
		while (p != vitima) {
			q = p;
			p = p->prox;
		}
		q->prox = vitima->prox;
		q->prox->ant = q;
	}
	free(vitima);
	lst->qtd = lst->qtd - 1;
}

//*** Consultar ****************************************************************
struct tNo *consultar(struct tDescritor lst, int codigo) {
	struct tNo *p = lst.ini;
	while (p != NULL) {
		if (p->dado.codigo == codigo)
			return p;
		p = p->prox;
	}
	return NULL;
}

//*** Listar *******************************************************************
void listar(struct tDescritor lst) {
	struct tNo *p = lst.ini, *q = lst.fim;
	char debug[] = "NULL", copDesc[30];
	int qnt = lst.qtd, copCod, debugCod = 999;

	if (p->ant == NULL || p->prox == NULL) {
        copCod = debugCod;
        strcpy(copDesc, debug);
	}

	printf("Qnt de nos: %d\n\n", qnt);
	while (p != NULL) {

        if (p->ant == NULL) {
            copCod = debugCod;
            strcpy(copDesc, debug);
            printf("%d - %s << ", copCod, copDesc);
        } else {
            printf("%d - %s <<", p->ant->dado.codigo, p->ant->dado.descricao);
        }

		printf("%d - %s", p->dado.codigo, p->dado.descricao);
		if (p->prox == NULL) {
            copCod = debugCod;
            strcpy(copDesc, debug);
            printf(" >> %d - %s\n", copCod, copDesc);
        } else {
            printf(" >> %d - %s\n", p->prox->dado.codigo, p->prox->dado.descricao);
        }
		p = p->prox;
	}

	if (qnt > 0) {
        printf("\nPrimeiro No: %d - %s\n", lst.ini->dado.codigo, lst.ini->dado.descricao);
        printf("Ultimo No: %d - %s\n", lst.fim->dado.codigo, lst.fim->dado.descricao);
	} else {
        printf("Nenhum no foi encontrado.\n");
	}

}

//*** Destruir *****************************************************************
void destruir(struct tDescritor *lst) {
	struct tNo *p = lst->ini, *q;
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

void atualizaFim(struct tDescritor *lst) {
    struct tNo *p = lst->ini, *q;
	int i = 0;

    while (i != lst->qtd && lst->qtd > 0) {
        q = p;
        if (p->prox == NULL) {
            lst->fim = q;
            return;
        } else
            p = p->prox;
    }
}
//*** FIM **********************************************************************

