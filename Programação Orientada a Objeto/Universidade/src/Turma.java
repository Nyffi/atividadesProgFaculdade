import java.util.ArrayList;

public class Turma {
	private Professor prof;
	private ArrayList<Aluno> alunos = new ArrayList<Aluno>();
	
	public void setProf (Professor prof, boolean transferencia) {
		if (this.prof == null || transferencia == true) {
			this.prof = prof;
		} else {
			throw new IllegalArgumentException("[Turma] Um professor já está alocado para esta turma.");
		}
	}
	
	public void addAluno (Aluno aluno) {
		if (alunos.size() < 5) {
			alunos.add(aluno);
		} else {
			throw new IllegalArgumentException("[Turma] Esta turma já contém o máximo de alunos permitido.");
		}
	}
	
	public Professor getProf() {
		return prof;
	}
	
	public ArrayList<Aluno> getAlunos() {
		return alunos;
	}
}
