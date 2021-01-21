package br.com.paulocesar.armazem.main;

import java.security.AccessControlException;
import java.util.ArrayList;

import br.com.paulocesar.armazem.utils.View;

public class Armazem {

	private ArrayList<Produto> produtos = new ArrayList<Produto>();
	private ArrayList<Cliente> clientes= new ArrayList<Cliente>();
	private ArrayList<Compra> pedidos= new ArrayList<Compra>();
	private ArrayList<Empacotador> empacotadores = new ArrayList<Empacotador>();
	private Admin admin = new Admin();
	//private Empacotador empac = new Empacotador();
	
	public Armazem() {
		admin.setNome("Admin");
		admin.setCPF("123.456.789-00");
		admin.setSenha("admin");
		
		Empacotador empac = new Empacotador();
		empac.setNome("Empac");
		empac.setCPF("987.654.321-00");
		empac.setSenha("empac");
		empacotadores.add(empac);
		
		Cliente cli = new Cliente();
		cli.setNome("ednaldo");
		cli.setCPF("78945612300");
		cli.setSenha("ednaldo");
		clientes.add(cli);
	}
	
	public ArrayList<Produto> getProdutos() {
		return this.produtos;
	}
	
	public ArrayList<Cliente> getClientes() {
		return this.clientes;
	}
	
	public ArrayList<Empacotador> getEmpacotadores() {
		return this.empacotadores;
	}
	
	public void alterarAdmin() {
		Admin novoAdmin = new Admin();
		String nome, cpf, senha;
		
		try {
			nome = View.solicitarString("Digite o nome do novo Administrador: ");
			cpf = View.solicitarString("Digite o CPF do novo Administrador: ");
			senha = View.solicitarString("Digite a senha do novo Administrador: ");
		} catch (NullPointerException e) {
			return;
		}
		
		if (nome == null || cpf == null || senha == null)
			return;
		
		try {
			novoAdmin.setNome(nome);
			novoAdmin.setCPF(cpf);
			novoAdmin.setSenha(senha);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
			return;
		}
		
		this.admin = novoAdmin;
	}
	
	public void adicionarProduto() {
		Produto temp = new Produto();
		//String nome, desc;
		//int qnt;
		//double preco;
		
		/*try {
			nome = View.solicitarString("Digite o nome do Produto: ");
			desc = View.solicitarString("Digite uma descrição curta pro Produto: ");
			qnt = View.solicitarInt("Digite a quantia inicial de unidades disponível: ");
			preco = View.solicitarDouble("Digite o preço por unidade: ");
		} catch (NullPointerException e) {
			return;
		}
		
		if (nome == null || desc == null)
			return;
		
		try {
			temp.setNome(nome);
			temp.setDesc(desc);
			temp.setQntUn(qnt);
			temp.setPreco(preco);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}*/
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do Produto: "));
			temp.setDesc(View.solicitarString("Digite uma descrição curta pro Produto: "));
			temp.setQntUn(View.solicitarInt("Digite a quantia inicial de unidades disponível: "));
			temp.setPreco(View.solicitarDouble("Digite o preço por unidade: "));
		} catch (NullPointerException e) {
			return;
		} catch (IllegalArgumentException f) {
			View.exibirErro(f.getMessage());
			return;
		}
		
		this.produtos.add(temp);
	}
	
	public void recarregarProduto(Produto prod) {
		if (prod == null) {
			throw new IllegalArgumentException("Produto não encontrado.");
		}
		
		prod.setQntUn(View.solicitarInt("Digite a quantia de unidades do reabastecimento: "), false);
	}
	
	public void listarProdutos() {
		String cabecalho = "LISTA - PRODUTOS\n\n", txt = "";
		
		for (Produto produto : produtos) {
			txt += "Nome: " + produto.getNome() +
				   "\nDescrição: " + produto.getDesc() +
				   "\nUnidades disponíveis: " + produto.getQntUn() +
				   "\nPreço: R$" + produto.getPreco() + "\n\n";
		}
		
		View.exibirMsg(cabecalho + txt);
	}
	
	public Produto procurarProduto(String nome) {
		for (Produto produto : produtos) {
			if (produto.getNome().equalsIgnoreCase(nome)) {
				return produto;
			}
		}
		return null;
	}
	
	public void removerProduto(Produto prod) {
		if (prod == null) {
			throw new IllegalArgumentException("O produto não foi encontrado.");
		}
		
		for (Produto produto : produtos) {
			if (prod == produto && View.solicitarBoolean("Deseja deletar o produto " + prod.getNome() + "?")) {
				produtos.remove(prod);
				return;
			}
		}
	}
	
	public void adicionarCliente() {
		Cliente temp = new Cliente();
		
		try {
			temp.setNome(View.solicitarString("Digite seu nome: "));
			temp.setCPF(View.solicitarString("Digite seu CPF: "));
			temp.setSenha(View.solicitarString("Digite a senha: "));
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
			return;
		} catch (NullPointerException f) {
			return;
		}
		
		clientes.add(temp);
	}
	
	public Cliente procurarCliente(String nome) {
		for (Cliente cliente : clientes) {
			if (cliente.getNome().equalsIgnoreCase(nome)) {
				return cliente;
			}
		}
		
		return null;
	}
	
	public Empacotador procurarEmpac(String nome) {
		for (Empacotador empac : empacotadores) {
			if (empac.getNome().equalsIgnoreCase(nome)) {
				return empac;
			}
		}
		
		return null;
	}
	
	public void listarPedidos(boolean prontoParaEnvio) {
		if (clientes.size() == 0) {
			throw new IllegalArgumentException("Não há clientes cadastrados.");
		}
		
		for (Cliente cliente : clientes) {
			this.listarPedidos(cliente, prontoParaEnvio);
		}
	}
	
	public void listarPedidos(Cliente cli, boolean prontoParaEnvio) {
		String cabecalho = "LISTA - PEDIDOS\n\n", txt = "";
		int pos = 0, qntPronto = 0;
		double precoTotal = 0d;
		
		for (Compra pedido : pedidos) {
			if (pedido.getEmpacotado())
				qntPronto++;
		}
		
		if ((prontoParaEnvio && qntPronto == 0) || pedidos.size() == 0) {
			txt += "Não há pedidos registrados no momento.";
			View.exibirMsg(cabecalho + txt);
			return;
		}
		
		txt += "PEDIDOS DE " + cli.getNome() + "\n";
		for (Compra pedido : pedidos) {
			txt += "ID Nº " + pedido.getID() + "\n";
			if (prontoParaEnvio) {
				if (pedido.getComprador() == cli && pedido.getEmpacotado()) {
					for (Produto produto : pedido.getProdutos()) {
						txt += produto.getNome() + " - R$" + produto.getPreco() + " - " + pedido.getQnt().get(pos) + " un\n";
						precoTotal += (produto.getPreco() * pedido.getQnt().get(pos));
					}
					txt += "Preço total do pedido: R$" + precoTotal;
					txt += "\nPronto para envio? " + pedido.getEmpacotado();
					txt += "\n\n";
					precoTotal = 0d;
				}
			} else {
				if (pedido.getComprador() == cli) {
					for (Produto produto : pedido.getProdutos()) {
						txt += produto.getNome() + " - R$" + produto.getPreco() + " - " + pedido.getQnt().get(pos) + " un\n";
						precoTotal += (produto.getPreco() * pedido.getQnt().get(pos));
					}
					txt += "Preço total do pedido: R$" + precoTotal;
					txt += "\nPronto para envio? " + pedido.getEmpacotado();
					txt += "\n\n";
					precoTotal = 0d;
				}
			}
			
		}
		
		//if (txt.equals("PEDIDOS DE " + cli.getNome() + "\n")) {
		//	txt = "NENHUM PEDIDO FOI ENCONTRADO.";
		//}
		
		View.exibirMsg(cabecalho + txt);
	}
	
	public Compra procurarCompra(int id) {
		for (Compra compra : pedidos) {
			if (compra.getID() == id && !compra.getEmpacotado()) {
				return compra;
			}
		}
		
		return null;
	}
	
	public void concluirCompra(Compra pedido) {
		if (pedido != null) {
			this.pedidos.add(pedido);
			View.exibirMsg("Compra concluida com sucesso. Ela será preparada para envio em breve.");
		}			
		else
			View.exibirErro("A compra foi cancelada.");
	}
	
	public void fazerLogin(String nome, String senha) {
		if (nome == null || senha == null)
			return;
		
		if (nome.equalsIgnoreCase(this.admin.getNome())) {
			this.admin.autenticar(senha, this);
			return;
		}
		
		for (Empacotador empac : empacotadores) {
			if (nome.equalsIgnoreCase(empac.getNome())) {
				empac.autenticar(senha, this);
				return;
			}
		}
		
		for (Cliente cliente : clientes) {
			if (nome.equalsIgnoreCase(cliente.getNome())) {
				cliente.autenticar(senha, this);
				return;
			}
		}
		
		throw new AccessControlException("A conta não foi encontrada.");
	}
}
