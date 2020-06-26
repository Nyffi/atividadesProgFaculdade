/*
	Objetivo:	Escreva um programa que transforme o computador em uma urna eletrônica para eleição do melhor jogador de futebol de todos os tempos.
	Entrada:	Número do voto.
	Saída:		Quantidade de votos de cada candidato, de votos em branco e nulo e nome do candidato vencedor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void clearBuffer(char c);

main() {
	int voto, votosPele = 0, votosMara = 0, votosBranco = 0, votosNulo = 0;
	char continuar, confirmar;
	bool confirma;
	
	do {
		do {
			printf("- Vote em um dos candidatos - \n");
			printf("25 - Pele\n");
			printf("33 - Maradona\n");
			printf("-------------------------------------\n");
			printf("Voto 0 sera considerado como voto em branco. \nQualquer outro voto sera considerado voto nulo.");
			printf("\n-------------------------------------\n");
			printf("Digite o seu voto: ");
			scanf("%d", &voto);
			clearBuffer(voto);
			
			do {
				printf("\nVoce votou: %d\tConfirma? (S/N): ", voto);
				confirmar = getchar();
				clearBuffer(confirmar);
				confirmar = toupper(confirmar);
			} while (confirmar != 'S' && confirmar != 'N');
			if (confirmar == 'S') 
				confirma = true;
			else {
				confirma = false;
				system("cls");
			}
		} while (confirma == false);
		do {
			printf("\nDeseja continuar? (S/N): ");
			continuar = getchar();
			clearBuffer(continuar);
			continuar = toupper(continuar);
		} while (continuar != 'S' && continuar != 'N');
		system("cls");		
		switch (voto) {
			case 25:
				votosPele++;
				break;
			case 33:
				votosMara++;
				break;
			case 0:
				votosBranco++;
				break;
			default:
				votosNulo++;
		}
	} while (continuar != 'N');
	printf("-------------------------------------\n");
	printf("Votos para o Pele: %d\n", votosPele);
	printf("Votos para o Maradona: %d", votosMara);
	printf("\n-------------------------------------\n");
	printf("Votos em branco: %d\n", votosBranco);
	printf("Votos nulo: %d", votosNulo);
	printf("\n-------------------------------------\n");
	if (votosPele > votosMara) {
		printf("Candidato vencedor: Pele");
	} else if (votosPele < votosMara) {
		printf("Candidato vencedor: Maradona");
	} else {
		printf("Candidato vencedor: EMPATE");
	}
	return 0;
}

void clearBuffer(char c) {
	while(c != '\n') {
		scanf("%c", &c);
	}
}
