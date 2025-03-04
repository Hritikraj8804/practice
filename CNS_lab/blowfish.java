import java.io.*;
import javax.crypto.*;
import javax.crypto.spec.*;
import java.security.key;
import java.util.Base64;

public class Blowfish {
	public static void main(String[] args) throws Exception {
		KeyGenerator keyGenerator = KeyGenerator.getInstance("Blowfish");
		keyGenerator.init(128);
		Key secretKey = keyGenerator.generatekey();
		Cipher cipherOut = Cipher.getInstance("Blowfish/CFB/NoPadding");
		cipherOut.init(Cipher.ENCRPYT_MODE, secretkey); 
		byte[] iv = cipherOut.getIV();
		if(iv != null){
			System.out.println("Initialization Vector of the Cipher : " + Base64.getEncoder().encodeToString(iv));
		}
		FileInputStream fin = new FileInputStream("inputFile.txt");
		FileInputStream fout = new FileInputStream("outputFile.txt");
		CipherOutputStream cout = new CipherOutputStream(fout, cipherOut);
		int input;
		while((input = fin.read()) != -1){
			cout.write(input);
		}
		fin.close();
		cout.close();
		fout.close();
	}
}
