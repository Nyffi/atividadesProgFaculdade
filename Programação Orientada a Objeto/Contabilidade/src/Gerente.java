import java.util.ArrayList;

public class Gerente extends Funcionario{
	public void cadastrarCliente(ArrayList<Cliente> clientes) {
		Cliente aux = new Cliente();
		
		try {
			aux.setNome(View.solicitarString("Digite o nome do cliente: "));
			if (View.solicitarBoolean("O cliente deseja uma Conta Empresarial?")) {
				aux.setCnpj(View.solicitarString("Digite o CNPJ do cliente:"));
				aux.setContaPJ(new ContaEmpresarial());
			} else {
				aux.setCpf(View.solicitarString("Digite o CPF do cliente: "));
				aux.setContaPF(new ContaCorrente());
			}
			aux.setRg(View.solicitarString("Digite o RG do cliente: "));
			aux.setSenha(View.solicitarString("Digite a senha do cliente: "));
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
		
		
		
		clientes.add(aux);
	}
	
	public void excluirCliente(ArrayList<Cliente> clientes, Cliente alvo) {
		if (alvo == null) {
			View.exibirErro("Cliente não encontrado.");
			return;
		}
		
		for (Cliente cliente : clientes) {
			if (alvo == cliente) {
				if (View.solicitarBoolean("Deseja mesmo deletar a conta?")) {
					clientes.remove(cliente);
				} else {
					return;
				}
			}
		}
	}
	
	public void criarContaCorrente(Cliente cli) {
		if (cli.getContaPF() != null) {
			View.exibirErro("[Banco] O cliente já possui uma Conta Corrente.");
			return;
		}
		
		if (cli.getCpf() != null && cli.getContaPF() == null)
			cli.setContaPF(new ContaCorrente());
		else
			if (cli.getCpf() == null) {
				cli.setCpf(View.solicitarString("Digite o CPF do Cliente: "));
				criarContaCorrente(cli);
			} else {
				throw new IllegalArgumentException("[Gerente] Não foi possível criar uma conta corrente.");
			}
	}
	
	public void criarContaEmpresarial(Cliente cli) {
		if (cli.getContaPJ() != null) {
			View.exibirErro("[Banco] O cliente já possui uma Conta Empresarial.");
			return;
		}

		if (cli.getCnpj() != null && cli.getContaPJ() == null)
			cli.setContaPJ(new ContaEmpresarial());
		else
			if (cli.getCnpj() == null) {
				cli.setCnpj(View.solicitarString("Digite o CNPJ do Cliente: "));
				criarContaEmpresarial(cli);
			} else {
				throw new IllegalArgumentException("[Gerente] Não foi possível criar uma conta empresarial.");
			}
	}
	
	public Contador alterarContador() {
		Contador aux = new Contador();
		
		try {
			aux.setNome(View.solicitarString("Digite o nome do novo Contador: "));
			aux.setCpf(View.solicitarString("Digite o CPF do novo Contador: "));
			aux.setSenha(View.solicitarString("Digite a senha do novo Contador: "));
			return aux;
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
		
		return null;
		
	}
}
