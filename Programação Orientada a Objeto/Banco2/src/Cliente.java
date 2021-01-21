
public class Cliente {
	private String senha = "1234";
	private boolean acessoAgencia = true;
	
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
}
