#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int leValidaNum();
bool verificaPar(int num);

main () {
	int numero;
	char continua;
	bool numPar;
	
	do {
		numero = leValidaNum();
		numPar = verificaPar(numero);
		printf("O numero %d e ", numero);
		if (numPar == true) {
			printf("Par.");
		} else {
			printf("Impar.");
		}
		printf("\nDeseja continuar? (S/N): ");
		continua = getchar();
		fflush(stdin);
		continua = toupper(continua);
	} while (continua == 'S');
}

int leValidaNum() {
	int num;
	
	printf("Digite o numero: ");
	scanf("%d", &num);
	fflush(stdin);
	
	return num;
}

bool verificaPar(int num) {
	if (num % 2 == 0) {
		return true;
	} else {
		return false;
	}
}
