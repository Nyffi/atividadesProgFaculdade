package com.paulocesar.clinicapediatrica.main;

import java.util.ArrayList;

import com.paulocesar.clinicapediatrica.utils.View;

public class Secretaria extends Pessoa implements Funcionario{
	
	private boolean estaPresente = false;
	
	public Secretaria(String nome, int idade, String cpf, String telefone) {
		super(nome, idade, cpf, telefone);
	}
	
	public void baterPonto() {
		this.estaPresente = !this.estaPresente;
		
		if(this.estaPresente) {
			System.out.println(this.getNome() + " - Secretaria(o) - bateu o ponto! [ENTRADA]");
		} else {
			System.out.println(this.getNome() + " - Secretaria(o) - bateu o ponto! [SAÍDA]");
		}
		
	}
	
	public void cadastraConsulta(Paciente paciente) {
		String titulo = "CADASTRO - PACIENTE";
		Consulta consulta = null;
		int qntConsultas = paciente.getConsultas().size();
		
		do {
			try {
				consulta = new Consulta(View.solicitarString("Digite o motivo da consulta: ", titulo), 
										View.selecionaLista("Selecione o médico requisitado: ", titulo, Clinica.getEspecialidades()));
				paciente.getConsultas().push(consulta);
			} catch (IllegalArgumentException e) {
				View.exibirErro(e.getMessage());
			}
		} while (qntConsultas == paciente.getConsultas().size());
			
	}
	
	public void cadastraConsulta(ArrayList<Paciente> pacientes, String cpf) {
		String titulo = "CADASTRO - PACIENTE", nome = "", telefone = "", alergias, medicamentos, profMedico = null;
		int idade = 0;
		
		boolean isValid[] = new boolean[4];
		
		Paciente paciente = null;
		
		do {
			
			do {
				isValid[0] = false;
				
				nome = View.solicitarString("Digite o nome do paciente: ", titulo);
				
				if(nome != null) {
					if(!nome.isEmpty()) {
						isValid[0] = true;
					}
				}
				
				if(!isValid[0]) {
					View.exibirErro("Nome inválido! Digite novamente...");
				}
				
			} while (!isValid[0]);
			
			do {
				isValid[1] = false;
				
				try {
					idade = View.solicitarInt("Digite a idade do paciente: ", titulo);
					
					if(idade > 0 && idade <= 18) {
						isValid[1] = true;
					} else {
						View.exibirErro("Idade inválida! Digite novamente...");
					}
					
				} catch (NumberFormatException e) {
					View.exibirErro("Idade inválida! Digite novamente...");
				}

			} while (!isValid[1]);
			
			do {
				isValid[2] = false;
				
				telefone = View.solicitarString("Digite o número de telefone do paciente: ", titulo);
				
				if(telefone.matches("(\\(?\\d{2}\\)?\\s)?(\\d{4,5}\\d{4})")) {
					isValid[2] = true;
				} else {
					View.exibirErro("Telefone inválido! Digite novamente...");
				}
				
			} while (!isValid[2]);
			
			isValid[3] = isValid[0] && isValid[1] && isValid[2];
			
		} while (!isValid[3]);
		
		paciente = new Paciente(nome, idade, cpf, telefone);
		
		alergias = View.solicitarString("O paciente possui alergias? Se não, pressione ENTER: ", titulo);
		
		if (alergias == null) {
			paciente.setAlergias("Nenhuma");
		} else {
			paciente.setAlergias(alergias);
		}
		
		medicamentos = View.solicitarString("O paciente toma algum medicamento? Se não, pressione ENTER: ", titulo);
		
		if (medicamentos == null) {
			paciente.setMedicamentos("Nenhum");
		} else {
			paciente.setMedicamentos(medicamentos);
		}
		
		profMedico = View.selecionaLista("Selecione o médico requisitado: ", titulo, Clinica.getEspecialidades());
		
		paciente.getConsultas().push(new Consulta(View.solicitarString("Digite o motivo da consulta: ", titulo), profMedico));
		
		pacientes.add(paciente);
	}
	
	public void listaMedicosPresentes(ArrayList<Medico> medicos) {
		String cabecalho = "-- LISTA DE MÉDICOS PRESENTES --\n\n", txt = "";
		
		if (medicos.size() == 0) {
			View.exibirMensagem(cabecalho + "Nenhum médico está presente/disponível no momento.");
			return;
		}
		
		for (Medico medico : medicos) {
			if (medico.isPresente())
				txt += medico.toString() + "\n";
		}
		
		View.exibirMensagem(cabecalho + txt);
	}
	
	@Override
	public String toString() {
		return "NOME: " + this.getNome()
		+ " IDADE: " + this.getIdade()
		+ " CPF: " + this.getCpf()
		+ " TELEFONE: " + this.getTelefone()
		+ " FUNÇÃO: Secretária";
	}

	@Override
	public boolean isPresente() {
		return this.estaPresente;
	}
	
}
