#include <stdio.h>
#include <stdlib.h>

main() {
	int i, j, matriz[20][20];
	
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("Digite o valor para a casa [%d|%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
			fflush(stdin);
		}
	}
	system("cls");
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}

