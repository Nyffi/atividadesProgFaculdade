// S�ntese
// Objetivo: "Ver se um numero � par ou impar - Abstra��o"
// Autor: Paulo C�sar de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Numero numero;
		
		System.out.print("Digite o n�mero: ");
		int val = scanner.nextInt();
		numero = new Numero(val);
		
		scanner.close();
	}

}
