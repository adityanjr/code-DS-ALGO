package L24;

public class TrieUse {

	public static void main(String[] args) {
		Tries t = new Tries();
		t.addWord("news");
		t.addWord("new");
		t.removeWord("new");
		System.out.println(t.findWord("news"));
	}
}
