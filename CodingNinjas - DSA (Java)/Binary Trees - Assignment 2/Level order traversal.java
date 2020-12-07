import java.util.*;


public class Solution {

	/*	Binary Tree Node class
	 * 
	 * class BinaryTreeNode<T> {
		T data;
		BinaryTreeNode<T> left;
		BinaryTreeNode<T> right;

		public BinaryTreeNode(T data) {
			this.data = data;
		}
	}
	 */

	public static void printLevelWise(BinaryTreeNode<Integer> root){
		
		Queue<BinaryTreeNode<Integer>> currentLevel = new LinkedList<BinaryTreeNode<Integer>>();
        Queue<BinaryTreeNode<Integer>> nextLevel = new LinkedList<BinaryTreeNode<Integer>>();

        currentLevel.add(root);

        while (!currentLevel.isEmpty()) {
            Iterator<BinaryTreeNode<Integer>> iter = currentLevel.iterator();
            while (iter.hasNext()) {
                BinaryTreeNode<Integer> currentNode = iter.next();
                if (currentNode.left != null) {
                    nextLevel.add(currentNode.left);
                }
                if (currentNode.right != null) {
                    nextLevel.add(currentNode.right);
                }
                System.out.print(currentNode.data + " ");
            }
            System.out.println();
            currentLevel = nextLevel;
            nextLevel = new LinkedList<BinaryTreeNode<Integer>>();

        }

    }
}
