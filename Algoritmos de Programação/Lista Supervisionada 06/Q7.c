#include <stdio.h>
#include <stdlib.h>	
#include <wctype.h>

int leValidaLetra ();

int main (){

	char letra;
	int c;

	letra = leValidaLetra();
	
	for (c = letra; c <= 89; c++){
		letra = letra +1;
		if((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        	printf ("%c.", letra);
		}
		
	}

	return 0;
}

int leValidaLetra (){
	char letra;
	do{

		printf ("Digite a letra inicial: ");
		letra = getchar();
		fflush(stdin);
		letra = towupper(letra);
		if (letra < 65 || letra > 90){
			printf ("Caracter invalido. Por favor digite novamente. \n");
		}
	} while (letra < 65 || letra > 90);
	return letra;
}
