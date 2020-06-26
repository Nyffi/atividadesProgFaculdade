#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>

void logoForca ();
void leValidaTema (char tema[]);
void leValidaPalavra (char palavra[]);
void jogoForca (char palavra[], char tema[], char chutes[], char acertos[], int tamPalavra);
void forcaAscii (int erros);
char leValidaChute (char chutes[]);
void resultadoJogo (int vitoria, char palavra[], int erros, char acertos[]);

main() {
	char tema[30], palavra[45], chutes[15], acertos[45];
	int tamPalavra;
	
	setlocale (LC_ALL, "");
	printf("\n\n\n\n\n\n\n\n");
	logoForca();
	Sleep(1500);
	system("cls");
	
	logoForca();
	leValidaTema(tema);
	leValidaPalavra(palavra);
	tamPalavra = strlen(palavra);
	jogoForca(palavra, tema, chutes, acertos, tamPalavra);
	
	
	return 0;
}

void leValidaTema (char tema[]) {
	int valido, i;
	do {
		valido = 1;
		printf("Digite o tema da palavra que deve ser adivinhada (apenas letras sem acento, não pode ser vazio): ");
		strupr(gets(tema));
		fflush(stdin);
		
		for (i = 0; i < strlen(tema); i++) {
			if (isalpha(tema[i]) == 0) {
				valido = 0;
			}
			if (i != 0 && tema[i] == ' ') {
				valido = 1;
			}
		}
	} while (strlen(tema) == 0 || isspace(tema[0]) || valido == 0);
	printf("\n");
}

void leValidaPalavra (char palavra[]) {
	int valido, i;
	do {
		valido = 1;
		printf("Digite a palavra que deve ser adivinhada (apenas letras sem acento, não pode ser vazio): ");
		strupr(gets(palavra));
		fflush(stdin);
		
		for (i = 0; i < strlen(palavra); i++) {
			if (isalpha(palavra[i]) == 0) {
				valido = 0;
			}
			if (i != 0 && palavra[i] == ' ') {
				valido = 1;
			}
		}
	} while (strlen(palavra) == 0 || isspace(palavra[0]) || valido == 0);
	printf("\n");
}

void jogoForca (char palavra[], char tema[], char chutes[], char acertos[], int tamPalavra) {
	int erros = 0, ctrl, correto, vitoria = 0;
	char letra;
	
	for (ctrl = 0; ctrl < tamPalavra; ctrl++) {
		acertos[ctrl] = '_';
	}
	
	while (erros < 6 && vitoria == 0) {
		system("cls");
		forcaAscii(erros);
		printf("\n\n");
		correto = 0;
		printf("Palavra: \n\n");
		
		for (ctrl = 0; ctrl < tamPalavra; ctrl++) {
			if (palavra[ctrl] == ' ') {
				acertos[ctrl] = ' ';
			}
			printf("%c ", acertos[ctrl]);
		}
		
		printf("\n\nTema: ");
		puts(tema);
		printf("\nChutes errados: \n");
		
		for (ctrl = 0; ctrl < erros; ctrl++) {
			if (ctrl == erros - 1) {
				printf("%c", chutes[ctrl]);
			} else {
				printf("%c, ", chutes[ctrl]);
			}
		}
		
		printf("\n\n");
		
		letra = leValidaChute(chutes);
		
		for (ctrl = 0; ctrl < tamPalavra; ctrl++) {
			if (letra == palavra[ctrl]) {
				acertos[ctrl] = letra;
				correto = 1;
			}
		}
		if (correto == 0) {
			chutes[erros] = letra;
			erros++;
		}	
		if (strcmp(acertos, palavra) == 0) {
			vitoria = 1;
		}
	}
	resultadoJogo (vitoria, palavra, erros, acertos);
}

void forcaAscii (int erros) {
	printf (" _________     \n");
	printf ("|         |    \n");
	switch (erros) {
		case 0:
		    printf ("|             \n");
		    printf ("|          \n");
		    printf ("|          \n");
			break;
		case 1:
		    printf ("|         0    \n");
		    printf ("|          \n");
		    printf ("|          \n");
			break;
		case 2:
		    printf ("|         0    \n");
		    printf ("|         |  \n");
		    printf ("|           \n");
			break;
		case 3:
		    printf ("|         0    \n");
		    printf ("|        /|  \n");
		    printf ("|          \n");
			break;
		case 4:
		    printf ("|         0    \n");
		    printf ("|        /|\\  \n");
		    printf ("|          \n");
			break;
		case 5:
		    printf ("|         0    \n");
		    printf ("|        /|\\  \n");
		    printf ("|        /   \n");
			break;
		case 6:
		    printf ("|         0    \n");
		    printf ("|        /|\\  \n");
		    printf ("|        / \\  \n");
		    
			break;
	}
	printf ("|              \n");
	printf ("|              \n");
}

char leValidaChute (char chutes[]) {
	char letra;

	do {
		printf("Seu chute: ");
		letra = getchar();
		fflush(stdin);
	} while (isspace(letra) || isalpha(letra) == 0);
	letra = toupper(letra);
	return letra;
}

void resultadoJogo (int vitoria, char palavra[], int erros, char acertos[]) {
	int ctrl;
	
	if (vitoria == 0) {
		system("cls");
		
		printf("\033[1;31m");
		forcaAscii(erros);
		printf("\033[0m");
		printf("\n\n");
		
		printf("Palavra: \n\n");
		
		for (ctrl = 0; ctrl < strlen(palavra); ctrl++) {
			printf("%c ", acertos[ctrl]);
		}
		
		printf ("\n\nVOCÊ PERDEU! TENTE NOVAMENTE...\n\n");
		printf("A palavra era: ");
		puts(palavra);
	} else {
		system("cls");
		
		forcaAscii(erros);
		
		printf("\n\nPalavra: \n\n");
		printf("\033[1;32m");
		
		for (ctrl = 0; ctrl < strlen(palavra); ctrl++) {
			printf("%c ", acertos[ctrl]);
		}
		
		printf("\033[0m");
		printf ("\n\nPARABÉNS! VOCÊ VENCEU.\n\n");
		printf ("A palavra era: ");
		printf("\033[1;32m");
		puts(palavra);
		printf("\033[0m");
	}
}

void logoForca () {
	printf("			@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("			@@@@@@((((@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("			@@@@,,,,,,,(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("			@@@@,,,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	printf("			@,,,,,,,,,,@@@&,,,,,,,*@@@@,,,,,@@,,,,,@@@/,,,,,,,(@@@&*,,,,,,,,@@@@@ \n");
	printf("			@,,,,,,,,,,@@,,,,,,,,,,,,@@/,,,,,,,,,,*@,,,,,,,,,,,@@@,,,,,,,,,,,,@@@ \n");
	printf("			@@@@,,,@@@@@,,,,@@@@@@,,,&@@@,,,(@@@@@@*,,,@@@@@@@@@@@@@@@@@@@@,,,#@@ \n");
	printf("			@@@@,,,@@@@@,,,,@@@@@@,,,(@@@,,,(@@@@@@,,,,@@@@@@@@@@@,,,,,,,,,,,,#@@ \n");
	printf("			@@@@,,,@@@@@,,,,@@@@@@,,,#@@@,,,(@@@@@@,,,,@@@@@@@@@@,,,,@@@@@@,,,#@@ \n");
	printf("			@@@@,,,@@@@@*,,,@@@@@(,,,@@@@,,,(@@@@@@&,,,*@@@@@@@@@,,,,@@@@@&,,,#@@ \n");
	printf("			@@,,,,,,,@@@@(,,,,,,,,,,@@@,,,,,,,@@@@@@@,,,,,,,,,,@@@,,,,,,,,*,,,,,@ \n");
	printf("			@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ \n");
	
	printf("\n\n\n");
}
