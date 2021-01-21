// Síntese
// Objetivo: "Criar um sistema de locadora"
// Autor: Paulo César de Lima Rocha
// Data: 04/09/2020

import java.util.ArrayList;

public class Executora {

	public static void main(String[] args) {
		Filial filiais[] = new Filial[3];
		ArrayList<Cliente> clientes = new ArrayList<Cliente>();
		ArrayList<Filme> filmes = new ArrayList<Filme>();

		Utils.iniciaFiliais(filiais);
		while (filmes.size() != 10) {
			Utils.adicionaFilme(filmes);
		}
		Utils.adicionaCliente(clientes);
		Utils.adicionaCliente(clientes);
		filiais[0].abrirPedido(clientes.get(0), filiais[0].getFunc().get(0), filmes.get(0));
		filiais[0].abrirPedido(clientes.get(1), filiais[0].getFunc().get(0), filmes.get(1));
		filiais[0].getPedidos();
		filiais[0].fecharPedido(clientes.get(0), filmes.get(0));
		filiais[0].getPedidos();
	}
}
