import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Corrida {
	private ArrayList<Volta> voltas = new ArrayList<Volta>();
	private Volta voltaMaisRapida;
	private int tempoMedioVolta;
	
	Corrida(int i) {
		switch (i) {
			case 1:
				this.tempoMedioVolta = 300;
				break;
			case 2:
				this.tempoMedioVolta = 550;
				break;
			case 3:
				this.tempoMedioVolta = 650;
				break;
			default:
				throw new IllegalArgumentException("[Volta] Houve um erro. Tente novamente.");
		}
	}
	
	public void configCorrida() {
		Volta temp;
		
		if (voltas.size() >= 3) {
			throw new IllegalArgumentException("[Corrida] Cada corrida deve ter apenas 3 voltas.");
		}
		
		while (voltas.size() < 3) {
			temp = new Volta();
			voltas.add(temp);
		}
	}
	
	public int getTempoMedioVolta() {
		return this.tempoMedioVolta;
	}
	
	public ArrayList<Volta> getVoltas() {
		return this.voltas;
	}
	
	public void ordenarVoltaMaisRapida() {
		Collections.sort(voltas, new Comparator<Volta>() {
			public int compare(Volta v1, Volta v2) {
				if (v1.getTempoMaisRapido() < v2.getTempoMaisRapido()) {
					return 1;
				} else if (v2.getTempoMaisRapido() < v1.getTempoMaisRapido()) {
					return -1;
				}
				return 0;
			}
		});
		
		this.voltaMaisRapida = voltas.get(0);
	}
	
	public Volta getVoltaMaisRapida() {
		return this.voltaMaisRapida;
	}
}
