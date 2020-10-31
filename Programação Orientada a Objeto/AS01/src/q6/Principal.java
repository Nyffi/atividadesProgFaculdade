// Síntese
// Objetivo: "Calcular valor total da compra"
// Autor: Paulo César de Lima Rocha
// Data: 13/08/2020

package q6;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite a quantia de maçãs: ");
		int qntMaca = scanner.nextInt();
		float valor = 1.3f;
		
		if (qntMaca >= 12) 
			valor = 1.0f;
		
		float preco = qntMaca * valor;
		
		System.out.print("O preço a ser pago é de R$" + preco);
		scanner.close();
	}

}
