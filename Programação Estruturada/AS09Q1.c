#include <stdio.h>
#include <stdlib.h>

int pesqSeq(int chave, int vetor[], int n);

main() {
	int chave, vetor[50], i, casa;
	
	srand(time(NULL));
	
	for (i = 0; i < 50; i++) {
		vetor[i] = rand() % 100;
		printf("%d, ", vetor[i]);
	}
	printf("\n\n");
	do {
		printf("Digite o valor a ser pesquisado: ");
		scanf("%d", &chave);
		fflush(stdin);
	} while (chave < 0);
	
	casa = pesqSeq(chave, vetor, 50);
	
	if (casa == -1) {
		printf("O valor fornecido não foi encontrado no vetor.");
	} else {
		printf("O valor foi encontrado na casa %d.", casa);
	}
	
	return 0;
}

int pesqSeq(int chave, int vetor[], int n) {
	int j;
	
	for (j = 0; j < n; j++) {
		if (chave == vetor[j]) {
			return j + 1;
		}
	}
	
	return -1;
}
