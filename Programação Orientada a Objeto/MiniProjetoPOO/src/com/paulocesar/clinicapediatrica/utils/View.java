package com.paulocesar.clinicapediatrica.utils;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

abstract public class View {
	
	public static void exibirMensagem(String mensagem) {
		JOptionPane.showMessageDialog(null, mensagem);
	}
	
	public static String solicitarString(String msg, String titulo) {
		return JOptionPane.showInputDialog(null, msg, titulo, JOptionPane.QUESTION_MESSAGE);
	}
	
	public static int solicitarInt(String msg, String titulo) {
		return Integer.parseInt(JOptionPane.showInputDialog(null, msg, titulo, JOptionPane.QUESTION_MESSAGE)); 
	}
	
	public static double solicitarDouble(String msg, String titulo) {
		return Double.parseDouble(JOptionPane.showInputDialog(null, msg, titulo, JOptionPane.QUESTION_MESSAGE)); 
	}
	
	public static void exibirErro(String erro) {
		JOptionPane.showMessageDialog(null, erro, "ERRO", JOptionPane.ERROR_MESSAGE);
	}
	
	public static String selecionaLista(String msg, String titulo, Object[] escolhas) {
		return (String) JOptionPane.showInputDialog(null, msg, titulo, JOptionPane.QUESTION_MESSAGE, null, escolhas, escolhas[0]);
	}
	
	public static void initFrameDisplayInfoWindow(JFrame frame, String inputText, String title) {
		
		frame = new DisplayInfoWindow(inputText, title);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(600,500);
		frame.setResizable(false);
		frame.setVisible(true);
		frame.setLocationRelativeTo(null);	
	}
	
}