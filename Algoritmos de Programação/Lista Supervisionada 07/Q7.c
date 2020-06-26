//Objetivo:	Desenvolver um algoritmo que cadastre os preços de até 100 diferentes CDs em uma loja e, após esse cadastro, possibilitar a execução de uma de duas funções para aumento dos preços cadastrados.
//Entrada:	Quantidade dos CDs, valor dos CDs e qual função de aumento de preço executar.
//Saída:	Valor original dos CDs, porcentagem de aumento e valor dos CDs com o aumento.

#include <stdio.h>
#include <stdlib.h>

float aplicaAcrescimo10 (float precoAtual);
float aplicaAcrescimo(float precoAtual,  float pctg);

main() {
	float cdOriginal[100], cdAumento[100], pctgAumento;
	int opcao, ctrl, quantCDs;
	char cd[4];
	
	quantCDs = -1;
	
	do {
		printf("Digite a quantidade de CDs que deseja dar um preco: ");
		gets(cd);
		fflush(stdin);
		if (isdigit(cd[0])) {
			quantCDs = atoi (cd);
			if (quantCDs < 0 || quantCDs > 100) {
				printf("Erro. O valor deve ser entre 0 e 100.\n");
			}
		} else {
			printf("Erro. O valor deve ser numerico e ser entre 0 e 100.\n");
		}
	} while (quantCDs < 0 || quantCDs > 100);
	
	for (ctrl = 0; ctrl < quantCDs; ctrl++) {
		do {
			printf("Digite o valor do CD No %d: R$", ctrl + 1);
			scanf("%f", &cdOriginal[ctrl]);
			fflush(stdin);
		} while (cdOriginal[ctrl] < 0);
	}
	
	do {
		system("cls");
		printf("O que deseja fazer com os valores dos CDs?\n\n");
		printf("1) Aumentar o valor em 10%\n");
		printf("2) Aumentar o valor em uma porcentagem customizada\n\n");
		printf("Sua escolha: ");
		scanf("%d", &opcao);
		fflush(stdin);
		switch (opcao) {
			case 1:
				pctgAumento = 10;
				for (ctrl = 0; ctrl < quantCDs; ctrl++) {
					cdAumento[ctrl] = aplicaAcrescimo10(cdOriginal[ctrl]);
				}
				break;
			case 2:
				do {
					printf("Digite uma porcentagem para acrescimo: ");
					scanf("%f", &pctgAumento);
					fflush(stdin);
				} while (pctgAumento < 0); 
				for (ctrl = 0; ctrl < quantCDs; ctrl++) {
					cdAumento[ctrl] = aplicaAcrescimo(cdOriginal[ctrl], pctgAumento);
				}
				break;
		}
	} while (opcao != 1 && opcao != 2);
	
	system("cls");
	for (ctrl = 0; ctrl < quantCDs; ctrl++) {
		printf("-----------------------------------------------\n");
		printf("Disco: %d \nValor Original: R$%.2f \nPorcentagem Aumento: %.2f \nValor com Aumento: R$%.2f \n", ctrl + 1, cdOriginal[ctrl], pctgAumento, cdAumento[ctrl]);
	}
	
	return 0;
}

float aplicaAcrescimo10 (float precoAtual) {

	float novoValor;

	novoValor = precoAtual * 1.1;

	return novoValor;
}

float aplicaAcrescimo(float precoAtual,  float pctg) {

	float novoValor;

	novoValor = precoAtual + (precoAtual * (pctg / 100)) ;


	return novoValor;
}
