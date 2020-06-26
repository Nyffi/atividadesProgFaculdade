/*
	Objetivo:	Elaborar um programa que solicite um valor ao usuário e imprima todos os números pares do número fornecido até 2.000, em uma janela de execução.
	Entrada:	Um valor inteiro.
	Saída:		Todos os números pares do valor informado até 2000.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int num, ctrl;

	printf("Digite um numero base: ");
	scanf("%d", &num);
	printf("\n");
	if (num > 2000) {
		printf("O limite de calculo foi excedido pois o numero fornecido (%d) passou do numero limite (2000)", num);
	} else {
		for (ctrl = num; ctrl <= 2000; ctrl++) {
			if (ctrl % 2 == 0) {
				printf("%d\n", ctrl);
			}
		}
	}

	return 0;
}

