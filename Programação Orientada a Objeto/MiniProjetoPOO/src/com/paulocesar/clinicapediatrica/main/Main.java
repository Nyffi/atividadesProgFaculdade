/*
 *                     MiniProjeto - POO
 * 
 * Alunos:
 * 		Paulo César de Lima Rocha - UC19105993
 * 		Rafael Coracini Basso     - UC19100102
 * 
 * Descrição:
 * 		Este sistema consiste em dispor processos  que auxiliam no 
 * funcionamento de uma clínica pediatra  em um hospital.  O fluxo
 * do programa consiste no cadastro de novos pacientes, na criação
 * de consultas (Para novos pacientes e  pacientes já existentes),
 * e  médicos  realizando o  atendimento dos  pacientes. Existem 4
 * especialidades  de médicos no  total: Pediatra, Oftalmologista,
 * Odontopediatra e Otorrinolaringologista. Existe também a classe
 * "Diretor", encarregada de administrar a clinica.
 * 
 */

package com.paulocesar.clinicapediatrica.main;

import com.paulocesar.clinicapediatrica.utils.Menus;


public class Main {

	public static void main(String[] args) {
				
		Clinica clinicaInfantil = new Clinica();
		Menus.m_Principal(clinicaInfantil);
		
	}

}
