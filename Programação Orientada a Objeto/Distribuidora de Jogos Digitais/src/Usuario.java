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
			throw new IllegalArgumentException("[Usuário] O apelido é muito curto.");
	}
	
	public String getEmail() {
		return this.email;
	}

	public void setEmail(String email) {		
		if (email.length() >= 7 && Utils.validaEmail(email))
			this.email = email;
		else
			throw new IllegalArgumentException("[Usuário] Email inválido.");
		
	}

	public String getSenha() {
		return this.senha;
	}

	public void setSenha(String senha) {
		if (senha.length() >= 6)
			this.senha = Utils.encriptaSenha(senha);
		else
			throw new IllegalArgumentException("[Usuário] A senha é muito curta.");
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
			if (compra) {		//A variável compra serve pra definir se essa função está sendo usada numa compra (redução de saldo) ou num depósito (adição de saldo)
				this.saldo -= val;
				View.exibirMsg("[Usuário] A compra foi executada com sucesso.");
			} else {
				this.saldo += val;
				View.exibirMsg("[Usuário] O valor foi adicionado ao saldo com sucesso.");
			}
		} else {
			throw new IllegalArgumentException("[Usuário] Não pôde ser feita a atualização do saldo.");
		}
	}
	
	public void comprarJogo(String nomeJogo, ArrayList<Publicadora> publicadoras) {
		for (Publicadora publicadora : publicadoras) {
			for (Jogo jogo : publicadora.getJogos()) {
				if (jogo.getNome().compareTo(nomeJogo) == 0) {
					if (View.solicitarBoolean("Jogo: " + jogo.getNome() //Mostra as informações do jogo a ser comprado e confirma se o usuário quer comprar
					+ "\nDescrição: " + jogo.getDesc() 
					+ "\nPreço: R$" + jogo.getPreco() 
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
							throw new IllegalArgumentException("[Usuário] Saldo insuficiente.");
						}
					} else {
						View.exibirMsg("A compra foi cancelada.");
						return;
					}
				}
			}
		}
		
		View.exibirErro("[Distribuidora] O jogo não foi encontrado.");
	}
	
}
