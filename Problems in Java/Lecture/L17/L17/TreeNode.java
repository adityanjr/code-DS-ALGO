package L17;

import java.util.ArrayList;

public class TreeNode<T> {
	T data;
	ArrayList<TreeNode<T>> children;
	
	public TreeNode(T data) {
		children = new ArrayList<TreeNode<T>>();
		this.data = data;
	}
}
