// S�ntese
// Objetivo: "Calcular valor da gasolina"
// Autor: Paulo C�sar de Lima Rocha
// Data: 13/08/2020

package q4;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o valor do litro de gasolina: R$");
		float preco = scanner.nextFloat();
		System.out.print("Digite quantos litros deseja: ");
		float gasosa = scanner.nextFloat();
		
		float valorFinal = preco * gasosa;
			
		System.out.println("O pre�o � de R$" + valorFinal);
		scanner.close();
	}

}
