public class Urna {
	private int num;
	private String candidato;
	private int qntVotos = 0;
	
	public void setNumero (int val) {
		this.num = val;
	}
	
	public int getNumero () {
		return this.num;
	}
	
	public void setCandidato (String nome) {
		this.candidato = nome;
	}
	
	public String getCandidato () {
		return this.candidato;
	}
	
	public int getVotos () {
		return this.qntVotos;
	}
	
	public void atualizaVoto () {
		this.qntVotos++;
	}
}
