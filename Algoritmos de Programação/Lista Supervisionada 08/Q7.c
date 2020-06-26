/*
  Objetivo:	Fa�a um programa que armazene uma frase a ser transmitida aos candidatos da pr�xima elei��o com at� 50 caracteres.
  Entrada:	Uma frase de 50 caracteres, primeiro nome do candidato.
  Sa�da:	Nome do candidato, todo em mai�sculo, concatenado � frase. Programa deve ser encerrado automaricamente em 10 segs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

main() {
	char frase[50], nome[20], nomeFrase[80];
	int ctrl, quantCaracNome;

	printf("Digite uma frase: ");
	gets(frase);
	fflush(stdin);
	printf("Digite o primeiro nome do candidato: ");
	gets(nome);
	fflush(stdin);
	quantCaracNome = strlen(nome);
	
	for (ctrl = 0; ctrl < quantCaracNome; ctrl++) {
		if (isalpha(nome[ctrl])) {
			nome[ctrl] = toupper(nome[ctrl]);
		}
	}
	printf("\n\n");
	strcpy(nomeFrase, nome);
	strcat(nomeFrase, ": ");
	strcat(nomeFrase, frase);
	puts(nomeFrase);
	Sleep(10000);
	system("taskkill -f -im \"ConsolePauser.exe\"");

	return 0;
}

