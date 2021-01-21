
public class Utils {
	static boolean validaCPF (String cpf) {		//Validação incompleta por motivos educacionais
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
	
	static boolean validaCNPJ (String cnpj) {	//Validação incompleta por motivos educacionais
		if (cnpj.isEmpty()) {
			View.exibirErro("CNPJ não informado.");
			return false;
		}
		
		cnpj = cnpj.replaceAll("[^0-9]", "");
		
		if (cnpj.length() != 14) {
			View.exibirErro("CNPJ incompleto.");
			return false;
		} else if (	cnpj.equals("00000000000000") || cnpj.equals("11111111111111") || 
					cnpj.equals("22222222222222") || cnpj.equals("33333333333333") ||
					cnpj.equals("44444444444444") || cnpj.equals("55555555555555") ||
					cnpj.equals("66666666666666") || cnpj.equals("77777777777777") || 
					cnpj.equals("88888888888888") || cnpj.equals("99999999999999") ) {
			View.exibirErro("CPF inválido.");
			return false;
		}
		
		return true;
	}
	
	static String removeSimbolo (String info) {
		String dados = info.replaceAll("[^0-9]", "");
		return dados;
	}
}
