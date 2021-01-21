package br.com.paulocesar.armazem.main;

import java.util.ArrayList;

import br.com.paulocesar.armazem.utils.Menus;
import br.com.paulocesar.armazem.utils.Utils;
import br.com.paulocesar.armazem.utils.View;

public class Cliente implements Autenticavel{
	private String nome;
	private String cpf;
	private String senha;
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		if (nome.length() > 4)
			this.nome = nome;
		else
			throw new IllegalArgumentException("[Cliente] Nome inv�lido.");
	}
	public String getCPF() {
		return cpf;
	}
	public void setCPF(String cpf) {
		if (Utils.validaCPF(cpf))
			this.cpf = cpf;
		else
			throw new IllegalArgumentException("[Cliente] CPF inv�lido.");
	}
	public String getSenha() {
		return senha;
	}
	public void setSenha(String senha) {
		if (senha.length() >= 4)
			this.senha = senha;
		else
			throw new IllegalArgumentException("[Cliente] Senha inv�lida.");
	}
	@Override
	public void autenticar(String senha, Armazem armazem) {
		if (senha.equals(this.senha)) {
			Menus.menuCliente(armazem, this);
		}
	}
	
	public Compra comprarProduto(ArrayList<Produto> produtos) {
		ArrayList<Produto> carrinho = new ArrayList<Produto>();
		ArrayList<Integer> qntProd = new ArrayList<Integer>();
		Compra pedido = new Compra();
		String nomeProd;
		int tamanhoCarrinho = 0, qnt = 0;
		double precoTotal = 0d;
		boolean continuar = false;
		
		do {
			nomeProd = View.solicitarString("Digite o nome do produto desejado: ");
			
			for (Produto produto : produtos) {
				if (produto.getNome().equalsIgnoreCase(nomeProd)) {
					qnt = View.solicitarInt("Digite a quantidade que deseja: ");
					if (qnt <= produto.getQntUn()) {
						produto.setQntUn(qnt, true);
						qntProd.add(qnt);
						carrinho.add(produto);
						precoTotal += (produto.getPreco() * qnt);
						tamanhoCarrinho = carrinho.size();
						View.exibirMsg("Produto adicionado ao carrinho.");
					} else {
						View.exibirErro("N�o h� unidades o suficiente para satisfazer o pedido.");
					}
					
				}
			}
			if (tamanhoCarrinho != carrinho.size()) {
				View.exibirErro("Produto n�o encontrado.");
			}
			
			continuar = View.solicitarBoolean("Deseja mais algum produto?");
		} while (continuar);
		
		if (carrinho.size() == 0) {
			return null;
		}
		
		if (View.solicitarBoolean("Deseja confirmar a compra? O valor total � de: R$" + precoTotal)) {
			pedido.setComprador(this);
			pedido.setProdutos(carrinho);
			pedido.setQnt(qntProd);
			return pedido;
		} else {
			int i = 0;
			
			for (i = 0; i < carrinho.size(); i++) {
				carrinho.get(i).setQntUn(qntProd.get(i), false);
			}
			return null;
		}
		
	}
}
