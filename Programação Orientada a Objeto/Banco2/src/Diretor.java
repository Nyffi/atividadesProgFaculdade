
public class Diretor extends Funcionario {
	public Diretor() {
		this.setSenha("1234");
		this.setAcessoAgencia(true);
		this.setAcessoCaixa(false);
		this.setAcessoCofre(true);
		this.setAcessoArquivo(true);
	}
}
