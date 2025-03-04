import java.util.Scanner;

public class CaesarCipher {

    // Function to encrypt the message
    public static String encrypt(String text, int shift) {
        StringBuilder encryptedText = new StringBuilder();
        
        // Loop through each character in the text
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            
            // Encrypt uppercase letters
            if (Character.isUpperCase(c)) {
                c = (char) (((int) c + shift - 65) % 26 + 65);
            }
            // Encrypt lowercase letters
            else if (Character.isLowerCase(c)) {
                c = (char) (((int) c + shift - 97) % 26 + 97);
            }
            
            // Append encrypted character to result
            encryptedText.append(c);
        }
        return encryptedText.toString();
    }

    // Function to decrypt the message
    public static String decrypt(String text, int shift) {
        return encrypt(text, 26 - shift);  // Decrypting is just reversing the shift
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take input from the user
        System.out.println("Enter the text:");
        String text = scanner.nextLine();
        
        System.out.println("Enter the shift value (1-25):");
        int shift = scanner.nextInt();
        
        // Encrypt the text
        String encryptedText = encrypt(text, shift);
        System.out.println("Encrypted text: " + encryptedText);
        
        // Decrypt the text
        String decryptedText = decrypt(encryptedText, shift);
        System.out.println("Decrypted text: " + decryptedText);
        
        scanner.close();
    }
}
