
public class Mamífero extends Animal {
	public void getDados() {
		String intro = "", msg = "";
		
		intro = "Nome: " + this.getNome() + "\nClasse: " + this.getClass().getSimpleName() + "\nTipo de Som: " + this.getSom() + "\n\n";
		msg = "O/A " + this.getNome() + " " + this.getDesc() + "\n";
		msg = msg.replaceAll("(.{1,50})\\s+", "$1\n");
		
		View.exibirMsg(intro + msg);
	}
}
