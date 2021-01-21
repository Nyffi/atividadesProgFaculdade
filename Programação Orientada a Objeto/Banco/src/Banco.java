import java.util.ArrayList;

public class Banco {
	private String nome;
	private int codigo;
	private ArrayList<Conta> contas = new ArrayList<Conta>();
	
	Banco(String nome, int codigo) {
		this.setNome(nome);
		this.setCodigo(codigo);
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public int getCodigo() {
		return this.codigo;
	}
	
	public void setNome(String nome) {
		if (nome.length() > 0) {
			this.nome = nome;
		}
	}
	
	public void setCodigo(int cod) {
		if (cod > 0 && cod < 1000) {
			this.codigo = cod;
		}
	}
	
	public ArrayList<Conta> getContas() {
		return this.contas;
	}
}
