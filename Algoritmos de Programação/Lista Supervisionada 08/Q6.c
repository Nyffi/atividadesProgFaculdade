/*
  Objetivo:	Elabore um programa que armazene o nome completo de uma pessoa com até 30 caracteres e o apresente em letras maiúsculas centralizado em uma janela limpa.
  Entrada:	Nome completo de até 30 caracteres.
  Saída:	Quantidade de caracteres
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main() {
	char nomeComp[30], escolha;
	int ctrl, quantCarac;
	do {
		printf("Digite um nome completo: ");
		gets(nomeComp);
		fflush(stdin);
		quantCarac = strlen(nomeComp);
		for (ctrl = 0; ctrl < quantCarac; ctrl++) {
			if (isalpha(nomeComp[ctrl])) {
				nomeComp[ctrl] = toupper(nomeComp[ctrl]);
			}
		}
		puts(nomeComp);
		printf("Quantidade de caracteres: %d\n", quantCarac);
		do {
			printf("Deseja continuar? (S/N): ");
			escolha = getchar();
			fflush(stdin);
		} while (escolha != 's' && escolha != 'S' && escolha != 'n' && escolha != 'N');
	} while (escolha == 's' || escolha == 'S');
	
	system("taskkill -f -im \"ConsolePauser.exe\"");
	return 0;
}

