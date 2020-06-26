//Objetivo:	Fazer um algoritmo que leia até 30 letras e as escreva na ordem inversa da que foram lidas.
//Entrada:	Até 30 letras.
//Saida:	As letras fornecidas, de forma inversa da que foram lidas.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

main() {
	char letras[30];
	int ctrl, quantLetra;
	
	printf("Quantas letras deseja fornecer? ");
	scanf("%d", &quantLetra);
	fflush(stdin);
	while (quantLetra < 0 || quantLetra > 30) {
		system("cls");
		printf("Valor invalido. Digite um numero entre 0 e 30.\n");
		printf("Quantas letras deseja fornecer? ");
		scanf("%d", &quantLetra);
		fflush(stdin);
	}
	system("cls");
	
	for (ctrl = 0; ctrl < quantLetra; ctrl++) {
		printf("Digite a letra No %d: ", ctrl + 1);
		letras[ctrl] = getchar();
		fflush(stdin);
		while (isalpha(letras[ctrl]) == 0) {
			printf("Erro. Uma letra não foi informada. Tente novamente.\n");
			printf("Digite a letra No %d: ", ctrl + 1);
			letras[ctrl] = getchar();
			fflush(stdin);
		}
	}
	
	for (ctrl = quantLetra - 1; ctrl >= 0; ctrl--) {
		if (ctrl == 0) {
			printf("%c", letras[ctrl]);
		} else {
			printf("%c . ", letras[ctrl]);
		}

	}
	
	return 0;
}

