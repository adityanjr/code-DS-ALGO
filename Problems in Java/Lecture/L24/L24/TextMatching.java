package L24;

import java.util.HashMap;

public class TextMatching {

	public static int bruteForce(String s, String t) {
		for(int i = 0; i < s.length() - t.length(); i++) {
			for(int j = 0; j < t.length(); j++) {
				if(s.charAt(i+j) != t.charAt(j)) {
					break;
				}
				else {
					if(j == t.length()-1) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	
	public static int boyreMoore(String s, String t) {
		HashMap<Character, Integer> lastOccurrences = new HashMap<Character, Integer>();
		for(int i = 0; i < t.length(); i++) {
			lastOccurrences.put(t.charAt(i), i);
		}
		
		for(int i = 0; i <= s.length() - t.length(); ) {
			for(int j = t.length()-1; j >= 0; j--) {
				if(s.charAt(i+j) != t.charAt(j)) {
					char culprit = s.charAt(i+j);
					if(lastOccurrences.containsKey(culprit)) {
						int index = lastOccurrences.get(culprit);
						if(j < index) {
							// when culprit lies in right side
							i++;
						}
						else {
							i += j - index;
						}
					}
					else {
						// Skipping culprit
						i = i + j + 1;
					}
				}
				else {
					if(j == 0) {
						return i;
					}
				}
			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		String s = "abdceghaabgh";
		String t = "abgh";
//		System.out.println(s.length() + " " + t.length());
		System.out.println(boyreMoore(s, t));
	}
}
