package com.paulocesar.clinicapediatrica.main;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import javax.swing.JFrame;

import com.paulocesar.clinicapediatrica.utils.DisplayInfoWindow;
import com.paulocesar.clinicapediatrica.utils.View;

public class Clinica {
	
	private static String[] especialidades = {
			"Pediatra",							// ID = 0
			"Oftalmologista",					// ID = 1
			"Odontopediatra",					// ID = 2
			"Otorrinolaringologista"			// ID = 3
	};
	
	private ArrayList<Paciente> pacientes = new ArrayList<Paciente>();
	private ArrayList<Medico> medicos = new ArrayList<Medico>();
	private Secretaria secretaria;
	private Diretor diretor;
	
	public Clinica() {			//Registros base para Debug
		this.setDiretor(new Diretor("Dr. Hanz Chucrute", 52, "322.789.504-87", "(93) 993088889"));
		this.setSecretaria(new Secretaria("Srta. Bellum", 26, "679.522.384-18", "(93) 987982874"));
		this.medicos.add(new Medico("Dr. Pimpolho", 48, "909.409.581-55", "(61) 988281080", 0));
		this.medicos.add(new Medico("Dr. Gregory House", 61, "483.085.581-94", "(61) 994045587", 1));
		this.medicos.add(new Medico("Dr. Rey", 59, "930.697.921-54", "(61) 994803890", 2));
		this.medicos.add(new Medico("Dr. Victor Frankenstein", 78, "698.487.581-19", "(62) 33282498", 3));
	}

	public Secretaria getSecretaria() {
		return secretaria;
	}

	public void setSecretaria(Secretaria secretaria) {
		this.secretaria = secretaria;
	}

	public Diretor getDiretor() {
		return diretor;
	}

	public void setDiretor(Diretor diretor) {
		this.diretor = diretor;
	}

	public ArrayList<Paciente> getPacientes() {
		return pacientes;
	}

	public ArrayList<Medico> getMedicos() {
		return medicos;
	}

	public static String[] getEspecialidades() {
		return especialidades;
	}
	
	public Paciente pesquisaPaciente(String cpf) {
		for (Paciente paciente : pacientes) {
			if (paciente.getCpf().equals(cpf)) {
				return paciente;
			}
		}
		
		return null;
	}
	
	public Medico pesquisaMedico(String cpf) {
		for (Medico medico : medicos) {
			if (medico.getCpf().equals(cpf)) {
				return medico;
			}
		}
		
		return null;
	}
	
	public Object[] getNomeMedicos() {
		Object[] info = new Object[getMedicos().size()];
		
		for (int i = 0; i < getMedicos().size(); i++) {
			info[i] = (String) getMedicos().get(i).getNome();
		}
		
		return info;
	}
	
	public Medico getMedicosPorNome(String input) {
		Medico m = null;
		
		for (int i = 0; i < getMedicos().size(); i++) {
			if(input.equalsIgnoreCase(getMedicos().get(i).getNome())) {
				m = getMedicos().get(i);
			}
		}
		
		return m;
		
	}
	
	public void ordernarPacientes() {
		Collections.sort(this.pacientes, new Comparator<Paciente>() {
		    @Override
		    public int compare(Paciente s1, Paciente s2) {
		        return s1.getNome().compareToIgnoreCase(s2.getNome());
		    }
		});
	}
	
	public void ordernarMedicos() {		
		Collections.sort(this.medicos, new Comparator<Medico>() {
		    @Override
		    public int compare(Medico s1, Medico s2) {
		        return s1.getNome().compareToIgnoreCase(s2.getNome());
		    }
		});
	}
	
	public String retornaInformacaoHTML(int index) { // int 
		String output = "";
		
		/* 
		 * MEDICO = 0
		 * PACIENTE = 1
		 * FUNCIONARIOS = 2;
		 */
		
		switch (index) {
		case 0:
			output += "<h2 align=\"center\">MEDICOS</h2>";
			
			if(!this.getMedicos().isEmpty()) {
				for (Medico m : this.getMedicos()) {
					output += "<p>"
							+ "<b>NOME</b>: " + m.getNome() + "<br>"
							+ "<b>IDADE</b>: " + m.getIdade() + "<br>"
							+ "<b>CPF</b>: " + m.getCpf() + "<br>"
							+ "<b>TELEFONE</b>: " + m.getTelefone() + "<br>"
							+ "<b>ESPECIALIDADE</b>: " + m.getEspecialidade()
							+"<p><hr style=\"heigth:100%\">";
				}
			} else {
				output += "<br><br><br><br><br><br><br><br><h3 align=\"center\"> NÃO EXISTEM MÉDICOS CADASTRADOS </h3>";
			}
			
			break;
			
		case 1:
			output += "<h2 align=\"center\">PACIENTES</h2>";
			
			if(!this.getPacientes().isEmpty()) {

				for (Paciente p : this.getPacientes()) {
					output += "<p>"
							+ "<b>NOME</b>: " + p.getNome() + "<br>"
							+ "<b>IDADE</b>: " + p.getIdade() + "<br>"
							+ "<b>CPF</b>: " + p.getCpf() + "<br>"
							+ "<b>TELEFONE</b>: " + p.getTelefone() + "<br>"
							+"<p><hr style=\"heigth:100%\">";
				}
			} else {
				output += "<br><br><br><br><br><br><br><br><h3 align=\"center\"> NÃO EXISTEM PACIENTES CADASTRADOS </h3>";
			}
			
			break;
			
		case 2:
			
			output += "<h2 align=\"center\">FUNCIONÁRIOS</h2><br>";
			
			output += "<h2 align=\"center\">Diretor</h2>";
			
			if(this.getDiretor() != null) {
				
				Diretor d = this.getDiretor();
				
				output += "<p>"
						+ "<b>NOME</b>: " + d.getNome() + "<br>"
						+ "<b>IDADE</b>: " + d.getIdade() + "<br>"
						+ "<b>CPF</b>: " + d.getCpf() + "<br>"
						+ "<b>TELEFONE</b>: " + d.getTelefone() + "<br>"
						+"<p><hr style=\"heigth:100%\">";
			} else {
				output += "<h3 align=\"center\"> NÃO HÁ DIRETOR CADASTRADO! </h3><hr>";
			}
			
			output += "<h2 align=\"center\">Secretária</h2>";
			
			if(this.getSecretaria() != null) {
				
				Secretaria s = this.getSecretaria();
				
				output += "<p>"
						+ "<b>NOME</b>: " + s.getNome() + "<br>"
						+ "<b>IDADE</b>: " + s.getIdade() + "<br>"
						+ "<b>CPF</b>: " + s.getCpf() + "<br>"
						+ "<b>TELEFONE</b>: " + s.getTelefone() + "<br>"
						+"<p><hr style=\"heigth:100%\">";
			} else {
				output += "<h3 align=\"center\"> NÃO HÁ SECRETÁRIA CADASTRADA! </h3><hr>";
			}
			
			output += "<h2 align=\"center\">Médicos</h2>";
			
			if(!this.getMedicos().isEmpty()) {
				for (Medico m : this.getMedicos()) {
					output += "<p>"
							+ "<b>NOME</b>: " + m.getNome() + "<br>"
							+ "<b>IDADE</b>: " + m.getIdade() + "<br>"
							+ "<b>CPF</b>: " + m.getCpf() + "<br>"
							+ "<b>TELEFONE</b>: " + m.getTelefone() + "<br>"
							+ "<b>ESPECIALIDADE</b>: " + m.getEspecialidade()
							+"<p>";
				}
			} else {
				output += "<h3 align=\"center\"> NÃO EXISTEM MÉDICOS CADASTRADOS </h3>";
			}
			
			break;
		}
		
		return output;
	}
	
	public void displayInfo(int index, String titulo) {
		View.initFrameDisplayInfoWindow(new JFrame(), this.retornaInformacaoHTML(index), titulo);
		while(DisplayInfoWindow.windowIsOpened) {try {Thread.sleep(50);} catch (InterruptedException e) {}}
	}
	
}
