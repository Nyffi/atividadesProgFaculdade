/*
 *                     MiniProjeto - POO
 * 
 * Alunos:
 * 		Paulo C�sar de Lima Rocha - UC19105993
 * 		Rafael Coracini Basso     - UC19100102
 * 
 * Descri��o:
 * 		Este sistema consiste em dispor processos  que auxiliam no 
 * funcionamento de uma cl�nica pediatra  em um hospital.  O fluxo
 * do programa consiste no cadastro de novos pacientes, na cria��o
 * de consultas (Para novos pacientes e  pacientes j� existentes),
 * e  m�dicos  realizando o  atendimento dos  pacientes. Existem 4
 * especialidades  de m�dicos no  total: Pediatra, Oftalmologista,
 * Odontopediatra e Otorrinolaringologista. Existe tamb�m a classe
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
