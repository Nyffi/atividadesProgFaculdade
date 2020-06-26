#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

struct PROD {
	int cod;
	char desc[40];
	float preco;
};

float incluirProd (int ctrl, char desc[]);
void listarProd (struct PROD *produto, struct PROD *produto_bak);
void pesquisarProd (struct PROD *produto);
void excluirProd (struct PROD *produto);
void alterarProd (struct PROD *produto);
void bkupProd (struct PROD *produto, struct PROD *produto_bak);
void rstProd (struct PROD *produto, struct PROD *produto_bak);


main() {
	setlocale (LC_ALL, "Portuguese");
	struct PROD produto[100];
	struct PROD produto_bak[100];
	int escolha, codTemp, qntString, ctrl;
	bool vago;
	
	for (ctrl = 0; ctrl < 100; ctrl++) {
		produto[ctrl].cod = 1337;
		produto_bak[ctrl].cod = 1337;
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
			printf("6 - Backup\n");
			printf("7 - Restore\n");
			printf("8 - Sair\n\n");
			printf("Sua escolha: ");
			scanf("%d", &escolha);
			fflush(stdin);
		} while (escolha < 1 || escolha > 8);
		
		switch(escolha) {
			case 1:
				vago = false;
				
				for (ctrl = 0; vago == false; ctrl++) {
					if (produto[ctrl].cod == 1337) {
						vago = true;
						produto[ctrl].cod = ctrl + 1;
					}
					
					if (ctrl >= 100 && vago == false) {
						printf("ERRO: Não foi possível encontrar um registro livre para escrita.");
						getch();
						break;
					}
				}			
				produto[ctrl-1].preco = incluirProd (ctrl, produto[ctrl].desc);
				break;
			case 2:
				listarProd(produto, produto_bak);
				break;
			case 3:
				pesquisarProd(produto);
				break;
			case 4:
				excluirProd(produto);
				break;	
			case 5:
				alterarProd(produto);
				break;
			case 6:
				vago = false;
				
				for (ctrl = 0; vago == false; ctrl++) {
					if (produto_bak[ctrl].cod == 1337) {
						vago = true;
						produto_bak[ctrl].cod = ctrl + 1;
					}
					
					if (ctrl >= 100 && vago == false) {
						printf("ERRO: Não foi possível encontrar um registro livre para escrita de backup.");
						getch();
						fflush(stdin);
						break;
					}
				}
				bkupProd(produto, produto_bak);
				break;
			case 7:
				vago = false;
				
				for (ctrl = 0; vago == false; ctrl++) {
					if (produto[ctrl].cod == 1337) {
						vago = true;
						produto[ctrl].cod = ctrl + 1;
					}
					
					if (ctrl >= 100 && vago == false) {
						printf("ERRO: Não foi possível encontrar um registro livre para escrita de restauração.");
						getch();
						break;
					}
				}
				rstProd(produto, produto_bak);
				break;
		}
	} while (escolha != 8);
	
	return 0;
	
}

float incluirProd (int ctrl, char desc[]) {
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
	
	strcpy(desc, descTemp);
	return precoTemp;
}
void listarProd (struct PROD *produto, struct PROD *produto_bak) {
	int i;
	bool valEx = false;
	
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("P R O D U T O S   A T I V O S\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("--------------------------------------------------------------------------------\n");
	
	for (i = 0; i < 100; i++) {
		if (produto[i].cod != 1337) {
			valEx = true;
			printf("	%d	|	", produto[i].cod);
			fputs(produto[i+1].desc, stdout);
			printf("		|	R$%.2f\n", produto[i].preco);
		} else if (valEx == false && i == 99) {
			printf("A tabela está vazia.\n");
		}
	}
	
	valEx = false;
	printf("\n--------------------------------------------------------------------------------\n");
	printf("L I S T A   D E   B A C K U P\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("--------------------------------------------------------------------------------\n");
	
	for (i = 0; i < 100; i++) {
		if (produto_bak[i].cod != 1337) {
			valEx = true;
			printf("	%d	|	", produto_bak[i].cod);
			fputs(produto_bak[i+1].desc, stdout);
			printf("		|	R$%.2f\n", produto_bak[i].preco);
		} else if (valEx == false && i == 99) {
			printf("A tabela está vazia.\n");
		}
	}
	
	printf("\n--------------------------------------------------------------------------------\n\n");
	printf("Aperte qualquer tecla para continuar...");
	getch();
}
void pesquisarProd (struct PROD *produto) {
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
			printf("--------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("--------------------------------------------------------------------------------\n");
			
			for (i = 0; i < pCod; i++) {
				if (produto[i].cod == pCod) {
					valEx = true;
					printf("	%d	|	", produto[i].cod);
					fputs(produto[i+1].desc, stdout);
					printf("		|	R$%.2f\n", produto[i].preco);
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
			printf("--------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("--------------------------------------------------------------------------------\n");
			
			for (i = 0; i < 100; i++) {
				if (strstr(produto[i+1].desc, pDesc) != NULL) {
					valEx = true;
					printf("	%d	|	", produto[i].cod);
					fputs(produto[i+1].desc, stdout);
					printf("		|	R$%.2f\n", produto[i].preco);
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
			printf("--------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("--------------------------------------------------------------------------------\n");
			
			for (i = 0; i < 100; i++) {
				if (pPreco == produto[i].preco) {
					valEx = true;
					printf("	%d	|	", produto[i].cod);
					fputs(produto[i+1].desc, stdout);
					printf("		|	R$%.2f\n", produto[i].preco);
				} else if (i == 99 && valEx == false) {
					printf("Não foi encontrado um resultado equivalente ao valor fornecido.\n");
				}
			}
			break;
	}
	
	printf("--------------------------------------------------------------------------------\n\n");
	printf("Aperte qualquer tecla para continuar...");
	getch();
}
void excluirProd (struct PROD *produto) {
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
	printf("--------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("--------------------------------------------------------------------------------\n");
	
	if (produto[tmpCod-1].cod == tmpCod) {
		valEx = true;
		printf("	%d	|	", produto[tmpCod-1].cod);
		fputs(produto[tmpCod].desc, stdout);
		printf("		|	R$%.2f\n", produto[tmpCod-1].preco);
	} else {
		printf("Não foi encontrado um registro correspondente ao código fornecido.\n");
	}
	
	printf("--------------------------------------------------------------------------------\n\n");
	
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
				produto[tmpCod-1].cod = 1337;
				strcpy(produto[tmpCod].desc, "");
				produto[tmpCod-1].preco = 0;
				break;
			case 'N':
				break;
		}
	}
}
void alterarProd (struct PROD *produto) {
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
	printf("--------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("--------------------------------------------------------------------------------\n");
	
	if (produto[tmpCod-1].cod == tmpCod) {
		valEx = true;
		printf("	%d	|	", produto[tmpCod-1].cod);
		fputs(produto[tmpCod].desc, stdout);
		printf("		|	R$%.2f\n", produto[tmpCod-1].preco);
	} else {
		printf("Não foi encontrado um registro correspondente ao código fornecido.\n");
	}
	
	printf("--------------------------------------------------------------------------------\n\n");
	
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
				strcpy(produto[tmpCod].desc, tmpDesc);
				produto[tmpCod-1].preco = tmpPreco;
				break;
			case 'N':
				break;
		}
	}
}
void bkupProd (struct PROD *produto, struct PROD *produto_bak) {
	int tmpCod, escolha, i, len = 0;
	char continuar;
	bool valEx = false;
	
	system("cls");
	
	printf("Que tipo de backup deseja fazer? \n\n");
	printf("1 - Total (Todos os valores na tabela ativa)\n");
	printf("2 - Parcial (Apenas um valor por vez)\n\n");
	do {
		printf("Sua escolha: ");
		scanf("%d", &escolha);
		fflush(stdin);
	} while (escolha < 1 || escolha > 2);
	
	switch (escolha) {
		case 1:
			printf("--------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("--------------------------------------------------------------------------------\n");
			
			for (i = 0; i < 100; i++) {
				if (produto[i].cod != 1337) {
					valEx = true;
					len++;
					printf("	%d	|	", produto[i].cod);
					fputs(produto[i+1].desc, stdout);
					printf("		|	R$%.2f\n", produto[i].preco);
				} else if (valEx == false && i == 99) {
					printf("A tabela está vazia.\n");
				}
			}
			if (valEx == false) {
				getch();
				fflush(stdin);
				break;
			}
			printf("--------------------------------------------------------------------------------\n");
			do {
				printf("Deseja confirmar o backup? (S/N) ");
				continuar = getchar();
				fflush(stdin);
				continuar = toupper(continuar);
			} while (continuar != 'S' && continuar != 'N');
			if (continuar == 'S') {
				for (i = 0; i < len; i++) {
					produto_bak[i].preco = produto[i].preco;
					strcpy(produto_bak[i].desc, produto[i].desc); 
					fflush(stdin);
				}
			}
			break;
		case 2:
			do {
				printf("Digite o código do produto: ");
				scanf("%d", &tmpCod);
				fflush(stdin);
			} while (tmpCod < 0 || tmpCod > 100);
			
			system("cls");
			printf("---------------------------------------------------------------------------------\n");
			printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
			printf("---------------------------------------------------------------------------------\n");
			
			if (produto[tmpCod-1].cod == tmpCod) {
				valEx = true;
				printf("	%d	|	", produto[tmpCod-1].cod);
				fputs(produto[tmpCod].desc, stdout);
				printf("		|	R$%.2f\n", produto[tmpCod-1].preco);
			} else {
				printf("Não foi encontrado um registro correspondente ao código fornecido.\n");
			}
			
			printf("--------------------------------------------------------------------------------\n\n");
			
			do {
				printf("Confirma? (S/N) ");
				continuar = getchar();
				fflush(stdin);
				continuar = toupper(continuar);
			} while (continuar != 'S' && continuar != 'N');
			
			if (continuar == 'S') {
				strcpy(produto_bak[tmpCod].desc, produto[tmpCod].desc);
			}
			break;
	} 
}
void rstProd (struct PROD *produto, struct PROD *produto_bak) {
	int ctrl;
	char continuar;
	bool valEx = false;
	
	system("cls");
	printf("--------------------------------------------------------------------------------\n");
	printf("	CÓDIGO	|	DESCRIÇÃO	|	PREÇO	\n");
	printf("--------------------------------------------------------------------------------\n");
	
	for (ctrl = 0; valEx == false && ctrl < 99; ctrl++) {
		if (produto_bak[ctrl].cod != 1337) {
			valEx = true;
			printf("	%d	|	", produto_bak[ctrl].cod);
			fputs(produto_bak[ctrl].desc, stdout);
			printf("		|	R$%.2f\n", produto_bak[ctrl].preco);
		}
	}
	
	printf("--------------------------------------------------------------------------------\n\n");
	
	do {
		printf("Confirma? (S/N) ");
		continuar = getchar();
		fflush(stdin);
		continuar = toupper(continuar);
	} while (continuar != 'S' && continuar != 'N');
	
	if (continuar == 'S') {
		strcpy(produto_bak[ctrl].desc, produto[ctrl].desc);
	}
}
