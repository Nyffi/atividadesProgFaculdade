/*
  Objetivo:	Desenvolver um algoritmo que cadastre os dados recebidos da Polícia Federal e produza um conjunto de informações para auxiliar os componentes da CPI.
  Entrada:	Quantidade de pessoas, identificação do investigado, valor recebido pelo investigado.
  Saída:	uma tabela, totalmente alinhada, conforme modelo a seguir, tendo na primeira linha a identificação dos dados, e a partir da segunda linha a identificação de cada investigado, o valor recebido e a classificação . Também deverá ser apresentado os totais para cada tipo de classificação seguido da soma de todos os valores investigados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leValidaId(int i, int idInv[], int qntPes);
float leValidaValor(int i);
int classificaCPI (float valor);

main() {
	char escolha;
	int confirmaCompara = 0, idInvestiga[150], classificacao[150], quantPessoas, ctrl, qntIni = 0, qntSV = 0, qntSaf = 0;
	float valoresInvestiga[150], valTotal = 0, valCheck;

	do {
		printf ("Digite quantas pessoas foram investigadas: ");
		scanf("%d", &quantPessoas);
		fflush(stdin);
	} while (quantPessoas < 2 || quantPessoas > 150);
	
	system("cls");
	
	for (ctrl = 0; ctrl < quantPessoas; ctrl++) {
		idInvestiga[ctrl] = leValidaId(ctrl, idInvestiga, quantPessoas);
		valoresInvestiga[ctrl] = leValidaValor(ctrl);
		classificacao[ctrl] = classificaCPI(valoresInvestiga[ctrl]);
		valTotal = valTotal + valoresInvestiga[ctrl];
	}
	
	system("cls");
	
	printf("Identificacao \tValor (R$) \tClassificacao\n");
	printf("--------------------------------------------------------------------\n");
	for (ctrl = 0; ctrl < quantPessoas; ctrl++) {
		printf("%d \t\t %9.2f\t", idInvestiga[ctrl], valoresInvestiga[ctrl]);
		switch (classificacao[ctrl]) {
			case 0:
				printf("Iniciante \n");
				qntIni++;
				break;
			case 1:
				printf("Sem Vergonha \n");
				qntSV++;
				break;
			case 2:
				printf("Safado \n");
				qntSaf++;
				break;
		}
	}
	printf("--------------------------------------------------------------------\n");
	printf("Resumo\n");
	printf("--------------------------------------------------------------------\n");
	printf("%d = Iniciante\n", qntIni);
	printf("%d = Sem Vergonha\n", qntSV);
	printf("%d = Safado\n\n", qntSaf);
	printf("Total de valores recebidos: R$%.2f\n\n", valTotal);
	
	do {
		printf("Deseja verificar se existe um investigado com valor recebido maior ou igual a um valor especifico? (S/N): ");
		escolha = getchar();
		fflush(stdin);
		escolha = toupper(escolha);
	} while (escolha != 'S' && escolha != 'N');
	
	if (escolha == 'S') {
		printf("Digite um valor para ser verificado: R$");
		scanf("%f", &valCheck);
		fflush(stdin);
		system("cls");
		printf("--------------------------------------------------------------------\n");
		printf("Resultados da comparacao\n");
		printf("--------------------------------------------------------------------\n");
		for (ctrl = 0; ctrl < quantPessoas; ctrl++) {
			if (valCheck <= valoresInvestiga[ctrl]) {
				confirmaCompara = 1;
			}
		}
		if (confirmaCompara == 0) {
			printf("Nenhum investigado recebeu valor >= que R$ %.2f", valCheck);
		} else {
			printf("Identificacao \tValor (R$) \tClassificacao\n");
			printf("--------------------------------------------------------------------\n");
			for (ctrl = 0; ctrl < quantPessoas; ctrl++) {
				if (valCheck <= valoresInvestiga[ctrl]) {
					printf("%d \t\t %9.2f\t", idInvestiga[ctrl], valoresInvestiga[ctrl]);
					switch (classificacao[ctrl]) {
						case 0:
							printf("Iniciante \n");
							break;
						case 1:
							printf("Sem Vergonha \n");
							break;
						case 2:
							printf("Safado \n");
							break;
					}
				}
			}
		}
	}
	return 0;
}

int leValidaId(int i, int idInv[], int qntPes) {
	int id, ctrl;
	
	do {
		printf("Digite o numero de identificacao do investigado No %d: ", i + 1);
		scanf("%d", &id);
		fflush(stdin);
	} while (id < 1000);
	
	for(ctrl = 0; ctrl < qntPes; ctrl++) {
		if (id == idInv[ctrl]) {
			do {
				printf("Redigite o numero de identificacao do investigado No %d: ", i + 1);
				scanf("%d", &id);
				fflush(stdin);
			} while (id < 1000);
		}
	}
	
	return id;
}

float leValidaValor(int i) {
	float valor;
	
	do {
		printf("Digite o valor em reais recebido pelo investigado No %d: R$", i + 1);
		scanf("%f", &valor);
		fflush(stdin);
	} while (valor < 0);
	return valor;
}

int classificaCPI (float valor) {
	if (valor <= 10000.00) {
		return 0;
	} else if (valor > 10000.00 && valor <= 50000.00) {
		return 1;
	} else {
		return 2;
	}
}
