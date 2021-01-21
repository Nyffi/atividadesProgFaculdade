package br.com.paulocesar.armazem.main;

import java.util.ArrayList;

import br.com.paulocesar.armazem.utils.Menus;
import br.com.paulocesar.armazem.utils.View;

public class Admin extends Funcionario implements Autenticavel{
	
	private String senha;
	
	@Override
	public void setNome(String nome) {
		try {
			super.setNome(nome);
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException("[Administrador] Nome inválido.");
		}
	}

	@Override
	public void setCPF(String cpf) {
		try {
			super.setCPF(cpf);
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException("[Administrador] CPF inválido.");
		}
	}

	@Override
	public void autenticar(String senha, Armazem armazem) {
		if (senha.equals(this.senha)) {
			Menus.menuAdmin(armazem, this);
		}
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		if (senha.length() >= 4)
			this.senha = senha;
		else
			throw new IllegalArgumentException("Senha inválida.");
	}
	
	/*public void adicionarEmpacotador (ArrayList<Empacotador> empacs) {
		Empacotador temp = new Empacotador();
		
		String nome, cpf, senha;
		
		try {
			nome = View.solicitarString("Digite o nome do novo Empacotador: ");
			cpf = View.solicitarString("Digite o CPF do novo Empacotador: ");
			senha = View.solicitarString("Digite a senha do novo Empacotador: ");
		} catch (NullPointerException e) {
			return;
		}
		
		if (nome == null || cpf == null || senha == null)
			return;
		
		try {
			temp.setNome(nome);
			temp.setCPF(cpf);
			temp.setSenha(senha);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
		
		empacs.add(temp);
	}*/
	
	public void adicionarEmpacotador(ArrayList<Empacotador> empacs) {
		Empacotador temp = new Empacotador();
		
		try {
			temp.setNome(View.solicitarString("Digite seu nome: "));
			temp.setCPF(View.solicitarString("Digite seu CPF: "));
			temp.setSenha(View.solicitarString("Digite a senha: "));
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		} catch (NullPointerException f) {
			return;
		}
		
		empacs.add(temp);
	}
	
	public void listarEmpacotadores (Armazem armazem) {
		String cabecalho = "LISTA - EMPACOTADORES\n\n", txt = "";
		
		for (Empacotador empac : armazem.getEmpacotadores()) {
			txt += empac.getNome() + " - " + empac.getCPF() + "\n";
		}
		
		View.exibirMsg(cabecalho + txt);
	}
	
	public void removerEmpacotador (Empacotador empac, ArrayList<Empacotador> empacotadores) {
		if (empac == null) {
			throw new IllegalArgumentException("O empacotador não foi encontrado.");
		}
		
		for (Empacotador empacotador : empacotadores) {
			if (empacotador == empac && View.solicitarBoolean("Deseja demitir o Empacotador " + empac.getNome() + "?")) {
				empacotadores.remove(empac);
				View.exibirMsg("Empacotador demitido com sucesso.");
				return;
			}
		}
	}
}
