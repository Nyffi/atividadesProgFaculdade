// S�ntese
// Objetivo: "Calcular quanto tempo pro valor alcan�ar 10 mil"
// Autor: Paulo C�sar de Lima Rocha
// Data: 13/08/2020

package q9;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int meses = 0;
		
		System.out.print("Digite o valor do dep�sito: R$");
		float bal = scanner.nextFloat();
		
		while (bal < 10000.0f) {
			System.out.println("Valor = " + bal);
			bal = bal + (bal * 0.015f);
			meses++;
		}
		
		System.out.println("Para alcan�ar o valor de R$10.000,00 ser� necess�rio aguardar " + meses + " meses.");
		scanner.close();
	}

}
