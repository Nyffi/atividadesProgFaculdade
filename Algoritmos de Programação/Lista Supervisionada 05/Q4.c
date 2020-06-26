/*
	Objetivo:	Fazer um programa para desenvolver o cálculo fatorial usando os três tipos de repetição.
	Entrada:	Qual loop usar e o valor para calcular o fator.
	Saída:		Fatorial do número fornecido.
*/

#include <stdio.h>
#include <stdlib.h>

void clearBuffer(char c);

main() {
	char opcao;
	do {	
		printf("Digite qual loop deseja testar: \n\n");
		printf("1) While\n");
		printf("2) Do ... While\n");
		printf("3) For\n");
		printf("\nSua escolha: ");
		opcao = getchar();
		clearBuffer(opcao);
		system("cls");
		switch (opcao) {
			case '1':
				fatorWhile();
				break;
			case '2':
				fatorDoWhile();
				break;
			case '3':
				fatorFor();
				break;
			default:
				printf("Valor invalido. Escolha uma das opcoes da lista.\n");
		}
	} while (opcao != '1' && opcao != '2' && opcao != '3');

	return 0;	
}

fatorWhile() {
	int i, res;
	
	//i = 5;
	res = 1;
	printf("Digite um valor: ");
	scanf("%d", &i);
	printf("%d! = ", i);
	while (i > 0) {
		res = res * i;
		printf("%i", i);
		if (i != 1) {
			printf(" x ");
		} else {
			printf(" = ");
		}
		i--;
	}
	printf("%i", res);
}

fatorDoWhile() {
	int i, res;
	
	//i = 5;
	res = 1;
	printf("Digite um valor: ");
	scanf("%d", &i);
	printf("%d! = ", i);
	do {
		res = res * i;
		printf("%i", i);
		if (i != 1) {
			printf(" x ");
		} else {
			printf(" = ");
		}
		i--;
	} while (i > 0);
	printf("%i", res);
}

fatorFor() {
	int i, res;
	
	res = 1;
	printf("Digite um valor: ");
	scanf("%d", &i);
	printf("%d! = ", i);
	for (i;i>0;i--) {
		res = res * i;
		printf("%i", i);
		if (i != 1) {
			printf(" x ");
		} else {
			printf(" = ");
		}
	}
	printf("%i", res);
}

void clearBuffer(char c) {
	while(c != '\n') {
		scanf("%c", &c);
	}
}
