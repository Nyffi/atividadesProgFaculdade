//Objetivo:	Escrever um programa que declare um vetor de reais e leia a nota de 30 alunos.
//Entrada:	Notas.
//Saida:	Notas.

#include <stdio.h>
#include <stdlib.h>

float validaNota(float nota);

main() {
	float nota[30];
	int ctrl;
	
	for (ctrl=0;ctrl < 30; ctrl++) {
		printf("Digite a nota No %d: ", ctrl + 1);
		scanf("%f", &nota[ctrl]);
		fflush(stdin);
		nota[ctrl] = validaNota(nota[ctrl]);
	}
	system("cls");
	for (ctrl=0;ctrl < 30; ctrl++) {
		printf("Nota No %d: %.2f \n", ctrl + 1, nota[ctrl]);
	}
	
	return 0;
}

float validaNota(float nota) {
	if (nota >= 0 && nota <= 10) {
		return nota;
	} else {
		if (nota < 0) {
			return 0;
		} else if (nota > 10) {
			return 10;
		}
	}
}
