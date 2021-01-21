import java.util.ArrayList;

public class Contador extends Funcionario{
	public void gerarRelatorio(ArrayList<Cliente> clientes) {
		double valorCorrente = 0, valorEmpresarial = 0;
		
		if (clientes.size() == 0) {
			View.exibirMsg("RELATÓRIO - BANCO \n\n\nNão há nenhum Cliente cadastrado no momento.");
			return;
		}
		
		for (Cliente cliente : clientes) {
			if (cliente.getContaPF() != null) {
				valorCorrente += cliente.getContaPF().getSaldo();
			}
			if (cliente.getContaPJ() != null) {
				valorEmpresarial += cliente.getContaPJ().getSaldo();
			}
		}
		
		View.exibirMsg("RELATÓRIO - BANCO \n\n\nValor total das Contas Correntes: R$" + valorCorrente 
				     + "\n\nValor total das Contas Empresariais: R$" + valorEmpresarial 
				     + "\n\nValor total de todas as Contas cadastradas: R$" + (valorCorrente + valorEmpresarial));
	}
}
