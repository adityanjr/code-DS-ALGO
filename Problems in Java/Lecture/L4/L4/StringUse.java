package L4;

import java.util.Scanner;

public class StringUse {

	public static String check(String s) {
		
		s = s + "ghi";
		System.out.println(s);
		return s;
	}
	
	public static void printChars(String s) {
		for(int i = 0; i < s.length(); i++) {
			System.out.println(s.charAt(i));
		}
	}
	
	public static boolean isPalindrome(String s) {
		int i = 0, j = s.length()-1;
		while(i <= j) {
			/*if(s.charAt(i) == s.charAt(j)) {
				i++;
				j--;
				continue;
			}*/
			
			if(s.charAt(i) != s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
	
	public static void count() {
		Scanner s1 = new Scanner(System.in);
		String s = s1.nextLine();
		while(!s.contains("$")) {
			
			
			
			
			
			s = s1.nextLine();
		}
	}
	
	public static void main(String[] args) {
		String s = "abcdedf";
		
		/*System.out.println(s.substring(2, 6));
		System.out.println(s.substring(2));
		System.out.println(s.indexOf("de"));
		System.out.println(s.startsWith("bc"));
		
		s = s.concat("ghi");
		
		System.out.println(s);*/
		
//		s = check(s);
//		System.out.println(s);
		
//		printChars("abcd");
		
		Scanner s1 = new Scanner(System.in);
		System.out.println("Enter String : ");
		String st = s1.nextLine();
		
		System.out.println(st.contains("a"));
		
		System.out.println(isPalindrome(st));
	}

}
