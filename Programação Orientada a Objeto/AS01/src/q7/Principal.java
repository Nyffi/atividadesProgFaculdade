// Síntese
// Objetivo: "Determinar se a velocidade do carro está acima ou abaixo do limite"
// Autor: Paulo César de Lima Rocha
// Data: 13/08/2020

package q7;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite a velocidade do veículo (km/h): ");
		int vel = scanner.nextInt();
		
		if (vel > 80) {
			System.out.print("O USUÁRIO ULTRAPASSOU A VELOCIDADE MÁXIMA E SERÁ MULTADO");
		} else {
			System.out.print("O USUÁRIO ESTÁ DENTRO DO LIMITE MÁXIMO DE VELOCIDADE.");
		}
		
		
		scanner.close();
	}

}
