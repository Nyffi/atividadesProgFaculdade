#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "");
	FILE *p_arquivo;
	
	if ((p_arquivo = fopen("Dado.txt", "r")) == NULL) {
		printf("Arquivo n�o pode ser aberto.");
		exit(1);
	} else {
		printf("Arquivo aberto com sucesso.");
		fclose(p_arquivo);
	}
	return 0;
}
