/*
  Objetivo:	Desenvolver um programa que efetue os cálculos relacionados a avaliação final desta disciplina neste anos e semestre, onde o cálculo da média deverá ser realizado por uma função denominada média.
  Entrada:	Notas.
  Saída:	Média final.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE (1==1)
#define FALSE (!TRUE)

float validaNota (float nota);
float media (float avPres1, float avVirt1, float avPres2, float avVirt2, float avPres3, float avVirt3, float avPrat, float trabFinal, float ativSup);
void mostraResultado (float notaFinal);

main() {
	int ctrl, continuar;
	char opcao;
	float nota[3], notaFinal, avPres[3], avVirt[3], avPrat, trabFinal, ativSup;

	do {
		for (ctrl = 1; ctrl <= 3; ctrl++) {
			printf("Digite a nota da Avaliacao Presencial No %d: ", ctrl);
			scanf("%f", &avPres[ctrl - 1]);
			fflush(stdin);
			avPres[ctrl - 1] = validaNota(avPres[ctrl-1]);
			printf("Digite a nota da Avaliacao Virtual No %d: ", ctrl);
			scanf("%f", &avVirt[ctrl - 1]);
			fflush(stdin);
			avVirt[ctrl - 1] = validaNota(avVirt[ctrl-1]);
		}
		printf("Digite a nota da Avaliacao Pratica: ");
		scanf("%f", &avPrat);
		fflush(stdin);
		avPrat = validaNota(avPrat);
		printf("Digite a nota do Trabalho Final: ");
		scanf("%f", &trabFinal);
		fflush(stdin);
		trabFinal = validaNota(trabFinal);
		printf("Digite a nota da Avaliacao Supervisionada: ");
		scanf("%f", &ativSup);
		fflush(stdin);
		ativSup = validaNota(ativSup);
		
		notaFinal = media(avPres[0], avVirt[0], avPres[1], avVirt[1], avPres[2], avVirt[2], avPrat, trabFinal, ativSup);
		notaFinal = validaNota(notaFinal);
		
		mostraResultado(notaFinal);
		printf("\nDeseja calcular a nota de outro aluno? (S/N): ");
		opcao = getchar();
		fflush(stdin);
		opcao = toupper(opcao);
		while (opcao != 'S' && opcao != 'N') {
			printf("Opcao invalida. Escolha entre as opcoes Sim (S) e Nao (N). \nDeseja calcular a nota de outro aluno? (S/N): ");
			opcao = getchar();
			fflush(stdin);
			opcao = toupper(opcao);
		}
		if (opcao == 'S'){
			continuar = TRUE;
		} else {
			continuar = FALSE;
		}
	} while (continuar != FALSE);
	return 0;
}

float validaNota (float nota) {
	if (nota >= 0 && nota <= 10) {
		return nota;
	} else {
		if (nota < 0) {
			return 0;
		} else if (nota > 10) {
			return 10;
		}
	}
}

float media (float avPres1, float avVirt1, float avPres2, float avVirt2, float avPres3, float avVirt3, float avPrat, float trabFinal, float ativSup) {
	float res, nota[3], prova[3];
	
	prova[0] = avPres1 + 0.1 * avVirt1;
	prova[1] = avPres2 + 0.1 * avVirt2;
	nota[0] = 0.4 * prova[0] + 0.6 * prova[1];
	nota[0] = validaNota(nota[0]);
	
	prova[2] = avPres3 + 0.1 * avVirt3;
	nota[1] = prova[2];
	nota[1] = validaNota(nota[1]);
	
	nota[2] = 0.5 * avPrat + 0.3 * trabFinal + 0.2 * ativSup;
	nota[2] = validaNota(nota[2]);
	
	res = (nota[0] + nota[1] + nota[2]) / 3;
	return res;
}

void mostraResultado (float notaFinal) {
	system("cls");
	printf("Nota final do aluno: %.2f\n", notaFinal);
	
	if (notaFinal >= 7) {
		printf("Resultado final: APROVADO");
	} else {
		printf("Resultado final: REPROVADO");
	}
}
