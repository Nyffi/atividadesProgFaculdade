import java.util.ArrayList;

public class Zool�gico {
	private ArrayList<Mam�fero> mamiferos = new ArrayList<Mam�fero>();
	private ArrayList<R�ptil> repteis = new ArrayList<R�ptil>();
	private ArrayList<Inseto> insetos = new ArrayList<Inseto>();
	
	public Zool�gico() {
		Utils.iniciaMamifero(mamiferos);
		Utils.iniciaReptil(repteis);
		Utils.iniciaInseto(insetos);
	}
	
	public void adicionaMamifero() {
		Mam�fero temp = new Mam�fero();
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do animal: "));
			temp.setSom(View.solicitarString("Digite o tipo de som que o animal produz: "));
			temp.setDesc(View.solicitarString("Digite a descri��o do animal: "));
			mamiferos.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
	}
	
	public void adicionaReptil() {
		R�ptil temp = new R�ptil();
		
		try {
			temp.setNome(View.solicitarString("Digite o nome do animal: "));
			temp.setSom(View.solicitarString("Digite o tipo de som que o animal produz: "));
			temp.setDesc(View.solicitarString("Digite a descri��o do animal: "));
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
			temp.setDesc(View.solicitarString("Digite a descri��o do animal: "));
			insetos.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}

	}
	
	public void listaAnimais() {
		String msg = "Lista de animais do Zool�gico\n\n";
		
		msg += "MAM�FEROS\n";
		for (Mam�fero mamifero : mamiferos) {
			msg += mamifero.getNome() + "\n";
		}
		msg += "\n";
		
		msg += "R�PTEIS\n";
		for (R�ptil reptil : repteis) {
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
		
		for (Mam�fero mamifero : mamiferos) {
			if (mamifero.getNome().equals(nomeAnimal)) {
				mamifero.getDados();
				return;
			}
		}
		
		for (R�ptil reptil : repteis) {
			if (reptil.getNome().equals(nomeAnimal)) {
				reptil.getDados();
				return;
			}
		}
		
		View.exibirErro("N�o foi encontrado nenhum animal com esse nome.");
	}
	
	public void adicionaAnimal(String classeAnimal) {
		switch(classeAnimal) {
			case "Mam�fero":
				Mam�fero mamifero = new Mam�fero();
				try {
					mamifero.setNome(View.solicitarString("Digite o nome do mam�fero: "));
					mamifero.setSom(View.solicitarString("Digite o tipo de som que o mam�fero citado faz: "));
					mamifero.setDesc(View.solicitarString("Digite uma descri��o do mam�fero citado: "));
					mamiferos.add(mamifero);
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
					return;
				}
				
				break;
			case "R�ptil":
				R�ptil reptil = new R�ptil();
				try {
					reptil.setNome(View.solicitarString("Digite o nome do r�ptil: "));
					reptil.setSom(View.solicitarString("Digite o tipo de som que o r�ptil citado faz: "));
					reptil.setDesc(View.solicitarString("Digite uma descri��o do r�ptil citado: "));
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
					inseto.setDesc(View.solicitarString("Digite uma descri��o do inseto citado: "));
					insetos.add(inseto);
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
					return;
				}
				
				break;
			default:
				View.exibirErro("A classe do animal est� escrita errada ou n�o tem suporte. \n\nFavor escolha entre \"Mam�fero\", \"R�ptil\", e \"Inseto\".");
				return;
		}
	}
}
