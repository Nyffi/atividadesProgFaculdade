//Objetivo:	fazer um algoritmo que calcule e escreva o somatório dos valores armazenados numa variável composta inudimensional, chamada dados, de até 100 elementos numéricos a serem lidos.
//Entrada:	Até 100 elementos numéricos.
//Saida:	Somatório desses elementos numéricos.

#include <stdio.h>
#include <stdlib.h>

main() {
	float num[100], dados;
	int ctrl, quantNum;
	
	dados = 0;

	printf("Digite a quantidade de valores a serem lidos: ");
	scanf("%d", &quantNum);
	fflush(stdin);
	while (quantNum < 0 || quantNum > 100) {
		printf("Valor invalido. Digite um numero entre 0 e 100.\n");
		printf("Digite a quantidade de valores a serem lidos: ");
		scanf("%d", &quantNum);
		fflush(stdin);
	}
	
	for (ctrl = 0; ctrl < quantNum; ctrl++){
		printf("Digite o valor No %d: ", ctrl + 1);
		scanf("%f", &num[ctrl]);
		dados = dados + num[ctrl];
	}
	
	printf("Somatoria dos dados informados: %.2f", dados);
	
	return 0;
}

