
public class Pagamento {
	float valProd;
	float valPag;
	
	public float calculaTroco (float valProd, float valPag) {
		if (valProd < valPag)
			return valPag - valProd;
		else
			return 0;
	}
}
