package com.paulocesar.clinicapediatrica.utils;

import java.util.ArrayList;

import com.paulocesar.clinicapediatrica.main.Clinica;
import com.paulocesar.clinicapediatrica.main.Diretor;
import com.paulocesar.clinicapediatrica.main.Medico;
import com.paulocesar.clinicapediatrica.main.Paciente;
import com.paulocesar.clinicapediatrica.main.Secretaria;

public class Menus {
	public static void m_Principal(Clinica clinica) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Vis�o - - - - - \n"
						+ "1 - Secret�ria \n"
						+ "2 - M�dico \n"
						+ "3 - Diretor \n"
						+ "0 - Sair", null);

				switch (opcao) {
					case 1:
						Menus.m_Secretaria(clinica, clinica.getSecretaria());
						break;
					case 2:
						Medico medico;
						
						medico = clinica.getMedicosPorNome(View.selecionaLista("Selecione o m�dico: ", "LOGIN - M�DICO", clinica.getNomeMedicos()));
						
						Menus.m_Medico(clinica.getPacientes(), medico);
						break;
					case 3:
						Menus.m_Diretor(clinica, clinica.getDiretor());
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas n�meros.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Secretaria(Clinica clinica, Secretaria secretaria) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Secret�ria - - - - - \n"
						+ "1 - Cadastrar nova Consulta \n"
						+ "2 - Listar M�dicos presentes \n"
						+ "3 - Bater ponto \n"
						+ "0 - Sair", null);

				switch (opcao) {
					case 1:
						try {
							if(secretaria.isPresente()) {
								String cpf = View.solicitarString("Digite o CPF do paciente: ", "PESQUISA - PACIENTE");
								
								if (Utils.validaCPF(cpf)) {
									try {
										secretaria.cadastraConsulta(clinica.pesquisaPaciente(cpf));
									} catch (Exception e) {
										View.exibirMensagem("Nenhum CPF foi encontrado. Iniciando cadastro...");
										secretaria.cadastraConsulta(clinica.getPacientes(), cpf);
									}
								}
								
								clinica.ordernarPacientes();
							} else {
								View.exibirErro("Voc� deve bater o ponto primeiro!");
							}
						} catch (Exception e) {
							View.exibirErro("ERRO!");
						}
						break;
						
					case 2:
						if(secretaria.isPresente()) {
							clinica.displayInfo(0, "INFO: MEDICOS");
						} else {
							View.exibirErro("Voc� deve bater o ponto primeiro!");
						}
						break;
						
					case 3:
						secretaria.baterPonto();
						break;
						
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas n�meros.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Medico(ArrayList<Paciente> pacientes, Medico medico) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     M�dico - - - - - \n"
						+ "1 - Atender paciente \n"
						+ "2 - Bater ponto \n"
						+ "0 - Sair", null);

				switch (opcao) {
					case 1:
						
						if(medico.isPresente()) {
							Paciente pacienteTmp;
							
							pacienteTmp = medico.escolherPaciente(pacientes);
							
							if(pacienteTmp != null) {
								m_Medico_AtenderPaciente(medico, pacienteTmp);
							}
						} else {
							View.exibirErro("Voc� deve bater o ponto primeiro!");
						}
						
						break;
					case 2:
						medico.baterPonto();
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas n�meros.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Medico_AtenderPaciente(Medico medico, Paciente paciente) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Atender Paciente - - - - - \n"
						+ "1 - Verificar Informa��es \n"
						+ "2 - Prescrever Medicamento(s) \n"
						+ "3 - Prescrever Tratamento \n"
						+ "0 - Finalizar consulta", null);

				switch (opcao) {
					case 1:
						View.exibirMensagem(medico.getCompleteInfoFromPaciente(paciente));
						
						break;
					case 2:
						String medicamento;
						
						try {
							medicamento = View.solicitarString("Digite o(s) medicamento(s), ou ENTER caso n�o seja(m) necess�rio(s) medicamento(s): ", "Tratamento");
							
							if(medicamento == null) {
								paciente.getStackHead().setTratamento("N�o ser� necess�rio a aplica��o de medicamentos.");
							} else {
								paciente.getStackHead().setTratamento(medicamento);
							}
						} catch (Exception e) {
							View.exibirErro("Falha ao definir tratamento!");
						}
						
						break;
					case 3:
						String tratamento;
						
						try {
							tratamento = View.solicitarString("Digite o tratamento, ou ENTER caso n�o seja necess�rio tratamento: ", "Tratamento");
							
							if(tratamento == null) {
								paciente.getStackHead().setTratamento("N�o ser� necess�rio tratamento.");
							} else {
								paciente.getStackHead().setTratamento(tratamento);
							}
						} catch (Exception e) {
							View.exibirErro("Falha ao definir tratamento!");
						}
						break;
					case 0:
						paciente.getStackHead().finalizarConsulta();
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas n�meros.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Diretor(Clinica clinica, Diretor diretor) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Diretor - - - - - \n"
						+ "1 - Listar todos os Pacientes \n"
						+ "2 - Listar todos os Funcion�rios \n"
						+ "3 - Adicionar um M�dico \n"
						+ "4 - Remover um M�dico \n"
						+ "5 - Alterar Secret�ria \n"
						+ "6 - Alterar Diretor \n"
						+ "7 - Bater ponto \n"
						+ "0 - Sair", null);

				switch (opcao) {
					case 1:
						clinica.ordernarPacientes();
						clinica.displayInfo(1, "INFO: PACIENTES");
						break;
					case 2:
						clinica.ordernarMedicos();
						clinica.displayInfo(2, "INFO: FUNCION�RIOS");
						break;
					case 3:
						diretor.adicionarMedico(clinica.getMedicos());
						clinica.ordernarMedicos();
						break;
					case 4:
						diretor.removerMedico(View.solicitarString("Digite o nome do m�dico desejado: ", "REMO��O - M�DICO"), clinica.getMedicos());
						break;
					case 5:
						diretor.alterarSecretaria(clinica);
						break;
					case 6:
						diretor.alterarDiretor(clinica);
						break;
					case 7:
						diretor.baterPonto();
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas n�meros.");
			}
		} while (opcao != 0);
	}
}
