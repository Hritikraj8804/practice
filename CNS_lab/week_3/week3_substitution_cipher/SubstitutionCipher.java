// Substitution Cipher

import java.io.*;
import java.util.*;

public class SubstitutionCipher {
	static Scanner sc = new Scanner(System.in);
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String [] args) throws IOException {
		
		// Alphabet for substitution
		String a = "abcdefghijklmnopqrstuvwxyz";
		String b = "zyxwvutsrqponmlkjihgfedcba";
		
		// Input String from user
		System.out.print("Enter any String: ");
		String str = br.readLine().toLowerCase();// Convert input to lowercase for consistent mapping
		String decrypt = ""; 

		// Encrypt the String
		for (int i = 0; i < str.length(); i++) {
			char c = str.charAt(i);
			if(Character.isLetter(c)) { //Check if character is a letter
				int j = a.indexOf(c);
				decrypt += b.charAt(j);
			} else {
				decrypt += c; // keep non-alphabet characters as it is		
			}
		}

		System.out.println("The encrypted data is: " + decrypt);
	}
}
		