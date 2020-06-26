#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void escreveNum(int num, int val);

main() {
	setlocale(LC_ALL, "Portuguese");
	int n1, val = 0;

	do {
		printf("Digite um número inteiro positivo: ");
		scanf("%d", &n1);
		fflush(stdin);
	} while (n1 < 0);
	
	escreveNum(n1, val);


	return 0;
}

void escreveNum(int num, int val) {
	
	if (val <= num) 
    { 
        printf("%d ", val); 
        val++; 
        escreveNum(num, val);
    } 
    else
        return; 
}
