/*
	Objetivo:	Desenvolver um programa em C que leia três valores numéricos e apresente o maior valor informado no meio de uma janela limpa. 
	Entrada:	Três valores numéricos.
	Saída:		Maior valor informado numa janela limpa.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	
	int num1, num2, num3;
	
	printf("Digite o primeiro numero: ");
	scanf("%d", &num1);
	printf("Digite o segundo numero: ");
	scanf("%d", &num2);
	printf("Digite o terceiro numero: ");
	scanf("%d", &num3);
	
	system("cls");
	printf("O maior numero e o ");
	if (num1 > num2 && num1 > num3) {
		printf("%d", num1);
	} else if (num2 > num1 && num2 > num3) {
		printf("%d", num2);
	} else {
		printf("%d", num3);
	}
	return 0;
}

