
public class ContaEmpresarial extends ContaBancaria{
	public ContaEmpresarial() {
		this.setSaldoMinimo(500);
	}

	@Override
	public void transferirSaldo(ContaBancaria destino) {
		// TODO Auto-generated method stub
		double valor; 
		
		try {
			valor = View.solicitarDouble("Digite o valor a ser transferido: \n\nOBS: Contas empresariais sofrem uma taxa de 1.0% em todas as transfer�ncias.");
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
		
		this.sacarSaldo(valor + (valor * 0.05));
		destino.depositarSaldo(valor);
		View.exibirMsg("Transfer�ncia completa. Seu saldo agora � de: R$ " + this.getSaldo());
	}
}
