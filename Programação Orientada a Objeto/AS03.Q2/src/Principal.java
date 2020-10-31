// Síntese
// Objetivo: "Implementar um programa em Java que simule um estádio de futebol com 15 entradas que devem fechar quando atingido a capacidade máxima"
// Autor: Paulo César de Lima Rocha
// Data: 29/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Catraca catraca[] = new Catraca[15];
		int i, escolha;
		int limiteEstadio = 5;
		inicializarVetor (catraca);
		
		while (catraca[0].getAberto()) {
			System.out.println("Estádio Mineirão - ENTRADAS");
			System.out.println("");
			for (i = 0; i < 15; i++) {
				System.out.println("Entrada "+ (i+1) + " - " + catraca[i].getQuantia() + " pessoas");
			}
			System.out.println("");
			System.out.print("Digite a entrada desejada: ");
			escolha = scanner.nextInt();
			
			catraca[escolha-1].addQuantia(1);
			verificaLotacao(limiteEstadio, catraca);
		}		
		System.out.println("");
		System.out.println("O estádio está lotado com " + limiteEstadio + " pessoas.");
		scanner.close();
	}
	
	private static void inicializarVetor (Catraca catraca[]) {
		int i;
		
		for (i = 0; i < 15; i++) {
			catraca[i] = new Catraca();
		}
	}
	
	private static void verificaLotacao (int qntMax, Catraca catraca[]) {
		int total, i;
		
		total = 0;
		
		for (i = 0; i < 15; i++) {
			total += catraca[i].getQuantia();
		}
		
		if (total == qntMax) {
			for (i = 0; i < 15; i++) {
				catraca[i].fecharCatraca();
			}
		}
	}
}
