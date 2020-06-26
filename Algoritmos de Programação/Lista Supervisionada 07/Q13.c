// Objetivo:	Fazer um algoritmo que leia uma frase de até 80 caracteres, incluindo os brancos, conte quantos caracteres em branco existem na frase, conte quantas vezes a letra a ou A aparecem, conte quntas vezes ocorre um mesmo par de letras na frase e quais são elas e apresente o que foi calculado nos itens anteriores
// Entrada:		Uma frase.
// Saída: 		Quantidade de caracteres em branco, de letras 'a' ou 'A' e quantas vezes ocorre um mesmo par de letras na frase e quais são elas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main () {
	int ctrl, qntCarac, qntCaracBranco = 0, qntCaracA = 0, qntCaracEspec1 = 0, qntCaracEspec2 = 0;
	char frase[80], caracEspec1, caracEspec2;
	
	
	do {
		printf("Digite uma frase de ate 80 caracteres: ");
		gets(frase);
		fflush(stdin);
		qntCarac = strlen(frase);
	} while (qntCarac <= 0 || qntCarac > 80);
	
	printf("Digite uma letra em especifico para encontrar a frequencia dela na frase: ");
	caracEspec1 = getchar();
	fflush(stdin);
	
	printf("Digite outra letra em especifico para encontrar a frequencia dela na frase: ");
	caracEspec2 = getchar();
	fflush(stdin);
	
	for (ctrl = 0; ctrl < qntCarac; ctrl++) {
		if (frase[ctrl] == ' ') {
			qntCaracBranco++;
		} else if (frase[ctrl] == 'a' || frase[ctrl] == 'A') {
			qntCaracA++;
		}
		if (frase[ctrl] == caracEspec1) {
			qntCaracEspec1++;
		}
		if (frase[ctrl] == caracEspec2) {
			qntCaracEspec2++;
		}
	}
	
	printf("Quantidade de caracter em branco: %d \n", qntCaracBranco);
	printf("Quantidade de caracter 'a' ou 'A': %d \n\n", qntCaracA);
	printf("Quantidade do caracter especifico '%c': %d \n", caracEspec1, qntCaracEspec1);
	printf("Quantidade do caracter especifico '%c': %d \n", caracEspec2, qntCaracEspec2);
	
	return 0;
}
