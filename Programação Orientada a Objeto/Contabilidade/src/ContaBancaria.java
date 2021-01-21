
public abstract class ContaBancaria {
	private double saldoMinimo;
	private double saldo;
	
	public double getSaldoMinimo() {
		return saldoMinimo;
	}
	public void setSaldoMinimo(double saldoMinimo) {
		if (saldoMinimo > 0) 
			this.saldoMinimo = saldoMinimo;
		else
			throw new IllegalArgumentException("[CONTA] Saldo m�nimo inv�lido.");
	}
	public double getSaldo() {
		return saldo;
	}
	public void setSaldoInicial(double saldo) {
		if (saldo >= saldoMinimo)
			this.saldo = saldo;
		else
			throw new IllegalArgumentException("[CONTA] Saldo inicial n�o permitido. O m�nimo � de R$" + this.saldoMinimo);
	}
	
	public void sacarSaldo(double valor) {	
		if (valor > 0 && valor <= this.saldo) {
			this.saldo -= valor;
		} else {
			View.exibirErro("[Conta] Saldo insuficiente ou valor inv�lido.");
		}
				
	}
	
	public void depositarSaldo(double valor) {
		if (valor > 0)
			this.saldo += valor;
		else
			View.exibirErro("[Conta] O valor depositado n�o pode ser negativo.");
	}
	
	public abstract void transferirSaldo(ContaBancaria destino);

}
