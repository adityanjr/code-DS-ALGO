package L24;

import java.util.HashMap;

public class TrieNode {
	char name;
	HashMap<Character, TrieNode> children;
	boolean isTerminal;
	
	public TrieNode(char name) {
		this.name = name;
		children = new HashMap<Character, TrieNode>();
		isTerminal = false;
	}
}
