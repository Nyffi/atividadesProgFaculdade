#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float lePrecoCompra();
void defineMostraValVenda(float valC);

main() {
	int i;
	float valCompra, valVenda;
	char continua;

	do {
		system("cls");
		valCompra = lePrecoCompra();
		defineMostraValVenda(valCompra);
		printf("\nDeseja continuar? (S/N): ");
		continua = getchar();
		fflush(stdin);
		continua = toupper(continua);
	} while (continua == 'S');
	
	return 0;
}

float lePrecoCompra() {
	float preco;
	
	do {
		printf("Digite o valor da compra: R$ ");
		scanf("%f", &preco);
		fflush(stdin);
	} while (preco < 0);
	
	return preco;
}

void defineMostraValVenda(float valC) {
	float valV;
	
	valV = valC + (valC * 0.3);
	
	printf("O valor de compra (R$%.2f) mais 30%% de lucro e igual a R$%.2f", valC, valV);
}
