#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "");
	
	FILE *p_arquivo;
	char nomeArq[30];
	
	printf("Digite o nome desejado para o arquivo: ");
	gets(nomeArq);
	fflush(stdin);
	sprintf(nomeArq, "%s.txt", nomeArq);
	
	if ((p_arquivo = fopen(nomeArq, "w")) == NULL) {
		printf("Falha ao gerar arquivo.");
		exit(1);
	} else {
		printf("Arquivo gerado com sucesso.");
		fclose(p_arquivo);
	}
	return 0;
}
