// S�ntese
// Objetivo: "Calcular quanto tempo pro valor alcan�ar 10 mil - Abstra��o"
// Autor: Paulo C�sar de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ContaBancaria contabancaria = new ContaBancaria();
		
		System.out.print("Digite o valor do dep�sito: R$");
		contabancaria.bal = scanner.nextFloat();
		
		System.out.println("Para alcan�ar o valor de R$10.000,00 ser� necess�rio aguardar " + contabancaria.calcula10Mil(contabancaria.bal) + " meses.");
		scanner.close();
	}

}
