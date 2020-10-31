// Síntese
// Objetivo: "Determinar se valor é positivo, negativo ou zero"
// Autor: Paulo César de Lima Rocha
// Data: 13/08/2020

package q8;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o valor: ");
		int num = scanner.nextInt();
		String res;
		
		if (num == 0) {
			res = "zero.";
		} else if (num > 0) {
			res = "positivo.";
		} else {
			res = "negativo.";
		}
		
		System.out.print("O valor é " + res);
		scanner.close();
	}

}
