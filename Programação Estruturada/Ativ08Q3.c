#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void escreveNum(int num, int val);

main() {
	setlocale(LC_ALL, "Portuguese");
	int n1, val;

	do {
		printf("Digite um n�mero inteiro positivo: ");
		scanf("%d", &n1);
		fflush(stdin);
	} while (n1 < 0);
	
	val = n1;
	escreveNum(n1, val);


	return 0;
}

void escreveNum(int num, int val) {
	
	if (val >= 0) 
    { 
        printf("%d ", val); 
        val--; 
        escreveNum(num, val);
    } 
    else
        return; 
}
