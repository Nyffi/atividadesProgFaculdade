#include <stdio.h>
#include <stdlib.h>

main() {
	int num[3][3] = { {1,2,3}, {4,1,2}, {0,2,1}}, soma, somaL[3], somaC[3], somaD[2], i, j;
	
	soma=somaL[0]=somaL[1]=somaL[2]=somaC[0]=somaC[1]=somaC[2]=somaD[0]=somaD[1]=0;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("	%d", num[i][j]);
			soma = soma + num[i][j];
			switch (i) {
				case 0:
					somaL[0] = somaL[0] + num[0][j];
					break;
				case 1:
					somaL[1] = somaL[1] + num[1][j];
					break;
				case 2:
					somaL[2] = somaL[2] + num[2][j];
					break;
			}
			switch (j) {
				case 0:
					somaC[0] = somaC[0] + num[i][0];
					break;
				case 1:
					somaC[1] = somaC[1] + num[i][1];
					break;
				case 2:
					somaC[2] = somaC[2] + num[i][2];
					break;
			}
			if (i==j) {
				somaD[0] = somaD[0] + num[i][j];
			}
			if (i+j == 2) {
				somaD[1] = somaD[1] + num[i][j];
			}
		}
		printf("\n\n");
	}
	printf ("\nSoma Total = %d\n\n", soma);
	printf ("Soma L1 = %d\n", somaL[0]);
	printf ("Soma L2 = %d\n", somaL[1]);
	printf ("Soma L3 = %d\n\n", somaL[2]);
	printf ("Soma C1 = %d\n", somaC[0]);
	printf ("Soma C2 = %d\n", somaC[1]);
	printf ("Soma C3 = %d\n\n", somaC[2]);
	printf("Soma D1 = %d\n", somaD[0]);
	printf("Soma D2 = %d\n", somaD[1]);
	return 0;
}

