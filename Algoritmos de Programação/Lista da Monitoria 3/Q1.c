/*
  Objetivo:  Elaborar um algoritmo/programa que seja capaz de armazenar o nome da cidade do DF que foi realizada a investigação de focos deste mosquito, não podendo este nome de cidade ser nulo.
  Entrada :	Nome da cidade, quantidade de estabelecimentos visitados (entre 5 e 100), quantidade de pessoas na cidade, quantidade de focos encontrados e quantidade de pessoas que viviam naquele estabelecimento.
  Saída   :	Nome da cidade, quantidade total de estabelecimentos investigados e total de pessoas que vivem nos mesmos, tabela com a quantidade d epessoas que vivem em cada estabelecimento investigado e o numero de foso que foi encontrado no establelecimento e o valor médio da quantidade de pessoas que vivem nesses estabelecimentos e quantidade de estabelecimentos que tem a quantidade maior de pessoas vivendo que este valor médio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

main() {
	char cidade[30] = {'\0'};
	int quantFoco[100], quantPessoas[100], quantidade, ctrl, quantTotal = 0, mediaTotal = 0, quantEstabAcimaMedia = 0;
	
	do {
		printf("Digite o nome da cidade: ");
		gets(cidade);
		fflush(stdin);
	} while (cidade[0] == '\0' || isspace(cidade[0]));
	
	do {
		printf("Digite quantos estabelecimentos foram visitados: ");
		scanf("%d", &quantidade);
		fflush(stdin);
	} while ((quantidade < 5 || quantidade > 100));

	for (ctrl = 0; ctrl < quantidade; ctrl++) {
		do {
			printf("Digite a quantidade de focos de dengue que foram encontrados no estabelecimento No %d: ", ctrl + 1);
			scanf("%d", &quantFoco[ctrl]);
			fflush(stdin);
		} while (quantFoco[ctrl] < 0);
		
		do {
			printf("Digite a quantidade de pessoas que vivem no estabelecimento No %d: ", ctrl + 1);
			scanf("%d", &quantPessoas[ctrl]);
			fflush(stdin);
		} while (quantPessoas[ctrl] < 0);
		
		quantTotal = quantTotal + quantPessoas[ctrl];
		
	}
	
	mediaTotal = quantTotal / quantidade;
	system("cls");
	
	printf("Cidade: ");
	puts(cidade);
	printf("\n\nQnt. total de estabelecimentos investigados: %d", quantidade);
	printf("\n\n-------------------------------------------------------\n");
	printf("Qnt. de pessoas \tNo. de focos\n");
	for (ctrl = 0; ctrl < quantidade; ctrl++) {
		printf("%3d \t\t\t%3d \n", quantPessoas[ctrl], quantFoco[ctrl]);
		
		if (quantPessoas[ctrl] > mediaTotal) {
			quantEstabAcimaMedia++;
		}
	}
	printf("\nMedia da quantidade de pessoas que vivem nos estabelecimentos: %d", mediaTotal);
	printf("\nQuantidade de estabelecimentos com quantidade de pessoas vivendo acima da media: %d", quantEstabAcimaMedia);
	return 0;
}

