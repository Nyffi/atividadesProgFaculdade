import java.util.ArrayList;

public class Zoológico {
	private ArrayList<Mamífero> mamiferos = new ArrayList<Mamífero>();
	private ArrayList<Réptil> repteis = new ArrayList<Réptil>();
	private ArrayList<Inseto> insetos = new ArrayList<Inseto>();
	
	public Zoológico() {
		Utils.iniciaMamifero(mamiferos);
		Utils.iniciaReptil(repteis);
		Utils.iniciaInseto(insetos);
	}
	
	public void adicionaMamifero() {
		Mamífero temp = new Mamífero();
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do animal: "));
			temp.setSom(View.solicitarString("Digite o tipo de som que o animal produz: "));
			temp.setDesc(View.solicitarString("Digite a descrição do animal: "));
			mamiferos.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
	}
	
	public void adicionaReptil() {
		Réptil temp = new Réptil();
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do animal: "));
			temp.setSom(View.solicitarString("Digite o tipo de som que o animal produz: "));
			temp.setDesc(View.solicitarString("Digite a descrição do animal: "));
			repteis.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
		
	}
	
	public void adicionaInseto() {
		Inseto temp = new Inseto();
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do animal: "));
			temp.setSom(View.solicitarString("Digite o tipo de som que o animal produz: "));
			temp.setDesc(View.solicitarString("Digite a descrição do animal: "));
			insetos.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}

	}
	
	public void listaAnimais() {
		String msg = "Lista de animais do Zoológico\n\n";
		
		msg += "MAMÍFEROS\n";
		for (Mamífero mamifero : mamiferos) {
			msg += mamifero.getNome() + "\n";
		}
		msg += "\n";
		
		msg += "RÉPTEIS\n";
		for (Réptil reptil : repteis) {
			msg += reptil.getNome() + "\n";
		}
		msg += "\n";
		
		msg += "INSETOS\n";
		for (Inseto inseto : insetos) {
			msg += inseto.getNome() + "\n";
		}
		
		View.exibirMsg(msg);
	}
	
	public void pesquisaAnimal(String nomeAnimal) {
		for (Inseto inseto : insetos) {
			if (inseto.getNome().equals(nomeAnimal)) {
				inseto.getDados();
				return;
			}
		}
		
		for (Mamífero mamifero : mamiferos) {
			if (mamifero.getNome().equals(nomeAnimal)) {
				mamifero.getDados();
				return;
			}
		}
		
		for (Réptil reptil : repteis) {
			if (reptil.getNome().equals(nomeAnimal)) {
				reptil.getDados();
				return;
			}
		}
		
		View.exibirErro("Não foi encontrado nenhum animal com esse nome.");
	}
	
	public void adicionaAnimal(String classeAnimal) {
		switch(classeAnimal) {
			case "Mamífero":
				Mamífero mamifero = new Mamífero();
				try {
					mamifero.setNome(View.solicitarString("Digite o nome do mamífero: "));
					mamifero.setSom(View.solicitarString("Digite o tipo de som que o mamífero citado faz: "));
					mamifero.setDesc(View.solicitarString("Digite uma descrição do mamífero citado: "));
					mamiferos.add(mamifero);
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
					return;
				}
				
				break;
			case "Réptil":
				Réptil reptil = new Réptil();
				try {
					reptil.setNome(View.solicitarString("Digite o nome do réptil: "));
					reptil.setSom(View.solicitarString("Digite o tipo de som que o réptil citado faz: "));
					reptil.setDesc(View.solicitarString("Digite uma descrição do réptil citado: "));
					repteis.add(reptil);
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
					return;
				}
				
				break;
			case "Inseto":
				Inseto inseto = new Inseto();
				try {
					inseto.setNome(View.solicitarString("Digite o nome do inseto: "));
					inseto.setSom(View.solicitarString("Digite o tipo de som que o inseto citado faz: "));
					inseto.setDesc(View.solicitarString("Digite uma descrição do inseto citado: "));
					insetos.add(inseto);
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
					return;
				}
				
				break;
			default:
				View.exibirErro("A classe do animal está escrita errada ou não tem suporte. \n\nFavor escolha entre \"Mamífero\", \"Réptil\", e \"Inseto\".");
				return;
		}
	}
}
