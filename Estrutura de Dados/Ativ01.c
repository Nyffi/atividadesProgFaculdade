#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10
#define VAZIA -1

struct tValor {
    float dec;
};

int menu(void);
void incluir(struct tValor[], int);
void listar(struct tValor[]);
int consultar(struct tValor[]);
void excluir(struct tValor[], int);
int hash (int, int);
int hashII (int);

int main(void) {
    struct tValor tabelaHash[M];
    float val[6] = {1.2, 1.7, 1.3, 1.8, 1.42, 1.51};
    int i, aux;

    for (i=0; i<M; i++)
        tabelaHash[i].dec = VAZIA;

    for (i = 0; i < 6; i++) {
        aux = (int)(val[i] * 100);
        incluir(tabelaHash, aux);
    }
    listar(tabelaHash);
    return 0;
}

//*** incluir *************************************************
void incluir(struct tValor tabelaHash[], int codigo) {
    int i=0, pos;
    float val;
    printf("\n\n*** Inclusao ***\n\n");

    printf("\nPOSICOES VERIFICADAS: ");
    do {
        pos = hash(codigo, i);
        printf("%d, ", pos);
        i++;
    } while ((i < M) && (tabelaHash[pos].dec != VAZIA));
    if (i == M)
        printf("\n\nERRO: Limite alcancado!\n");
    else {
        val = (float)(codigo);
        tabelaHash[pos].dec = val;
    }
}

//*** listar **************************************************
void listar(struct tValor tabelaHash[]) {
    int i, aux;
    printf("\n\n*** Listagem ***\n\n** (    ) = Vazio **\n** ( X  ) = Preenchido **\n** ( XX ) = Excluido **\n\n");
    for (i=0; i<M; i++) {
        if (tabelaHash[i].dec != VAZIA)
            aux = (int)(tabelaHash[i].dec * 100);
        else if (tabelaHash[i].dec == -1.00) {
            aux = VAZIA;
        } else if (tabelaHash[i].dec == 0.00) {
            aux = 0;
        }

        switch (aux) {
            case VAZIA:
                printf("[%3d] = (   )\n", i);
            break;
            case 0:
                printf("[%3d] = ( XX )\n", i);
                break;
            default:
                printf("[%3d] = ( X ) = %.2f\n", i, tabelaHash[i].dec / 100);
        }
    }
}

int hash (int k, int i) {
    return (k + i) % M;
}

int hashII (int k) {
    return abs ((M-k)%7);
}
