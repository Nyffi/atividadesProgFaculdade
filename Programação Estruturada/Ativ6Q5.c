#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float leValidaSalario();
void defineDesc(float sal, float desc[2]);
void mostraRes(float sal, float desc[2]);

main() {
	float salario, desc[2];
	char continua;
	
	do {
		system("cls");
		salario = leValidaSalario();
		defineDesc(salario, desc);
		mostraRes(salario, desc);
		printf("\nDeseja continuar? (S/N): ");
		continua = getchar();
		fflush(stdin);
		continua = toupper(continua);
	} while (continua == 'S');

	return 0;
}

float leValidaSalario() {
	float sal;
	
	do {
		printf("Digite o salario: R$");
		scanf("%f", &sal);
		fflush(stdin);
	} while (sal <= 0);
	
	return sal;
}

void defineDesc(float sal, float desc[2]) {
	desc[0] = sal * 0.1;
	desc[1] = sal * 0.05;
}

void mostraRes(float sal, float desc[2]) {
	system("cls");
	printf("Salario bruto: R$%.2f\n", sal);
	printf("Desconto da Previdencia Social (10%%): R$%.2f\n", desc[0]);
	printf("Desconto de Imposto (5%%): R$%.2f\n", desc[1]);
	printf("Salario liquido: R$%.2f\n", sal - desc[0] - desc[1]);
}
