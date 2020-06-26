#include <stdio.h>
#include <stdlib.h>

main() {
	int i, j, matriz[50][20], maiorNum, posMaiorNum[2];
	
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 20; j++) {
//			printf("Digite o valor para a casa [%d|%d]: ", i, j);
//			scanf("%d", &matriz[i][j]);
//			fflush(stdin);
			matriz[i][j] = rand() % 100;
		}
	}
	system("cls");
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 20; j++) {
			printf("%d ", matriz[i][j]);
			if (matriz[i][j] > maiorNum) {
				maiorNum = matriz[i][j];
				posMaiorNum[0] = i + 1;
				posMaiorNum[1] = j;
			}
		}
		printf("\n");
	}
	printf("\nO maior numero da matriz (%d) esta na posicao %d|%d.", maiorNum, posMaiorNum[0], posMaiorNum[1]);

	return 0;
}

