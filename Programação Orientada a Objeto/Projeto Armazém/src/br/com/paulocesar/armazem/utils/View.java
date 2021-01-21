package br.com.paulocesar.armazem.utils;

import javax.swing.JOptionPane;

public abstract class View {
	public static void exibirMsg (String msg) {
		JOptionPane.showMessageDialog(null, msg);
	}
	
	public static String solicitarString (String msg) {
		return JOptionPane.showInputDialog(msg);
	}
	
	public static int solicitarInt (String msg) {
		String retorno = JOptionPane.showInputDialog(msg);
		
		return Integer.parseInt(retorno);
	}
	
	public static double solicitarDouble (String msg) {
		String retorno = JOptionPane.showInputDialog(msg);
		
		return Double.parseDouble(retorno);
	}
	
	public static void exibirErro (String erro) {
		JOptionPane.showMessageDialog(null, erro, "ERRO DE EXECUÇÃO", JOptionPane.ERROR_MESSAGE);
	}
	
	public static boolean solicitarBoolean (String msg) {
		int retorno = JOptionPane.showConfirmDialog(null, msg, "Confirma?", JOptionPane.YES_NO_OPTION);
		
		if (retorno == JOptionPane.YES_OPTION) {
			return true;
		}
		return false;
	}
}
