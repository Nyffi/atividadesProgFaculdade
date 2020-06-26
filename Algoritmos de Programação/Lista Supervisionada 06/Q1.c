/*
  Objetivo:	Desenvolver um programa que solicite as três notas das provas para cada estudante de uma turma em determinada disciplina.
  Entrada:	Três notas.
  Saída:	Média das notas.
*/

#include <stdio.h>
#include <stdlib.h>

float calculaMedia(float notas[]);

main() {
	float nota[3], media = 0;
	int ctrl; 
	
	for (ctrl = 0; ctrl < 3; ctrl++) {
		printf("Digite a nota No %d:", ctrl + 1);
		scanf("%f", &nota[ctrl]);
		fflush(stdin);
		if (nota[ctrl] > 10) 
			nota[ctrl] = 10.0;
		else if (nota [ctrl] < 0)
			nota[ctrl] = 0.0;
	}
	media = calculaMedia(nota);
	system("cls");
	for (ctrl = 0; ctrl < 3; ctrl++) {
		printf("Nota No %d: %.2f \n", ctrl + 1, nota[ctrl]);
	}
	printf("\nMedia Final: %.2f", media);
	return 0;
}

float calculaMedia(float notas[]) {
	float med;
	int i;
	
	for (i=0;i<3;i++) {
	med = med + notas[i];
	}
	med = med / 3;
	return med;
}
