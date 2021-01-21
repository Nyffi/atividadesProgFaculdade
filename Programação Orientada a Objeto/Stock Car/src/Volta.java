
public class Volta {
	private int tempoMaisRapido;
	private Piloto pilotoMaisRapido = null;

	public int getTempoMaisRapido() {
		return tempoMaisRapido;
	}
	
	public Piloto getPilotoMaisRapido() {
		return pilotoMaisRapido;
	}

	public void setTempoMaisRapido(int tempo, Piloto piloto) {
		if (tempo < tempoMaisRapido || pilotoMaisRapido == null) {
			this.tempoMaisRapido = tempo;
			pilotoMaisRapido = piloto;
		}
	}
}
