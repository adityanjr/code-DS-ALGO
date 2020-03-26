package L10;

public class PalindromeSubstrings {

	public static int countPalindromeSubstrings(String s) {
		int count = 0;
		for(int i = 0; i < s.length(); i++) {
			int left = i-1;
			int right = i+1;
			System.out.println(s.charAt(i));
			count++;
			while(left >= 0 && right < s.length()) {
				if(s.charAt(left) == s.charAt(right)) {
					System.out.println(s.substring(left, right+1));
					count++;
					left--;
					right++;
				}
				else {
					break;
				}
				
			}
			
			if(i < s.length()-1 && s.charAt(i) == s.charAt(i+1)) {
				left = i-1;
				right = i+2;
				System.out.println(s.substring(i, i+2));
				count++;
				while(left >= 0 && right < s.length()) {
					if(s.charAt(left) == s.charAt(right)) {
						System.out.println(s.substring(left, right+1));
						count++;
						left--;
						right++;
					}
					else {
						break;
					}
					
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) {
		int count = countPalindromeSubstrings("aabaa");
		System.out.println(count);
	}

}
