#include <stdio.h>
#include <stdlib.h>

float leValidaNota();
float defineMedia(float nota[]);
void mostraRes(float med);

main() {
	int i;
	float nota[3], med;

	for (i = 0; i < 3; i++) {
		nota[i] = leValidaNota();
	}
	med = defineMedia(nota);
	mostraRes(med);
	
	return 0;
}

float leValidaNota() {
	float nota;
	
	do {
		printf("Digite a nota (0 a 10): ");
		scanf("%f", &nota);
		fflush(stdin);
	} while (nota < 0 || nota > 10);
	
	return nota;
}

float defineMedia(float nota[]) {
	float media = 0;
	
	media = (nota[0] + nota[1] + nota[2]) / 3;
	
	return media;
}

void mostraRes(float med) {
	system("cls");
	
	printf("A media das notas inseridas e de %.2f", med);
}
