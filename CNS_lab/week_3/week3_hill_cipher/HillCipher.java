import java.io.*;
import java.util.*;

public class HillCipher {

	static float[][] decrypt = new float[3][1];
	static float[][] a = new float[3][3]; // Encryption key matrix
	static float[][] b = new float[3][3]; // Inverse of key matrix
	static float[][] mes = new float[3][1]; // Message matrix
	static float[][] res = new float[3][1]; // Result matrix
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(System.in);

	public static void main(String [] args) throws IOException {
		
		getKeyMessage(); // Get key and Message
		
		// Encryption process: Multiply key matrix with meassage matrix
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 1; j++) {
				for(int k = 0; k < 3; k++) {
					res[i][j] = res[i][j] + a[i][k] * mes[k][j];
				} 
			} 
		} 

		System.out.print("\nEncrypted string is : ");
		for(int i = 0; i < 3; i++) {
			System.out.print((char) (Math.round(res[i][0]) % 26 + 97));	
		}
		
		inverse();
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 1; j++) {
				for(int k = 0; k < 3; k++) {
					decrypt[i][j] = decrypt[i][j] + b[i][k] * res[k][j];
				} 
			} 
		} 
		
		System.out.println("\nDecrypted String is : ");
		for(int i = 0; i < 3; i++) {
			 System.out.print((char) (Math.round(decrypt[i][0]) % 26 + 97));
		} 
		System.out.println("\n);

		public static void getKeyMessage() throws IOException {
			System.out.println("\nEnter 3x3 matrix for the key (It should be Invertible) : ");
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					a[i][j] = sc.nextFloat();
				} 
			} 
			
			System.out.print("\nEnter a 3 letter string : ");
			String msg = br.readLine();
			for(int i = 0; i < 3; i++) {
				mes[i][0] = msg.charAt(i) - 97;
			}
		}
		
		public static void inverse() {
			float p, q;
			float[][] c = new float[3][3];
			
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 3; j++) {
					c[i][j] = a[i][j];
					if(i == j) {
						b[i][j] = 1;
					} else {
						b[i][j] = 0;
					}
				} 
			}
		}
	}

}
	