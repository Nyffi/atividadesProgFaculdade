import java.util.ArrayList;

public class Cliente {
	private String nome;
	private int id;
	private ArrayList<Filme> filmesAlocados = new ArrayList<Filme>();
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public ArrayList<Filme> getFilmesAlocados() {
		return filmesAlocados;
	}
	public boolean podeAlugar () {
		if (this.filmesAlocados.size() < 2)
			return true;
		else
			return false;
	}
	public void setFilmesAlocados(Filme filme) {
		if (this.podeAlugar() && filme.alugado == false) {
			this.filmesAlocados.add(filme);
		} else {
			View.exibirErro("O filme n�o est� dispon�vel ou o cliente j� possui a quantia m�xima de filmes alugados.");
			return;
		}
	}
}
