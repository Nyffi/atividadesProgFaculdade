
public class ContaCorrente extends ContaBancaria{
	public ContaCorrente() {
		this.setSaldoMinimo(100);
	}

	@Override
	public void transferirSaldo(ContaBancaria destino) {
		// TODO Auto-generated method stub
		double valor; 
		
		try {
			valor = View.solicitarDouble("Digite o valor a ser transferido: ");
		} catch (NumberFormatException e) {
			View.exibirErro("[Conta] Valor inv�lido.");
			return;
		}
		
		if (this.getSaldo() < valor) {
			throw new IllegalArgumentException("[Conta] Saldo insuficiente.");
		}
		
		if (valor <= 0) {
			throw new IllegalArgumentException("[Conta] Valor inv�lido.");
		}
		
		if (destino.getClass().equals(this.getClass())) {
			View.exibirMsg("Transfer�ncia inter-conta encontrada. Uma taxa de 0.5% ser� aplicada.");
			this.sacarSaldo(valor + (valor * 0.05));
			destino.depositarSaldo(valor);
			View.exibirMsg("Transfer�ncia completa. Seu saldo agora � de: R$ " + this.getSaldo());
		}
	}
	
}
