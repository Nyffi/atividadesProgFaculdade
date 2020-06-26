#include <stdio.h>
#include <stdlib.h>

main() {
	int i, j, matriz[50][50], somaD = 0;
	
	srand ( time(NULL) );
	
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			printf("Digite o valor para a casa [%d|%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
			fflush(stdin);
		}
	}
	system("cls");	
	for (i = 0; i < 50; i++) {
		for (j = 0; j < 50; j++) {
			printf("%d ", matriz[i][j]);
			if (i==j) {
				somaD = somaD + matriz[i][j];
			}
		}
		printf("\n");
	}
	printf("\nSoma da Diagonal Principal: %d", somaD);
	
	return 0;
}

