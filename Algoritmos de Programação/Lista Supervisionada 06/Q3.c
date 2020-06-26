/*
  Objetivo:	Calcular duas opera��es aritm�ticas consecutivas em tr�s valores e duas opera��es lidas na fun��o proncipal e verificar se o resultado produriz� um n�mero maior, menor ou igual a zero numa fun��o secund�ria.
  Entrada:	Tr�s valores e duas opera��es.
  Sa�da:	Resultado do c�lculo e se o resultado � maior, menor ou igual a zero.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculaOp (float num1, char op1, float num2, char op2, float num3);
char comparaZero (float resultado, char *desc);

main() {
	float n1, n2, n3, res;
	char op1, op2, compZero[14];
	
	printf("Digite o primeiro numero: ");
	scanf("%f", &n1);
	fflush(stdin);
	do {
		printf("Digite o primeiro operador: ");
		op1 = getchar();
		fflush(stdin);
	} while (op1 != '+' && op1 != '-' && op1 != '*' && op1 != '/');
	printf("Digite o segundo numero: ");
	scanf("%f", &n2);
	fflush(stdin);
	do {
		printf("Digite o segundo operador: ");
		op2 = getchar();
		fflush(stdin);
	} while (op2 != '+' && op2 != '-' && op2 != '*' && op2 != '/');
	printf("Digite o terceiro numero: ");
	scanf("%f", &n3);
	fflush(stdin);
	
	res = calculaOp (n1, op1, n2, op2, n3);
	comparaZero(res, compZero);	
	
	printf("%.2f %c %.2f %c %.2f = %.2f \n", n1, op1, n2, op2, n3, res);
	puts(compZero);
	
	return 0;
}

float calculaOp (float num1, char op1, float num2, char op2, float num3) {
	float resultado;
	
	switch (op1) {
		case '+':
			switch (op2) {
				case '+':
					resultado = num1 + num2 + num3;
					break;
				case '-':
					resultado = num1 + num2 - num3;
					break;
				case '*':
					resultado = num1 + num2 * num3;
					break;
				case '/':
					resultado = num1 + num2 / num3;
					break;
			}
			break;
		case '-':
			switch (op2) {
				case '+':
					resultado = num1 - num2 + num3;
					break;
				case '-':
					resultado = num1 - num2 - num3;
					break;
				case '*':
					resultado = num1 - num2 * num3;
					break;
				case '/':
					resultado = num1 - num2 / num3;
					break;
			}
			break;
		case '*':
			switch (op2) {
				case '+':
					resultado = num1 * num2 + num3;
					break;
				case '-':
					resultado = num1 * num2 - num3;
					break;
				case '*':
					resultado = num1 * num2 * num3;
					break;
				case '/':
					resultado = num1 * num2 / num3;
					break;
			}
			break;
		case '/':
			switch (op2) {
				case '+':
					resultado = num1 / num2 + num3;
					break;
				case '-':
					resultado = num1 / num2 - num3;
					break;
				case '*':
					resultado = num1 / num2 * num3;
					break;
				case '/':
					resultado = num1 / num2 / num3;
					break;
			}
			break;
	} 
	
	return resultado;
}

char comparaZero (float resultado, char *desc) {
	char resp[14];
	
	if (resultado > 0) {
		strcpy(desc, "Resultado > 0");
	} else if (resultado < 0) {
		strcpy(desc, "Resultado < 0");
	} else {
		strcpy(desc, "Resultado == 0");
	}
}
