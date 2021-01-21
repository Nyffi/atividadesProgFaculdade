import java.util.ArrayList;

public class Menus {
	public static void menuPrincipal (ArrayList<Banco> bancos) {
		int opcao;
		
		do {
			opcao = View.solicitarInt("- - - - - Menu  DEBUG - - - - - \n"
									+ "1 - Criar um novo Banco \n"
									+ "2 - Listar Bancos \n"
									+ "3 - Logar em um Banco \n"
									+ "4 - Deletar um Banco \n"
									+ "5 - Sair");
			
			switch (opcao) {
				case 1:
					Utils.adicionaBanco(bancos);
					break;
				case 2:
					Utils.listarBancos(bancos);
					break;
				case 3:
					Utils.logarBanco(bancos);
					break;
				case 4:
					Utils.deletarBanco(bancos);
					break;
				case 5:
					break;
			}
		} while (opcao != 5);
	}
	
	public static void menuBanco (Banco banco) {
		int opcao;
		
		do {
			opcao = View.solicitarInt("- - - - - Banco " + banco.getNome() + " - - - - - \n"
									+ "1 - Criar uma nova Conta \n"
									+ "2 - Listar Contas \n"
									+ "3 - Logar em uma Conta \n"
									+ "4 - Deletar uma Conta \n"
									+ "5 - Informações do Banco \n"
									+ "6 - Voltar ao Menu anterior");
			
			switch (opcao) {
				case 1:
					Utils.criarConta(banco.getContas());
					break;
				case 2:
					Utils.listarContas(banco.getContas());
					break;
				case 3:
					Utils.logarConta(banco.getContas());
					break;
				case 4:
					Utils.deletarConta(banco.getContas());
					break;
				case 5:
					Utils.infoBanco(banco);
					break;
				case 6:
					break;
			}
		} while (opcao != 6);
	}
	
	public static void menuConta (Conta conta, ArrayList<Conta> lista) {
		int opcao;
		
		do {
			opcao = View.solicitarInt("- - - - - Bem-vindo(a) " + conta.getTitular().getNome() + " - - - - - \n"
									+ "1 - Checar Saldo \n"
									+ "2 - Depositar \n"
									+ "3 - Sacar \n"
									+ "4 - Transferir \n"
									+ "5 - Pedir aumento de limite \n"
									+ "6 - Informações Gerais\n"
									+ "7 - Sair");
			
			switch (opcao) {
				case 1:
					Utils.mostrarSaldo(conta);
					break;
				case 2:
					conta.depositar(View.solicitarDouble("Digite o valor a ser depositado: "));
					Utils.mostrarSaldo(conta);
					break;
				case 3:
					conta.sacar(View.solicitarDouble("Digite o valor a ser sacado: "));
					Utils.mostrarSaldo(conta);
					break;
				case 4:
					int remetente = View.solicitarInt("Digite o ID do remetente: ");
					conta.transferir(View.solicitarDouble("Digite o valor a ser transferido: "), lista.get(remetente));
					break;
				case 5:
					View.exibirMsg("Nome do Titular: " + conta.getTitular().getNome() + "\n"
								 + "CPF do Titular: " + conta.getTitular().getCPF() + "\n"
								 + "Numero da Conta + Agência: " + conta.getNumero() + "-" + conta.getAgencia() + "\n"
								 + "Limite de transações: R$" + conta.getLimite());
					break;
				case 6:
					conta.setLimite(View.solicitarDouble("Digite o valor do aumento desejado: "));
					break;
				case 7:
					break;
			}
		} while (opcao != 7);
	}
}
