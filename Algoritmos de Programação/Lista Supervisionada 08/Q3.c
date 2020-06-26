// Objetivo: Faça um programa que solicite o primeiro e o último nome de 5 pessoas.
// Entrada:	Primeiro e último nome de 5 pessoas.
// Saída: Tamanho de cada primeiro e ultimo nome e o nome completo concatenado.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



main() {
	char nome1[5][20], nome2[5][20], nomeComp[5][41];
	int ctrl, tamNome1[5], tamNome2[5];
	
	
	for (ctrl = 0; ctrl < 5; ctrl++) {
		printf("Digite o primeiro nome da pessoa No %d: ", ctrl + 1);
		gets(nome1[ctrl]);
		fflush(stdin);
		tamNome1[ctrl] = strlen(nome1[ctrl]);
		strcat(nomeComp[ctrl], nome1[ctrl]);
		strcat(nomeComp[ctrl], " ");
		printf("Digite o ultimo nome da pessoa No %d: ", ctrl + 1);
		gets(nome2[ctrl]);
		fflush(stdin);
		tamNome2[ctrl] = strlen(nome2[ctrl]);
		strcat(nomeComp[ctrl], nome2[ctrl]);
	}
	system("cls");
	for (ctrl = 0; ctrl < 5; ctrl++) {
		printf("Primeiro nome: ");
		puts(nome1[ctrl]);
		printf("Tamanho: %d\n", tamNome1[ctrl]);
		printf("Ultimo nome: ");
		puts(nome2[ctrl]);
		printf("Tamanho: %d\n\n", tamNome2[ctrl]);
		printf("Nome concatenado: ");
		puts(nomeComp[ctrl]);
		printf("\n\n");
	}
	return 0;
}
