// S�ntese
// Objetivo: "Calcular valor total da compra - Abstra��o"
// Autor: Paulo C�sar de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Maca maca;
		
		System.out.print("Digite a quantia de ma��s: ");
		int qntMaca = scanner.nextInt();
		maca = new Maca(qntMaca);
		
		float valFinal = maca.calculaPrecoFinal(qntMaca, maca.val);
		System.out.print("O pre�o a ser pago � de R$" + valFinal);
		scanner.close();
	}

}
