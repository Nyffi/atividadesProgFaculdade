
public class ContaEmpresarial extends ContaBancaria{
	public ContaEmpresarial() {
		this.setSaldoMinimo(500);
	}

	@Override
	public void transferirSaldo(ContaBancaria destino) {
		// TODO Auto-generated method stub
		double valor; 
		
		try {
			valor = View.solicitarDouble("Digite o valor a ser transferido: \n\nOBS: Contas empresariais sofrem uma taxa de 1.0% em todas as transferências.");
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
		
		this.sacarSaldo(valor + (valor * 0.05));
		destino.depositarSaldo(valor);
		View.exibirMsg("Transferência completa. Seu saldo agora é de: R$ " + this.getSaldo());
	}
}
