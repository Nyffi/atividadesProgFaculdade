// Síntese
// Objetivo: "Determinar se a velocidade do carro está acima ou abaixo do limite - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Veiculo veiculo;
		
		System.out.print("Digite a velocidade do veículo (km/h): ");
		int vel = scanner.nextInt();
		
		veiculo = new Veiculo(vel);
		
		scanner.close();
	}

}
