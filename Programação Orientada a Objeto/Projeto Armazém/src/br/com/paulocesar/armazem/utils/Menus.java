package br.com.paulocesar.armazem.utils;

import java.security.AccessControlException;

import br.com.paulocesar.armazem.main.Admin;
import br.com.paulocesar.armazem.main.Armazem;
import br.com.paulocesar.armazem.main.Cliente;
import br.com.paulocesar.armazem.main.Empacotador;

public class Menus {
	public static void menuPrincipal (Armazem armazem) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu    Armazém - - - - - \n"
										+ "1 - Fazer Login \n"
										+ "2 - Criar uma conta de cliente \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						try {
							armazem.fazerLogin(View.solicitarString("Digite o nome: "), View.solicitarString("Digite a senha: "));
						} catch (AccessControlException e) {
							View.exibirErro(e.getMessage());
						}
						break;
					case 2:
						armazem.adicionarCliente();
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void menuAdmin (Armazem armazem, Admin admin) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu    Admin - - - - - \n"
										+ "1 - Adicionar Produto \n"
										+ "2 - Reabastecer Produto \n"
										+ "3 - Listar Produtos \n"
										+ "4 - Remover Produto \n"
										+ "5 - Listar Vendas \n"
										+ "6 - Listar Empacotadores \n"
										+ "7 - Adicionar Empacotador \n"
										+ "8 - Demitir Empacotador \n"
										+ "9 - Alterar Admin \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						armazem.adicionarProduto();
						break;
					case 2:
						try {
							armazem.recarregarProduto(armazem.procurarProduto(View.solicitarString("Digite o nome do produto: ")));
						} catch (IllegalArgumentException e) {
							View.exibirErro(e.getMessage());
						}
						break;
					case 3:
						armazem.listarProdutos();
						break;
					case 4:
						try {
							armazem.removerProduto(armazem.procurarProduto(View.solicitarString("Digite o nome do produto: ")));
						} catch (IllegalArgumentException e) {
							View.exibirErro(e.getMessage());
						}
						break;
					case 5:
						try {
							armazem.listarPedidos(View.solicitarBoolean("Deseja visualizar apenas os pedidos prontos para envio?"));
						} catch (IllegalArgumentException e) {
							View.exibirErro(e.getMessage());
						}
						break;
					case 6:
						admin.listarEmpacotadores(armazem);
						break;
					case 7:
						admin.adicionarEmpacotador(armazem.getEmpacotadores());
						break;
					case 8:
						try {
							admin.removerEmpacotador(armazem.procurarEmpac(View.solicitarString("Digite o nome do Empacotador: ")), armazem.getEmpacotadores());
						} catch (IllegalArgumentException e) {
							View.exibirErro(e.getMessage());
						}
						break;
					case 9:
						armazem.alterarAdmin();
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void menuCliente (Armazem armazem, Cliente cliente) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu    Cliente - - - - - \n"
										+ "1 - Listar produtos \n"
										+ "2 - Comprar produto \n"
										+ "3 - Listar suas compras \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						armazem.listarProdutos();
						break;
					case 2:
						armazem.concluirCompra(cliente.comprarProduto(armazem.getProdutos()));
						break;
					case 3:
						armazem.listarPedidos(cliente, false);
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
	
	public static void menuEmpacotador (Armazem armazem, Empacotador empac) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu    Empacotador - - - - - \n"
										+ "1 - Listar pedidos \n"
										+ "2 - Empacotar pedidos \n"
										+ "0 - Sair");
				
				switch (opcao) {
					case 1:
						armazem.listarPedidos(View.solicitarBoolean("Deseja ver apenas os pedidos prontos para envio?"));
						break;
					case 2:
						empac.empacotarPedido(armazem.procurarCompra(View.solicitarInt("Digite o ID da compra: ")));
						break;
					case 0:
						break;
				}
			} catch (NumberFormatException e) {
				View.exibirErro("Digite apenas números.");
			}
		} while (opcao != 0);
	}
}
