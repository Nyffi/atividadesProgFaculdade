
public class Menus {
	public static void menuPrincipal(Zool�gico zoo) {
		int opcao;
		
		do {
			opcao = View.solicitarInt("- - - - - Menu  Zool�gico - - - - - \n"
									+ "1 - Listar todos os animais cadastrados \n"
									+ "2 - Procurar animal espec�fico \n"
									+ "3 - Adicionar animal \n"
									+ "4 - Sair");
			
			switch (opcao) {
				case 1:
					zoo.listaAnimais();
					break;
				case 2:
					zoo.pesquisaAnimal(View.solicitarString("Digite o nome do animal desejado: "));
					break;
				case 3:
					zoo.adicionaAnimal(View.solicitarString("Digite a classe do animal, \"Mam�fero\", \"R�ptil\", ou \"Inseto\": "));
					break;
				case 4:
					break;
			}
		} while (opcao != 4);
	}
}
