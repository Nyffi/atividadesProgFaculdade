// Objetivo: Elabore um programa que faça o armazenamento de um texto.
// Entrada:	Texto.
// Saída: Texto onde todas as primeiras letras de cada palavra são maiúsculas e o resto são minúsculas, quantas palavras há no texto.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
	char texto[100];
	int quantLetra, ctrl, quantPalavra = 0;
	
	printf("Digite o texto desejado: ");
	gets(texto);
	fflush(stdin);
	quantLetra = strlen(texto);
	
	system("cls");
	
	for (ctrl = 0; ctrl <= quantLetra; ctrl++) {
		if (isalpha(texto[0])) {
			texto[0] = toupper(texto[0]);
		}
		if (isalpha(texto[ctrl]) && texto[ctrl - 1] == ' ') {
			texto[ctrl] = toupper(texto[ctrl]);
		} else if (isalpha(texto[ctrl]) && texto[ctrl - 1] != ' ') {
			texto[ctrl] = tolower(texto[ctrl]);
		}
		
		if (texto[ctrl] == ' ' || texto[ctrl] == '\0') {
			quantPalavra++;
		}
	}
	
	puts(texto);
	printf("Este texto possui %d palavras.", quantPalavra);
	
	return 0;
}
