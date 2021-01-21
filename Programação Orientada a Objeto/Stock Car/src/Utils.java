import java.util.ArrayList;
import java.util.Random;

public class Utils {
	public static int randomInRangeInt (int menor, int maior) {
		Random r = new Random();
		int result = r.nextInt(maior - menor) + menor;
		return result;
	}
	
	public static void exibirPilotos (ArrayList<Piloto> pilotos) {
		String cabecalho = "Lista de Pilotos \n\nIndex - Nome - Tipo Sangu�neo\n", msg = "";
		int index = 0;
		
		if (pilotos.size() == 0) {
			View.exibirErro("[Campeonato] N�o h� pilotos cadastrados.");
			return;
		}
		
		for (Piloto piloto : pilotos) {
			msg = msg + index + " - " + piloto.getNome() + " - " + piloto.getTipoSangue() + "\n";
			index++;
		}
		
		View.exibirMsg(cabecalho + msg);
	}
	
	public static void resultadoCorrida (Campeonato campeonato) {
		String cabecalho = "Resultado da Corrida \n\nPosi��o - Nome - Tempo\n", msg = "";
		Volta voltaMaisRapida;
		int index = 0;
		
		voltaMaisRapida = campeonato.concluirCorrida();
		
		for (Piloto piloto : campeonato.getPilotos()) {
			msg = msg + (index + 1) + " - " + piloto.getNome() + " - " + piloto.getTempoCorrida() + "s \n";
			index++;
		}
		
		msg = msg + "\n Volta mais r�pida: " + voltaMaisRapida.getTempoMaisRapido() + "s - " + voltaMaisRapida.getPilotoMaisRapido().getNome();
		View.exibirMsg(cabecalho + msg);
	}
	
	public static void resultadoCampeonato (Campeonato campeonato) {
		String cabecalho = "Resultado do Campeonato de Stock Car Brasil \n\nPosi��o - Nome - Pontua��o\n", msg = "";
		int index = 0;
		
		campeonato.ordernarPontuacao();
		
		for (Piloto piloto : campeonato.getPilotos()) {
			msg = msg + (index + 1) + " - " + piloto.getNome() + " - " + piloto.getPontuacao() + " pontos \n";
			index++;
		}
		
		View.exibirMsg(cabecalho + msg);
	}
}
