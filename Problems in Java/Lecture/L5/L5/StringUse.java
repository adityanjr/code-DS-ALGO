package L5;
import java.util.Scanner;

public class StringUse {

	public static char highestOccurringChar(String s) {
		int frequencies[] = new int[26];
		for(int i = 0; i < s.length(); i++) {
			int index = s.charAt(i) - 'a';
			frequencies[index] += 1;
		}
		
		int maxCount = frequencies[0];
		int position = 0;
		for(int i = 1; i < frequencies.length; i++) {
			if(frequencies[i] > maxCount) {
				maxCount = frequencies[i];
				position = i;
			}
		}
		
		return (char)(position + 'a');
		
	}
	
	public static void main(String[] args) {
//		Scanner s = new Scanner(System.in);
//		System.out.println("Enter any string : ");
//		String str = s.next(); 
//		System.out.println(highestOccurringChar(str));
		
		
		String s1 = "abc";
		String s2 = "abc";
		s2 = s2 + "def";
		s1 = s1 + "g";
		s2 = "abc";
		s1 = s1.substring(0, 3);

		System.out.println(s1);
		System.out.println(s2);
		if(s1.equals(s2)) {
			System.out.println("True");
		}
		else {
			System.out.println("False");
		}
		
	}

}
