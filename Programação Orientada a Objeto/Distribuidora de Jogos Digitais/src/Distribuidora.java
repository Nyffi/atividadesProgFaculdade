import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

public class Distribuidora {

	private ArrayList<Publicadora> publicadoras = new ArrayList<Publicadora>();
	private ArrayList<Usuario> usuarios = new ArrayList<Usuario>();
	
	Distribuidora() {	// Toda vez que a distribuidora for criada, uma conta de Administrador será criada junto.
		Usuario admin = new Usuario();
		admin.setAdmin();
		admin.setApelido("admin");
		admin.setEmail("admin@hex.com");
		admin.setSenha("adminroot");
		usuarios.add(admin);
	}
	
	public ArrayList<Publicadora> getPublicadoras() {
		return this.publicadoras;
	}
	
	public void adicionarPublicadora() {
		Publicadora publish = new Publicadora();
		View.telaRegistro("REGISTRO - PUBLICADORA", null, publish, false);
		try {
			while (publish.getEmail() == null || publish.getSenha() == null || publish.getNome() == null) {
				TimeUnit.SECONDS.sleep(1);
			}
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
			View.exibirErro("[Distribuidora] Houve um erro no cadastro. Feche a tela de registro e tente novamente.");
			return;
		}
		
		publicadoras.add(publish);
		View.exibirMsg("[Distribuidora] Conta criada com sucesso.");
	}
	
	public void adicionarUsuario(boolean admin) {
		Usuario user = new Usuario();
		if (admin) {
			View.telaRegistro("REGISTRO - ADMIN", user, null, true);
		} else {
			View.telaRegistro("REGISTRO - USUÁRIO", user, null, false);
		}
		
		try {
			while (user.getEmail() == null || user.getSenha() == null || user.getApelido() == null) {
				TimeUnit.SECONDS.sleep(1);
			}
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
			View.exibirErro("[Distribuidora] Houve um erro no cadastro. Feche a tela de registro e tente novamente.");
			return;
		}
		
		usuarios.add(user);
		View.exibirMsg("[Distribuidora] Conta criada com sucesso.");
	}
	
	public void removeConta(String emailConta) {
		int index = 0;
		
		if (Utils.validaEmail(emailConta)) {
			for (Publicadora publicadora : publicadoras) {
				if (publicadora.getEmail().compareTo(emailConta) == 0) {
					if (View.solicitarBoolean("Deseja mesmo apagar a conta de " + publicadora.getNome() + "?")) {
						publicadoras.remove(index);
						View.exibirMsg("[Distribuidora] Conta de Publicadora apagada com sucesso.");
					}
					return;
				}
				index++;
			}
			
			index = 0;
			
			for (Usuario usuario : usuarios) {
				if (usuario.getEmail().compareTo(emailConta) == 0) {
					if (View.solicitarBoolean("Deseja mesmo apagar a conta de " + usuario.getApelido() + "?")) {
						usuarios.remove(index);
						View.exibirMsg("[Distribuidora] Conta de Publicadora apagada com sucesso.");
					}
					return;
				}
				index++;
			}
		} else {
			View.exibirErro("[Distribuidora] Email inválido.");
		}
		
		
	}
	
	public void fazerLogin() throws InterruptedException {
		Login dados = new Login();
		View.telaLogin("LOGIN", dados);
		while (dados.getEmail() == null || dados.getSenha() == null) {		//Enquanto não receber os dados de login, o sistema é pausado. 
			TimeUnit.SECONDS.sleep(1);										//Caso não seja pausado, o resto do código é executado e causa conflitos.
		}
		
		if (publicadoras.size() > 0) {
			for (Publicadora publicadora : publicadoras) {
				if (publicadora.getEmail().compareTo(dados.getEmail()) == 0 && publicadora.getSenha().compareTo(dados.getSenha()) == 0) {
					View.exibirMsg("Conta de Publicadora encontrada. Bem vindo(a), " + publicadora.getNome());
					Menus.menuPublicadora(publicadora);
					return;
				}
			}
		}
		
		for (Usuario usuario : usuarios) {
			if (usuario.getEmail().compareTo(dados.getEmail()) == 0 && usuario.getSenha().compareTo(dados.getSenha()) == 0) {
				if (usuario.getAdmin()) {	//Se o usuário tiver o boolean de admin como verdadeiro, abrir o menu de admin.
					View.exibirMsg("Conta de Administrador encontrada. Bem vindo(a), " + usuario.getApelido());
					Menus.menuAdmin(usuario, this);
				} else {					//Caso contrário, abrir o menu de Usuário comum.
					View.exibirMsg("Conta de Usuário encontrado. Bem vindo(a), " + usuario.getApelido());
					Menus.menuUsuario(usuario, publicadoras);
				}
				return;
			}
		}
		
		View.exibirErro("[Distribuidora] O email/senha não está cadastrado.");
	}
	
	public void pesquisaApagaJogo(String nomeJogo) {
		
		for (Publicadora publicadora : publicadoras) {
			publicadora.removeJogo(nomeJogo);
			return;
		}
		
		View.exibirErro("[Administrador] A pesquisa chegou no final. O jogo não foi encontrado.");
	}
}
