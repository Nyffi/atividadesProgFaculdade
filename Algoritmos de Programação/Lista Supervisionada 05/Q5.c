/*
	Objetivo:	Fazer um programa que calcule e escreva a maior e a menor altura do grupo, a média da altura das mulheres e o número de homens, utilizando os três comandos de repetição na solução do problema.
	Entrada:	Altura e sexo.
	Saída:		Maior e menor altura do grupo, a média da altura das mulheres e o número de homens.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void clearBuffer(char c);

main() {
	char sexo;
	float altura, maiorAltura = 0, menorAltura = 999, mediaAlturaF = 0;
	int quantPes, ctrl, quantM = 0, quantF = 0;
	
	printf("Digite quantas pessoas deseja coletar dados (max 10): ");
	scanf("%d", &quantPes);
	clearBuffer(quantPes);
	while (quantPes < 0 || quantPes > 10) {
		system("cls");
		printf("Valor invalido. A quantidade de pessoas deve ser acima de zero e, no maximo, até 10.\n");
		printf("Digite quantas pessoas deseja coletar dados (max 10): ");
		scanf("%d", &quantPes);
		clearBuffer(quantPes);
	}
	for (ctrl = 1;ctrl <= quantPes; ctrl++) {
		do {
			printf("Digite a altura informada: ");
			scanf("%f", &altura);
			clearBuffer(altura);
			if (altura < 0) {
				printf("Valor invalido. Digite um valor que seja acima de zero.\n");
			}
		} while (altura < 0);
		if (altura > maiorAltura) {
			maiorAltura = altura;
		}
		if (altura < menorAltura) {
			menorAltura = altura;
		}
		
		printf("Qual o sexo informado? (M - Masculino, F - Feminino)");
		sexo = getchar();
		clearBuffer(sexo);
		sexo = toupper(sexo);
		while (sexo != 'M' && sexo != 'F') {
			printf("Opcao invalida. Selecione uma das opcoes fornecidas. \n");
			printf("Qual o sexo informado? (M - Masculino, F - Feminino)");
			sexo = getchar();
			clearBuffer(sexo);
			sexo = toupper(sexo);
		}
		switch(sexo) {
			case 'M':
				quantM = quantM + 1;
				break;
			case 'F':
				quantF = quantF + 1;
				mediaAlturaF = mediaAlturaF + altura;
				break;
		}
	}
	mediaAlturaF = mediaAlturaF / quantF;
	system("cls");
	printf("Maior altura: %.2f \nMenor altura: %.2f \n", maiorAltura, menorAltura);
	printf("Media altura das mulheres: %.2f \n", mediaAlturaF);
	printf("Numero de homens: %d", quantM);
	return 0;
}

void clearBuffer(char c) {
	while(c != '\n') {
		scanf("%c", &c);
	}
}
