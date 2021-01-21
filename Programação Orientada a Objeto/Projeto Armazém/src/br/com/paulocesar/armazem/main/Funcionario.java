package br.com.paulocesar.armazem.main;

import br.com.paulocesar.armazem.utils.Utils;

public abstract class Funcionario {

	private String nome;
	private String cpf;

	public void setNome(String nome) {
		if (nome.length() > 4)
			this.nome = nome;
		else
			throw new IllegalArgumentException("[Funcionário] Nome inválido.");
	}

	public void setCPF(String cpf) {
		if (Utils.validaCPF(cpf))
			this.cpf = cpf;
		else
			throw new IllegalArgumentException("[Funcionário] CPF inválido.");
	}

	public String getNome() {
		return this.nome;
	}

	public String getCPF() {
		return this.cpf;
	}

}
