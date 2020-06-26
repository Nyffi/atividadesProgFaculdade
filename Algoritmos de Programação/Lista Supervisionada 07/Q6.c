/*
  Objetivo:	Fazer um algoritmo/programa que leia a matricula e o sal�rio dos funcion�rios de uma empresa (m�ximo de 100 funcion�rios)
  Entrada:	Matr�cula e sal�rio dos funcion�rios.
  Sa�da:	Matr�cula, sal�rio dos funcion�rios, maior sal�rio e menor sal�rio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool verificaRepete (int matricula[], int quantidade);

main() {
	int matricula[100], ctrl, quantFunc, numMat;
	float salario[100], maiorSal, menorSal;
	char valSal[10];
	
	maiorSal = 0;
	menorSal = 9999999;
	
	do {
		system("cls");
		printf("Digite quantos funcionarios serao checados: ");
		scanf("%d", &quantFunc);
		fflush(stdin);
	} while (quantFunc < 0 || quantFunc > 100);
	system("cls");
	for (ctrl = 0; ctrl < quantFunc; ctrl++) {
		do {
			printf("Digite a matricula do funcionario No %d: ", ctrl + 1);
			scanf("%d", &matricula[ctrl]);
			fflush(stdin);
			
			while (verificaRepete(matricula, quantFunc)) {
				scanf("%d", &matricula[ctrl]);
			}
		} while (matricula[ctrl] < 0);
		
		
		
		printf("Digite o valor do salario do funcionario No %d: ", ctrl + 1);
		scanf("%f", &salario[ctrl]);
		fflush(stdin);
		while (salario[ctrl] < 0) {
			printf("Valor invalido. Digite um salario acima de zero: ");
			scanf("%f", &salario[ctrl]);
			fflush(stdin);
		}
		if (salario[ctrl] > maiorSal) {
			maiorSal = salario[ctrl];
		} 
		if (salario[ctrl] < menorSal) {
			menorSal = salario[ctrl];
		}
	}
	system("cls");	
	for (ctrl = 0; ctrl < quantFunc; ctrl++) {
		printf("Matricula: %d \n", matricula[ctrl]);
		printf("Salario: R$ %.2f \n\n", salario[ctrl]);
	}
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("Maior salario: R$ %.2f\n", maiorSal);
	printf("Menor salario: R$ %.2f\n", menorSal);
	return 0;
}

bool verificaRepete (int matricula[], int quantidade) {
	int i, j;
	
	for (i = 0; i < quantidade; ++i) {
		for (j = i + 1; j < quantidade; j++) {
			if (matricula[j] == matricula[i]) {
				printf("Erro, valor repetido.\n");
				printf("Digite a matricula do funcionario No %d: ", j + 1);
				return true;
			}
		}
	}
	return false;
}
