#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void tetranacci (int num[], int repet);

main() {
	setlocale(LC_ALL, "Portuguese");
	int num[4], repet;
	num[0] = num[1] = num[2] = 0;

	do {
		printf("Digite um número inteiro positivo: ");
		scanf("%d", &num[3]);
		fflush(stdin);
	} while (num[3] <= 0);
	
	do {
		printf("Quantas vezes o algoritmo deve ser repetido? ");
		scanf("%d", &repet);
		fflush(stdin);
	} while (repet <= 0);
	
	printf("%d, %d, %d, %d, ", num[0], num[1], num[2], num[3]);
	tetranacci(num, repet);

	return 0;
}

void tetranacci (int num[], int repet) {
	int tempNum = num[0];
	
	if (repet <= 0) {
		return;
	}
	
	num[0] = num[1];
	num[1] = num[2];
	num[2] = num[3];
	num[3] = tempNum + num[0] + num[1] + num[2];
	if (repet == 1) {
		printf("%d", num[3]);
	} else {
		printf("%d, ", num[3]);
	}
	
	repet--;
	tetranacci(num, repet);
}
