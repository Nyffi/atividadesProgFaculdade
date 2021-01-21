package com.paulocesar.clinicapediatrica.main;

import java.util.ArrayList;

import com.paulocesar.clinicapediatrica.utils.View;

public class Medico extends Pessoa implements Funcionario{
	
	// ATRIBUTOS
	
	private boolean presente = false;
	private String especialidade;

	// CONSTRUTOR
	
	public Medico(String nome, int idade, String cpf, String telefone, int indexEspecialidade) {
		super(nome, idade, cpf, telefone);
		this.setEspecialidade(indexEspecialidade);
	}

	// GETTERS & SETTERS
	
	public String getEspecialidade() {
		return especialidade;
	}

	public void setEspecialidade(int indexEspecialidade) {
		this.especialidade = Clinica.getEspecialidades()[indexEspecialidade];
	}

	public boolean isPresente() {
		return presente;
	}
	
	// MÉTODOS
	
	public Paciente escolherPaciente(ArrayList<Paciente> pacientes) {
		
		ArrayList<Object[]> listaPacientes = new ArrayList<Object[]>();
		Object[] listaPacientesFormatada;
		String pacienteEscolhido;
		Paciente p = null;
		
		for (int i = 0; i < pacientes.size(); i++) {
			if (pacientes.get(i).getStackHead().getMedicoRequisitado().equals(this.getEspecialidade()) && pacientes.get(i).getStackHead().isActive() == true) {
				listaPacientes.add(new Object[] {new String(pacientes.get(i).getNome() + " - " + pacientes.get(i).getIdade()), i});
			}
		}

		if(listaPacientes.size() == 0) {
			View.exibirMensagem("Não existem pacientes listados para serem atendidos por sua especialidade!");
		} else {
			listaPacientesFormatada = new Object[listaPacientes.size()];
			
			for (int i = 0; i < listaPacientesFormatada.length; i++) {
				listaPacientesFormatada[i] = listaPacientes.get(i)[0];
			}
			
			pacienteEscolhido = View.selecionaLista("Selecione o paciente: ", "SELECIONAR PACIENTE", listaPacientesFormatada);
			
			for (int i = 0; i < listaPacientes.size(); i++) {
				if(pacienteEscolhido.equals(listaPacientes.get(i)[0])) {
					p = pacientes.get(i);
				}
			}
			
		}
		
		return p;
		
	}
	
	public void prescreverMedicamentos(Paciente p) {
		String medicamento;
		
		medicamento = View.solicitarString("Prescreva os medicamentos para " + p.getNome() + ":\n\n", "PRESCREVER MEDICAMENTOS");
		
		if(medicamento != null) {
			p.getStackHead().setReceitaRemedios(medicamento);
		} else {
			View.exibirErro("Falha ao registrar medicamentos!");
		}	
	}
	
	public void prescreverTratamento(Paciente p) {
		String tratamento;
		
		tratamento = View.solicitarString("Prescreva o tratamento para " + p.getNome() + ":\n\n", "PRESCREVER TRATAMENTO");
		
		if(tratamento != null) {
			p.getStackHead().setTratamento(tratamento);
		} else {
			View.exibirErro("Falha ao registrar tratamento!");
		}	
		

	}
	
	public String getCompleteInfoFromPaciente(Paciente p) {
		String info = "";
		
		info += p.toString() + "\n"
				+ "MEDICAMENTOS: " + p.getMedicamentos()  + "\n"
				+ "ALERGIAS: " + p.getAlergias();
		
		return info;
	}
	
	@Override
	public void baterPonto() {
		this.presente = !this.presente;
		
		if(this.presente) {
			System.out.println(this.getNome() + " - " + this.getEspecialidade()+ " - " + " bateu o ponto! [ENTRADA]");
		} else {
			System.out.println(this.getNome() + " - " + this.getEspecialidade()+ " - " + " bateu o ponto! [SAÍDA]");
		}
		
	}
	
	@Override
	public String toString() {
		String data = "[" + this.getEspecialidade().toUpperCase() + "] " + super.toString();
		
		return data;
	}
	
}
