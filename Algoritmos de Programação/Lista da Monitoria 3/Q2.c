/*
  Objetivo:	Elaborar um algoritmo para uma pesquisa que tem como objetivo saber o sexo, idade e o local da ultima viagem fora do país dentro de determinados continentes.
  Entrada:	Sexo, idade, local da última viagem fora do país, quantidade de pessoas.
  Saída:	Sexo, idade, logal da ultima viagem das pessoas que possuem idade menor que a média de todas as idades, média de todas as idade cadastradas, quantidade de pessoas que visitou cada continente, quantidade de pessoas que não sairam do brasil.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validaPessoas ();
void validaSexo (char sexo[], int i);
void validaIdade (int idade[], int i);
void validaViagem (char viagem[], int i);
void visaoFinal (int qntEU, int qntAS, int qntAN, int qntNV);

main() {
	char sexo[500], viagem[500];
	int quantEU = 0, quantAS = 0, quantAN = 0, quantNaoViajou = 0, ctrl, quantPessoas, idade[500];
	float mediaIdade = 0;
	
	quantPessoas = validaPessoas ();	
	
	for (ctrl = 0; ctrl < quantPessoas; ctrl++) {
		validaSexo (sexo, ctrl);
		validaIdade (idade, ctrl);	
		mediaIdade = mediaIdade + idade[ctrl];
		validaViagem (viagem, ctrl);
	}
	mediaIdade = mediaIdade / quantPessoas;
	
	system("cls");
	
	printf("----------------------------------------------------------------\n");
	printf("Tabela de pessoas com idade menor que a media\n");
	printf("----------------------------------------------------------------\n");
	printf("Sexo \tIdade \tLocal de viagem\n");
	printf("----------------------------------------------------------------\n");
	
	for (ctrl = 0; ctrl < quantPessoas; ctrl++) {
		if (idade[ctrl] < mediaIdade) {
			printf("%c \t%d \t", sexo[ctrl], idade[ctrl]);
			switch (viagem[ctrl]) {
				case 'E':
					printf("Europa\n");
					break;
				case 'S':
					printf("Asia\n");
					break;
				case 'A':
					printf("America do Norte\n");
					break;
				case 'N':
					printf("N/A\n");
					break;
			}
		}
		switch (viagem[ctrl]) {
				case 'E':
					quantEU++;
					break;
				case 'S':
					quantAS++;
					break;
				case 'A':
					quantAN++;
					break;
				case 'N':
					quantNaoViajou++;
					break;
			}
	}
	printf("\n----------------------------------------------------------------\n");
	visaoFinal(quantEU, quantAS, quantAN, quantNaoViajou);
	
	return 0;
}

int validaPessoas () {
	int qntPes;
	do {
		printf("Digite quantas pessoas serao entrevistadas: ");
		scanf("%d", &qntPes);
		fflush(stdin);
	} while (qntPes < 0 || qntPes > 500);
	
	return qntPes;
}

void validaSexo (char sexo[], int i) {
	do {
		printf("Digite o seu sexo (M/F): ");
		sexo[i] = getchar();
		fflush(stdin);
		if (isalpha(sexo[i]) != 0) {
			sexo[i] = toupper(sexo[i]);
		}
	} while (sexo[i] != 'M' && sexo[i] != 'F');
}

void validaIdade (int idade[], int i) {
	do {
		printf("Digite sua idade: ");
		scanf("%d", &idade[i]);
		fflush(stdin);
	} while (idade[i] < 0);
}

void validaViagem (char viagem[], int i) {
	do {
		printf("Escolha qual dos continentes voce viajou recentemente: \n\n");
		printf("----------------------------------------------------------------\n\n");
		printf("E ) Europa\n");
		printf("S ) Asia\n");
		printf("A ) America do Norte\n");
		printf("N ) Nunca saiu do pais\n\n");
		printf("----------------------------------------------------------------\n\n");
		printf("Digite sua escolha: ");
		viagem[i] = getchar();
		fflush(stdin);
		if (isalpha(viagem[i]) != 0) {
			viagem[i] = toupper(viagem[i]);
		}
	} while (viagem[i] != 'E' && viagem[i] != 'S' && viagem[i] != 'A' && viagem[i] != 'N');
}

void visaoFinal (int qntEU, int qntAS, int qntAN, int qntNV) {
	printf("Qnt. de pessoas que visitaram a Europa: %d\n", qntEU);
	printf("Qnt. de pessoas que visitaram a Asia: %d\n", qntAS);
	printf("Qnt. de pessoas que visitaram a America do Norte: %d\n", qntAN);
	printf("Qnt. de pessoas que nao sairam do Brasil: %d", qntNV);
}
