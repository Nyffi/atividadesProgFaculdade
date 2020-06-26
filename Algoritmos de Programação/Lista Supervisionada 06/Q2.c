#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char opcao();
char conFiat(char *modelo);
char conChevy(char *modelo);
char conFord(char *modelo);
char confirmaEscolha (char palavra[]);

main(){

char nome[30], op, veiculo[10], marca[10];

	do {
		system("cls");
		op = opcao();
	} while (op == 'N');
	
	switch (op) {
		case '1':
			conFiat(veiculo);
			strcpy(marca, "Fiat");
			break;
		case '2':
			conChevy(veiculo);
			strcpy(marca, "Chevrolet");
			break;
		case '3':
			conFord(veiculo);
			strcpy(marca, "Ford");
			break;
	}
	
	printf ("\nDigite seu nome: ");
	gets(nome);
	fflush(stdin);
	system ("cls");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - -");
	printf ("\n|Parabens, %s, pelo seu novo %s %s.\t|\n|Obrigado por comprar em nossa Concessionaria!\t|", nome, marca, veiculo);
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - -");
	return 0;
}

char opcao (){
	char op, confirma, marca[10];

	do{
		printf ("Concessionarias disponiveis: \n\n1) FIAT \n2) CHEVROLET  \n3) FORD \n\n");
		printf ("Escolha uma das concessionarias: ");
		op = getchar();
		fflush(stdin);
		
		switch (op) {
			case '1':
				confirma = confirmaEscolha("FIAT");
				if (confirma == 'S') {
					return op;
					break;
				} else {
					break;
				}
			case '2':
				confirma = confirmaEscolha("CHEVROLET");
				if (confirma == 'S') {
					return op;
					break;
				} else {
					break;
				}
			case '3':
				confirma = confirmaEscolha("FORD");
				if (confirma == 'S') {
					return op;
					break;
				} else {
					break;
				}
			default:
				system("cls");
				printf("Valor invalido. Insira uma das opcoes descritas. \n");
		}
		
	} while (op != '1' && op != '2' && op != '3');
}

char conFiat (char *modelo){
	char opcao, carro[5], confirmaCarro;
	
	do {
		do {
			system ("cls");
			printf("\n- - - V E I C U L O S    F I A T - - - \n");
			printf("\n1) Argo");
			printf("\n2) Punto");
			printf("\n3) Palio");
			printf("\n\nEscolha o seu carro: ");
			opcao = getchar();
			fflush(stdin);
		} while (opcao != '1' && opcao != '2' && opcao != '3');
		switch (opcao) {
			case '1':
				strcpy(carro, "Argo");
				break;
			case '2':
				strcpy(carro, "Punto");
				break;
			case '3':
				strcpy(carro, "Palio");
				break;
		}
		confirmaCarro = confirmaEscolha(carro);
		if (confirmaCarro == 'S') {
			strcpy(modelo, carro);
		}
	} while (confirmaCarro == 'N');
}
	
char conChevy (char *modelo){
	char opcao, carro[5], confirmaCarro;
	
	do {
		do {
			system ("cls");
			printf("\n- - - V E I C U L O S    C H E V R O L E T - - - \n");
			printf("\n1) Prisma");
			printf("\n2) S10");
			printf("\n3) Onix");
			printf("\n\nEscolha o seu carro: ");
			opcao = getchar();
			fflush(stdin);
		} while (opcao != '1' && opcao != '2' && opcao != '3');
		switch (opcao) {
			case '1':
				strcpy(carro, "Prisma");
				break;
			case '2':
				strcpy(carro, "S10");
				break;
			case '3':
				strcpy(carro, "Onix");
				break;
		}
		confirmaCarro = confirmaEscolha(carro);
		if (confirmaCarro == 'S') {
			strcpy(modelo, carro);
		}
	} while (confirmaCarro == 'N');
}
		
	
char conFord (char *modelo){
	char opcao, carro[5], confirmaCarro;
	
	do {
		do {
			system ("cls");
			printf("\n- - - V E I C U L O S    F I A T - - - \n");
			printf("\n1) Ka");
			printf("\n2) Ranger");
			printf("\n3) Fusion");
			printf("\n\nEscolha o seu carro: ");
			opcao = getchar();
			fflush(stdin);
		} while (opcao != '1' && opcao != '2' && opcao != '3');
		switch (opcao) {
			case '1':
				strcpy(carro, "Ka");
				break;
			case '2':
				strcpy(carro, "Ranger");
				break;
			case '3':
				strcpy(carro, "Fusion");
				break;
		}
		confirmaCarro = confirmaEscolha(carro);
		if (confirmaCarro == 'S') {
			strcpy(modelo, carro);
		}
	} while (confirmaCarro == 'N');
}

char confirmaEscolha (char palavra[]) {
	char confirma;
	
	do {
		printf("Voce escolheu: %s\nConfirma? (S/N): ", palavra);
		confirma = getchar();
		fflush(stdin);
		confirma = toupper(confirma);
	} while (confirma != 'S' && confirma != 'N');
	return confirma;
}
