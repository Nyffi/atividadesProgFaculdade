package br.com.paulocesar.armazem.main;

public class Produto {

	private String nome;
	private String descricao;
	private int qntUn;
	private double preco;

	public String getNome() {
		return nome;
	}

	public String getDesc() {
		return descricao;
	}

	public int getQntUn() {
		return qntUn;
	}

	public double getPreco() {
		return preco;
	}
	
	public void setNome(String nome) {
		if (nome.length() > 4)
			this.nome = nome;
		else 
			throw new IllegalArgumentException("[Produto] Nome inv�lido.");
	}

	public void setDesc(String descricao) {
		if (descricao.length() > 4)
			this.descricao = descricao;
		else 
			throw new IllegalArgumentException("[Produto] Descri��o inv�lida.");
	}

	public void setQntUn(int qntLote) {
		if (qntLote >= 1)
			this.qntUn = qntLote;
		else 
			throw new IllegalArgumentException("[Produto] Quantia de Unidades inv�lida.");
	}
	
	public void setQntUn(int qntLote, boolean isVenda) {
		if (isVenda) {
			if (qntLote >= 1)
				this.qntUn -= qntLote;
			else
				throw new IllegalArgumentException("[VENDA] Atualiza��o de Quantia de Lotes dispon�vel inv�lida.");
		} else {
			if (qntLote >= 1)
				this.qntUn += qntLote;
			else
				throw new IllegalArgumentException("[REABASTECIMENTO] Atualiza��o de Quantia de Lotes dispon�vel inv�lida.");
		}
			
	}

	public void setPreco(double preco) {
		if (preco >= 1.0d)
			this.preco = preco;
		else 
			throw new IllegalArgumentException("[Produto] Pre�o inv�lido.");
	}

}

