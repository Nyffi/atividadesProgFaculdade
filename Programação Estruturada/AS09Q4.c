#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pesqBin (int chave, int dados[], int n, int* repet);

main () {
	setlocale(LC_ALL, "Portuguese");
	int dados[50], i, j, temp, pesq, resultado, repeticoes = 0;
	
	srand(time(NULL));
	
	for (i = 0; i < 50; i++) {
		dados[i] = rand() % 100;
	}
	
	for (i = 0; i < 50; i++) {
		for (j = i + 1; j < 50; j++) {
			if (dados[i] > dados[j]) {
				temp = dados[i];
				dados[i] = dados[j];
				dados[j] = temp;
			}
		}
		printf("%d, ", dados[i]);
	}
	
	printf("\n");
	
	do {
		printf("Digite um valor para ser pesquisado: ");
		scanf("%d", &pesq);
		fflush(stdin);
	} while (pesq < 0);
	
	resultado = pesqBin(pesq, dados, 50, &repeticoes);
	
	if (resultado == (-1)) {
		printf("O valor não foi encontrado.");
	} else {
		printf("O valor %d foi encontrado na posição %d", pesq, resultado + 1);
	}
	
	printf("\nA busca foi executada %d vezes.", repeticoes);
	
	return 0;
}

int pesqBin (int chave, int dados[], int n, int* repet) {
	int inicio, meio, fim;
	
	inicio = 0;
	fim = n - 1;
	
	while (inicio <= fim) {
		*repet = *repet + 1;
		meio = (inicio + fim) / 2;
		if (chave < dados[meio]) {
			fim = meio - 1;
		} else if (chave > dados[meio]) {
			inicio = meio + 1;
		} else {
			return meio;
		}
	}
	return (-1);
}
