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
			View.exibirMensagem(cabecalho + "Não há nenhum paciente cadastrado no momento.");
			return;
		}
		
		for (Paciente paciente : pacientes) {
			txt += paciente.toString() + "\n\n";
		}
		
		View.exibirMensagem(cabecalho + txt);
	}
	
	public void listarFuncionarios(ArrayList<Medico> medicos, Secretaria secretaria, Diretor diretor) {
		String cabecalho = "LISTA - FUNCIONÁRIOS\n\n", txt = "";
		
		txt += "DIRETOR\n\n" + diretor.toString() + "\n\n";
		txt += "SECRETÁRIA\n\n" + secretaria.toString() + "\n\n";
		txt += "MÉDICOS\n\n";
		
		if (medicos.size() == 0) {
			View.exibirMensagem(cabecalho + "Não há nenhum médico cadastrado no momento.");
			return;
		}
		
		for (Medico medico : medicos) {
			txt += medico.toString() + "\n\n";
		}
		
		View.exibirMensagem(cabecalho + txt);
	}
	
	public void adicionarMedico(ArrayList<Medico> medicos) {
		String titulo = "REGISTRO - MÉDICO";
		Medico aux = null;
		
		try {
			aux = new Medico(View.solicitarString("Digite o nome do Médico: ", titulo), 
							 View.solicitarInt("Digite a idade do médico:", titulo), 
							 View.solicitarString("Digite o CPF do médico: ", titulo), 
							 View.solicitarString("Digite o telefone do médico: ", titulo), 
							 View.solicitarInt("Selecione a função do médico:\n\n"
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
			View.exibirErro("Nome inválido.");
			return;
		}
		
		for (Medico medico : medicos) {
			if (medico.getNome().equalsIgnoreCase(nome)) {
				medicos.remove(medico);
				View.exibirMensagem("Médico removido com sucesso.");
				return;
			}
		}
		
		View.exibirErro("Não foi possível encontrar o médico citado.");
	}
	
	public void alterarSecretaria(Clinica clinica) {
		String titulo = "REGISTRO - SECRETÁRIA";
		
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
			System.out.println(this.getNome() + " - Diretor - bateu o ponto! [SAÍDA]");
		}
		
	}
	
	@Override
	public String toString() {
		return "NOME: " + this.getNome()
		+ " IDADE: " + this.getIdade()
		+ " CPF: " + this.getCpf()
		+ " TELEFONE: " + this.getTelefone()
		+ " FUNÇÃO: Diretor";
	}

	@Override
	public boolean isPresente() {
		return this.estaPresente;
	}
	
}
