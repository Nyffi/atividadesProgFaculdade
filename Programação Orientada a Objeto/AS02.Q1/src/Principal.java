// Síntese
// Objetivo: "Converter Celsius para Fahrenheit - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Termometro termometro;
		
		System.out.print("Digite o valor Celsius: ");
		float temp = scanner.nextFloat();
		termometro = new Termometro(temp);
		termometro.celsius = temp;
		
		System.out.println(termometro.celsius + "°C -> " + termometro.fahrenheit + "°F");
		scanner.close();
	}

}
