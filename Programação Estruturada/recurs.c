#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
// S�ntese
//  Objetivo:  Calcular o fatorial usando recurs�o
//  Entrada : O fatorial a ser calculado
//  Sa�da   : O resultado do c�lculoint fatorial(int num) ;  
// prot�tipo

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
