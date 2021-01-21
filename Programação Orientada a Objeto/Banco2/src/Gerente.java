
public class Gerente extends Funcionario {
	public Gerente() {
		this.setSenha("1234");
		this.setAcessoAgencia(true);
		this.setAcessoCaixa(true);
		this.setAcessoCofre(true);
		this.setAcessoArquivo(true);
	}
}
