// Objetivo: Faça um programa que leia um nome e apresente-o na formatação dos transportes aéreos.
// Entrada:	Nome completo.
// Saída: Nome na formatação dos transportes aéreos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main() {
	char nomeComp[70], primeiroNome[15], ultimoNome[15], nomeFormat[30];
	char * ultEspaco;
	int ctrl, quantLetra, primNome = 0, ultNome = 0, ultimoEspaco;
	
	printf("Digite seu nome completo: ");
	gets(nomeComp);
	fflush(stdin);
	quantLetra = strlen(nomeComp);
	
	for (ctrl = 0; primNome != 1; ctrl++) {
		if (primNome == 0 && isalpha(nomeComp[ctrl])) {
			primeiroNome[ctrl] = nomeComp[ctrl];
		}
		if (primNome == 0 && nomeComp[ctrl] == ' ') {
			primeiroNome[ctrl] = '\0';
			primNome = 1;
		}
	}

	ultEspaco = strrchr(nomeComp, ' ');
	if (ultEspaco && *(ultEspaco+1)) {
		strcpy(ultimoNome, ultEspaco+1);
	}

	strcpy(nomeFormat, ultimoNome);
	strcat(nomeFormat, "/");
	strcat(nomeFormat, primeiroNome);
	
	printf("Nome formatado: ");
	puts(nomeFormat);
	return 0;
}
