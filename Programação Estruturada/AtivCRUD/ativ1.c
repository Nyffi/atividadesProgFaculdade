#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char incluirProd (float preco[]);
void listarProd (int cod[], char desc[][100], float preco[]);
void pesquisarProd (int cod[], char *desc[], float preco[]);
void excluirProd (int cod[], char *desc[], float preco[]);

main() {
	int cod[100] = {-1}, escolha, codTemp, qntString, ctrl;
	char desc[40][100];
	float preco[100];
	bool vago;
	
	do {
		do {
			system("cls");
			printf("Escolha uma das opcoes: \n\n");
			printf("1 - Incluir\n");
			printf("2 - Listar\n");
			printf("3 - Pesquisar\n");
			printf("4 - Excluir\n");
			printf("5 - Alterar\n");
			printf("6 - Sair\n\n");
			printf("Sua escolha: ");
			scanf("%d", &escolha);
			fflush(stdin);
		} while (escolha < 1 || escolha > 6);
		
		switch(escolha) {
			case 1:
				vago = false;
				for (ctrl = 0; vago == false && ctrl < 100; ctrl++) {
					if (cod[ctrl] == -1) {
						vago = true;
						cod[ctrl] = ctrl + 1;
					}
				}
				*desc[ctrl] = incluirProd (preco);
				break;
			case 2:
				listarProd(cod, desc, preco);
				break;
			case 3:
				
				break;
			case 4:
				
				break;	
			case 5:
				
				break;
		}
	} while (escolha != 6);
	
	return 0;
	
}

char incluirProd (float preco[]) {
	char descTemp[40], continuar;
	float precoTemp;
	
	do {
		system("cls");
		do {
			printf("Digite a descricao do produto: ");
			gets(descTemp);
			fflush(stdin);
		} while (descTemp[0] == '\0');
		
		do {
			precoTemp = -1;
			printf("Digite o valor do produto: ");
			scanf("%f", &precoTemp);
			fflush(stdin);
		} while (precoTemp < 0);
		
		system("cls");
		printf("Descricao: ");
		puts(descTemp);
		printf("\nPreco: R$%.2f\n\n", precoTemp);
		do {
			printf("Confirma? (S/N) ");
		continuar = getchar();
		fflush(stdin);
		continuar = toupper(continuar);
		} while (continuar != 'S' && continuar != 'N');
	} while (continuar != 'S');
	
	*preco = precoTemp;
	return *descTemp;
}
void listarProd (int cod[], char desc[][100], float preco[]) {
	int i;
	system("cls");
	printf("---------------------------------------------------------\n");
	printf("	CODIGO	|		DESCRICAO		|	PRECO	");
	printf("---------------------------------------------------------\n");
	for (i = 0; cod[i] != -1; i++) {
		printf("	%d	|		%s		|	R$%.2f\n", cod[i], desc, preco);
	}
	printf("---------------------------------------------------------\n");
	printf("Aperte qualquer tecla para continuar...");
	getch();
}

void pesquisarProd (int cod[], char *desc[], float preco[]) {
	
}
void excluirProd (int cod[], char *desc[], float preco[]) {
	
}
