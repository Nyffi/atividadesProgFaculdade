/*
  Objetivo:	Alterar o algoritmo de ordena��o de caracteres para pesquisar um caractere espec�fico.	
  Entrada:	30 caracteres e um caracter espec�fico.
  Sa�da:	Posi��o do caractere espec�fico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char carac, entrada[30];
    int tamanhoCarac, ctrl, confirma = 0;
	
    do {
	printf("Digite ate 30 caracteres: ");
    gets(entrada);
    fflush(stdin);
    tamanhoCarac = strlen(entrada);
    } while (tamanhoCarac > 30);
    
    printf("Digite um caracter especifico: ");
    carac = getchar();
    fflush(stdin);
	
    for (ctrl = 0; ctrl < tamanhoCarac; ctrl++)
    {
    	if (entrada[ctrl] == carac) {
    		printf("\nCaractere encontrado na posicao %d \n", ctrl + 1);
    		confirma = 1;
		}
    }
    if (confirma == 0) {
    	printf("\nCaracter nao encontrado.");
	}
    
    return 0;
}
