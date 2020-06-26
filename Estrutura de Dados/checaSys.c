#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int sys = 0;
    float teste;
    char escolha, strNome[50];
	float valNota;

    #ifdef _WIN32
        printf("Sistema Windows\nCod: %d", sys);
    #endif

    #ifdef linux
        sys++;
        printf("Sistema Linux\nCod: %d", sys);
    #endif

    printf("Digite a nota: ");
	scanf("%f", &valNota);
	fflush(stdin);
	printf("Digite o nome: ");
	gets(strNome);
	fflush(stdin);
    printf("Nome: %s \nNota: %.2f", strNome, valNota);

    return sys;
}