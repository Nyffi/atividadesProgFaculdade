// Síntese
// Objetivo: "Receber o voto de cada eleitor e ao final apresentar o nome do vitorioso e o percentual de votos de cada candidato."
// Autor: Paulo César de Lima Rocha
// Data: 29/08/2020

import java.util.Scanner;

public class Principal {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Urna urna[] = new Urna[2];
		urna[0] = new Urna();
		urna[1] = new Urna();
		boolean fim = false;
		
		inicializar(urna);
		
		do {
			System.out.println("Urna Eletrônica - Votação");
			System.out.println("");
			System.out.println(urna[0].getNumero() + " - " + urna[0].getCandidato());
			System.out.println(urna[1].getNumero() + " - " + urna[1].getCandidato());
			System.out.println("");
			System.out.println("Vote 0 para terminar a eleição.");
			System.out.println("");
			
			int voto = scanner.nextInt();
			
			if (voto == urna[0].getNumero()) {
				urna[0].atualizaVoto();
			} else if (voto == urna[1].getNumero()) {
				urna[1].atualizaVoto();
			} else if (voto == 0) {
				fim = true;
			}
			System.out.flush();
		} while (!fim);
		
		exibirRes(urna);
		
		scanner.close();
	}
	
	private static void inicializar(Urna[] urna) {
		urna[0].setNumero(11);
		urna[0].setCandidato("Nicolás Maduro");
		urna[1].setNumero(23);
		urna[1].setCandidato("Juan Guaidó");
	}
	
	private static void exibirRes(Urna[] urna) {
		int total = urna[0].getVotos() + urna[1].getVotos();
		int vencedor, perdedor;
		double pctgVit, pctgPer;
		
		System.out.println("Urna Eletrônica - Resultados");
		System.out.println("");
		System.out.println(urna[0].getCandidato() + " = " + urna[0].getVotos());
		System.out.println(urna[1].getCandidato() + " = " + urna[1].getVotos());
		System.out.println("");
		System.out.println("Total de votos: " + total);
		
		if (urna[0].getVotos() > urna[1].getVotos()) {
			vencedor = 0;
			perdedor = 1;
		} else {
			vencedor = 1;
			perdedor = 0;
		}
		
		if (total == 0) {
			System.out.println("Não houve votos.");
			return;
		}
		
		pctgVit = Math.ceil((double) (urna[vencedor].getVotos() / (double) total) * 100.0);
		pctgPer = Math.ceil((double) (urna[perdedor].getVotos() / (double) total) * 100.0);
		
		if (urna[0].getVotos() == urna[1].getVotos()) {
			System.out.println("Houve um empate.");
		} else {
			System.out.println(urna[vencedor].getCandidato() + " venceu com " + pctgVit + "% dos votos.");
			System.out.println(urna[perdedor].getCandidato() + " obteve " + pctgPer + "% dos votos.");
		}
		
	}
}
