import java.util.ArrayList;

public class Menus {
	public static void menuPrincipal (Distribuidora distribuidora) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - HeX - Distribuidora de Jogos - - - - - \n"
										+ "1 - Fazer Login \n"
										+ "2 - Criar uma conta de cliente \n"
										+ "3 - Criar uma conta de publicadora \n"
										+ "4 - Ver jogos disponíveis \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						distribuidora.fazerLogin();
						break;
					case 2:
						distribuidora.adicionarUsuario(false);
						break;
					case 3:
						distribuidora.adicionarPublicadora();
						break;
					case 4:
						Utils.listarJogos(distribuidora.getPublicadoras());
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			} catch (InterruptedException f) {
				View.exibirErro("Não foi possivel fazer o login.");
			}
		} while (opcao != 0);
	}
	
	public static void menuPublicadora(Publicadora publish) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Seja Bem-Vindo(a), " + publish.getNome() + " - - - - - \n"
										+ "1 - Adicionar um jogo \n"
										+ "2 - Remover um jogo \n"
										+ "3 - Editar um jogo \n"
										+ "4 - Ver jogos publicados \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						publish.adicionaJogo();
						break;
					case 2:
						publish.removeJogo(View.solicitarString("Digite o nome do jogo: "));
						break;
					case 3:
						publish.editaJogo(View.solicitarString("Digite o nome do jogo: "));
						break;
					case 4:
						publish.listarJogos();
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			} 
		} while (opcao != 0);
	}
	
	public static void menuUsuario(Usuario usuario, ArrayList<Publicadora> publicadoras) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Seja Bem-Vindo(a), " + usuario.getApelido() + " - - - - - \n"
						+ "1 - Comprar um jogo \n"
						+ "2 - Ver jogos disponíveis \n"
						+ "3 - Adicionar saldo \n"
						+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						try {
							usuario.comprarJogo(View.solicitarString("Digite o nome do jogo desejado: "), publicadoras);
						} catch (IllegalArgumentException e) {
							View.exibirErro(e.getMessage());
						}
						break;
					case 2:
						Utils.listarJogos(publicadoras);
						break;
					case 3:
						usuario.atualizaSaldo(View.solicitarDouble("Digite o valor a ser adicionado: "), false);
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			} 
		} while (opcao != 0);
	}
	
	public static void menuAdmin(Usuario usuario, Distribuidora distribuidora) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu ADMIN - - - - - \n"
										+ "1 - Adicionar Admin \n"
										+ "2 - Apagar Conta de Usuário/Distribuidora \n"
										+ "3 - Apagar Jogo \n"
										+ "4 - Ver Menu de Usuário \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						distribuidora.adicionarUsuario(true);
						break;
					case 2:
						distribuidora.removeConta(View.solicitarString("Digite o email da conta desejada: "));
						break;
					case 3:
						distribuidora.pesquisaApagaJogo(View.solicitarString("Digite o nome do jogo: "));
						break;
					case 4:
						Menus.menuUsuario(usuario, distribuidora.getPublicadoras());
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			} 
		} while (opcao != 0);
	}
}
