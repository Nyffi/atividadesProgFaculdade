import java.util.ArrayList;

public class Filial {
	private ArrayList<Locacao> pedidos = new ArrayList<Locacao>(); 
	private ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();
	
	public void addFuncionario () {
		if (this.funcionarios.size() == 2) {
			View.exibirErro("Cada filial deve ter, no máximo, 2 funcionários.");
			return;
		}
		Funcionario func = new Funcionario();
		func.setNomeFunc(View.solicitarString("Digite o nome do funcionário: "));
		func.setIdFunc(Utils.gerarInt());
		this.funcionarios.add(func);
	}
	
	public void abrirPedido (Cliente cli, Funcionario func, Filme filme) {
		if (cli.podeAlugar() && filme.alugado == false) {
			Locacao temp = new Locacao();
			cli.setFilmesAlocados(filme);
			filme.alugado = true;
			temp.setCli(cli);
			temp.setFilme(filme);
			temp.getFilme().alugado = true;
			temp.setFunc(func);
			temp.setIdLoc(Utils.gerarInt());
			this.pedidos.add(temp);
		} else {
			View.exibirErro("O filme já foi alugado ou o cliente já possui 2 aluguéis ativos.");
			return;
		}
	}
	
	public void fecharPedido (Cliente cli, Filme filme) {
		int i, j;
		boolean infoCorreta = true;
		
		for (i = 0; i < this.pedidos.size(); i++) {
			for (j = 0; j < 2; j++) {
				if (this.pedidos.get(i).getFilme().equals(filme) == true && cli.getFilmesAlocados().get(j).equals(filme)) {
					this.pedidos.get(i).getFilme().alugado = false;
					this.pedidos.get(i).setDevolveu(true);
					cli.getFilmesAlocados().remove(i);
					infoCorreta = true;
					View.exibirMsg("O filme foi devolvido e os dados foram atualizados");
					break;
				} else {
					infoCorreta = false;
				}
			}
			
			if (infoCorreta) {
				break;
			}
		}
		
		if (!infoCorreta)
			View.exibirErro("O filme não existe ou não foi alugado pelo cliente fornecido.");
	}
	
	public void concluirPedido (Locacao pedido) {
		Filme temp = new Filme();
		pedido.setDevolveu(true);
		temp = pedido.getFilme();
		temp.alugado = false;
		pedido.setFilme(temp);
		View.exibirMsg("O pedido foi concluido e fechado. O filme voltou a estar disponível.");
	}
	
	public ArrayList<Funcionario> getFunc() {
		return this.funcionarios;
	}
	
	public void getPedidos() {
		for (Locacao i : pedidos) {
			View.exibirMsg("Cliente: " + i.getCli().getNome() + "\nFuncionário: " + i.getFunc().getNomeFunc() + "\nFilme: " + i.getFilme().nome + "\nID: " + i.getIdLoc() + "\n\nFoi devolvido? " + i.isDevolveu());
		}
	}
}
