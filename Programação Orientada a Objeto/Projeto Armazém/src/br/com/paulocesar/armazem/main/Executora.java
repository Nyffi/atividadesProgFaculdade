/*
 *                     Projeto Final - POO
 * 
 * Aluno:
 * 		Paulo C�sar de Lima Rocha - UC19105993
 * 
 * Descri��o:
 * 		O sistema ter� como objetivo auxiliar o 
 * gerenciamento de um armaz�m de produtos de 
 * todos os tipos e quantidades. Para gerenciar 
 * todos os lotes de produtos armazenados, o 
 * sistema ir� oferecer uma forma de manter o 
 * controle dos produtos, do armazenamento at� 
 * o empacotamento, antes de ser enviado para 
 * o comprador.
 * 
 */

package br.com.paulocesar.armazem.main;

import br.com.paulocesar.armazem.utils.Menus;

public class Executora {

	public static void main(String[] args) {
		Armazem armazem = new Armazem();
		Menus.menuPrincipal(armazem);
	}

}
