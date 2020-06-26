#include <stdio.h>
#include <stdlib.h>

int converterBinario (int dec);

main() {
	int decimal;
	
	printf("Digite um numero em decimal para efetuar a conversao para binario: ");
	scanf("%i", &decimal);
	fflush(stdin);
	printf("Binario: %i", converterBinario(decimal));
	getch();


	return 0;
}

int converterBinario (int dec) {
	if (dec == 0) {
		return 0;
	} else {
		return (dec % 2 + 10 * converterBinario(dec / 2));
	}
}
