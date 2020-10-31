
public class Banco {
	String nomeCli;
	float dinheiro;
	
	public float calculaBonus (float dinheiro) {
		
		if (dinheiro >= 500000.00f) {
			dinheiro = dinheiro * 1.15f;
		} else {
			dinheiro = dinheiro * 1.1f;
		}
		
		return dinheiro;
	}
}
