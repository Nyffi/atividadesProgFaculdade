// Síntese
// Objetivo: "Calcular valor total da compra - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Maca maca;
		
		System.out.print("Digite a quantia de maçãs: ");
		int qntMaca = scanner.nextInt();
		maca = new Maca(qntMaca);
		
		float valFinal = maca.calculaPrecoFinal(qntMaca, maca.val);
		System.out.print("O preço a ser pago é de R$" + valFinal);
		scanner.close();
	}

}
