package br.com.paulocesar.armazem.utils;

import java.util.Random;

public class Utils {
	static public boolean validaCPF (String cpf) {		//Valida��o incompleta por motivos educacionais
		if (cpf.isEmpty()) {
			View.exibirErro("CPF n�o informado.");
			return false;
		}
		
		cpf = cpf.replaceAll("[^0-9]", "");
		
		if (cpf.length() != 11) {
			View.exibirErro("CPF incompleto.");
			return false;
		} else if (	cpf.equals("00000000000") || cpf.equals("11111111111") || 
					cpf.equals("22222222222") || cpf.equals("33333333333") ||
					cpf.equals("44444444444") || cpf.equals("55555555555") || 
					cpf.equals("66666666666") || cpf.equals("77777777777") || 
					cpf.equals("88888888888") || cpf.equals("99999999999") ) {
			View.exibirErro("CPF inv�lido.");
			return false;
		}
		
		return true;
	}
	
	public static int gerarID (int min, int max) {
		Random rand = new Random();
		
		return rand.nextInt((max - min) + 1) + min;
	}
}
