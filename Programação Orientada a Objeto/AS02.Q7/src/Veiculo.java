
public class Veiculo {
	int velocidade;
	
	Veiculo (int vel) {
		if (vel > 80) {
			System.out.print("O USU�RIO ULTRAPASSOU A VELOCIDADE M�XIMA E SER� MULTADO");
		} else {
			System.out.print("O USU�RIO EST� DENTRO DO LIMITE M�XIMO DE VELOCIDADE.");
		}
	}
}
