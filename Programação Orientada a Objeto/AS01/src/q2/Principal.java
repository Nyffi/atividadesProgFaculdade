// Síntese
// Objetivo: "Aplicar desconto de 10% no valor de uma mercadoria"
// Autor: Paulo César de Lima Rocha
// Data: 17/08/2020

package q2;

import java.util.Scanner;

public class Principal {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
			
		System.out.print("Digite o valor da mercadoria: R$");
		float preco = scanner.nextFloat();
		float valDesc = preco - (preco * 0.10f);
			
		System.out.println("A vista, o valor com desconto é de R$" + valDesc);
		scanner.close();
	}
}
