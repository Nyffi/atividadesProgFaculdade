
public class Maca {
	float val = 1.3f;
	
	Maca(int qnt) {
		if (qnt >= 12) {
			this.val = 1.0f;
		}
	}
	
	public float calculaPrecoFinal (int qnt, float val) {
		return val * qnt;
	}
}
