// Síntese
// Objetivo: "Determinar se valor é positivo, negativo ou zero - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Numero numero = new Numero();
		
		System.out.print("Digite o valor: ");
		numero.val = scanner.nextInt();
		String res = numero.avaliaNum(numero.val);
		
		System.out.print("O valor é " + res);
		scanner.close();
	}

}
