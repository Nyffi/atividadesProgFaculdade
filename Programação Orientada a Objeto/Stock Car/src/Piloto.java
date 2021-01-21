
public class Piloto {
	private String nome;
	private String tipoSangue;
	private int pontuacao = 0;
	private int tempoCorrida = 0;
	private int tempoVolta;
	
	public void setNome(String nome) {
		if (nome.length() >= 3) {
			this.nome = nome;
		} else {
			throw new IllegalArgumentException("[Piloto] Nome inválido.");
		}
	}
	
	public void setTipoSangue(String sangue) {
		if (sangue.length() > 0 || sangue.length() <= 3) {
			this.tipoSangue = sangue;
		} else {
			throw new IllegalArgumentException("[Piloto] Tipo sanguíneo inválido.");
		}
	}
	
	public int getPontuacao() {
		return pontuacao;
	}

	public void setPontuacao(int pontuacao) {
		this.pontuacao = this.pontuacao + pontuacao;
	}

	public int getTempoCorrida() {
		return tempoCorrida;
	}
	
	public int getTempoVolta() {
		return tempoVolta;
	}

	public String getNome() {
		return nome;
	}

	public String getTipoSangue() {
		return tipoSangue;
	}

	public void setTempoCorrida(boolean novaCorrida, int tempoMedioVolta) {
		if (novaCorrida) {
			this.tempoCorrida = 0;
		} else {
			this.setTempoVolta(tempoMedioVolta);
			this.tempoCorrida += this.tempoVolta;
		}
	}
	
	public void setTempoVolta(int tempoMedioVolta) {
		this.tempoVolta = tempoMedioVolta + Utils.randomInRangeInt(-100, 100);
	}
}
