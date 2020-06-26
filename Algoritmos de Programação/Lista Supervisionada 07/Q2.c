//Objetivo:	Alterar o algoritmo anterior considerando que não se conhece quantos alunos esta turma tem (menos que 50), e permitir que o usuário possa informar a quantidade de alunos.
//Entrada:	Quantidade de alunos e notas.
//Saida:	Notas.

#include <stdio.h>
#include <stdlib.h>

float validaNota(float nota);

main() {
	float nota[50];
	int ctrl, alunos;
	
	printf("Digite a quantidade de alunos: ");
	scanf("%d", &alunos);
	fflush(stdin);
	
	for (ctrl=0; ctrl < alunos; ctrl++) {
		printf("Digite a nota No %d: ", ctrl + 1);
		scanf("%f", &nota[ctrl]);
		fflush(stdin);
		nota[ctrl] = validaNota(nota[ctrl]);
	}
	system("cls");
	for (ctrl=0;ctrl < alunos; ctrl++) {
		printf("Nota No %d: %.2f \n", ctrl + 1, nota[ctrl]);
	}
	
	return 0;
}

float validaNota(float nota) {
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
