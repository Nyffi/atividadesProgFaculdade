public class Jogo {

	private String nome = null;
	private String descricao = null;
	private double preco = -1;
	private long copiasVendidas = 0;

	public String getNome() {
		return this.nome;
	}

	public void setNome(String nome) {
		if (nome.length() >= 2)
			this.nome = nome;
		else
			throw new IllegalArgumentException("[Jogo] O nome é muito curto.");
	}

	public String getDesc() {
		return this.descricao;
	}

	public void setDesc(String descricao) {
		if (descricao.length() >= 15)
			this.descricao = descricao;
		else
			throw new IllegalArgumentException("[Jogo] A descrição é muito curta.");
	}

	public double getPreco() {
		return this.preco;
	}

	public void setPreco(double preco) {
		if (preco >= 0.0d) {
			this.preco = preco;
		} else {
			throw new IllegalArgumentException("[Jogo] O preço deve ser um valor positivo.");
		}
	}

	public long getCopiasVendidas() {
		return this.copiasVendidas;
	}

	public void addCopiaVendida() {
		this.copiasVendidas++;
	}

}
