// S�ntese
// Objetivo: "Calcular troco"
// Autor: Paulo C�sar de Lima Rocha
// Data: 13/08/2020

package q3;

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("Digite o valor da mercadoria: R$");
		float preco = scanner.nextFloat();
		System.out.print("Digite o valor pago pelo cliente: R$");
		float pagamento = scanner.nextFloat();
		if (pagamento > preco) {
			float troco = pagamento - preco;
			System.out.println("O troco � de R$" + troco);
		} else {
			System.out.println("N�o h� troco ou o valor � insuficiente.");
		}
		scanner.close();
	}

}
