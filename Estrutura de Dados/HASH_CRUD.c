// Sintese ****************************************************
//   objetivo "Tabela hash"
//   autor "Paulo César de Lima Rocha & Edson F. da Fonseca"
//   data "09/05/2020"
#include <stdio.h>
#include <stdlib.h>

//*** Declaracao de constante *********************************
#define M 11 // 11 é primo
#define VAZIA -1

//*** Declaracao de tipo **************************************
struct tProduto {
 int codigo;
 char descricao[30];
};

// *** Prototipo de funcoes ***********************************
int menu(void);
int hash(int, int);
void incluir(struct tProduto[]);
void listar(struct tProduto[]);
int consultar(struct tProduto[]);
void excluir(struct tProduto[], int);
void limpaBuffer();

// *** main ***************************************************
int main(void) {
    struct tProduto tabelaHash[M];
    int op, i;
 // Marca todas as posições como livres
    for (i=0; i<M; i++)
        tabelaHash[i].codigo = VAZIA;
    do {
        op = menu();
        switch (op) {
            case 1:
                incluir(tabelaHash);
                break;
            case 2:
                listar(tabelaHash);
                break;
            case 3:
                printf("\n\n*** Consulta ***\n\n");
                if (consultar(tabelaHash) == -1)
                    printf("\n\nERRO: Produto nao encontrado!\n");
                break;
            case 4:
                printf("\n\n*** Exclusao ***\n\n");
                i = consultar(tabelaHash);
                if (i == -1)
                    printf("\n\nERRO: Produto nao encontrado!\n");
                else
                    excluir(tabelaHash, i);
        }
    } while (op != 0);
    return 0;
}

//*** menu ****************************************************
int menu(void) {
    int op;
    do {
         printf("\n\n*** MENU ***\n\n");
         printf("1. Incluir\n");
         printf("2. Listar\n");
         printf("3. Consultar\n");
         printf("4. Excluir\n");
         printf("0. Sair\n\n");
         printf("Digite sua opcao: ");
      scanf("%d", &op);
      if ((op < 0) || (op > 4))
        printf("\nValor invalido!!!\n");
    } while ((op < 0) || (op > 4));
    return op;
}

//*** hash ****************************************************
int hash(int k, int i) {
    return (k + i) % M;
}

//*** incluir *************************************************
void incluir(struct tProduto tabelaHash[]) {
    int codigo, i=0, pos;
    printf("\n\n*** Inclusao ***\n\n");
    do {
        printf("Digite o codigo do produto...: ");
        scanf("%i", &codigo);
    } while (codigo < 1);
    printf("\nPOSICOES VERIFICADAS: ");
    do {
        pos = hash(codigo, i);
        printf("%d, ", pos);
        i++;
    } while ((i < M) && (tabelaHash[pos].codigo != VAZIA));
    if (i == M)
        printf("\n\nERRO: Limite alcancado!\n");
    else {
        tabelaHash[pos].codigo = codigo;
        printf("\n\nDigite a descricao do produto: ");
        limpaBuffer();
        fgets(tabelaHash[pos].descricao, 30, stdin);
    }
}

//*** listar **************************************************
void listar(struct tProduto tabelaHash[]) {
    int i;
    printf("\n\n*** Listagem ***\n\n** (    ) = Vazio **\n** ( X  ) = Preenchido **\n** ( XX ) = Excluido **\n\n");
    for (i=0; i<M; i++) {
        switch (tabelaHash[i].codigo) {
            case VAZIA:
                printf("[%3d] = (   )\n", i);
            break;
            case 0:
                printf("[%3d] = ( XX )\n", i);
                break;
            default:
                printf("[%3d] = ( X ) = %d, %s\n", i, tabelaHash[i].codigo, tabelaHash[i].descricao);
        }
    }
}

//*** consultar ***********************************************
int consultar(struct tProduto tabelaHash[]) {
    int codigo, i=0, pos;
    do {
        printf("Codigo buscado: ");
        scanf("%i", &codigo);
    } while (codigo < 1);
    printf("\nPOSICOES VERIFICADAS: ");
    do {
        pos = hash(codigo, i);
        printf("%d, ", pos);
        i++;
    } while ((i < M) && (tabelaHash[pos].codigo != VAZIA) && (tabelaHash[pos].codigo != codigo));
    if ((i == M) || (tabelaHash[pos].codigo == VAZIA))
        return -1;
    if (tabelaHash[pos].codigo == 0) {
        printf("\n\nEssa posicao foi excluida.");
    }
    printf("\n\nDescricao.....: %s\n", tabelaHash[pos].descricao);
    return pos;
}

//*** excluir *************************************************
void excluir(struct tProduto tabelaHash[], int i) {
    tabelaHash[i].codigo = 0;
}

//*** Limpar Buffer ************************************************************
void limpaBuffer() {
	int c;

	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

//*************************************************************
