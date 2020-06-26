#include <stdio.h>
#include <stdlib.h>


int pesqSeq(int chave, int vetor[], int n, int* repet);

main() {
	int chave, vetor[50], i, casa;
	int repeticoes;
	
	srand(time(NULL));
	
	repeticoes = 0;
	
	
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
	
	casa = pesqSeq(chave, vetor, 50, &repeticoes);
	
	if (casa == -1) {
		printf("O valor fornecido não foi encontrado no vetor.\n");
	} else {
		printf("O valor foi encontrado na casa %d.\n", casa);
	}
	
	printf("A busca foi executada %d vezes.", repeticoes);
	
	return 0;
}

int pesqSeq(int chave, int vetor[], int n, int* repet) {
	int j;
	
	for (j = 0; j < n; j++) {
		*repet = *repet + 1;
		if (chave == vetor[j]) {
			return j + 1;
		}
	}
	
	return -1;
}
