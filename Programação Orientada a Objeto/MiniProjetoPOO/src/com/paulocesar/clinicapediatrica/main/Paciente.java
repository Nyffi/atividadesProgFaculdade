package com.paulocesar.clinicapediatrica.main;

import java.util.Stack;

public class Paciente extends Pessoa{
	
	// ATRIBUTOS
	
	private Stack<Consulta> consultas = new Stack<Consulta>();
	private String alergias;
	private String medicamentos;
	
	// CONSTRUTOR
	
	public Paciente(String nome, int idade, String cpf, String telefone) {
		super(nome, idade, cpf, telefone);
	}
	
	// MÉTODOS
	
	public String getAlergias() {
		return alergias;
	}

	public void setAlergias(String alergias) {
		this.alergias = alergias;
	}

	public String getMedicamentos() {
		return medicamentos;
	}

	public void setMedicamentos(String medicamentos) {
		this.medicamentos = medicamentos;
	}
	
	public Stack<Consulta> getConsultas() {
		return consultas;
	}
	
	public Consulta getStackHead() {
		return this.getConsultas().get(this.getConsultas().size() - 1);
	}
	
	@Override
	public String toString() {
		return super.toString();
	}
	
}
