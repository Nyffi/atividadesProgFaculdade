// Síntese
// Objetivo: "Calcular quanto tempo pro valor alcançar 10 mil - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ContaBancaria contabancaria = new ContaBancaria();
		
		System.out.print("Digite o valor do depósito: R$");
		contabancaria.bal = scanner.nextFloat();
		
		System.out.println("Para alcançar o valor de R$10.000,00 será necessário aguardar " + contabancaria.calcula10Mil(contabancaria.bal) + " meses.");
		scanner.close();
	}

}
