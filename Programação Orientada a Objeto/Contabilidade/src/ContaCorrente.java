
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
			View.exibirErro("[Conta] Valor inválido.");
			return;
		}
		
		if (this.getSaldo() < valor) {
			throw new IllegalArgumentException("[Conta] Saldo insuficiente.");
		}
		
		if (valor <= 0) {
			throw new IllegalArgumentException("[Conta] Valor inválido.");
		}
		
		if (destino.getClass().equals(this.getClass())) {
			View.exibirMsg("Transferência inter-conta encontrada. Uma taxa de 0.5% será aplicada.");
			this.sacarSaldo(valor + (valor * 0.05));
			destino.depositarSaldo(valor);
			View.exibirMsg("Transferência completa. Seu saldo agora é de: R$ " + this.getSaldo());
		}
	}
	
}
