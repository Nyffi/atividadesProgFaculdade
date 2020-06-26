//Objetivo:		Fazer um algoritmo que leia um vetor de até 80 elementos.
//Entrada:		Dados, número específico.
//Saida:		Quantas vezes o numero aparece no vetor e a posição de cada repetição

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

main() {
	int dados[80], ctrl, numEspec, quantNum, numRepet, casaNumRepet[80];
	
	numRepet = 0;

	printf("Quantos valores deseja fornecer? ");
	scanf("%d", &quantNum);
	fflush(stdin);
	while (quantNum < 0 || quantNum > 80) {
		system("cls");
		printf("Valor invalido. Digite um numero entre 0 e 80.\n");
		printf("Quantos valores deseja fornecer? ");
		scanf("%d", &quantNum);
		fflush(stdin);
	}
	system("cls");
	for (ctrl = 0; ctrl < quantNum; ctrl++) {
		printf("Digite o valor No %d: ", ctrl + 1);
		scanf("%d", &dados[ctrl]);
		fflush(stdin);
	}
	
	printf("\nQue valor especifico deseja encontrar no vetor? ");
	scanf("%d", &numEspec);
	fflush(stdin);
	system("cls");
	printf("Repeticoes encontradas no vetor: \n\n");
	for (ctrl = 0; ctrl < quantNum; ctrl++) {
		if (dados[ctrl] == numEspec) {
			printf("Casa %d \n", ctrl);
			numRepet++;
		}
	}
	if (numRepet != 0) {
		printf("\nNo total, foram encontradas %d repeticoes.", numRepet);
	} else {
		printf("Nao foi encontrada nenhuma repeticao.");
	}
	
	return 0;
}


