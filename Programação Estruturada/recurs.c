#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
// Síntese
//  Objetivo:  Calcular o fatorial usando recursão
//  Entrada : O fatorial a ser calculado
//  Saída   : O resultado do cálculoint fatorial(int num) ;  
// protótipo

int main()  {
	int num;

		printf("\nDigite um numero: ");
		scanf("%i",&num);
		printf("Fatorial = %i",fatorial(num));

	getch();
	return 0;
}

int fatorial (int num){
	if (num == 0) 
		return (1);
	else
		return(fatorial(num-1) * num);
}
