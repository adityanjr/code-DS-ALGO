package L20;

public class StringUse {

	public static String longestSubstringWith2Chars(String s) {
		if(s.length() <= 2) {
			return s;
		}
		int startIndex = 0, maxLen = 0, si = 0, len = 1;
		int lastOcuurrenceFirst = 0, lastOccurrenceSecond = 0;
		char first = s.charAt(0), second;
		int i = 1;
		while(s.charAt(i) == first) {
			len++;
			i++;
			lastOcuurrenceFirst++;
		}
		second = s.charAt(i);
		len++;
		lastOccurrenceSecond = i;
		i++;
		
		while(i < s.length()) {
			if(s.charAt(i) == first || s.charAt(i) == second) {
				if(s.charAt(i) == first) {
					lastOcuurrenceFirst = i;
				}
				else {
					lastOccurrenceSecond = i;
				}
				len++;
				i++;
			}
			else {
				if(len > maxLen) {
					startIndex = si;
					maxLen = len;
				}
				if(s.charAt(si) == first) {
					si = lastOcuurrenceFirst + 1;
					len = (s.substring(si, i)).length() + 1;
					first = s.charAt(i);
				}
				else {
					si = lastOccurrenceSecond + 1;
					len = (s.substring(si, i)).length() + 1;
					second = s.charAt(i);
				}
				i++;
			}
		}
		if(len > maxLen) {
			startIndex = si;
			maxLen = len;
		}
		return s.substring(startIndex, startIndex + maxLen);
	}
	
	public static void main(String[] args) {
		String s = "mississippii";
		System.out.println(longestSubstringWith2Chars(s));
	}
}
