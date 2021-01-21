import java.util.ArrayList;

public class Curso {
	private String nomeCurso;
	private ArrayList<Turma> turmas = new ArrayList<Turma>();
	
	Curso (String nome) throws IllegalArgumentException {
		try {
			nomeCurso = setNome(nome);
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException(e.getMessage());
		}
	}
	
	public String setNome (String nome) {
		if (nome.length() <= 2) {
			throw new IllegalArgumentException("[Curso] Nome inválido.");
		} else {
			return nome;
		}
	}
	
	public void addTurma(Turma turma) {
		if (turmas.size() >= 3) {
			throw new IllegalArgumentException("[Curso] Número limite de Turmas atingido.");
		} else {
			this.turmas.add(turma);
		}
	}
	
	public void removeTurma(int index) {
		if (this.turmas.get(index).getAlunos().size() > 0) {
			if (View.solicitarBoolean("[Curso] Esta turma ainda tem alunos. Deseja deletar mesmo assim?")) {
				this.turmas.remove(index);
				View.exibirMsg("[Curso] Turma deletada com sucesso.");
			}
		} else {
			this.turmas.remove(index);
			View.exibirMsg("[Curso] Turma deletada com sucesso.");
		}
	}
	
	public String getNome() {
		return nomeCurso;
	}
	
	public ArrayList<Turma> getTurmas() {
		return turmas;
	}
	
	public void switchProf (Turma remetente, Turma destinatario) {
		Professor aux;
		
		aux = destinatario.getProf();
		destinatario.setProf(remetente.getProf(), true);
		remetente.setProf(aux, true);
	}
	
	public void transferAluno (Turma turmaA, Turma turmaB, int indexAluno) {
		Aluno aux;
		
		try {
			aux = turmaA.getAlunos().get(indexAluno);
			turmaA.getAlunos().remove(indexAluno);
			turmaB.getAlunos().add(aux);
		} catch (IndexOutOfBoundsException e) {
			View.exibirErro("[Curso] Este aluno não existe na turma indicada.");
		}
		
	}
}
