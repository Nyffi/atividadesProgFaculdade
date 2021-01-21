
public class Locacao {
	private Cliente cli;
	private Funcionario func;
	private Filme filme;
	private int idLoc;
	private boolean devolveu = false;
	
	public Cliente getCli() {
		return cli;
	}
	public void setCli(Cliente cli) {
		this.cli = cli;
	}
	public Funcionario getFunc() {
		return func;
	}
	public void setFunc(Funcionario func) {
		this.func = func;
	}
	public Filme getFilme() {
		return filme;
	}
	public void setFilme(Filme filme) {
		this.filme = filme;
	}
	public int getIdLoc() {
		return idLoc;
	}
	public void setIdLoc(int idLoc) {
		this.idLoc = idLoc;
	}
	public boolean isDevolveu() {
		return devolveu;
	}
	public void setDevolveu(boolean devolveu) {
		this.devolveu = devolveu;
	} 
	
}
