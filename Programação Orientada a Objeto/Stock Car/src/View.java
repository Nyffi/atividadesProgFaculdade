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
	
	static double solicitarDouble (String msg) {
		String retorno = JOptionPane.showInputDialog(msg);
		
		return Double.parseDouble(retorno);
	}
	
	static void exibirErro (String erro) {
		JOptionPane.showMessageDialog(null, erro, "ERRO DE EXECUÇÃO", JOptionPane.ERROR_MESSAGE);
	}
	
	static boolean solicitarBoolean (String msg) {
		int retorno = JOptionPane.showConfirmDialog(null, msg, "Confirma?", JOptionPane.YES_NO_OPTION);
		
		if (retorno == JOptionPane.YES_OPTION) {
			return true;
		}
		return false;
	}
}
