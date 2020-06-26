#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void revs(int i, int tamanho, float num[]);

int main() {
	setlocale(LC_ALL, "Portuguese");
	int i, tamanho;
	float num[100];
	
	do {
		printf("Digite quantos digitos deseja inserir (máx. 100): ");
		scanf("%d", &tamanho);
		fflush(stdin);
	} while (tamanho <= 0 || tamanho > 100);
	
  	for(i=0; i<tamanho; i++) {
  		printf("Digite o valor %d: ", i+1);
		scanf("%f", &num[i]);
		fflush(stdin);
  	}
  	printf("\nVetor invertido\n");
  	revs(0, tamanho, num);

  	return 0;
}

void revs(int i, int tamanho, float num[]) {
  	if(i==tamanho) {
		return;
  	} else {
    	revs(i+1, tamanho, num);
    	printf("%.2f\n", num[i]);
	}
}
