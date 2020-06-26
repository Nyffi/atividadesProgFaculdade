#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int leValidaNum();
bool verificaPrimo(int num);
void mostraRes(int num, bool primo);

main() {
	int num;
	char continua;
	bool primo;
	
	do {
		system("cls");
		num = leValidaNum();
		primo = verificaPrimo(num);
		mostraRes(num, primo);
		printf("\nDeseja continuar? (S/N): ");
		continua = getchar();
		fflush(stdin);
		continua = toupper(continua);
	} while (continua == 'S');

	return 0;
}

int leValidaNum() {
	int num;
	
	do {
		printf("Digite o numero: ");
		scanf("%d", &num);
		fflush(stdin);
	} while (num < 0);
	
	return num;
}

bool verificaPrimo(int num) {
	int i, resultado = 0;
	
	for (i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			resultado++;
			break;
		}
	}
	
	if (resultado == 0) {
		return true;
	} else {
		return false;
	}
}

void mostraRes(int num, bool primo) {
	if (primo == true) {
		printf("O numero %d e Primo.", num);
	} else {
		printf("O numero %d nao e Primo.", num);
	}
}
