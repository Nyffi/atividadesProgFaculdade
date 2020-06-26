#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	int num[100], i, qntVal;
	
	do {
		printf("Quantos valores deseja digitar? ");
		scanf("%d", &qntVal);
		fflush(stdin);
	} while (qntVal <= 0 || qntVal > 100);
	
    for (i = 0; i < qntVal; i++) {
    	printf("Digite um número: ");
	    scanf("%d", &num[i]);
	    fflush(stdin);
	}
	
    printf("Soma = %d", somaNum(num, 0, qntVal));
    return 0;
}
int somaNum(int num[], int comeco, int tamanho) {
    
    if (comeco >= tamanho) {
    	return 0;
	}
		return (num[comeco] + somaNum(num, comeco + 1, tamanho));
}
