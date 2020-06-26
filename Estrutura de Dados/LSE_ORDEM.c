// Sintese
//   objetivo "LSE - Lista Simplesmente Encadeada com CRUD e Ordenação"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "29/04/2020"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tAluno {
	char nome[50];
	float nota;  // chave de ordenação
};

struct tNo {
	struct tAluno dado;
	struct tNo *prox;
};

void inicializar(struct tNo **lst);
void incluir(struct tNo **lst, struct tNo *novo);
void listar(struct tNo *lst);
void alterar(struct tNo **lst);
void pesquisar(struct tNo *lst);
void destruir(struct tNo **lst);
void limpaTela();
void limpaBuffer();

int main() {
	struct tNo *lista, *no;
	char escolha, strNome[50];
	float valNota;

	inicializar(&lista);

	do {
		printf("- - - LSE (Lista Simplesmente Encadeada) com CRUD - - -\n");
		printf("1) Incluir Registro\n2) Listar Registros\n3) Alterar Registro (Nome Apenas)\n4) Pesquisar Registro\n5) Destruir Lista\n6) Sair\n\n>");
		scanf("%c", &escolha);
		limpaBuffer();

		switch(escolha){
			case '1':
				limpaTela();
				printf("Digite a nota: ");
				scanf("%f", &valNota);
				limpaBuffer();
				printf("Digite o nome: ");
				fgets(strNome, 50, stdin);
				limpaBuffer();

				no = malloc(sizeof(struct tNo));
				no->dado.nota = valNota;
				strcpy(no->dado.nome, strNome);
				incluir(&lista, no);
				break;
			case '2':
				limpaTela();
				listar(lista);
				break;
			case '3':
				limpaTela();
				alterar(&lista);
				break;
			case '4':
				limpaTela();
				pesquisar(lista);
				break;
			case '5':
				limpaTela();
				destruir(&lista);
				break;
			case '6':
				limpaTela();
				break;
			default:
				limpaTela();
				printf("Escolha inválida. Tente novamente...");
		}
	} while (escolha != '6');
	return 0;
}

void inicializar(struct tNo **lst) {
	(*lst) = NULL;
}

void incluir(struct tNo **lst, struct tNo *novo) {
    struct tNo *p = (*lst), *q;
    if ((*lst) == NULL) { // lista vazia
        (*lst) = novo;
        novo->prox = NULL;  // (*lst)->prox = NULL;
    }
    else { // inicio, meio e fim
        if (novo->dado.nota < (*lst)->dado.nota || novo->dado.nota == (*lst)->dado.nota) { // inclusao inicio
            novo->prox = (*lst);
            (*lst) = novo;
        }
        else { // meio e fim
            while (p->prox != NULL) {
                p = p->prox;
            }
            if (novo->dado.nota > p->dado.nota) { // fim
                p->prox = novo;
                novo->prox = NULL;
            }
            else { // meio
                p = (*lst);
                while (p->dado.nota < novo->dado.nota) {
                    q = p;
                    p = p->prox;
                }
                q->prox = novo;
                novo->prox = p;
            }
        }
    }
}

void listar(struct tNo *lst) {
	struct tNo *p = lst;
	int cont = 0;
	while (p != NULL) {
		printf("--> %2.2f - %s\n", p->dado.nota, p->dado.nome);
		p = p->prox;
		cont++;
	}
	if (cont == 0) {
		printf("A lista está vazia.\n\n");
	}
	free(p);
}

void alterar(struct tNo **lst) {
	struct tNo *p = (*lst);
	char *nomePesq, *novoNome;

	novoNome = nomePesq = (char *)malloc(sizeof(char));	//Strings dinâmicas
	printf("Digite o nome que deseja alterar: ");
	fgets(nomePesq, 50, stdin);

	while (strcmp(nomePesq, p->dado.nome) != 0 && p != NULL) { //Avançar enquanto não for igual e enquanto não for o último registro da lista
		p = p->prox;
		if (p == NULL) {
			printf("Nenhum registro foi encontrado. Aperte qualquer tecla para continuar...");
			getchar();
			limpaBuffer();
			return;
		}
	}

	printf("Digite o novo nome: ");
	fgets(novoNome, 50, stdin);
	limpaBuffer();

	strcpy(p->dado.nome, novoNome);

	//free(p);
	free(nomePesq);
}

void pesquisar(struct tNo *lst) {
	struct tNo *p = lst;
	char *nomePesq;

	nomePesq = (char *)malloc(sizeof(char));	//String dinâmica
	printf("Digite o nome que deseja pesquisar: ");
	fgets(nomePesq, 50, stdin);
	limpaBuffer();

	while (strcmp(nomePesq, p->dado.nome) != 0 && p != NULL) { //Avançar enquanto não for igual e enquanto não for o último registro da lista
		p = p->prox;
		if (p == NULL) {
			printf("Nenhum registro foi encontrado. Aperte qualquer tecla para continuar...");
			getchar();
			limpaBuffer();
			return;
		}
	}
	printf("--> %2.2f - %s\n", p->dado.nota, p->dado.nome);
}

void destruir(struct tNo **lst) {
	struct tNo *p = (*lst);
	struct tNo *q;

	while(p != NULL) {
		q = p->prox;
		free(p);
		p = q;
	}
	*lst = NULL;
	inicializar(lst);
	printf("Lista deletada com sucesso. Aperte qualquer tecla para continuar...\n");
	getchar();
	limpaBuffer();
	free(q);
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
