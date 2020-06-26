#include <stdio.h>
#include <stdlib.h>

void particao (int inicio, int fim, int v[]);

main() {
	int tam = 8, num[8] = {2,8,7,1,3,5,6,4}, i, teste;

	for (i = 0; i < tam; i++) {
		printf("%d  ", num[i]);
	}
	printf("\n");
	
	particao(0, tam - 1, num);
	
	return 0;
}

void particao (int inicio, int fim, int v[]) {
	int i, j, temp, pivo, ctrl;
	
	if (inicio < fim) {
		pivo = inicio;
		i = inicio;
		j = fim;
		
		while (i < j) {
			while (v[i] <= v[pivo] && i < fim) {
				i++;
			}
			while (v[j] > v[pivo]) {
				j--;
			}
			if (i < j) {
				temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
		
		temp = v[pivo];
		v[pivo] = v[j];
		v[j] = temp;
		
		
		
		particao(inicio, j-1, v);
		particao(j+1, fim, v);
		
		
	}

	for (ctrl = 0; ctrl <= fim; ctrl++) {
		printf("%d  ", v[ctrl]);
	}
	printf("\n");
	
}
