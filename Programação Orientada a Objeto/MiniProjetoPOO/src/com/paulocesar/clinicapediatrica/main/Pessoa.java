package com.paulocesar.clinicapediatrica.main;

import com.paulocesar.clinicapediatrica.utils.Utils;
import com.paulocesar.clinicapediatrica.utils.View;

abstract public class Pessoa {
	
	// ATRIBUTOS
	
	private String nome;
	private int idade;
	private String cpf;
	private String telefone;
	
	public Pessoa(String nome, int idade, String cpf, String telefone){
		try {
			setNome(nome);
			setIdade(idade);
			setCpf(cpf);
			setTelefone(telefone);
		} catch (IllegalArgumentException e) {
			View.exibirErro("Erro ao criar pessoa!\n\n" + e.getMessage());
		}
	}
	
	// GETTERS & SETTERS

	public String getNome() {
		return nome;
	}

	public void setNome(String nome){
		if(nome.length() > 4) {
			this.nome = nome;
		} else {
			throw new IllegalArgumentException("Nome inválido!");
		}
		
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade){
		if(idade > 0) {
			this.idade = idade;
		} else {
			throw new IllegalArgumentException("Idade inválida!");
		}
		
	}
	
	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		if(Utils.validaCPF(cpf)) {
			this.cpf = cpf;
		} else {
			throw new IllegalArgumentException("Cpf inválido!");
		}
		
	}
	
	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		if(telefone.matches("(\\(?\\d{2}\\)?\\s)?(\\d{4,5}\\d{4})")) {
			this.telefone = telefone;
		} else {
			throw new IllegalArgumentException("Telefone inválido!");
		}
		
	}
	
	// MÉTODOS

	@Override
	public String toString() {
		return "NOME: " + this.getNome() + "\n"
		+ "IDADE: " + this.getIdade() + "\n"
		+ "CPF: " + this.getCpf() + "\n"
		+ "TELEFONE: " + this.getTelefone();
	}
	
}
