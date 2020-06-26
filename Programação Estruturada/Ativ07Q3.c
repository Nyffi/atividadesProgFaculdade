#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int multiplica (int valK, int valN, int qntLoop, int i);

main() {
	setlocale(LC_ALL, "Portuguese");
	int numK, numN, qntLoop, i;
	
	do {
		printf("Digite quantas vezes a variável K deve ser multiplicada pela variável N: ");
		scanf("%d", &qntLoop);
		fflush(stdin);
	} while (qntLoop <= 0);
	
	printf("Digite o valor de K: ");
	scanf("%d", &numK);
	fflush(stdin);

	printf("Digite o valor de N: ");
	scanf("%d", &numN);
	fflush(stdin);
	
	for (i = 0; i < qntLoop; i++) {
		printf("Resultado %d: %d\n", i+1, multiplica (numK, numN, qntLoop, i));
	}
	
	return 0;
}

int multiplica (int valK, int valN, int qntLoop, int i) {	
	
	if (valN == 0 || valK == 0) {
		return 0;
	}
	if ( valK < 0 ) {
		return -multiplica(-valK, valN, qntLoop, i);
	} 
    if ( valN < 0 ) {
    	return -multiplica(valK, -valN, qntLoop, i);
	}
		
	return ((multiplica(valK,valN>>1, qntLoop, i)<<1 * i+1)+(valN&1?valK:0));
}
