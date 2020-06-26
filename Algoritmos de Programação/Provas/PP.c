// Nome: Paulo César		Data: 21/06/2019
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void leValidaEvento (char nomeEvento[]);
int leValidaQuantGastos ();
float leValidaGastos (int i);
float calculaMedia (int numGasto, float gastos[]);

main () {
	float gastosEvento[50], mediaGastos = 0;
	int ctrl, qntGastos;
	char nomeEvento[51];
	
	leValidaEvento(nomeEvento);
	qntGastos = leValidaQuantGastos();
	for (ctrl = 0; ctrl < qntGastos; ctrl++) {
		gastosEvento[ctrl] = leValidaGastos(ctrl + 1);
	}
	mediaGastos = calculaMedia(qntGastos, gastosEvento);
	
	system("cls");
	
	printf("Evento: ");
	puts(nomeEvento);
	printf("Sequencial	  Gastos (R$) \n");
	for (ctrl = 0; ctrl < qntGastos; ctrl++) {
		printf("   %03d		  %11.2f \n", ctrl + 1, gastosEvento[ctrl]);
	}
	printf("\nMedia dos Gastos = R$%.2f", mediaGastos);
	
	return 0;
}

void leValidaEvento (char nomeEvento[]) {
	do {
		printf("Digite o nome do evento: ");
		gets(nomeEvento);
		fflush(stdin);
	} while (strlen(nomeEvento) == 0 || isspace(nomeEvento[0]));
	nomeEvento = strupr(nomeEvento);
}

int leValidaQuantGastos () {
	int gastos;
	
	do {
		printf("Digite a quantidade de gastos realizados no evento: ");
		scanf("%d", &gastos);
		fflush(stdin);
	} while (gastos < 3 || gastos > 50);
	
	return gastos;
}

float leValidaGastos (int i) {
	float gasto;
	do {
		printf("Digite o gasto No %d: R$", i);
		scanf("%f", &gasto);
		fflush(stdin);
	} while (gasto < 5000.00);
	return gasto;
}

float calculaMedia (int numGasto, float gastos[]) {
	int i;
	float media;
	
	for (i = 0; i < numGasto; i++) {
		media = media + gastos[i];
	}
	media = media / numGasto;
	return media;
}
