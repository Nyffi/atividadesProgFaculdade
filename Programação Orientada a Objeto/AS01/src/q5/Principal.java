// S�ntese
// Objetivo: "Ver se um numero � par ou impar"
// Autor: Paulo C�sar de Lima Rocha
// Data: 13/08/2020

package q5;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o n�mero: ");
		int preco = scanner.nextInt();
		
		if (preco % 2 == 0) {
			System.out.println("O n�mero � par.");
		} else {
			System.out.println("O n�mero � �mpar.");
		}
		
		scanner.close();
	}

}
