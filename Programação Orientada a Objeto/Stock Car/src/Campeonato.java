import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Campeonato {
	private ArrayList<Piloto> pilotos = new ArrayList<Piloto>();
	private ArrayList<Corrida> corridas = new ArrayList<Corrida>();
	
	Campeonato () {
		Corrida corrida;
		
		while (corridas.size() < 5) {
			corrida = new Corrida(Utils.randomInRangeInt(1, 3));
			corrida.configCorrida();
			this.corridas.add(corrida);
		}
	}
	
	public ArrayList<Corrida> getCorridas () {
		return this.corridas;
	}
	
	public ArrayList<Piloto> getPilotos () {
		return this.pilotos;
	}
	
	public void adicionarPiloto() {
		Piloto temp = new Piloto();
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do piloto: "));
			temp.setTipoSangue(View.solicitarString("Digite o tipo sanguíneo do piloto: "));
			pilotos.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro("[Campeonato] Não foi possível adicionar o piloto. Tente novamente.");
		}
	}
	
	public void removerPiloto() {
		try {
			pilotos.remove(View.solicitarInt("Digite o index do piloto:"));
			View.exibirMsg("[Campeonato] Piloto removido com sucesso.");
		} catch (IndexOutOfBoundsException e) {
			View.exibirErro("[Campeonato] Esse Piloto não existe.");
		}
	}
	
	public void iniciarCorrida() {
		if (pilotos.size() < 5) {
			throw new IllegalArgumentException("[Campeonato] É necessário no mínimo 5 competidores para iniciar o campeonato.");
		}
		
		for (Piloto piloto : pilotos) {
			piloto.setTempoCorrida(true, 0);
		}
	}
	
	public void ordernarPontuacao() {
		Collections.sort(pilotos, new Comparator<Piloto>() {
			public int compare(Piloto p1, Piloto p2) {
				if (p1.getPontuacao() < p2.getPontuacao()) {
					return 1;
				} else if (p2.getPontuacao() < p1.getPontuacao()) {
					return -1;
				}
				return 0;
			}
		});
	}
	
	public void ordernarChegada() {
		Collections.sort(pilotos, new Comparator<Piloto>() {
			public int compare(Piloto p1, Piloto p2) {
				if (p1.getTempoCorrida() > p2.getTempoCorrida()) {
					return 1;
				} else if (p2.getTempoCorrida() > p1.getTempoCorrida()) {
					return -1;
				}
				return 0;
			}
		});
	}
	
	public Volta concluirCorrida() {		
		int aux = 0;
		ArrayList<Volta> voltas = this.corridas.get(0).getVoltas();
		Volta vMR;
		
		for (Volta volta : voltas) {
			for (Piloto piloto : pilotos) {
				piloto.setTempoCorrida(false, corridas.get(0).getTempoMedioVolta());
				volta.setTempoMaisRapido(piloto.getTempoVolta(), piloto);
			}
		}
		
		corridas.get(0).ordenarVoltaMaisRapida();
		
		this.ordernarChegada();
		
		for (Piloto piloto : pilotos) {
			piloto.setPontuacao(pilotos.size() - aux);
			aux++;
		}
		
		//this.ordernarPontuacao();
		
		vMR = corridas.get(0).getVoltaMaisRapida();
		corridas.remove(0);
		return vMR;
	}
}
