package L24;

public class Tries {
	
	TrieNode root;
	int numWords;
	
	public Tries() {
		root = new TrieNode('\0');
		numWords = 0;
	}

	private static void addWord(TrieNode node, String word) {
		if(word.length() == 0) {
			node.isTerminal = true;
			return;
		}
		char first = word.charAt(0);
		if(node.children.containsKey(first)) {
			TrieNode child = node.children.get(first);
			addWord(child, word.substring(1));
		}
		else {
			TrieNode newNode = new TrieNode(first);
			node.children.put(first, newNode);
			addWord(newNode, word.substring(1));
		}
	}
	
	public void addWord(String word) {
		addWord(root, word);
	}

	private static void removeWord(TrieNode node, String word) {
		if(word.length() == 0) {
			node.isTerminal = false;
			return;
		}
		char first = word.charAt(0);
		if(node.children.containsKey(first)) {
			TrieNode child = node.children.get(first);
			removeWord(child, word.substring(1));
			if(!child.isTerminal && child.children.size() == 0) {
				node.children.remove(first);
			}
		}
		
	}
	
	public void removeWord(String word) {
		removeWord(root, word);
	}

	private static boolean findWord(TrieNode node, String word) {
		if(word.length() == 0) {
			return node.isTerminal;
		}
		char first = word.charAt(0);
		if(node.children.containsKey(first)) {
			TrieNode child = node.children.get(first);
			return findWord(child, word.substring(1));
		}
		else {
			return false;
		}
	}
	
	public boolean findWord(String word) {
		return findWord(root, word);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
