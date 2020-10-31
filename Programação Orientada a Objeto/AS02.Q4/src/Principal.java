// S�ntese
// Objetivo: "Calcular valor da gasolina - Abstra��o"
// Autor: Paulo C�sar de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Gasolina gasolina = new Gasolina();
		
		System.out.print("Digite o valor do litro de gasolina: R$");
		gasolina.preco = scanner.nextFloat();
		System.out.print("Digite quantos litros deseja: ");
		gasolina.litros = scanner.nextFloat();
		
		float gasosa = gasolina.valorFinal(gasolina.preco, gasolina.litros);
			
		System.out.println("O pre�o � de R$" + gasosa);
		scanner.close();
	}

}
