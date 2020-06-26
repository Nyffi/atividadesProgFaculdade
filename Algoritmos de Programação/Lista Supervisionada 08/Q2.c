// Objetivo: Desenvolva um programa que solicite o nome de cinco equipamentos de informática.
// Entrada:	Cinco nomes de equipamentos de informática.
// Saída: Nomes duplicados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
	char equip[5][40];
	int ctrl, ctrl2, qntCarac;
	
	for (ctrl = 0; ctrl < 5; ctrl++) {
		do {
			printf("Digite o nome do equipamento: ");
			gets(equip[ctrl]);
			fflush(stdin);
			qntCarac = strlen(equip[ctrl]);
		} while (qntCarac > 40);
	}
	
	for (ctrl = 0; ctrl < 5; ctrl++) {
		puts(equip[ctrl]);
	}
	
	printf("\nEquipamentos repetidos: \n\n");
	for (ctrl = 0; ctrl < 5; ctrl++) {
		for (ctrl2 = ctrl + 1; ctrl2 < 5; ctrl2++) {
			if (strcmp(equip[ctrl], equip[ctrl2]) == 0) {
				puts(equip[ctrl]);
			}
		}
	}
	
	return 0;
}
