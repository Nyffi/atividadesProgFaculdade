#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

int encontraMenor (int num[], int contador, int tamanhoVetor);

main() {
	setlocale(LC_ALL, "Portuguese");
	int num[50], i;

	for (i = 0; i < 50; i++) {
		do {
			printf("Digite o número inteiro positivo Nº %d: ", i+1);
			scanf("%d", &num[i]);
			fflush(stdin);
		} while (num[i] <= 0);
	}
	
	for (i = 0; i < 50; i++) {
		printf("%d, ", num[i]);
	}
	
	printf("\n\nO menor elemento do vetor é %d", encontraMenor(num, 0, 49));
	
	return 0;
}

int encontraMenor (int num[], int contador, int tamanhoVetor) {
	int menor;
	
	if (contador >= tamanhoVetor) {
		return num[contador];
	}
	
	menor = encontraMenor(num, contador+1, tamanhoVetor);
	if (num[contador] > menor) {
		return menor;
	}
	
}
