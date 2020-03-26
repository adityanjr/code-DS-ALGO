package L18;

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
	
	public static int findMin(BTNode<Integer> root) {
		if(root == null) {
			return Integer.MAX_VALUE;
		}
		int min = root.data;
		return Math.min(min, Math.min(findMin(root.left), findMin(root.right)));
	}
	
	public static int findMax(BTNode<Integer> root) {
		if(root == null) {
			return Integer.MIN_VALUE;
		}
		int max = root.data;
		return Math.max(max, Math.max(findMax(root.left), findMax(root.right)));
	}
	
	public static boolean isBst(BTNode<Integer> root) {
		if(root == null) {
			return true;
		}
		int max = findMax(root.left);
		int min = findMin(root.right);
		if(max > root.data || min < root.data) {
			return false;
		}
		else {
			return isBst(root.left) && isBst(root.right);
		}
	}
	
	public static void main(String[] args) throws QueueEmptyException {
		BTNode<Integer> root = takeInput();
		System.out.println(isBst(root));
	}

}
