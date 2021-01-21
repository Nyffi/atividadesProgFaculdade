
public class Menus {
	public static boolean menuPrincipal (Campeonato campeonato) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Campeonato de Stock Car Brasil - - - - - \n"
										+ "1 - Adicionar um novo Piloto \n"
										+ "2 - Remover um Piloto \n"
										+ "3 - Checar lista de Pilotos \n"
										+ "4 - Iniciar Campeonato \n"
										+ "5 - Zerar Campeonato \n"
										+ "6 - Sair");
				
				switch (opcao) {
					case 1:
						campeonato.adicionarPiloto();
						break;
					case 2:
						campeonato.removerPiloto();
						break;
					case 3:
						Utils.exibirPilotos(campeonato.getPilotos());
						break;
					case 4:
						try {
							while (campeonato.getCorridas().size() != 0) {
								campeonato.iniciarCorrida();
								Utils.resultadoCorrida(campeonato);
							}
							Utils.resultadoCampeonato(campeonato);
						} catch (IllegalArgumentException e) {
							View.exibirErro(e.getMessage());
						}
						
						break;
					case 5:
						View.exibirMsg("[Campeonato] Campeonato zerado com sucesso.");
						return true;
					case 6:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 6);
		
		return false;
	}
}
