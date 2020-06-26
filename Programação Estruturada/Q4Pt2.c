#include <stdio.h>
#include <stdlib.h>

main() {
	int matriz[10][5], qntPar, qntImpar, i, j;
	
	qntPar = qntImpar = 0;
	
	for (i = 0; i < 10; i++) {
		for (j= 0; j < 5; j++) {
			matriz[i][j] = rand() % 10;
		}
	}	
	
	system("cls");
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d ", matriz[i][j]);
			if (matriz[i][j] % 2 == 0) {
				qntPar++;
			} else {
				qntImpar++;
			}
		}
		printf("\n");
	}
	
	printf("Quantidade de numeros pares: %d\n", qntPar);
	printf("Quantidade de numeros impares: %d", qntImpar);
	
	return 0;
}

