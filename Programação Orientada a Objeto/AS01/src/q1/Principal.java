// Síntese
// Objetivo: "Converter Celsius para Fahrenheit"
// Autor: Paulo César de Lima Rocha
// Data: 13/08/2020

package q1;

import java.util.Scanner;

public class Principal {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o valor Celsius: ");
		float celsius = scanner.nextFloat();
		float fahrenheit = ((celsius * 9) / 5) + 32;
		
		System.out.println(celsius + "°C -> " + fahrenheit + "°F");
		scanner.close();
	}
}