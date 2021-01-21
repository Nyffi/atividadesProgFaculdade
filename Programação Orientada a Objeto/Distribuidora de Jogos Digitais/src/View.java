import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public abstract class View implements ActionListener {
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
	
	static void telaLogin (String titulo, Login dados) {
		JFrame frame = new JFrame(titulo);
		JPanel panel = new JPanel();
		
		frame.setSize(260, 160);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.add(panel);
		panel.setLayout(null);
		JLabel email = new JLabel("Email: ");
		JLabel senha = new JLabel("Senha: ");
		
		email.setBounds(10,20,80,25);
		senha.setBounds(10,50,80,25);
        panel.add(email);
        panel.add(senha);
		
        JTextField user = new JTextField();
        user.setBounds(70,20,165,25);
        panel.add(user);
        
		JPasswordField pass = new JPasswordField();
		pass.setBounds(70,50,165,25);
        panel.add(pass);
        
        JButton login = new JButton("Fazer Login");
        login.setBounds(10, 80, 225, 25);
        panel.add(login);
        
        frame.setResizable(false);
        frame.setVisible(true);
        
        login.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				try {
					dados.setEmail(user.getText());
					dados.setSenha(String.valueOf(pass.getPassword()));
					frame.dispose();
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
				}
				
			}
        	
        });
	}
	
	static void telaRegistro (String titulo, Usuario user, Publicadora publish, boolean isAdmin) {	//A função pega a classe Usuário e Publicadora pois ela é reusada no registro de ambos. Quando um deles for registrado, o outro deve receber o valor null.
		JFrame frame = new JFrame(titulo);	//Cria uma janela customizável
		JPanel panel = new JPanel();		//Cria um painél para enmoldurar caixas de texto, labels, entre outros.
		
		frame.setSize(260, 220);			//Tamanho da janela.
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		//Operação padrão quando clicar no X vermelho da janela.
		
		frame.add(panel);					//Adiciona o painél na janela.
		panel.setLayout(null);
		
		JLabel apelido;
		if (user != null && publish == null) 
			apelido = new JLabel("Apelido: ");
		else
			apelido = new JLabel("Nome: ");
		apelido.setBounds(10,20,80,25);
		panel.add(apelido);
		JLabel correio = new JLabel("Email: ");
		correio.setBounds(10,50,80,25);
		panel.add(correio);
		JLabel senha = new JLabel("Senha: ");
		senha.setBounds(10,80,80,25);
        panel.add(senha);
		
        JTextField nick = new JTextField();
        nick.setBounds(70,20,165,25);
        panel.add(nick);
        
        JTextField email = new JTextField();
        email.setBounds(70,50,165,25);
        panel.add(email);
        
		JPasswordField pass = new JPasswordField();
		pass.setBounds(70,80,165,25);
        panel.add(pass);
        
        JCheckBox admin = new JCheckBox("É Administrador?");
        admin.setBounds(55, 111, 150, 25);
        if (user != null && publish == null && isAdmin == true) {
            panel.add(admin);
            admin.setSelected(true);
        }
        
        JButton login = new JButton("Criar Conta");
        login.setBounds(10, 140, 225, 25);
        panel.add(login);
        
        frame.setResizable(false);
        frame.setVisible(true);
        
        
        login.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				try {
					if (user != null && publish == null) {	//Caso a função esteja focando em registrar um Usuário, esse trecho de código é executado.
						user.setApelido(nick.getText());
						user.setEmail(email.getText());
						user.setSenha(String.valueOf(pass.getPassword()));
						if (admin.isSelected()) 
							user.setAdmin();
					} else {								//Caso a função esteja focando o registro de uma publicadora, esse trecho é executado.
						publish.setNome(nick.getText());
						publish.setEmail(email.getText());
						publish.setSenha(String.valueOf(pass.getPassword()));
					}
					frame.dispose();
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
				}
			}
        	
        });
        
	}
	
	static void telaPublicacao (Jogo jogoNovo) {
		JFrame frame = new JFrame("Publicar Jogo");
		JPanel panel = new JPanel();
		
		frame.setSize(260, 220);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		frame.add(panel);
		panel.setLayout(null);
		
		JLabel jogo = new JLabel("Título: ");
		jogo.setBounds(10,20,80,25);
		panel.add(jogo);
		JLabel descricao = new JLabel("Descrição: ");
		descricao.setBounds(10,50,80,25);
		panel.add(descricao);
		JLabel senha = new JLabel("Preço: ");
		senha.setBounds(10,80,80,25);
        panel.add(senha);
		
        JTextField game = new JTextField();
        game.setBounds(70,20,165,25);
        panel.add(game);
        
        JTextField description = new JTextField();
        description.setBounds(70,50,165,25);
        panel.add(description);
        
        JTextField price = new JTextField();
        price.setBounds(70,80,165,25);
        panel.add(price);
        
        JButton publish = new JButton("Publicar Jogo");
        publish.setBounds(10, 140, 225, 25);
        panel.add(publish);
        
        frame.setResizable(false);
        frame.setVisible(true);
        
        
        publish.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent arg0) {
				try {
					jogoNovo.setNome(game.getText());
					jogoNovo.setDesc(description.getText());
					jogoNovo.setPreco(Double.parseDouble(price.getText()));
					frame.dispose();
				} catch (IllegalArgumentException e) {
					View.exibirErro(e.getMessage());
				}
			}
        	
        });
        
	}
}
