
public class Menus {
	public static void menuLogin(Banco banco) {
		String cargo, senha;
		
		do {
			cargo = View.solicitarString("Digite o cargo desejado: \n\nCliente\nFuncionário\nGerente\nDiretor\n");
		} while(cargo.length() < 5);
		
		do {
			senha = View.solicitarString("Digite a senha: ");
		} while(senha.length() < 3);
		
		banco.fazLogin(cargo, senha);
	}
	
	public static void menuCliente(Banco banco) {
		
	}
	
	public static void menuFuncionario(Banco banco, int nivelAcesso) {
		if (nivelAcesso <= 0 || nivelAcesso > 3) {
			View.exibirErro("[ERRO] Nível de acesso inválido.");
			return;
		}
		
		
	}
}
