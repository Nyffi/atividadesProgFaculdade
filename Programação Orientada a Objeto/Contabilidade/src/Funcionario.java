
public abstract class Funcionario {
	private String cpf;
	private String nome;
	private String senha;
	
	public String getSenha() {
		return senha;
	}
	public void setSenha(String senha) {
		if (senha.length() > 3)
			this.senha = senha;
		else
			throw new IllegalArgumentException("[Cliente] Senha insuficiente. Insira uma senha maior que 4 dígitos.");
	}
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		if (Utils.validaCPF(cpf))
			cpf = Utils.removeSimbolo(cpf);
			this.cpf = cpf;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		if (nome.length() > 4)
			this.nome = nome;
	}
	
}
