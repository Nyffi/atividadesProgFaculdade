// Síntese
// Objetivo: "Calcular bonus para 150 clientes - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Banco banco = new Banco();
		int qntCli = 150;
		
		while (qntCli > 0) {
			System.out.print("Digite o nome do cliente: ");
			banco.nomeCli = scanner.next();
			
			if (banco.nomeCli.equals("fim")) break;
			
			System.out.print("Digite o valor total das compras: R$");
			banco.dinheiro = scanner.nextFloat();
			banco.dinheiro = banco.calculaBonus(banco.dinheiro);
			
			
			System.out.println("O valor do bônus é de R$" + banco.dinheiro);
			qntCli--;
		}
		
		scanner.close();
	}

}
