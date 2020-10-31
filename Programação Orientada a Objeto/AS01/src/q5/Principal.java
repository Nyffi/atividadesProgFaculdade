// Síntese
// Objetivo: "Ver se um numero é par ou impar"
// Autor: Paulo César de Lima Rocha
// Data: 13/08/2020

package q5;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o número: ");
		int preco = scanner.nextInt();
		
		if (preco % 2 == 0) {
			System.out.println("O número é par.");
		} else {
			System.out.println("O número é ímpar.");
		}
		
		scanner.close();
	}

}
