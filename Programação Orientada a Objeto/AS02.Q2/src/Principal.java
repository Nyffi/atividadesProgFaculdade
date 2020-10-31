// Síntese
// Objetivo: "Aplicar desconto de 10% no valor de uma mercadoria - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Mercadoria mercadoria;
		
		System.out.print("Digite o valor da mercadoria: R$");
		float preco = scanner.nextFloat();
		mercadoria = new Mercadoria(preco);
		mercadoria.calcularDesconto();
			
		System.out.println("- - Produto - -");
		System.out.println("Valor base: R$" + mercadoria.valor);
		System.out.println("Desconto à vista: R$" + mercadoria.descVista);
		System.out.println("Valor descontado: R$" + mercadoria.valorVista);
		scanner.close();
	}

}
