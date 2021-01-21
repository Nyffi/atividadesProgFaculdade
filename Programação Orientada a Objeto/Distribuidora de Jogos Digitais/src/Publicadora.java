import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

public class Publicadora {
	
	private String email = null;
	private String nome = null;
	private String senha = null;
	private ArrayList<Jogo> jogos = new ArrayList<Jogo>();
	
	public void setNome(String nome) {
		if (nome.length() >= 2)
			this.nome = nome;
		else
			throw new IllegalArgumentException("[Publicadora] O apelido é muito curto.");
	}

	public String getNome() {
		return this.nome;
	}
	
	public String getEmail() {
		return this.email;
	}

	public void setEmail(String email) {		
		if (email.length() >= 7 && Utils.validaEmail(email))
			this.email = email;
		else
			throw new IllegalArgumentException("[Publicadora] Email inválido.");
	}
	
	public void setSenha(String senha) {
		if (senha.length() >= 6)
			this.senha = Utils.encriptaSenha(senha);
		else
			throw new IllegalArgumentException("[Publicadora] A senha é muito curto.");
	}

	public String getSenha() {
		return this.senha;
	}

	public ArrayList<Jogo> getJogos() {
		return this.jogos;
	}

	public void adicionaJogo() {
		Jogo jogo = new Jogo();
		View.telaPublicacao(jogo);
		
		try {
			while (jogo.getNome() == null || jogo.getDesc() == null || jogo.getPreco() == -1.0d) {
				TimeUnit.SECONDS.sleep(1);
			}
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
			View.exibirErro("[Distribuidora] Houve um erro no cadastro. Feche a tela de registro e tente novamente.");
			return;
		}

		this.jogos.add(jogo);
		View.exibirMsg("[Distribuidora] Jogo publicado com sucesso.");
	}

	public void removeJogo(String nomeJogo) {
		int index = 0;
		
		if (jogos.size() == 0) {
			View.exibirErro("[Publicadora] Você ainda não publicou nenhum jogo.");
			return;
		}
		
		for (Jogo jogo : jogos) {
			if (jogo.getNome().compareTo(nomeJogo) == 0) {
				if (View.solicitarBoolean("Deseja remover o jogo \"" + nomeJogo + " ?")) {
					jogos.remove(index);
					View.exibirMsg("[Distribuidora] Jogo excluído com sucesso.");
					return;
				} else {
					return;
				}
			}
			index++;
		}
		
		View.exibirErro("[Publicadora] O jogo citado não foi encontrado.");
	}
	
	public void editaJogo(String nomeJogo) {
		Jogo jogoEditado = new Jogo();
		for (Jogo jogo : jogos) {
			if (jogo.getNome().compareTo(nomeJogo) == 0) {
				View.telaPublicacao(jogoEditado);
				
				try {
					while (jogo.getNome() == null || jogo.getDesc() == null || jogo.getPreco() == -1.0d) {
						TimeUnit.SECONDS.sleep(1);
					}
				} catch (InterruptedException e) {
					Thread.currentThread().interrupt();
					View.exibirErro("[Distribuidora] Houve um erro no cadastro. Feche a tela de registro e tente novamente.");
					return;
				}
				
				if (View.solicitarBoolean("Deseja confirmar a edição?")) {
					jogo.setNome(jogoEditado.getNome());
					jogo.setDesc(jogoEditado.getDesc());
					jogo.setPreco(jogoEditado.getPreco());
				}
				return;
			}
		}
		View.exibirErro("[Publicadora] O jogo não foi encontrado.");
	}
	
	public void listarJogos() {		//Esse Listar Jogos fornece uma listagem com dados importantes para a publicadora.
		String cabecalho = "INDEX - NOME - PRECO - COPIAS VENDIDAS \n\n", msg = "";
		int index = 0;
		double lucroTotal = 0d;
		
		if (jogos.size() == 0) {
			View.exibirErro("[Publicadora] Nenhum jogo foi encontrado.");
			return;
		}
		
		for (Jogo jogo : jogos) {
			msg += index + " - " + jogo.getNome() + " - R$" + jogo.getPreco() + " - " + jogo.getCopiasVendidas() + " copias\n";
			lucroTotal += jogo.getPreco();
			index++;
		}
		
		msg += "\nLucro total obtido: R$" + lucroTotal;
		
		View.exibirMsg(cabecalho + msg);
	}
	
	public void listarJogosPublico() {		//Este Listar Jogos fornece uma listagem com dados importantes para o público.
		String cabecalho = "Publicadora: " + this.getNome() + "\n\n", msg = "";
		
		if (jogos.size() == 0) {
			msg += "Não há jogos publicados no momento.";
		}
		
		for (Jogo jogo : jogos) {
			msg += "Título: " + jogo.getNome() + "\nDescrição: " + jogo.getDesc() + "\nPreço: R$" + jogo.getPreco() + "\n\n";
		}
		
		View.exibirMsg(cabecalho + msg);
	}
}
