package L17;

import java.util.Scanner;

public class BinaryTreeUse {
	
	public static BTNode<Integer> takeInput() throws QueueEmptyException {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter root data : ");
		int rootData = s.nextInt();
		if(rootData == -1) {
			return null;
		}
		BTNode<Integer> root = new BTNode<Integer>(rootData);
		QueueUsingLL<BTNode<Integer>> pendingNodes = new QueueUsingLL<BTNode<Integer>>();
		pendingNodes.enqueue(root);
		while(!pendingNodes.isEmpty()) {
			BTNode<Integer> first = pendingNodes.dequeue();
			System.out.println("Enter left child of " + first.data);
			int left = s.nextInt();
			if(left != -1) {
				BTNode<Integer> leftChild = new BTNode<Integer>(left);
				first.left = leftChild;
				pendingNodes.enqueue(leftChild);
			}
			System.out.println("Enter right child of " + first.data);
			int right = s.nextInt();
			if(right != -1) {
				BTNode<Integer> rightChild = new BTNode<Integer>(right);
				first.right = rightChild;
				pendingNodes.enqueue(rightChild);
			}
		}
		return root;
	}
	
	public static void print(BTNode<Integer> root) {
		if(root == null) {
			return;
		}
		String toBePrinted = root.data + " : ";
		if(root.left != null) {
			toBePrinted += root.left.data + ", ";
		}
		if(root.right != null) {
			toBePrinted += root.right.data;
		}
		System.out.println(toBePrinted);
		print(root.left);
		print(root.right);
	}
	
	public static int height(BTNode<Integer> root) {
		if(root == null) {
			return 0;
		}
		return Math.max(height(root.left), height(root.right)) + 1;
	}
	
	public static int diameter(BTNode<Integer> root) {
		if(root == null) {
			return 0;
		}
		int d1 = diameter(root.left);
		int d2 = diameter(root.right);
		int d3 = height(root.left) + height(root.right) + 1;
		return Math.max(d1, Math.max(d2, d3));
	}
	
	public static Pair diameterBetter(BTNode<Integer> root) {
		if(root == null) {
			Pair ans = new Pair();
			ans.diameter = 0;
			ans.height = 0;
			return ans;
		}
		Pair ans1 = diameterBetter(root.left);
		Pair ans2 = diameterBetter(root.right);
		Pair ans3 = new Pair();
		ans3.height = Math.max(ans1.height, ans2.height) + 1;
		ans3.diameter = ans1.height + ans2.height + 1;
		Pair ans;
		if(ans1.diameter > ans2.diameter && ans1.diameter > ans3.diameter) {
			ans = ans1;
		}
		else if(ans2.diameter > ans3.diameter && ans2.diameter > ans1.diameter) {
			ans = ans2;
		}
		else {
			ans = ans3;
		}
		return ans;
	}
	
	public static void main(String[] args) throws QueueEmptyException {
		BTNode<Integer> root = takeInput();
		print(root);
		System.out.println("Diameter : " + diameterBetter(root).diameter);
	}
}
