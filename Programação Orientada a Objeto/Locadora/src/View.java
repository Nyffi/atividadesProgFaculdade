import javax.swing.JOptionPane;

public class View {
	static void exibirMsg (String msg) {
		JOptionPane.showMessageDialog(null, msg);
	}
	
	static String solicitarString (String msg) {
		return JOptionPane.showInputDialog(msg);
	}
	
	static int solicitarInt (String msg) {
		String retorno = JOptionPane.showInputDialog(msg);
		
		return Integer.parseInt(retorno);
	}
	
	static void exibirErro (String erro) {
		JOptionPane.showMessageDialog(null, erro, "ERRO DE EXECUÇÃO", JOptionPane.ERROR_MESSAGE);
	}
}
