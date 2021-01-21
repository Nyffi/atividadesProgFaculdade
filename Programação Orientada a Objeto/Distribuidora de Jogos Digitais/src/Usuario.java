import java.util.ArrayList;

public class Usuario {
	
	private String email;
	private String apelido;
	private String senha;
	private ArrayList<Jogo> jogosComprados = new ArrayList<Jogo>();
	private double saldo = 0.0d;
	private boolean isAdmin = false;

	public String getApelido() {
		return this.apelido;
	}

	public void setApelido(String apelido) {
		if (apelido.length() >= 2)
			this.apelido = apelido;
		else
			throw new IllegalArgumentException("[Usu�rio] O apelido � muito curto.");
	}
	
	public String getEmail() {
		return this.email;
	}

	public void setEmail(String email) {		
		if (email.length() >= 7 && Utils.validaEmail(email))
			this.email = email;
		else
			throw new IllegalArgumentException("[Usu�rio] Email inv�lido.");
		
	}

	public String getSenha() {
		return this.senha;
	}

	public void setSenha(String senha) {
		if (senha.length() >= 6)
			this.senha = Utils.encriptaSenha(senha);
		else
			throw new IllegalArgumentException("[Usu�rio] A senha � muito curta.");
	}

	public void addJogo(Jogo jogo) {
		this.jogosComprados.add(jogo);
	}

	public ArrayList<Jogo> getJogosComprados() {
		return this.jogosComprados;
	}

	public boolean getAdmin() {
		return this.isAdmin;
	}

	public void setAdmin() {
		this.isAdmin = !this.isAdmin;
	}
	
	public double getSaldo() {
		return this.saldo;
	}
	
	public void atualizaSaldo(double val, boolean compra) {
		if (val > 0) {
			if (compra) {		//A vari�vel compra serve pra definir se essa fun��o est� sendo usada numa compra (redu��o de saldo) ou num dep�sito (adi��o de saldo)
				this.saldo -= val;
				View.exibirMsg("[Usu�rio] A compra foi executada com sucesso.");
			} else {
				this.saldo += val;
				View.exibirMsg("[Usu�rio] O valor foi adicionado ao saldo com sucesso.");
			}
		} else {
			throw new IllegalArgumentException("[Usu�rio] N�o p�de ser feita a atualiza��o do saldo.");
		}
	}
	
	public void comprarJogo(String nomeJogo, ArrayList<Publicadora> publicadoras) {
		for (Publicadora publicadora : publicadoras) {
			for (Jogo jogo : publicadora.getJogos()) {
				if (jogo.getNome().compareTo(nomeJogo) == 0) {
					if (View.solicitarBoolean("Jogo: " + jogo.getNome() //Mostra as informa��es do jogo a ser comprado e confirma se o usu�rio quer comprar
					+ "\nDescri��o: " + jogo.getDesc() 
					+ "\nPre�o: R$" + jogo.getPreco() 
					+ "\n\nSeu saldo: R$" + this.getSaldo() 
					+ "\n\nDeseja comprar o jogo selecionado?")) {
						if (this.saldo >= jogo.getPreco()) {
							try {
								this.atualizaSaldo(jogo.getPreco(), true);
								this.addJogo(jogo);
								jogo.addCopiaVendida();
							} catch (IllegalArgumentException e) {
								View.exibirErro(e.getMessage());
							}
							return;
						} else {
							throw new IllegalArgumentException("[Usu�rio] Saldo insuficiente.");
						}
					} else {
						View.exibirMsg("A compra foi cancelada.");
						return;
					}
				}
			}
		}
		
		View.exibirErro("[Distribuidora] O jogo n�o foi encontrado.");
	}
	
}
