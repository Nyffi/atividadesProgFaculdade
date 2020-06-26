/*
  Objetivo:	Fazer um algoritmo para ler um número indeterminado de informações (máximo de 50) contendo a matrícula funcional do empregado e o número de meses de trabalho deste empregado.
  Entrada:	Matrícula, número de meses trabalhados
  Saída:	Três empregados mais recentes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

bool verificaRepete (int matricula[], int quantidade);

main() {
	int matricula[50], meses[50], empRecMes[3], empRecMat[3], ctrl, quantFunc, numMat;
	
	empRecMat[0] = empRecMat[1] = empRecMat[2] = INT_MAX;
	empRecMes[0] = empRecMes[1] = empRecMes[2] = INT_MAX;
	
	do {
		system("cls");
		printf("Digite quantos funcionarios serao checados: ");
		scanf("%d", &quantFunc);
		fflush(stdin);
	} while (quantFunc < 0 || quantFunc > 50);
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
		
		do {
			printf("Digite a quantidade de meses de trabalho do funcionario No %d: ", ctrl + 1);
			scanf("%d", &meses[ctrl]);
			fflush(stdin);
		} while (meses[ctrl] < 0);
	}
	system("cls");	
	for (ctrl = 0; ctrl < quantFunc; ctrl++) {
		printf("Matricula: %d \n", matricula[ctrl]);
		printf("Meses: %d \n\n", meses[ctrl]);
	}
	
	for (ctrl = 0; ctrl < quantFunc; ctrl++) {
		if (meses[ctrl] < empRecMes[0]) {
			empRecMat[2] = empRecMat[1];
			empRecMat[1] = empRecMat[0];
			empRecMat[0] = matricula[ctrl];
			
			empRecMes[2] = empRecMes[1];
			empRecMes[1] = empRecMes[0];
			empRecMes[0] = meses[ctrl];
		} else if (meses[ctrl] < empRecMes[1] && meses[ctrl] != empRecMes[0]) {
			empRecMat[2] = empRecMat[1];
			empRecMat[1] = matricula[ctrl];
			
			empRecMes[2] = empRecMes[1];
			empRecMes[1] = meses[ctrl];
		} else if (meses[ctrl] < empRecMes[2] && meses[ctrl] != empRecMes[0] && meses[ctrl] != empRecMes[1]) {
			empRecMat[2] = matricula[ctrl];
			
			empRecMes[2] = meses[ctrl];
		}
	}
	
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("Empregados mais recentes: %d - %d - %d", empRecMat[0], empRecMat[1], empRecMat[2]);
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
