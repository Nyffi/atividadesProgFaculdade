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
				opcao = View.solicitarInt("- - - - - Menu     Visão - - - - - \n"
						+ "1 - Secretária \n"
						+ "2 - Médico \n"
						+ "3 - Diretor \n"
						+ "0 - Sair", null);

				switch (opcao) {
					case 1:
						Menus.m_Secretaria(clinica, clinica.getSecretaria());
						break;
					case 2:
						Medico medico;
						
						medico = clinica.getMedicosPorNome(View.selecionaLista("Selecione o médico: ", "LOGIN - MÉDICO", clinica.getNomeMedicos()));
						
						Menus.m_Medico(clinica.getPacientes(), medico);
						break;
					case 3:
						Menus.m_Diretor(clinica, clinica.getDiretor());
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Secretaria(Clinica clinica, Secretaria secretaria) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Secretária - - - - - \n"
						+ "1 - Cadastrar nova Consulta \n"
						+ "2 - Listar Médicos presentes \n"
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
								View.exibirErro("Você deve bater o ponto primeiro!");
							}
						} catch (Exception e) {
							View.exibirErro("ERRO!");
						}
						break;
						
					case 2:
						if(secretaria.isPresente()) {
							clinica.displayInfo(0, "INFO: MEDICOS");
						} else {
							View.exibirErro("Você deve bater o ponto primeiro!");
						}
						break;
						
					case 3:
						secretaria.baterPonto();
						break;
						
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Medico(ArrayList<Paciente> pacientes, Medico medico) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Médico - - - - - \n"
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
							View.exibirErro("Você deve bater o ponto primeiro!");
						}
						
						break;
					case 2:
						medico.baterPonto();
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Medico_AtenderPaciente(Medico medico, Paciente paciente) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Atender Paciente - - - - - \n"
						+ "1 - Verificar Informações \n"
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
							medicamento = View.solicitarString("Digite o(s) medicamento(s), ou ENTER caso não seja(m) necessário(s) medicamento(s): ", "Tratamento");
							
							if(medicamento == null) {
								paciente.getStackHead().setTratamento("Não será necessário a aplicação de medicamentos.");
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
							tratamento = View.solicitarString("Digite o tratamento, ou ENTER caso não seja necessário tratamento: ", "Tratamento");
							
							if(tratamento == null) {
								paciente.getStackHead().setTratamento("Não será necessário tratamento.");
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
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void m_Diretor(Clinica clinica, Diretor diretor) {
		int opcao = 999;

		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu     Diretor - - - - - \n"
						+ "1 - Listar todos os Pacientes \n"
						+ "2 - Listar todos os Funcionários \n"
						+ "3 - Adicionar um Médico \n"
						+ "4 - Remover um Médico \n"
						+ "5 - Alterar Secretária \n"
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
						clinica.displayInfo(2, "INFO: FUNCIONÁRIOS");
						break;
					case 3:
						diretor.adicionarMedico(clinica.getMedicos());
						clinica.ordernarMedicos();
						break;
					case 4:
						diretor.removerMedico(View.solicitarString("Digite o nome do médico desejado: ", "REMOÇÃO - MÉDICO"), clinica.getMedicos());
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
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
}
