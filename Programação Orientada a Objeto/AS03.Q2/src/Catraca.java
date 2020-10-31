
public class Catraca {
	private int qntPessoas = 0;
	private boolean aberto = true;
	
	public void addQuantia (int qnt) {
		this.qntPessoas += qnt;
	}
	
	public void fecharCatraca () {
		this.aberto = false;
	}
	
	public int getQuantia () {
		return this.qntPessoas;
	}
	
	public boolean getAberto () {
		return this.aberto;
	}
	
}
