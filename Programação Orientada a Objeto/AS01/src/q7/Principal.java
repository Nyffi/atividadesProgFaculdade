// S�ntese
// Objetivo: "Determinar se a velocidade do carro est� acima ou abaixo do limite"
// Autor: Paulo C�sar de Lima Rocha
// Data: 13/08/2020

package q7;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite a velocidade do ve�culo (km/h): ");
		int vel = scanner.nextInt();
		
		if (vel > 80) {
			System.out.print("O USU�RIO ULTRAPASSOU A VELOCIDADE M�XIMA E SER� MULTADO");
		} else {
			System.out.print("O USU�RIO EST� DENTRO DO LIMITE M�XIMO DE VELOCIDADE.");
		}
		
		
		scanner.close();
	}

}
