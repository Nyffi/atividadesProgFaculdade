// Síntese
// Objetivo: "Calcular bonus para 150 clientes"
// Autor: Paulo César de Lima Rocha
// Data: 13/08/2020

package q10;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int qntCli = 150;
		
		while (qntCli > 0) {
			System.out.print("Digite o nome do cliente: ");
			String cli = scanner.next();
			
			if (cli.equals("fim")) break;
			
			System.out.print("Digite o valor total das compras: R$");
			float bal = scanner.nextFloat();
			
			if (bal >= 500000.00f) {
				bal = bal * 1.15f;
			} else {
				bal = bal * 1.1f;
			}
			
			System.out.println("O valor do bônus é de R$" + bal);
			qntCli--;
		}
		
		scanner.close();
	}

}
