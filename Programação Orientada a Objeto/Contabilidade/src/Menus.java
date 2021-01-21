
public class Menus {
	public static void m_Principal(Banco banco) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu	Banco - - - - - \n"
						+ "1 - Fazer Login \n"
						+ "0 - Sair");

				switch (opcao) {
				case 1:
					banco.fazerLogin(View.solicitarString("Digite o seu Nome: "), View.solicitarString("Digite a Senha:"));
					break;
				case 0:
					break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}

	public static void m_Funcionario(Banco banco, Contador contador) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu	Contador - - - - - \n"
						+ "1 - Gerar Relatório Geral \n"
						+ "0 - Sair");
				switch (opcao) {
					case 1:
						contador.gerarRelatorio(banco.getClientes());
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}

	public static void m_Funcionario(Banco banco, Gerente gerente) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu	Gerente - - - - - \n"
						+ "1 - Criar Conta de Cliente \n"
						+ "2 - Adicionar Conta Corrente para um Cliente \n"
						+ "3 - Adicionar Conta Empresarial para um Cliente \n"
						+ "4 - Apagar uma Conta de Cliente \n"
						+ "5 - Alterar Contador \n"
						+ "0 - Sair");

				switch (opcao) {
				case 1:
					gerente.cadastrarCliente(banco.getClientes());
					break;
				case 2:
					gerente.criarContaCorrente(banco.procuraCliente(View.solicitarString("Digite o nome do Cliente: ")));
					break;
				case 3:
					gerente.criarContaEmpresarial(banco.procuraCliente(View.solicitarString("Digite o nome do Cliente:")));
					break;
				case 4:
					gerente.excluirCliente(banco.getClientes(), banco.procuraCliente(View.solicitarString("Digite o nome do Cliente: ")));
					break;
				case 5:
					banco.setContador(gerente.alterarContador());
				case 0:
					break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}

	public static void m_Cliente(Banco banco, Cliente cliente) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu	Cliente - - - - - \n"
						+ "1 - Ver saldo \n"
						+ "2 - Depositar \n"
						+ "3 - Sacar \n"
						+ "4 - Transferir saldo \n"
						+ "0 - Sair");

				switch (opcao) {
				case 1:
					cliente.verSaldo();
					break;
				case 2:
					cliente.depositarValor(View.solicitarDouble("Digite o valor que deseja depositar: "));
					break;
				case 3:
					cliente.sacarValor(View.solicitarDouble("Digite o valor que deseja sacar: "));
					break;
				case 4:
					Cliente dest = banco.procuraCliente(View.solicitarString("Digite o nome do cliente que deseja: "));
					
					cliente.transferirValor(View.solicitarDouble("Digite o valor que deseja transferir: "), dest);
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
