/*
  Objetivo: Faça um algoritmo que leia a idade de até 100 pessoas e apresente a média entre todas, além de identificar a mais velha e a posição em que ela se encontra no vetor.
  Entrada:	Idade.
  Saída:	Média das idades, idade mais velha e sua posição no vetor.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int idade[100], ctrl, quantDados, vetorIdadeVelha, idadeVelha;
	float mediaIdade;
	
	mediaIdade = 0;
	idadeVelha = 0;
	
	do {
		printf("Digite quantas idades serao fornecidas: ");
		scanf("%d", &quantDados);
		fflush(stdin);
	} while (quantDados < 0 || quantDados > 100);
	system("cls");
	for (ctrl = 0; ctrl < quantDados; ctrl++) {
		do {
			printf("Digite a idade No %d: ", ctrl + 1);
			scanf("%d", &idade[ctrl]);
			fflush(stdin);
		} while (idade[ctrl] < 0);
		mediaIdade = mediaIdade + idade[ctrl];
		if (idade[ctrl] > idadeVelha) {
			idadeVelha = idade[ctrl];
			vetorIdadeVelha = ctrl;
		}	
	}
	system("cls");
	mediaIdade = mediaIdade / quantDados;
	printf("Media das idades informadas: %.2f\n", mediaIdade);
	printf("Idade mais velha: %d\n", idadeVelha);
	printf("Casa do vetor da idade mais velha: %d", vetorIdadeVelha);

	return 0;
}

