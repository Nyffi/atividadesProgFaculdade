import java.util.ArrayList;
import java.util.Random;

public class Utils {
	static boolean validaCPF (String cpf) {		// Validação incompleta para propósitos educacionais ;)
		if (cpf.isEmpty()) {
			View.exibirErro("CPF não informado.");
			return false;
		}
		
		cpf = cpf.replaceAll("[^0-9]", "");
		
		if (cpf.length() != 11) {
			View.exibirErro("CPF incompleto.");
			return false;
		} else if (	cpf.equals("00000000000") ||
					cpf.equals("11111111111") || 
					cpf.equals("22222222222") ||
					cpf.equals("33333333333") ||
					cpf.equals("44444444444") ||
					cpf.equals("55555555555") ||
					cpf.equals("66666666666") ||
					cpf.equals("77777777777") || 
					cpf.equals("88888888888") ||
					cpf.equals("99999999999") ) {
			View.exibirErro("CPF inválido.");
			return false;
		}
		
		return true;
	}
	
	public static int gerarInt() {
		Random rand = new Random();
		return rand.nextInt(99999);
	}
	
	public static void adicionaBanco(ArrayList<Banco> bancos) {
		Banco temp = new Banco(View.solicitarString("Digite o nome do Banco: "), 
							   View.solicitarInt("Digite o código do Banco: "));
		bancos.add(temp);
	}
	
	public static void listarBancos(ArrayList<Banco> bancos) {
		String lista = "ID - NOME - CÓDIGO \n", aux;
		int qntBancos = bancos.size();
		int i;
		
		if (qntBancos > 0) {
			for (i = 0; i < qntBancos; i++) {
				aux = String.format("%d - %s - %d \n", i, bancos.get(i).getNome(), bancos.get(i).getCodigo());
				lista = lista + aux;
			}
			View.exibirMsg(lista);
		} else {
			View.exibirErro("Não há bancos registrados no momento.");
		}
	}
	
	public static void deletarBanco(ArrayList<Banco> bancos) {
		int idBanco;
		
		if (bancos.size() == 0) {
			View.exibirErro("Não há bancos cadastrados no sistema.");
			return;
		}
		
		idBanco = View.solicitarInt("Digite o ID do Banco desejado: ");
		
		//TODO Colocar aviso para caso o banco ainda tenha clientes
		
		bancos.remove(idBanco);
	}

	public static void logarBanco(ArrayList<Banco> bancos) {
		int idBanco = View.solicitarInt("Digite o ID do Banco desejado: ");
		
		try {
			Menus.menuBanco(bancos.get(idBanco));
		} catch (Exception e) {
			View.exibirErro("Não há bancos registrados no momento. \n");
		}
	}
	
	public static void criarConta(ArrayList<Conta> contas) {
		Cliente cli = new Cliente();
		cli.setCPF();
		cli.setNome();
		Conta temp = new Conta(View.solicitarInt("Digite o número da Agência: "), cli);
		
		contas.add(temp);
		View.exibirMsg("Conta criada com sucesso.\n\nNumero: " + temp.getNumero() + "\nAgência: " + temp.getAgencia() + "\nTitular: " + cli.getNome());
	}
	
	public static void listarContas(ArrayList<Conta> contas) {
		String lista = "ID - NÚMERO - AGÊNCIA - NOME \n", aux;
		int qntContas = contas.size();
		int i;
		
		if (qntContas > 0) {
			for (i = 0; i < qntContas; i++) {
				aux = String.format("%d - %d - %d - %s \n", i, contas.get(i).getNumero(), contas.get(i).getAgencia(), contas.get(i).getTitular().getNome());
				lista = lista + aux;
			}
			View.exibirMsg(lista);
		} else {
			View.exibirErro("Não há contas registradas no momento.");
		}
	}
	
	public static void deletarConta(ArrayList<Conta> contas) {
		int idConta;
		
		if (contas.size() == 0) {
			View.exibirErro("Não há bancos cadastrados no sistema.");
			return;
		}
		
		idConta = View.solicitarInt("Digite o ID da Conta desejada: ");
		
		if (contas.get(idConta).getSaldo() > 0) {
			if (View.solicitarBoolean("A Conta selecionada ainda possui saldo. Deseja continuar?")) {
				contas.remove(idConta);
				View.exibirMsg("A Conta foi deletada com sucesso.");
			}
		} else {
			contas.remove(idConta);
			View.exibirMsg("A Conta foi deletada com sucesso.");
		}
	}
	
	public static void infoBanco (Banco banco) {
		View.exibirMsg("Nome do Banco: " + banco.getNome() + "\nCódigo do Banco: " + banco.getCodigo() + "\nQuantidade de Contas cadastradas: " + banco.getContas().size());
	}
	
	public static void logarConta(ArrayList<Conta> contas) {
		int idConta = View.solicitarInt("Digite o ID da Conta desejada: ");
		
		try {
			Menus.menuConta(contas.get(idConta), contas);
		} catch (Exception e) {
			View.exibirErro("Não há bancos registrados no momento. \n");
		}
	}
	
	public static void mostrarSaldo(Conta conta) {
		View.exibirMsg("Saldo atual: R$" + conta.getSaldo());
	}
}
