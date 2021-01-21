
public class Funcionario {
	private String senha;
	private boolean acessoAgencia;
	private boolean acessoCaixa;
	private boolean acessoCofre;
	private boolean acessoArquivo;
	
	public Funcionario() {
		this.senha = "1234";
		this.acessoAgencia = true;
		this.acessoCaixa = true;
		this.acessoCofre = true;
		this.acessoArquivo = false;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}

	public boolean isAcessoAgencia() {
		return acessoAgencia;
	}

	public void setAcessoAgencia(boolean acessoAgencia) {
		this.acessoAgencia = acessoAgencia;
	}

	public boolean isAcessoCaixa() {
		return acessoCaixa;
	}

	public void setAcessoCaixa(boolean acessoCaixa) {
		this.acessoCaixa = acessoCaixa;
	}

	public boolean isAcessoCofre() {
		return acessoCofre;
	}

	public void setAcessoCofre(boolean acessoCofre) {
		this.acessoCofre = acessoCofre;
	}

	public boolean isAcessoArquivo() {
		return acessoArquivo;
	}

	public void setAcessoArquivo(boolean acessoArquivo) {
		this.acessoArquivo = acessoArquivo;
	}
}
