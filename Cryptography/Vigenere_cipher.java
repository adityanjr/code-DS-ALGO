
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

import javax.naming.ldap.HasControls;

public class Vigenere_cipher {

	public static void main(String[] args) {

		int i;
		Scanner scan = new Scanner(System.in);

		String alpha =new String("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		int all[] = new int[26];
		for(i=0;i<alpha.length();i++) {
			int temp = alpha.charAt(i)-65;
			all[i] = temp;
			System.out.println(""+alpha.charAt(i)+" : "+all[i]);
		}
			
		System.out.println("Enter the Keyword Value :");
		
		String key = scan.next().toUpperCase();
		scan.nextLine();
		int a[] = new int[key.length()];
		for(i=0;i<key.length();i++) {
			int temp = key.charAt(i)-65;
			a[i] = temp;
			System.out.println(""+key.charAt(i)+" : "+a[i]);
		}
		
		String enciphered = new String("");
		int cir=0;
		System.out.println("Enter the plainText Message :");
		String plainText = scan.nextLine().toUpperCase();
		for(i=0;i<plainText.length();i++) {
			if(cir >= key.length()) {
				cir=0;
			}
			if(plainText.charAt(i)==32) {
				enciphered+=" ";
			}
			else {
			int pt = plainText.charAt(i)-65;
			int keyword = key.charAt(cir)-65;
			int x= pt+keyword;
			if(x>25) {
				x= x-26;
			}
			enciphered+= alpha.charAt(x);
			//System.out.println(enciphered);
			cir++;
			}
		}
		System.out.println("The Encrypted Text is "+enciphered);
		
	
		String decrypted_string = "";
		 for (int k = 0, j = 0; k < enciphered.length(); k++)
	        {
	            char c = enciphered.charAt(k);
	            if(enciphered.charAt(k)==32)
	            	decrypted_string+=" ";
	            if (c < 'A' || c > 'Z')
	                continue; 
	            decrypted_string += (char) ((c - key.charAt(j) + 26) % 26 + 'A');
	            j = ++j % key.length();
	        }			 
		System.out.println("The Decrypted Text is "+decrypted_string);
		
		
		
	}
}