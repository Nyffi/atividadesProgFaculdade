import java.util.ArrayList;
import java.util.Random;

public class Utils {
	public static void iniciaFiliais(Filial fil[]) {
		int i;
		
		for (i = 0; i <= 2; i++) {
			fil[i] = new Filial();
			fil[i].addFuncionario();
			fil[i].addFuncionario();
		}
	}
	
	public static void adicionaCliente(ArrayList<Cliente> cli) {
		Cliente temp = new Cliente();
		temp.setNome(View.solicitarString("Digite o nome do cliente: "));
		temp.setId(Utils.gerarInt());
		cli.add(temp);
	}
	
	public static void adicionaFilme(ArrayList<Filme> filme) {
		if (filme.size() == 10) {
			View.exibirErro("O limite é de 10 filmes apenas.");
			return;
		}
		
		Filme temp = new Filme();
		temp.nome = View.solicitarString("Digite o nome do filme: ");
		temp.id = Utils.gerarInt();
		filme.add(temp);
	}
	
	public static int gerarInt() {
		Random rand = new Random();
		return rand.nextInt(999999);
	}
	
}
