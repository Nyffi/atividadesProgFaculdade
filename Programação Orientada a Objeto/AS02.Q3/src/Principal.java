// Síntese
// Objetivo: "Calcular troco - Abstração"
// Autor: Paulo César de Lima Rocha
// Data: 23/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Pagamento pagamento = new Pagamento();
		
		System.out.print("Digite o valor da mercadoria: R$");
		pagamento.valProd = scanner.nextFloat();
		System.out.print("Digite o valor pago pelo cliente: R$");
		pagamento.valPag = scanner.nextFloat();
		
		float troco = pagamento.calculaTroco(pagamento.valProd, pagamento.valPag);
		
		if (troco > 0) {
			System.out.println("O troco é de R$" + troco);
		} else {
			System.out.println("Não há troco ou o valor é insuficiente.");
		}
		scanner.close();
	}

}
