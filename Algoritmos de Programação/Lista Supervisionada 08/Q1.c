// Objetivo: Leia o nome completo de 2 pessoas e apresente o primeiro nome somente em letras mai�sculas e na linha seguinte, com uma tabula��o, o segundo nome em letras min�sculas, solicitando outros nomes caso o usu�rio deseje.
// Entrada:	Dois nomes completos.
// Sa�da: O primeiro nome completo, em mai�sculo, e o segundo nome completo, em min�sculo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
	char nome1[70], nome2[70], escolha;
	int quantCaracNome1, quantCaracNome2;
	
	do {
		do {
			printf("Insira um nome completo: ");
			gets(nome1);
			fflush(stdin);
			quantCaracNome1 = strlen(nome1);
		} while (quantCaracNome1 < 0 || quantCaracNome1 > 70);
		
		do {
			printf("Insira outro nome completo: ");
			gets(nome2);
			fflush(stdin);
			quantCaracNome2 = strlen(nome2);
		} while (quantCaracNome2 < 0 || quantCaracNome2 > 70);
		
		printf("%s\n\t%s", strupr(nome1), strlwr(nome2));
		printf("\n\nDeseja inserir mais dois nomes? (S/N): ");
		escolha = getchar();
		fflush(stdin);
	} while (escolha != 'n' && escolha != 'N');
	return 0;
}
