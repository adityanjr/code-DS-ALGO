package L18;

public class BSTClass {
	BTNode<Integer> root;
	int size;	// No. of nodes
	
	public BTNode<Integer> addElement(int v) {
		return null;
	}
	
	private static boolean findElement(int value, BTNode<Integer> root) {
		if(root == null) {
			return false;
		}
		if(root.data == value) {
			return true;
		}
		if(value < root.data)
			return findElement(value, root.left);
		else 
			return findElement(value, root.right);
	}
	
	public boolean findElement(int value) {
		return findElement(value, root);
	}
	
}
