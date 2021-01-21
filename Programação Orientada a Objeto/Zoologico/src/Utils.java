import java.util.ArrayList;

public class Utils {
	public static void iniciaMamifero(ArrayList<Mamífero> mamiferos) {
		Mamífero aux = new Mamífero();
		
		aux.setNome("Capivara");
		aux.setDesc("É o maior roedor do mundo, pesando até 91 kg e medindo até 1,2 m de comprimento e 60 cm de altura. "
				+ "A pelagem é densa, de cor avermelhada a marrom escuro.");
		aux.setSom("Grito");
		
		mamiferos.add(aux);
		aux = new Mamífero();
		
		aux.setNome("Tamanduá-Bandeira");
		aux.setDesc("É a maior das quatro espécies de tamanduás e, junto com as preguiças, está incluído na ordem Pilosa. "
				+ "Tem hábito predominantemente terrestre, diferente de seus parentes próximos, o tamanduá-mirim e o tamanduaí, que são arborícolas. "
				+ "O animal mede entre 1,8 e 2,1 metros de comprimento e pesa até 41 kg. "
				+ "É facilmente reconhecido pelo seu focinho longo e padrão característico de pelagem.");
		aux.setSom("Rugido (Adulto), Assobio (Filhote)");
		
		mamiferos.add(aux);
		aux = new Mamífero();
		
		aux.setNome("Lobo-Guará");
		aux.setDesc("É o maior canídeo da América do Sul, podendo atingir entre 20 e 30 kg de peso e até 90 cm na altura da cernelha. "
				+ "Suas pernas longas e finas e a densa pelagem avermelhada lhe conferem uma aparência inconfundível.");
		aux.setSom("Latido");
		
		mamiferos.add(aux);
	}
	
	public static void iniciaReptil(ArrayList<Réptil> repteis) {
		Réptil aux = new Réptil();
		
		aux.setNome("Dragão-de-komodo");
		aux.setDesc("Pertence à família de lagartos-monitores Varanidae, e é a maior espécie de lagarto conhecida, "
				+ "chegando a atingir 40 cm de altura e 2–3 m de comprimento e até 166 kg de peso no caso dos maiores indivíduos. "
				+ "O seu tamanho invulgar é atribuído a gigantismo insular, uma vez que não há outros animais carnívoros para "
				+ "preencher o nicho ecológico nas ilhas onde ele vive, e também ao seu baixo metabolismo.");
		aux.setSom("Silvo");
		
		repteis.add(aux);
		aux = new Réptil();
		
		aux.setNome("Jacaré");
		aux.setDesc("É muito parecido com o crocodilo, do qual se distingue pela cabeça mais curta e larga e pela presença de membranas "
				+ "interdigitais nos polegares das patas traseiras. Diferencia-se dos crocodilos ainda com relação à dentição, o quarto "
				+ "dente canino da mandíbula inferior encaixa num furo da mandíbula superior, enquanto que nos crocodilos sobressai para fora, "
				+ "quando têm a boca fechada.");
		aux.setSom("Rugido");
		
		repteis.add(aux);
		aux = new Réptil();
		
		aux.setNome("Cascavel");
		aux.setDesc("Por razões não bem entendidas, em vez de sair completamente de sua pele antiga, elas mantém parte dela enrolada na cauda "
				+ "em forma de um anel cinzento grosseiro. Com o correr dos anos, estes pedaços de epiderme ressecados formam os guizos que, "
				+ "quando o animal vibra a cauda, balançam e causam o ruído característico.");
		aux.setSom("Silvo, Chocalho (Cauda)");
		
		repteis.add(aux);
	}
	
	public static void iniciaInseto(ArrayList<Inseto> insetos) {
		Inseto aux = new Inseto();
		
		aux.setNome("Grilo");
		aux.setDesc("Tem seu corpo um pouco achatado e longas antenas. Existem cerca de 900 espécies de grilos. "
				+ "Eles tendem a ser noturnos e são frequentemente confundidos com gafanhotos porque possuem uma estrutura corporal "
				+ "semelhante incluindo saltar as patas traseiras. Grilos são inofensivos aos seres humanos.");
		aux.setSom("Estridulação");
		
		insetos.add(aux);
		aux = new Inseto();
		
		aux.setNome("Abelha");
		aux.setDesc("É um inseto voador, conhecido pelo seu importante papel na polinização. As espécies de abelhas nativas das Américas e "
				+ "Oceania não possuem ferrão e são menos agressivas do que as espécies africanas, a maioria destas pertence à tribo "
				+ "Meliponini. As abelhas com ferrão encontradas comumente no Brasil são espécies híbridas de abelhas europeias e "
				+ "africanas, criadas para maior produtividade e resistência.");
		aux.setSom("Zumbido");
		
		insetos.add(aux);
		aux = new Inseto();
		
		aux.setNome("Mariposa Atlas");
		aux.setDesc("É considerada a maior mariposa do mundo em termos de área de superfície total da asa (para mais de 400 cm²). "
				+ "Sua envergadura também é considerada entre as melhores, de 25–30 cm. As fêmeas são razoavelmente maiores e mais pesadas. "
				+ "As mariposas-atlas são tidas como nomeadas em homenagem ao titã da mitologia grega, Atlas, ou por suas asas com padrões tipo mapas.");
		aux.setSom("Nenhum");
		
		insetos.add(aux);
	}
}
