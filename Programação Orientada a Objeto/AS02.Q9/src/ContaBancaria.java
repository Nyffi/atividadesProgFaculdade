
public class ContaBancaria {
	float bal;
	
	public float calcula10Mil (float bal) {
		int meses = 0;
		
		while (bal < 10000.0f) {
			System.out.println("Valor = " + bal);
			bal = bal + (bal * 0.015f);
			meses++;
		}
		
		return meses;
	}
}
