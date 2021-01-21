
public class Aluno {
	private String nome;
	private int id;
	
	Aluno (String nome) throws IllegalArgumentException {
		try {
			setNome(nome);
			setID();
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException(e.getMessage());
		}
	}
	
	public void setNome (String nome) {
		if (nome.length() > 2) {
			this.nome = nome;
		} else {
			throw new IllegalArgumentException("[Aluno] Nome inválido.");
		}
	}
	
	public void setID() {
		id = Utils.gerarID(10000000, 99999999);
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getID() {
		return id;
	}
}
