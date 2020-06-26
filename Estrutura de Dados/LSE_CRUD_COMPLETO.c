// Sintese
//   objetivo "LSE - Lista Simplesmente Encadeada com CRUD"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "04/04/2020"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct tAluno {
	char nome[50];
	float nota;  // chave de ordenação
};

struct tNo {
	struct tAluno dado;
	struct tNo *prox;
};

struct tDescritor {
	struct tNo *ini;
	int qtd;
	struct tNo *fim;
};

void inicializar(struct tNo **lst);
void incluir(struct tNo **lst, struct tNo *novo);
void listar(struct tNo *lst);
void alterar(struct tNo **lst, char *nomePesq, char *novoNome);
struct tNo* pesquisar(struct tNo *lst, char *nome);
void excluir(struct tNo **lst, char *nome);
void destruir(struct tNo **lst);
void limpaTela();
void limpaBuffer();

int main() {
	setlocale(LC_ALL, "Portuguese");
	struct tNo *lista, *no;
	char escolha, strNome[50], nomePesq[50], novoNome[50];
	float valNota;

	//nomePesq = novoNome = (char *)malloc(sizeof(char));
	inicializar(&lista);

	do {
		printf("- - - LSE (Lista Simplesmente Encadeada) com CRUD - - -\n");
		printf("1) Incluir Registro\n2) Listar Registros\n3) Alterar Registro (Nome Apenas)\n4) Pesquisar Registro\n5) Excluir Registro\n6) Destruir a Lista e Sair\n\n>");
		scanf("%c", &escolha);
		limpaBuffer();

		switch(escolha){
			case '1':
				limpaTela();
				printf("Digite a nota: ");
				scanf("%f", &valNota);
				limpaBuffer();
				printf("Digite o nome: ");
				gets(strNome);

				no = malloc(sizeof(struct tNo));
				no->dado.nota = valNota;
				strcpy(no->dado.nome, strNome);
				incluir(&lista, no);
				limpaTela();
				break;
			case '2':
				limpaTela();
				listar(lista);
				break;
			case '3':
				limpaTela();
				printf("Digite o nome que deseja alterar: ");
				gets(nomePesq);
				printf("Digite o novo nome: ");
				gets(novoNome);
				alterar(&lista, nomePesq, novoNome);
				break;
			case '4':
				limpaTela();
				printf("Digite o nome que deseja pesquisar: ");
				gets(nomePesq);
				no = pesquisar(lista, nomePesq);
				if (no == NULL)
					printf("Nome não encontrado. Aperte qualquer tecla para continuar...");
				else
					printf("Nota: %.2f \n\nAperte qualquer tecla para continuar...", no->dado.nota);
				getchar();
				limpaTela();
				break;
			case '5':
				limpaTela();
				printf("Digite o nome que deseja excluir: ");
				gets(nomePesq);
				excluir(&lista, nomePesq);
				break;
			case '6':
				limpaTela();
				destruir(&lista);
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
	if (((*lst) == NULL) || (novo->dado.nota < (*lst)->dado.nota)) { // lista vazia & inclusao inicio
		novo->prox = (*lst);
		(*lst) = novo;
	}
	else { // meio e fim
		while ((p != NULL) && (p->dado.nota < novo->dado.nota)) {
			q = p;
			p = p->prox;
		}
		q->prox = novo;
		novo->prox = p;
	}
}

void listar(struct tNo *lst) {
	struct tNo *p = lst;
	int cont = 0;
	printf("- - - NOTA - NOME - - - - - - - - - - - - - - - - - - -\n");
	while (p != NULL) {
		printf("--> %2.2f - %s\n", p->dado.nota, p->dado.nome);
		p = p->prox;
		cont++;
	}
	if (cont == 0) {
		printf("A lista está vazia.\n");
	}

	printf("\nAperte qualquer tecla para continuar...");
	getchar();
	free(p);

	limpaTela();
}

void alterar(struct tNo **lst, char *nomePesq, char *novoNome) {
	struct tNo *p = (*lst);

	if (p == NULL) {
		printf("A lista está vazia. Aperte qualquer tecla para continuar...");
		getchar();
		limpaTela();
		return;
	}

	while (strcmp(nomePesq, p->dado.nome) != 0) { //Avançar enquanto não for igual e enquanto não for o último registro da lista
		p = p->prox;
		printf("passou\n");
		if (p == NULL) {
			printf("Nenhum registro foi encontrado. Não foi possível realizar a alteração. Aperte qualquer tecla para continuar...");
			getchar();
			limpaTela();
			return;
		}
	}

	strcpy(p->dado.nome, novoNome);

	//free(p);

	limpaTela();
}

struct tNo* pesquisar(struct tNo *lst, char *nome) {
	struct tNo *p = lst;

	while (p != NULL) {
		if (strcmp(nome, p->dado.nome) == 0)
			return p;
		p = p->prox;
	}
	limpaTela();
}

void excluir(struct tNo **lst, char *nome) {
	struct tNo *p = (*lst), *q;
	struct tNo *temp;

	while (p != NULL) {
		if(strcmp(nome, p->dado.nome) == 0){
			break;
		}
		q = p;
		p = p -> prox;
	}

	temp = q->prox;
	q->prox = temp->prox;
	free(temp);

	limpaTela();
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
	free(q);
	limpaTela();
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
