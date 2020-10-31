
public class Numero {
	int val;
	
	public String avaliaNum (int num) {
		if (num == 0) {
			return "zero.";
		} else if (num > 0) {
			return "positivo.";
		} else {
			return "negativo.";
		}
	}
}
