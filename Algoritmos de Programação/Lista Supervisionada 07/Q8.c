/*
  Objetivo:	Fazer um algoritmo que leia até 30 caracteres e os ordene em ordem decrescente.
  Entrada:	Letras.
  Saída:	Letras em ordem decrescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char carac, entrada[30], saida[30];
    int num[26] = {0}, tamanhoCarac, ctrl, casa, val;
	
    do {
	printf("Digite ate 30 caracteres: ");
    gets(entrada);
    fflush(stdin);
    tamanhoCarac = strlen(entrada);
    } while (tamanhoCarac > 30);
	
    for (ctrl = 0; ctrl < tamanhoCarac; ctrl++)
    {
    	carac = entrada[ctrl] - 'a';
		num[carac]++;
    }
    
    casa = 0;
    
   	
    for (carac = 'z'; carac >= 'a'; carac--) {
    	val = carac - 'a';
        for (ctrl = 0; ctrl < num[val]; ctrl++) {
        	saida[casa] = carac;
        	casa++;
        }
    }
    saida[casa] = '\0';
    
    printf("%s\n", saida);
    return 0;
}
