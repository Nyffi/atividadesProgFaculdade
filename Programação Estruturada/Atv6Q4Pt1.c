#include <stdio.h>
#include <stdlib.h>

struct PES {
	float peso, altura;
};

float leValidaPeso();
float leValidaAltura();
void mostraRes(float peso, float altura);

main () {
	struct PES pessoa;
	char continua;
	
	do {
		system("cls");
		pessoa.peso = leValidaPeso();
		pessoa.altura = leValidaAltura();
		mostraRes(pessoa.peso, pessoa.altura);
		printf("\nDeseja continuar? (S/N): ");
		continua = getchar();
		fflush(stdin);
		continua = toupper(continua);
	} while (continua == 'S');
}

float leValidaPeso() {
	float kg;
	
	do {
		printf("Digite seu peso (kg): ");
		scanf("%f", &kg);
		fflush(stdin);
	} while (kg <= 0);
	
	return kg;
}

float leValidaAltura() {
	float alt;
	
	do {
		printf("Digite sua altura (m): ");
		scanf("%f", &alt);
		fflush(stdin);
	} while (alt <= 0);
	
	return alt;
}

void mostraRes(float peso, float altura) {
	float imc;
	
	printf("Seu peso (kg): %.2f\n", peso);
	printf("Sua altura (m): %.2f\n\n", altura);
	printf("Sua classificacao: ");
	
	imc = peso / (altura * altura);
	if (imc <= 18.5) {
		printf("Abaixo do Peso");
	} else if (imc > 18.5 && imc < 25) {
		printf("Peso ideal");
	} else {
		printf("Acima do Peso");
	}
}
