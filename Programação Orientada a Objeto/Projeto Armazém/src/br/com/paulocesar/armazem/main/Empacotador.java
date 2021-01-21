package br.com.paulocesar.armazem.main;

import br.com.paulocesar.armazem.utils.Menus;
import br.com.paulocesar.armazem.utils.View;

public class Empacotador extends Funcionario implements Autenticavel {
	
	private String senha;
	
	@Override
	public void setNome(String nome) {
		try {
			super.setNome(nome);
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException("[Empacotador] Nome inválido.");
		}
	}

	@Override
	public void setCPF(String cpf) {
		try {
			super.setCPF(cpf);
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException("[Empacotador] CPF inválido.");
		}
	}
	
	@Override
	public void autenticar(String senha, Armazem armazem) {
		if (senha.equals(this.senha)) {
			Menus.menuEmpacotador(armazem, this);
		}
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}
	
	public void empacotarPedido(Compra pedido) {
		if (pedido != null)
			pedido.pedidoEmpacotado();
		else
			View.exibirErro("O pedido não foi encontrado.");;
	}

}
