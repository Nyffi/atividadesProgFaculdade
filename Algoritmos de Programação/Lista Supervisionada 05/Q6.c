/*
	Objetivo:	Fazer um programa que escreva uma tabela de valores do lucro esperado em função do preço do ingresso, fazendo-o variar de R$15,00 a R$3,00 de 3 em 3 reais. Escrever, ainda, o lucro máximo esperado, o preço e o número de ingressos correspondentes.
	Entrada:	Nada.
	Saída:		Valores de lucro esperado em função do preço do ingresso, lucro máximo esperado, o preço e o número de ingressos correspondentes.
*/

#include <stdio.h>
#include <stdlib.h>

main() {
	int ingresso = 120, ingLucro;
	float despesa = 600.00, lucro = 0.00, arrecadado = 0.00, preco = 15.00, maiorLucro, precoIngLucro;

	printf("-----------------------------------------------------------------------------\n");
	printf("%s\t%s\t%s\t%s\n", "Valor do Ingresso", "Ing. Vendidos", "Valor arrecadado", "Lucros");
	printf("-----------------------------------------------------------------------------\n");
	for ( ; preco >= 3; preco = preco - 3) {
		arrecadado = ingresso * preco;
		lucro = arrecadado - despesa;
		if (lucro > maiorLucro) {
			maiorLucro = lucro;
			ingLucro = ingresso;
			precoIngLucro = preco;
		}
		if (preco > 10){
			printf("R$ %.2f\t\t", preco);
			printf("%d Un.\t\t", ingresso);
			printf("R$ %.2f\t\t", arrecadado);
			printf("R$ %.2f \n", lucro);
		} else {
			printf("R$ %.2f\t\t\t", preco);
			printf("%d Un.\t\t", ingresso);
			printf("R$ %.2f\t\t", arrecadado);
			printf("R$ %.2f \n", lucro);
		}
		
		ingresso = ingresso + 26;
	}
	printf("-----------------------------------------------------------------------------\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("Maior lucro esperado: R$ %.2f \n", maiorLucro);
	printf("Valor de ingresso mais lucrativo: R$ %.2f \n", precoIngLucro);
	printf("Quantidade de ingresso mais lucrativo: %d Un. \n", ingLucro);
	printf("-----------------------------------------------------------------------------\n");

	return 0;
}

