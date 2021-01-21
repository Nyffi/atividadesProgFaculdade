
public class Cliente {
	private String nome;
	private String cpf;
	
	public String getNome() {
		return this.nome;
	}
	
	public String getCPF() {
		return this.cpf;
	}
	
	public void setNome () {
		String nome;
		
		do {
			nome = View.solicitarString("Digite o nome do propriet�rio: ");
			
			if(nome.length() == 0) {
				View.exibirErro("O nome n�o pode ser vazio.");
			}
		} while (nome.length() == 0);
		
		this.nome = nome;
	}
	
	public void setCPF() {
		String cpf;
		
		do {
			cpf = View.solicitarString("Digite o CPF do propriet�rio: ");
		} while (!Utils.validaCPF(cpf));
		
		this.cpf = cpf;
	}
}
