package com.paulocesar.clinicapediatrica.utils;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JEditorPane;
import javax.swing.JFrame;
import javax.swing.JScrollPane;


public class DisplayInfoWindow extends JFrame implements ActionListener{
	
	private static final long serialVersionUID = 1L;
	
	public static boolean windowIsOpened;
	
	private BoxLayout layout;
	
	private JEditorPane editorPane;
	private JScrollPane scrollPane;
	private JButton button;
	
	public DisplayInfoWindow(String inputText, String title) {
		
		super(title);
		
		windowIsOpened = true;
		
		layout = new BoxLayout(getContentPane(), BoxLayout.PAGE_AXIS);
		
		getContentPane().setLayout(layout);
		
		displayInfo(inputText);

	}
	
	private void displayInfo(String inputText) {
		
		editorPane = new JEditorPane();
		editorPane.setEditable(false);
		
		editorPane.setContentType("text/html");

		scrollPane = new JScrollPane(editorPane);
		scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		scrollPane.setPreferredSize(new Dimension(600, 450));
		scrollPane.setMinimumSize(new Dimension(150, 150));
		
		editorPane.setText(inputText);
		
		button = new JButton("VOLTAR");
		button.setAlignmentX(Component.CENTER_ALIGNMENT);
		button.addActionListener(this);
		
		add(scrollPane);
		add(button);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getActionCommand().equals("VOLTAR")) {
			DisplayInfoWindow.windowIsOpened = false;
			setVisible(false);
			this.dispose();
		}
	}
	
}
