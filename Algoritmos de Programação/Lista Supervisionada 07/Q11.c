/*
  Objetivo:	Elaborar um algoritmo que armazene o código funcional inteiro e respectivo salário real de todos os funcionários de uma empresa.
  Entrada:	Quantidade de funcionários, código funcional inteiro e salário de cada funcionário.
  Saída:	Maior e menor salário de todos os funcionários e a média dos salários.
*/

#include <stdio.h>
#include <stdlib.h>

float defineMaiorSal (float sal[], int qntFunc);
float defineMenorSal (float sal[], int qntFunc);
float adicaoMedia (float salario, float mediaSal);
void calculaRetornaMedia (float media, int quant);
void retornaMaiorMenorSalario (float maiorSalario, float menorSalario);

main() {
	int codFunc[100], quantFunc, ctrl;
	float salario[100], maiorSal, menorSal, mediaSal;
	
	mediaSal = 0;

	do {
		printf("Digite a quantidade de funcionarios da empresa (Max. 100): ");
		scanf("%d", &quantFunc);
		fflush(stdin);
	} while (quantFunc < 0 || quantFunc > 100);

	for (ctrl = 0; ctrl < quantFunc; ctrl++) {
		do {
			printf("Digite o codigo funcional do funcionario No %d: ", ctrl + 1);
			scanf("%d", &codFunc[ctrl]);
			fflush(stdin);
		} while (codFunc[ctrl] < 0);
		do {
			printf("Digite o salario do funcionario No %d: ", ctrl + 1);
			scanf("%f", &salario[ctrl]);
			fflush(stdin);
		} while (salario[ctrl] < 0);
		mediaSal = adicaoMedia(salario[ctrl], mediaSal);
	}
	system("cls");
	maiorSal = defineMaiorSal(salario, quantFunc);
	menorSal = defineMenorSal(salario, quantFunc);
	calculaRetornaMedia (mediaSal, quantFunc);
	retornaMaiorMenorSalario (maiorSal, menorSal);

	return 0;
}

float defineMaiorSal (float salario[], int qntFunc) {
	int i;
	float maiorSalario;
	maiorSalario = 0;
	for (i = 0; i < qntFunc; i++) {
		if (salario[i] > maiorSalario) {
			maiorSalario = salario[i];
		}
	}
	return maiorSalario;
}

float defineMenorSal (float salario[], int qntFunc) {
	int i;
	float menorSalario;
	menorSalario = 999999;
	
	for (i = 0; i < qntFunc; i++) {
		if (salario[i] < menorSalario) {
			menorSalario = salario[i];
		}
	}
	return menorSalario;
}

float adicaoMedia (float salario, float mediaSal) {
	float media;
	media = mediaSal + salario;
	return media;
}

void calculaRetornaMedia (float media, int quant) {
	float med;
	med = media / quant;
	printf("Media dos salarios: R$ %.2f \n\n", med);
}

void retornaMaiorMenorSalario (float maiorSalario, float menorSalario) {
	printf("Maior Salario: R$ %.2f \n", maiorSalario);
	printf("Menor Salario: R$ %.2f \n", menorSalario);
}
