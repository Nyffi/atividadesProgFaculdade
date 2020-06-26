/*
  Objetivo:	Fazer um programa que calcule, por meio de uma função, o valor de x elevado a n usando apenas a operação de multiplicação.
  Entrada:	Valores x (real) e n (inteiro).
  Saída:	Resultado da potência.
*/

#include <stdio.h>
#include <stdlib.h>

float calculaPotencia (float x, int y);

main() {
	float valX, res;
	int valN;

	printf("Digite o valor de x: ");
	scanf("%f", &valX);
	fflush(stdin);
	printf("Digite o valor de n: ");
	scanf("%d", &valN);
	fflush(stdin);
	
	res = calculaPotencia(valX, valN);
	printf("%.2f ^ %d = %.2f", valX, valN, res);
	return 0;
}

float calculaPotencia (float x, int n) {
	float res = x;
	int i;
	
	
	for (i=1;i<n;i++) {
		res = res * x;
	}
	return res;
}
