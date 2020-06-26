/*
  Objetivo:	Escrever um algoritmo que solicite e leia letra por letra o nome completo de uma pessoa.
  Entrada:	Nome de uma pessoa, letra por letra.
  Saída:	Nome da pessoa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

main() {
	char nome[50], letra;
	int ctrl = 0;

	do {
		printf("Digite uma letra: ");
		scanf("%c", &letra);
		fflush(stdin);
		if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || letra == ' ') {
			nome[ctrl] = letra;
			ctrl++;
		} else if (letra == '#') {
			nome[ctrl] = '\0';
		}
	} while (letra != '#' && ctrl <= 50);
	
	printf("Seu nome: ");
	puts(nome);
	
	return 0;
}

