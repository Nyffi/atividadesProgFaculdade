
public class Veiculo {
	int velocidade;
	
	Veiculo (int vel) {
		if (vel > 80) {
			System.out.print("O USUÁRIO ULTRAPASSOU A VELOCIDADE MÁXIMA E SERÁ MULTADO");
		} else {
			System.out.print("O USUÁRIO ESTÁ DENTRO DO LIMITE MÁXIMO DE VELOCIDADE.");
		}
	}
}
