// S�ntese
// Objetivo: "Determinar se a velocidade do carro est� acima ou abaixo do limite - Abstra��o"
// Autor: Paulo C�sar de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Veiculo veiculo;
		
		System.out.print("Digite a velocidade do ve�culo (km/h): ");
		int vel = scanner.nextInt();
		
		veiculo = new Veiculo(vel);
		
		scanner.close();
	}

}
