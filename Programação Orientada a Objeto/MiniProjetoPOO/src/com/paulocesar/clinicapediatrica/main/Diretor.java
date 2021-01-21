package com.paulocesar.clinicapediatrica.main;

import java.util.ArrayList;

import com.paulocesar.clinicapediatrica.utils.View;

public class Diretor extends Pessoa implements Funcionario {
	
	private boolean estaPresente = false;

	public Diretor(String nome, int idade, String cpf, String telefone) {
		super(nome, idade, cpf, telefone);
	}
	
	public void listarPacientes(ArrayList<Paciente> pacientes) {
		String cabecalho = "LISTA - PACIENTES\n\n", txt = "";
		
		if (pacientes.size() == 0) {
			View.exibirMensagem(cabecalho + "N�o h� nenhum paciente cadastrado no momento.");
			return;
		}
		
		for (Paciente paciente : pacientes) {
			txt += paciente.toString() + "\n\n";
		}
		
		View.exibirMensagem(cabecalho + txt);
	}
	
	public void listarFuncionarios(ArrayList<Medico> medicos, Secretaria secretaria, Diretor diretor) {
		String cabecalho = "LISTA - FUNCION�RIOS\n\n", txt = "";
		
		txt += "DIRETOR\n\n" + diretor.toString() + "\n\n";
		txt += "SECRET�RIA\n\n" + secretaria.toString() + "\n\n";
		txt += "M�DICOS\n\n";
		
		if (medicos.size() == 0) {
			View.exibirMensagem(cabecalho + "N�o h� nenhum m�dico cadastrado no momento.");
			return;
		}
		
		for (Medico medico : medicos) {
			txt += medico.toString() + "\n\n";
		}
		
		View.exibirMensagem(cabecalho + txt);
	}
	
	public void adicionarMedico(ArrayList<Medico> medicos) {
		String titulo = "REGISTRO - M�DICO";
		Medico aux = null;
		
		try {
			aux = new Medico(View.solicitarString("Digite o nome do M�dico: ", titulo), 
							 View.solicitarInt("Digite a idade do m�dico:", titulo), 
							 View.solicitarString("Digite o CPF do m�dico: ", titulo), 
							 View.solicitarString("Digite o telefone do m�dico: ", titulo), 
							 View.solicitarInt("Selecione a fun��o do m�dico:\n\n"
							  				 + "0 - Pediatria\n"
											 + "1 - Oftalmologista\n"
											 + "2 - Odontopediatria\n"
											 + "3 - Otorrinolaringologista", titulo));
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
		
		
		medicos.add(aux);
	}
	
	public void removerMedico(String nome, ArrayList<Medico> medicos) {
		if (nome.length() <= 4) {
			View.exibirErro("Nome inv�lido.");
			return;
		}
		
		for (Medico medico : medicos) {
			if (medico.getNome().equalsIgnoreCase(nome)) {
				medicos.remove(medico);
				View.exibirMensagem("M�dico removido com sucesso.");
				return;
			}
		}
		
		View.exibirErro("N�o foi poss�vel encontrar o m�dico citado.");
	}
	
	public void alterarSecretaria(Clinica clinica) {
		String titulo = "REGISTRO - SECRET�RIA";
		
		Secretaria aux = new Secretaria(View.solicitarString("Digite o nome: ", titulo), 
										View.solicitarInt("Digite a idade:", titulo), 
										View.solicitarString("Digite o CPF: ", titulo), 
										View.solicitarString("Digite o telefone: ", titulo));
		
		clinica.setSecretaria(aux);
	}
	
	public void alterarDiretor(Clinica clinica) {
		String titulo = "REGISTRO - DIRETOR";
		
		this.setNome(View.solicitarString("Digite o nome: ", titulo));
		this.setIdade(View.solicitarInt("Digite a idade:", titulo));
		this.setCpf(View.solicitarString("Digite o CPF: ", titulo));
		this.setTelefone(View.solicitarString("Digite o telefone: ", titulo));
	}

	@Override
	public void baterPonto() {
		this.estaPresente = !this.estaPresente;
		
		if(this.estaPresente) {
			System.out.println(this.getNome() + " - Diretor - bateu o ponto! [ENTRADA]");
		} else {
			System.out.println(this.getNome() + " - Diretor - bateu o ponto! [SA�DA]");
		}
		
	}
	
	@Override
	public String toString() {
		return "NOME: " + this.getNome()
		+ " IDADE: " + this.getIdade()
		+ " CPF: " + this.getCpf()
		+ " TELEFONE: " + this.getTelefone()
		+ " FUN��O: Diretor";
	}

	@Override
	public boolean isPresente() {
		return this.estaPresente;
	}
	
}
