/*
  Objetivo:
  Entrada:
  Saída:
*/

struct TEST {
	float grana;
};

void defina (float preco);
void lista (struct TEST *teste);

#include <stdio.h>
#include <stdlib.h>

main() {
	int escolha;
	
	struct TEST *teste;

printf("1 - Defina\n");
printf("2 - Lista\n\n");
printf("-> ");
scanf("%d", &escolha);
if (escolha == 1) {
	defina ((*teste).grana);
} else {
	lista (teste);
}
	return 0;
}

void defina (float preco) {
	printf("Preco: ");
	scanf("%f", &preco);
}
void lista (struct TEST *teste) {
	printf ("Valor nformado: %.2f", teste->grana);
}
