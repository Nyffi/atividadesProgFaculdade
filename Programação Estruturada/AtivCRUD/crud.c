#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

void incluirProd (float preco[], int ctrl, char desc[][100]);
void listarProd (int cod[], char desc[][100], float preco[]);
void pesquisarProd (int cod[], char desc[][100], float preco[]);
void excluirProd (int cod[], char desc[][100], float preco[]);
void alterarProd (int cod[], char desc[][100], float preco[]);


main() {
	setlocale (LC_ALL, "Portuguese");
	int cod[100], escolha, codTemp, qntString, ctrl;
	char desc[40][100];
	float preco[100];
	bool vago;
	
	for (ctrl = 0; ctrl < 100; ctrl++) {
		cod[ctrl] = 1337;
	}
	
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
				
				for (ctrl = 0; vago == false; ctrl++) {
					if (cod[ctrl] == 1337) {
						vago = true;
						cod[ctrl] = ctrl + 1;
					}
					
					if (ctrl >= 100 && vago == false) {
						printf("ERRO: Não foi possível encontrar um registro livre para escrita.");
						getch();
						break;
					}
				}
				
				incluirProd (preco, ctrl, desc);
				break;
			case 2:
				listarProd(cod, desc, preco);
				break;
			case 3:
				pesquisarProd(cod, desc, preco);
				break;
			case 4:
				excluirProd(cod, desc, preco);
				break;	
			case 5:
				alterarProd(cod, desc, preco);
				break;
		}
	} while (escolha != 6);
	
	return 0;
	
}

void incluirProd (float preco[], int ctrl, char desc[][100]) {
	static char descTemp[40];
	char continuar;
	float precoTemp;
	
	do {
		system("cls");
		
		do {
			printf("Digite a descrição do produto: ");
			gets(descTemp);
			fflush(stdin);
		} while (descTemp[0] == '\0');
		
		do {
			precoTemp = -1;
			printf("Digite o valor do produto: R$ ");
			scanf("%f", &precoTemp);
			fflush(stdin);
		} while (precoTemp < 0);
		
		system("cls");
		printf("Descrição: ");
		puts(descTemp);
		printf("\nPreço: R$%.2f\n\n", precoTemp);
		
		do {
			printf("Confirma? (S/N) ");
			continuar = getchar();
			fflush(stdin);
			continuar = toupper(continuar);
		} while (continuar != 'S' && continuar != 'N');
	} while (continuar != 'S');
	
	preco[ctrl - 1] = precoTemp;
	strcpy(desc[ctrl], descTemp);
}
void listarProd (int cod[], char desc[][100], float preco[]) {
	int i;
	bool valEx = false;
	
	system("cls");
	printf("-------------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("-------------------------------------------------------------------------------------\n");
	
	for (i = 0; i < 100; i++) {
		if (cod[i] != 1337) {
			valEx = true;
			printf("	%d	|	", cod[i]);
			fputs(desc[i+1], stdout);
			printf("		|	R$%.2f\n", preco[i]);
		} else if (valEx == false && i == 99) {
			printf("A tabela está vazia.\n");
		}
	}
	
	printf("-------------------------------------------------------------------------------------\n\n");
	printf("Aperte qualquer tecla para continuar...");
	getch();
}

void pesquisarProd (int cod[], char desc[][100], float preco[]) {
	int i, escolha, pCod;
	float pPreco;
	char pDesc[40];
	bool valEx = false;
	
	do {
		system("cls");
		printf("Deseja pesquisar por qual campo?\n\n");
		printf("1 - Código\n2 - Descrição\n3 - Preço\n\n");
		printf("Sua escolha: ");
		scanf("%d", &escolha);
		fflush(stdin);
	} while (escolha < 1 || escolha > 3);
	
	system("cls");
	
	switch(escolha) {
		case 1:
			do {
				printf("Digite o código para ser pesquisado (1-100): ");
				scanf("%d", &pCod);
				fflush(stdin);
			} while (pCod <= 0 || pCod > 100);
			
			system("cls");
			printf("-------------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("-------------------------------------------------------------------------------------\n");
			
			for (i = 0; i < pCod; i++) {
				if (cod[i] == pCod) {
					valEx = true;
					printf("	%d	|	", cod[i]);
					fputs(desc[i+1], stdout);
					printf("		|	R$%.2f\n", preco[i]);
				} else if (i == pCod - 1 && valEx == false) {
					printf("Não foi encontrado um resultado equivalente à descrição fornecido.\n");
				}
			}
			break;
		case 2:
			do {
				printf("Digite a descrição para ser pesquisada (até 40 caracteres): ");
				gets(pDesc);
				fflush(stdin);
			} while (strlen(pDesc) == 0 || pDesc[0] == '\0');
			
			system("cls");
			printf("-------------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("-------------------------------------------------------------------------------------\n");
			
			for (i = 0; i < 100; i++) {
				if (strstr(desc[i+1], pDesc) != NULL) {
					valEx = true;
					printf("	%d	|	", cod[i]);
					fputs(desc[i+1], stdout);
					printf("		|	R$%.2f\n", preco[i]);
				} else if (i == 99 && valEx == false) {
					printf("Não foi encontrado um resultado equivalente à descrição fornecido.\n");
				}
			}
			break;
		case 3:
			do {
				printf("Digite o preço a ser pesquisado: R$");
				scanf("%f", &pPreco);
				fflush(stdin);
			} while (pPreco < 0);
			
			system("cls");
			printf("-------------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("-------------------------------------------------------------------------------------\n");
			
			for (i = 0; i < 100; i++) {
				if (pPreco == preco[i]) {
					valEx = true;
					printf("	%d	|	", cod[i]);
					fputs(desc[i+1], stdout);
					printf("		|	R$%.2f\n", preco[i]);
				} else if (i == 99 && valEx == false) {
					printf("Não foi encontrado um resultado equivalente ao valor fornecido.\n");
				}
			}
			break;
	}
	
	printf("-------------------------------------------------------------------------------------\n\n");
	printf("Aperte qualquer tecla para continuar...");
	getch();
}
void excluirProd (int cod[], char desc[][100], float preco[]) {
	int tmpCod;
	char confirma;
	bool valEx = false;
	
	system("cls");
	
	do {
		printf("Digite o código do produto: ");
		scanf("%d", &tmpCod);
		fflush(stdin);
	} while (tmpCod < 0 || tmpCod > 100);
	
	system("cls");
	printf("-------------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("-------------------------------------------------------------------------------------\n");
	
	if (cod[tmpCod-1] == tmpCod) {
		valEx = true;
		printf("	%d	|	", cod[tmpCod-1]);
		fputs(desc[tmpCod], stdout);
		printf("		|	R$%.2f\n", preco[tmpCod-1]);
	} else {
		printf("Não foi encontrado um registro correspondente ao código fornecido.\n");
	}
	
	printf("-------------------------------------------------------------------------------------\n\n");
	
	if (valEx == false) {
		printf("Aperte qualquer tecla para continuar...");
		getch();
	} else {
		do {
			printf("Deseja confirmar a exclusão do registro? (S/N) ");
			confirma = getchar();
			fflush(stdin);
			confirma = toupper(confirma);
		} while (confirma != 'S' && confirma != 'N');
		
		switch (confirma) {
			case 'S':
				cod[tmpCod-1] = 1337;
				strcpy(desc[tmpCod], "");
				preco[tmpCod-1] = 0;
				break;
			case 'N':
				break;
		}
	}
}
void alterarProd (int cod[], char desc[][100], float preco[]) {
	int tmpCod;
	float tmpPreco;
	char confirma, tmpDesc[40];
	bool valEx = false;
	
	system("cls");
	
	do {
		printf("Digite o código do produto: ");
		scanf("%d", &tmpCod);
		fflush(stdin);
	} while (tmpCod < 0 || tmpCod > 100);
	
	system("cls");
	printf("-------------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("-------------------------------------------------------------------------------------\n");
	
	if (cod[tmpCod-1] == tmpCod) {
		valEx = true;
		printf("	%d	|	", cod[tmpCod-1]);
		fputs(desc[tmpCod], stdout);
		printf("		|	R$%.2f\n", preco[tmpCod-1]);
	} else {
		printf("Não foi encontrado um registro correspondente ao código fornecido.\n");
	}
	
	printf("-------------------------------------------------------------------------------------\n\n");
	
	if (valEx == false) {
		printf("Aperte qualquer tecla para continuar...");
		getch();
	} else {
		do {
			printf("Digite a nova descrição do produto: ");
			gets(tmpDesc);
			fflush(stdin);
		} while (tmpDesc[0] == '\0');
		
		do {
			printf("Digite o novo valor do produto: R$ ");
			scanf("%f", &tmpPreco);
			fflush(stdin);
		} while (tmpPreco < 0);
		
		do {
			printf("Deseja confirmar a alteração do registro? (S/N) ");
			confirma = getchar();
			fflush(stdin);
			confirma = toupper(confirma);
		} while (confirma != 'S' && confirma != 'N');
		
		switch (confirma) {
			case 'S':
				strcpy(desc[tmpCod], tmpDesc);
				preco[tmpCod-1] = tmpPreco;
				break;
			case 'N':
				break;
		}
	}
}
