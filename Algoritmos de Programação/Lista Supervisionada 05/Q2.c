/*
	Objetivo:	 Fazer um programa que leia três valores numéricos e os mostre em ordem crescente.
	Entrada:	Três valores numéricos.
	Saída:		Os valores em ordem crescente.
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
	printf("A ordem crescente dos numeros e:  \n\n");
	if (num1 < num2 && num1 < num3) {
		printf("%d\n", num1);
		if (num2 < num3) {
			printf("%d \n%d", num2, num3);
		} else {
			printf("%d \n%d", num3, num2);
		}
	} else if (num2 < num1 && num2 < num3) {
		printf("%d\n", num2);
		if (num1 < num3) {
			printf("%d \n%d", num1, num3);
		} else {
			printf("%d \n%d", num3, num1);
		}
	} else {
		printf("%d\n", num3);
		if (num1 < num2) {
			printf("%d \n%d", num1, num2);
		} else {
			printf("%d \n%d", num2, num1);
		}
	}
	
	
	return 0;
}

