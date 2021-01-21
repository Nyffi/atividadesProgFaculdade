
public class Conta {
	private int numero;
	private int agencia;
	private double saldo;
	private double limite = 250;
	private Cliente titular;
	
	Conta(int agencia, Cliente titular) {
		this.numero = Utils.gerarInt();
		this.setAgencia(agencia);
		this.saldo = 30;
		this.setTitular(titular);
	}

	public int getNumero() {
		return this.numero;
	}
	
	public int getAgencia() {
		return this.agencia;
	}

	public double getSaldo() {
		return this.saldo;
	}
	
	public double getLimite() {
		return this.limite;
	}
	
	public Cliente getTitular() {
		return this.titular;
	}
	
	public void setAgencia(int agencia) {
		if (agencia > 0) {
			this.agencia = agencia;
		} else {
			View.exibirErro("Agência inválida.");
		}
	}
	
	public void setLimite(double limite) {
		this.limite = limite;
	}

	public void setTitular(Cliente titular) {
		this.titular = titular;
	}

	public boolean depositar(double val) {
		if (val > 0) {
			saldo += val;
			return true;
		} else {
			View.exibirErro("Não foi possível proceder com o depósito.");
			return false;
		}
	}
	
	public boolean sacar (double val) {
		if (this.getSaldo() >= val) {
			saldo -= val;
			return true;
		} else {
			View.exibirErro("Não foi possível proceder com o saque.");
			return false;
		}
	}
	
	public boolean transferir (double val, Conta remetente) {
		if (this.sacar(val) && remetente.depositar(val)) {
			View.exibirMsg("A transferencia de R$ " + val + " foi feita com sucesso.");
			return true;
		} else {
			View.exibirErro("Houve um erro na transferência. Verifique seu saldo e tente novamente.");
			return false;
		}
	}
}
