package com.paulocesar.clinicapediatrica.utils;

public class Utils {
	static public boolean validaCPF (String cpf) {		//Validação incompleta por motivos educacionais
		if (cpf.isEmpty()) {
			View.exibirErro("CPF não informado.");
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
			View.exibirErro("CPF inválido.");
			return false;
		}
		
		return true;
	}
	
}
