
public class Mercadoria {
	float valor;
	float descVista;
	float valorVista;
	
	Mercadoria(float valor) {
		this.valor = valor;
	}
	
	public void calcularDesconto() {
		descVista = this.valor * 0.1f;
		valorVista = this.valor + this.descVista;
	}
}
