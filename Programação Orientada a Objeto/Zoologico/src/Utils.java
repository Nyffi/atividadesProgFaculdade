import java.util.ArrayList;

public class Utils {
	public static void iniciaMamifero(ArrayList<Mam�fero> mamiferos) {
		Mam�fero aux = new Mam�fero();
		
		aux.setNome("Capivara");
		aux.setDesc("� o maior roedor do mundo, pesando at� 91 kg e medindo at� 1,2 m de comprimento e 60 cm de altura. "
				+ "A pelagem � densa, de cor avermelhada a marrom escuro.");
		aux.setSom("Grito");
		
		mamiferos.add(aux);
		aux = new Mam�fero();
		
		aux.setNome("Tamandu�-Bandeira");
		aux.setDesc("� a maior das quatro esp�cies de tamandu�s e, junto com as pregui�as, est� inclu�do na ordem Pilosa. "
				+ "Tem h�bito predominantemente terrestre, diferente de seus parentes pr�ximos, o tamandu�-mirim e o tamandua�, que s�o arbor�colas. "
				+ "O animal mede entre 1,8 e 2,1 metros de comprimento e pesa at� 41 kg. "
				+ "� facilmente reconhecido pelo seu focinho longo e padr�o caracter�stico de pelagem.");
		aux.setSom("Rugido (Adulto), Assobio (Filhote)");
		
		mamiferos.add(aux);
		aux = new Mam�fero();
		
		aux.setNome("Lobo-Guar�");
		aux.setDesc("� o maior can�deo da Am�rica do Sul, podendo atingir entre 20 e 30 kg de peso e at� 90 cm na altura da cernelha. "
				+ "Suas pernas longas e finas e a densa pelagem avermelhada lhe conferem uma apar�ncia inconfund�vel.");
		aux.setSom("Latido");
		
		mamiferos.add(aux);
	}
	
	public static void iniciaReptil(ArrayList<R�ptil> repteis) {
		R�ptil aux = new R�ptil();
		
		aux.setNome("Drag�o-de-komodo");
		aux.setDesc("Pertence � fam�lia de lagartos-monitores Varanidae, e � a maior esp�cie de lagarto conhecida, "
				+ "chegando a atingir 40 cm de altura e 2�3 m de comprimento e at� 166 kg de peso no caso dos maiores indiv�duos. "
				+ "O seu tamanho invulgar � atribu�do a gigantismo insular, uma vez que n�o h� outros animais carn�voros para "
				+ "preencher o nicho ecol�gico nas ilhas onde ele vive, e tamb�m ao seu baixo metabolismo.");
		aux.setSom("Silvo");
		
		repteis.add(aux);
		aux = new R�ptil();
		
		aux.setNome("Jacar�");
		aux.setDesc("� muito parecido com o crocodilo, do qual se distingue pela cabe�a mais curta e larga e pela presen�a de membranas "
				+ "interdigitais nos polegares das patas traseiras. Diferencia-se dos crocodilos ainda com rela��o � denti��o, o quarto "
				+ "dente canino da mand�bula inferior encaixa num furo da mand�bula superior, enquanto que nos crocodilos sobressai para fora, "
				+ "quando t�m a boca fechada.");
		aux.setSom("Rugido");
		
		repteis.add(aux);
		aux = new R�ptil();
		
		aux.setNome("Cascavel");
		aux.setDesc("Por raz�es n�o bem entendidas, em vez de sair completamente de sua pele antiga, elas mant�m parte dela enrolada na cauda "
				+ "em forma de um anel cinzento grosseiro. Com o correr dos anos, estes peda�os de epiderme ressecados formam os guizos que, "
				+ "quando o animal vibra a cauda, balan�am e causam o ru�do caracter�stico.");
		aux.setSom("Silvo, Chocalho (Cauda)");
		
		repteis.add(aux);
	}
	
	public static void iniciaInseto(ArrayList<Inseto> insetos) {
		Inseto aux = new Inseto();
		
		aux.setNome("Grilo");
		aux.setDesc("Tem seu corpo um pouco achatado e longas antenas. Existem cerca de 900 esp�cies de grilos. "
				+ "Eles tendem a ser noturnos e s�o frequentemente confundidos com gafanhotos porque possuem uma estrutura corporal "
				+ "semelhante incluindo saltar as patas traseiras. Grilos s�o inofensivos aos seres humanos.");
		aux.setSom("Estridula��o");
		
		insetos.add(aux);
		aux = new Inseto();
		
		aux.setNome("Abelha");
		aux.setDesc("� um inseto voador, conhecido pelo seu importante papel na poliniza��o. As esp�cies de abelhas nativas das Am�ricas e "
				+ "Oceania n�o possuem ferr�o e s�o menos agressivas do que as esp�cies africanas, a maioria destas pertence � tribo "
				+ "Meliponini. As abelhas com ferr�o encontradas comumente no Brasil s�o esp�cies h�bridas de abelhas europeias e "
				+ "africanas, criadas para maior produtividade e resist�ncia.");
		aux.setSom("Zumbido");
		
		insetos.add(aux);
		aux = new Inseto();
		
		aux.setNome("Mariposa Atlas");
		aux.setDesc("� considerada a maior mariposa do mundo em termos de �rea de superf�cie total da asa (para mais de 400 cm�). "
				+ "Sua envergadura tamb�m � considerada entre as melhores, de 25�30 cm. As f�meas s�o razoavelmente maiores e mais pesadas. "
				+ "As mariposas-atlas s�o tidas como nomeadas em homenagem ao tit� da mitologia grega, Atlas, ou por suas asas com padr�es tipo mapas.");
		aux.setSom("Nenhum");
		
		insetos.add(aux);
	}
}
