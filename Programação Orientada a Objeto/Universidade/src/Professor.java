
public class Professor {
	private String nome;
	private int id;
	
	Professor (String nome) throws IllegalArgumentException {
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
			throw new IllegalArgumentException("[Professor] Nome inválido.");
		}
	}
	
	public void setID() {
		id = Utils.gerarID(1, 99999);
	}
	
	public String getNome() {
		return nome;
	}
	
	public int getID() {
		return id;
	}
}
