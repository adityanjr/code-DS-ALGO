package L16;

import java.util.Scanner;

public class TreeUse {

	public static TreeNode<Integer> takeInput() {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter data : ");
		int data = s.nextInt();
		TreeNode<Integer> root = new TreeNode<Integer>(data);
		System.out.println("Enter no. of children of " + data + " : ");
		int n = s.nextInt();
		for(int i = 0; i < n; i++) {
			TreeNode<Integer> child = takeInput();
			root.children.add(child);
		}
		return root;
	}
	
	public static TreeNode<Integer> takeInputLevelWise() throws QueueEmptyException {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter root data : ");
		int data = s.nextInt();
		TreeNode<Integer> root = new TreeNode<Integer>(data);
		QueueUsingLL<TreeNode<Integer>> queue = new QueueUsingLL<TreeNode<Integer>>();
		queue.enqueue(root);
		while(!queue.isEmpty()) {
			TreeNode<Integer> node = queue.dequeue();
			System.out.println("Enter no. of children of " + node.data + " : ");
			int n = s.nextInt();
			for(int i = 0; i < n; i++) {
				System.out.println("Enter " + i + "th child of " + node.data + " : ");
				int d = s.nextInt();
				TreeNode<Integer> child = new TreeNode<Integer>(d);
				node.children.add(child);
				queue.enqueue(child);
			}
 		}
		return root;
	}
	
	public static void print(TreeNode<Integer> root) {
		String toBePrinted = root.data + " : ";
		for(TreeNode<Integer> child : root.children) {
			toBePrinted += child.data + ", ";
		}
		System.out.println(toBePrinted);
		for(TreeNode<Integer> child : root.children) {
			print(child);
		}
	}
	
	public static int getHeight(TreeNode<Integer> root) {
		if(root == null) {
			return 0;
		}
		int height = 0;
		for(TreeNode<Integer> child : root.children) {
			int ans = getHeight(child);
			if(ans > height) {
				height = ans;
			}
		}
		return height + 1;
	}
	
	public static void allElementsAtDepthK(TreeNode<Integer> root, int k) {
		if(k == 0) {
			System.out.print(root.data + " ");
			return;
		}
		for(TreeNode<Integer> child : root.children) {
			allElementsAtDepthK(child, k-1);
		}
	}
	
	public static void main(String[] args) throws QueueEmptyException {
		// 1 3 2 3 4 0 2 5 6 1 7 0 0 1 8 0
//		TreeNode<Integer> root = takeInput();
		TreeNode<Integer> root = takeInputLevelWise();
		print(root);
		System.out.println("Height : " + getHeight(root));
		int k = 4;
		System.out.println("All elements at depth " + k + " : ");
		allElementsAtDepthK(root, k);
		System.out.println();
	}

}
