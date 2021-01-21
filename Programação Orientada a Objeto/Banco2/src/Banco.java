
public class Banco {
	private Funcionario func = new Funcionario();
	private Cliente cli = new Cliente();
	private Gerente ger = new Gerente();
	private Diretor dir = new Diretor();
	
	public void fazLogin(String cargo, String senha) {
		int nivelAcesso = 0;
		
		switch (cargo) {
			case "Cliente":
				if (cli.getSenha().equals(senha)) {
					View.exibirMsg("Logado com sucesso como Cliente.");
					Menus.menuCliente(this);
				}
				break;
			case "Funcionário":
				if (cargo.equals("Funcionário")) {
					nivelAcesso = 1;
				}
			case "Gerente":
				if (cargo.equals("Gerente")) {
					nivelAcesso = 2;
				}
			case "Diretor":
				if (cargo.equals("Diretor")) {
					nivelAcesso = 3;
				}
				if (func.getSenha().equals(senha)) {
					View.exibirMsg("Logado com sucesso como Funcionário.");
					Menus.menuFuncionario(this, nivelAcesso);
				} else if (ger.getSenha().equals(senha)) {
					View.exibirMsg("Logado com sucesso como Gerente.");
					Menus.menuFuncionario(this, nivelAcesso);
				} else if (dir.getSenha().equals(senha)) {
					View.exibirMsg("Logado com sucesso como Diretor.");
					Menus.menuFuncionario(this, nivelAcesso);
				}
				break;
		}
	}
}
