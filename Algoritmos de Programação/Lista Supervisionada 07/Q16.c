/*
  Objetivo:		Criar um algoritmo que lêia um vetor A e B, cada um com 10 elementos, e gere uma matriz C com o resultado das somas de A e B.
  Entrada:		20 valores divididos para dois vetores.
  Saída:		Soma dos dois vetores em uma matriz C.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int vetorA[10], vetorB[10], matriz[10][10], ctrl, ctrl2;
	
	//ctrl2 = coluna
	//ctrl = linha
	
	printf("Vetor A\n");
	for (ctrl = 0; ctrl < 10; ctrl++) {
		printf("Digite o valor %d: ", ctrl + 1);
		scanf("%d", &vetorA[ctrl]);
		fflush(stdin);
	}
	printf("\nVetor B\n");
	for (ctrl = 0; ctrl < 10; ctrl++) {
		printf("Digite o valor %d: ", ctrl + 1);
		scanf("%d", &vetorB[ctrl]);
		fflush(stdin);
	}
	system("cls");
	printf("\t\t\t   TABELA \tMATRIZ\n\n");
	for (ctrl = 0; ctrl < 10; ctrl++) {
		for (ctrl2 = 0; ctrl2 < 10; ctrl2++) {
			matriz[ctrl][ctrl2] = vetorA[ctrl] + vetorB[ctrl2];
			printf("%d \t", matriz[ctrl][ctrl2]);
		}
		printf("\n");
	}


	return 0;
}

