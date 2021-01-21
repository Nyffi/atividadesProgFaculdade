
public class Login {
	private String email = null;
	private String senha = null;
	
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {		
		if (email.length() >= 7 && Utils.validaEmail(email))
			this.email = email;
		else
			throw new IllegalArgumentException("[Login] Email inválido.");
	}
	public String getSenha() {
		return senha;
	}
	public void setSenha(String senha) {
		if (senha.length() >= 6)
			this.senha = Utils.encriptaSenha(senha);
		else
			throw new IllegalArgumentException("[Login] A senha é muito curta.");
	}
}
