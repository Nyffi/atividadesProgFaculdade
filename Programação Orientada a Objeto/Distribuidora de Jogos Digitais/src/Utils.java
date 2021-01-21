import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Utils {
	public static void listarJogos(ArrayList<Publicadora> publicadoras) {
		if (publicadoras.size() == 0) {
			View.exibirErro("[Distribuidora] Não há publicadoras cadastradas.");
			return;
		}
		
		for (Publicadora publicadora : publicadoras) {
			publicadora.listarJogosPublico();
		}
	}
	
	public static boolean validaEmail(String email) {
		final String regex = "^(.+)@(.+)$";
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(email);
		
		return matcher.matches();
	}
	
	public static String encriptaSenha(String senha) {
		try{
	        MessageDigest digest = MessageDigest.getInstance("SHA-256");
	        byte[] hash = digest.digest(senha.getBytes("UTF-8"));
	        StringBuffer hexString = new StringBuffer();

	        for (int i = 0; i < hash.length; i++) {
	            String hex = Integer.toHexString(0xff & hash[i]);
	            if(hex.length() == 1) hexString.append('0');
	            hexString.append(hex);
	        }

	        return hexString.toString();
	    } catch(Exception ex){
	       throw new RuntimeException(ex);
	    }
	}
}
