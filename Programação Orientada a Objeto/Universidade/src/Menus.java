import java.util.ArrayList;

public class Menus {
	public static void menuPrincipal (ArrayList<Curso> cursos) {
		int opcao = 999;
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu Universidade - - - - - \n"
										+ "1 - Criar um novo Curso \n"
										+ "2 - Modificar um Curso \n"
										+ "3 - Listar todas as informações \n"
										+ "4 - Deletar um Curso \n"
										+ "0 - Sair");
			} catch (NumberFormatException e) {
				View.exibirMsg("[Universidade] Favor digitar um número correspondente às opções disponíveis.");
			}
			
			switch (opcao) {
				case 1:
					Utils.criarCurso(cursos);
					break;
				case 2:
					Curso curso = null;	
					
					try {
						curso = cursos.get(View.solicitarInt("Digite o index do curso: "));
					} catch (IndexOutOfBoundsException e) {
						View.exibirErro("[Curso] Este curso não existe.");
					} catch (NumberFormatException f) {
						View.exibirErro("[Curso] Digite apenas números.");
					}
					
					if (curso != null) {
						menuCurso(curso);
					}
						
					break;
				case 3:
					Utils.exibirInfo(cursos);
					break;
				case 4:
					try {
						Utils.apagarCurso(cursos);
					} catch (IllegalArgumentException e) {
						View.exibirErro(e.getMessage());
					}
					break;
				default:
					break;
			}
		} while (opcao != 0);
	}
	
	public static void menuCurso (Curso curso) {
		int opcao = 999;
		
		do {
			try {
				opcao = View.solicitarInt("- - - - - Menu Curso de " + curso.getNome() + " - - - - - \n"
						+ "1 - Criar Turma \n"
						+ "2 - Transferir Professor \n"
						+ "3 - Adicionar Aluno \n"
						+ "4 - Transferir Aluno \n"
						+ "5 - Deletar Aluno \n"
						+ "6 - Deletar uma Turma \n"
						+ "0 - Sair");
			} catch (NumberFormatException e) {
				View.exibirMsg("[Universidade] Favor digitar um número correspondente às opções disponíveis.");
			}
			
			switch (opcao) {
				case 1:
					Utils.adicionarTurma(curso);
					break;
				case 2:
					Utils.transferirProf(curso);
					break;
				case 3:
					try {
						Utils.adicionarAluno(curso.getTurmas().get(View.solicitarInt("Digite o index da turma: ")));
					} catch (IndexOutOfBoundsException e) {
						View.exibirErro("[Curso] Esta turma não existe.");
					} catch (NumberFormatException f) {
						View.exibirErro("[Curso] Digite apenas números.");
					}
					break;
				case 4:
					Utils.transferirAluno(curso);
					break;
				case 5:
					Utils.removerAluno(curso);
					break;
				case 6:
					Utils.removerTurma(curso);
				default:
					break;
			}
		} while (opcao != 0);
	}
	
}
