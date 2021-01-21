
public class Executora {

	public static void main(String[] args) {
		boolean continua = true;
		
		do {
			Campeonato campeonato = new Campeonato();
			continua = Menus.menuPrincipal(campeonato);
		} while (continua == true);
		
	}
}
