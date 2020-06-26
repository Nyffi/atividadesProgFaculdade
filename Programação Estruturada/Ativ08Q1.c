#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int Multip_Rec(int n1, int n2);

main() {
	setlocale(LC_ALL, "Portuguese");
	int n1, n2;

	printf("Digite um número inteiro: ");
	scanf("%d", &n1);
	fflush(stdin);
	
	printf("Digite outro número inteiro: ");
	scanf("%d", &n2);
	fflush(stdin);
	
	printf("%d x %d = %d", n1, n2, Multip_Rec(n1, n2));


	return 0;
}

int Multip_Rec(int n1, int n2) {
	
	if (n1 == 0 || n2 == 0) {
		return 0;
	}
	
	return (Multip_Rec(n1, n2 - 1)) + n1;
}
