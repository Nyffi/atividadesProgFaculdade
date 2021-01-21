import java.util.ArrayList;
import java.util.Random;

public class Utils {
	public static int gerarID (int min, int max) {
		Random rand = new Random();
		
		return rand.nextInt((max - min) + 1) + min;
	}
	
	public static void criarCurso (ArrayList<Curso> cursos) {
		try {
			Curso temp = new Curso(View.solicitarString("Digite o nome do curso: "));
			cursos.add(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
		
	}
	
	public static void apagarCurso (ArrayList<Curso> cursos) {
		if (cursos.size() == 0) {
			throw new IllegalArgumentException("[Universidade] Não há cursos disponíveis.");
		} else {
			try {
				cursos.remove(View.solicitarInt("Digite o index do Curso: "));
				View.exibirMsg("[Universidade] Curso removido com sucesso.");
			} catch (IndexOutOfBoundsException e) {
				View.exibirErro("[Universidade] Esse curso não existe.");
			}
		}
	}
	
	public static void exibirInfo (ArrayList<Curso> cursos) {
		int indice, countCurso = 0, countTurma;
		Professor prof;
		String msg, aux = "";
		
		if (cursos.size() == 0) {
			View.exibirErro("[Universidade] Não há nenhum curso registrado no momento.");
		}
		
		for (Curso curso : cursos) {
			msg = "Index: " + countCurso + "\nCurso: " + curso.getNome() + "\n\n";
			
			if (curso.getTurmas().size() == 0) {
				aux = "Este Curso está vazio.";
			}
			
			countCurso++;
			countTurma = 0;
			
			for (Turma turma : curso.getTurmas()) {
				aux = aux + "TURMA " + countTurma + "\n";
				countTurma++;
				aux = aux + "PROFESSOR\n";
				try {
					prof = turma.getProf();
					aux = aux + "P" + prof.getID() + " - " + prof.getNome() + "\n";
				} catch (IndexOutOfBoundsException e) {
					aux = aux + "Não alocado.\n";
				}
				
				indice = 0;
				aux = aux + "ALUNOS\n";
				
				for (Aluno aluno : turma.getAlunos()) {
					try {
						aux = aux + indice + ") UC" + aluno.getID() + " - " + aluno.getNome() + "\n";
					} catch (IndexOutOfBoundsException e) {
						aux = aux + indice + "Não alocado.\n";
					}
					indice++;
				}
				
				aux = aux + "\n";
			}
			
			View.exibirMsg(msg + aux);
		}
	}
	
	public static void adicionarTurma (Curso curso) {
		try {
			Professor prof = new Professor(View.solicitarString("Digite o nome do professor: "));
			Turma temp = new Turma();
			temp.setProf(prof, false);
			curso.addTurma(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
	}
	
	public static void adicionarAluno (Turma turma) {
		Aluno temp;
		
		try {
			temp = new Aluno(View.solicitarString("Digite o nome do aluno: "));
			turma.addAluno(temp);
		} catch (IllegalArgumentException e) {
			View.exibirErro(e.getMessage());
		}
	}
	
	public static void transferirProf (Curso curso) {
		Turma rem, dest;
		
		try {
			rem = curso.getTurmas().get(View.solicitarInt("Digite o index da turma remetente: "));
			dest = curso.getTurmas().get(View.solicitarInt("Digite o index da turma destinatário: "));
			
			if (rem.getProf() == dest.getProf()) {
				throw new IllegalArgumentException("[Curso] Não pode transferir um professor para a mesma turma.");
			}
			
			curso.switchProf(rem, dest);
			View.exibirMsg("[Curso] Transferência de professores feita com sucesso.");
		} catch (IndexOutOfBoundsException e) {
			View.exibirErro("[Curso] A turma não existe.");
		} catch (IllegalArgumentException f) {
			View.exibirErro(f.getMessage());
		}
		
	}
	
	public static void transferirAluno (Curso curso) {
		try {
			int turmaRem = View.solicitarInt("Digite o index da turma remetente: ");
			int indexAluno = View.solicitarInt("Digite o index do aluno a ser transferido: ");
			int turmaDest = View.solicitarInt("Digite o index da turma destino: ");
			
			curso.transferAluno(curso.getTurmas().get(turmaRem), 
					curso.getTurmas().get(turmaDest), 
					indexAluno);
			View.exibirMsg("[Curso] Aluno transferido com sucesso.");
		} catch (IndexOutOfBoundsException e) {
			View.exibirErro("[Curso] Uma das turmas não existe. Tente novamente.");
		} catch (NumberFormatException f) {
			View.exibirErro("[Curso] Index inválido. Favor digitar apenas números.");
		}
	}
	
	public static void removerAluno (Curso curso) {
		try {
			int turmaAlvo = View.solicitarInt("Digite o index da turma: ");
			int alunoAlvo = View.solicitarInt("Digite o index do aluno alvo: ");
			
			curso.getTurmas().get(turmaAlvo).getAlunos().remove(alunoAlvo);
			View.exibirMsg("[Turma] Aluno removido com sucesso.");
		} catch (IndexOutOfBoundsException e) {
			View.exibirErro("[Curso] A Turma ou o Aluno alvo não existe.");
		} catch (NumberFormatException f) {
			View.exibirErro("[Curso] Digite apenas números.");
		}
	}
	
	public static void removerTurma (Curso curso) {
		try {
			int turmaAlvo = View.solicitarInt("Digite o index da turma alvo: ");
			
			curso.removeTurma(turmaAlvo);
		} catch (IndexOutOfBoundsException e) {
			View.exibirErro("[Curso] A turma não existe.");
		} catch (NumberFormatException f) {
			View.exibirErro("[Curso] Digite o número index da turma (0-2).");
		} catch (IllegalArgumentException g) {
			View.exibirErro(g.getMessage());
		}
	}
}
