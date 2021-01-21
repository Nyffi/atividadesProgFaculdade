
public class Cliente {
	private String cpf = null;
	private String cnpj = null;
	private String rg;
	private String nome;
	private ContaCorrente contaPF = null;
	private ContaEmpresarial contaPJ = null;
	private String senha;
	
	public String getSenha() {
		return senha;
	}
	public void setSenha(String senha) {
		if (senha.length() > 4)
			this.senha = senha;
		else
			throw new IllegalArgumentException("[Cliente] Senha insuficiente. Insira uma senha maior que 4 dígitos.");
	}
	public String getCpf() {
		return cpf;
	}
	public void setCpf(String cpf) {
		if (Utils.validaCPF(cpf)) {
			cpf = Utils.removeSimbolo(cpf);
			this.cpf = cpf;	
		}
		else
			throw new IllegalArgumentException("[Cliente] CPF inválido.");
	}
	public String getCnpj() {
		return cnpj;
	}
	public void setCnpj(String cnpj) {
		if (Utils.validaCNPJ(cnpj)) {
			cnpj = Utils.removeSimbolo(cnpj);
			this.cnpj = cnpj;
		}
		else
			throw new IllegalArgumentException("[Cliente] CNPJ inválido.");
	}
	public String getRg() {
		return rg;
	}
	public void setRg(String rg) {
		this.rg = rg;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		if (nome.length() > 4)
			this.nome = nome;
		else
			throw new IllegalArgumentException("[Cliente] Nome inválido.");
	}
	public ContaCorrente getContaPF() {
		return contaPF;
	}
	public void setContaPF(ContaCorrente contaPF) {
		this.contaPF = contaPF;
	}
	public ContaEmpresarial getContaPJ() {
		return contaPJ;
	}
	public void setContaPJ(ContaEmpresarial contaPJ) {
		this.contaPJ = contaPJ;
	}
	public void verSaldo() {
		String cabecalho = "SALDO - CLIENTE\n\n", txt = "";
		
		if (this.getContaPF() != null) {
			txt += "CONTA CORRENTE\nR$" + this.getContaPF().getSaldo();
		}
		
		txt += "\n\n";
		
		if (this.getContaPJ() != null) {
			txt += "CONTA EMPRESARIAL\nR$" + this.getContaPJ().getSaldo();
		}
		
		View.exibirMsg(cabecalho + txt);
	}
	public void depositarValor(double valor) {
		
		if (this.contaPF != null && this.contaPJ != null) {
			if (View.solicitarBoolean("Deseja depositar na Conta Empresarial?")) {
				this.contaPJ.depositarSaldo(valor);
			} else {
				this.contaPF.depositarSaldo(valor);
			}
		} else {
			if (this.contaPF != null) {
				this.contaPF.depositarSaldo(valor);
			} else {
				this.contaPJ.depositarSaldo(valor);
			}
		}
	}
	public void sacarValor(double valor) {
		if (this.contaPF != null && this.contaPJ != null) {
			if (View.solicitarBoolean("Deseja sacar da Conta Empresarial?")) {
				this.contaPJ.sacarSaldo(valor);
			} else {
				this.contaPF.sacarSaldo(valor);
			}
		} else {
			if (this.contaPF != null) {
				this.contaPF.sacarSaldo(valor);
			} else {
				this.contaPJ.sacarSaldo(valor);
			}
		}
	}
	
	public void transferirValor(double valor, Cliente dest) {
		if (dest == this) {
			View.exibirErro("O destinatário não pode ser você.");
			return;
		} else if (dest == null) {
			View.exibirErro("Destinatário não encontraado.");
			return;
		}
		
		this.sacarValor(valor);
		dest.depositarValor(valor);
	}
}
