package br.com.paulocesar.armazem.main;

import java.util.ArrayList;

import br.com.paulocesar.armazem.utils.Utils;

public class Compra {
	private int id;
	private Cliente comprador;
	private ArrayList<Produto> produtos;
	private ArrayList<Integer> qnt = new ArrayList<Integer>();
	private boolean isEmpacotado = false;
	
	public Compra() {
		id = Utils.gerarID(1, 999);
	}
	
	public ArrayList<Integer> getQnt() {
		return qnt;
	}
	public void setQnt(ArrayList<Integer> qnt) {
		this.qnt = qnt;
	}
	public Cliente getComprador() {
		return comprador;
	}
	public void setComprador(Cliente comprador) {
		this.comprador = comprador;
	}
	public ArrayList<Produto> getProdutos() {
		return produtos;
	}
	public void setProdutos(ArrayList<Produto> produtos) {
		this.produtos = produtos;
	}
	public void pedidoEmpacotado() {
		this.isEmpacotado = true;
	}
	public boolean getEmpacotado() {
		return this.isEmpacotado;
	}
	public int getID() {
		return this.id;
	}
}
