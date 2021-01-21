
public class Animal {
	private String nome;
	private String som;
	private String desc;
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		if (nome.length() > 3) {
			this.nome = nome;
		} else {
			throw new IllegalArgumentException("O nome do animal � inv�lido.");
		}
		
	}
	
	public String getSom() {
		return som;
	}
	
	public void setSom(String som) {
		if (som.length() >= 2) {
			this.som = som;
		} else {
			throw new IllegalArgumentException("O som do animal � inv�lido.");
		}
		
	}
	
	public String getDesc() {
		return desc;
	}
	
	public void setDesc(String desc) {
		if (desc.length() >= 10) {
			this.desc = desc;
		} else {
			throw new IllegalArgumentException("A descri��o do animal � inv�lida.");
		}
	}
	
}
