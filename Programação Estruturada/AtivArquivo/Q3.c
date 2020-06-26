#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "");
	
	FILE *p_arquivo;
	char nomeArq[30], texto[100];
	double valor[3];
	int i;
	
	for (i = 0; i < 3; i++) {
		printf("Digite um valor: ");
		scanf("%lf", &valor[i]);
		fflush(stdin);
	}
	
	printf("\nDigite o nome desejado para o arquivo: ");
	gets(nomeArq);
	fflush(stdin);
	sprintf(nomeArq, "%s.txt", nomeArq);
	
	if ((p_arquivo = fopen(nomeArq, "w")) == NULL) {
		printf("Falha ao gerar arquivo.");
		exit(1);
	} else {
		printf("Arquivo criado com sucesso.\nEscrevendo informações...\n");
		for (i = 0; i < 3; i++) {
			fprintf(p_arquivo, "valor[%d] = %.2lf\n", i, valor[i]);
		}
		printf("Informações salvas com sucesso.\n\n");
		fclose(p_arquivo);
	}
	
	if ((p_arquivo = fopen(nomeArq, "r")) == NULL) {
		printf("Falha ao abrir arquivo.");
		exit(1);
	} else {
		printf("Informações do arquivo %s: \n\n", nomeArq);
		
		while (fgets(texto, sizeof(texto), p_arquivo) != NULL) {
			fputs(texto, stdout);
		}
		fclose(p_arquivo);
	}
	return 0;
}
