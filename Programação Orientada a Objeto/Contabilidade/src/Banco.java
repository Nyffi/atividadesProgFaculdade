import java.util.ArrayList;

public class Banco {
	private ArrayList<Cliente> clientes = new ArrayList<Cliente>();
	private Gerente gerente = new Gerente();
	private Contador contador = new Contador();
	
	public Banco() {
		gerente.setNome("Doug Dimmadome");
		gerente.setCpf("855.284.091-01");
		gerente.setSenha("1234");
		contador.setNome("Tio Patinhas");
		contador.setCpf("198.868.471-40");
		contador.setSenha("1234");
	}

	public Gerente getGerente() {
		return gerente;
	}

	public void setGerente(Gerente gerente) {
		this.gerente = gerente;
	}

	public Contador getContador() {
		return contador;
	}

	public void setContador(Contador contador) {
		if (contador != null) {
			this.contador = contador;
		}
	}

	public ArrayList<Cliente> getClientes() {
		return clientes;
	}
	
	public void fazerLogin(String nome, String senha) {
		if (nome.equals(null) || senha.equals(null)) {
			return;
		}
		
		if (nome.equals(this.contador.getNome()) && senha.equals(this.contador.getSenha())) {
			View.exibirMsg("Seja Bem Vindo(a)! Você está logado(a) como Contador(a).");
			Menus.m_Funcionario(this, this.contador);
			return;
		}
		
		if (nome.equals(this.gerente.getNome()) && senha.equals(this.gerente.getSenha())) {
			View.exibirMsg("Seja Bem Vindo(a)! Você está logado(a) como Gerente.");
			Menus.m_Funcionario(this, this.gerente);
			return;
		}
		
		for (Cliente cliente : clientes) {
			if (nome.equals(cliente.getNome()) && senha.equals(cliente.getSenha())) {
				View.exibirMsg("Seja Bem Vindo(a)! Você está logado(a) como Cliente.");
				Menus.m_Cliente(this, cliente);
				return;
			}
		}
		
		View.exibirErro("[Banco] A conta não foi encontrada.");
	}
	
	public Cliente procuraCliente(String nome) {
		for (Cliente cliente : clientes) {
			if (cliente.getNome().equals(nome)) {
				return cliente;
			}
		}
		
		return null;
	}
}
