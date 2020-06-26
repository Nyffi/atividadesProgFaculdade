/*
  Objetivo:		Elaborar um algoritmo que leia um conjunto de valores inteiros correspondentes a até 80 notas, variando de 0 a 10, dos alunos de uma turma (vários alunos).
  Entrada:		80 valores inteiros.
  Saída:		Tabela contendo os valores das notas e suas frequências.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int notas[11] = {0,0,0,0,0,0,0,0,0,0,0}, quantNotas, ctrl, valNota;

	printf("Digite a quantidade de notas a serem informadas: ");
	scanf("%d", &quantNotas);
	fflush(stdin);

	for (ctrl = 0; ctrl < quantNotas; ctrl++) {
		printf("Digite a nota No %d: ", ctrl + 1);
		scanf("%d", &valNota);
		fflush(stdin);
		
		if (valNota > 10) {
			valNota = 10;
		} else if (valNota < 0) {
			valNota = 0;
		}
		
		switch(valNota) {
			case 0:
				notas[0]++;
				break;
			case 1:
				notas[1]++;
				break;
			case 2:
				notas[2]++;
				break;
			case 3:
				notas[3]++;
				break;
			case 4:
				notas[4]++;
				break;
			case 5:
				notas[5]++;
				break;
			case 6:
				notas[6]++;
				break;
			case 7:
				notas[7]++;
				break;
			case 8:
				notas[8]++;
				break;
			case 9:
				notas[9]++;
				break;
			case 10:
				notas[10]++;
				break;	
		}
	}
	system("cls");
	for (ctrl = 0; ctrl < 11; ctrl++) {
		printf("Nota %d: %d \n", ctrl, notas[ctrl]);
	}
		

	return 0;
}

