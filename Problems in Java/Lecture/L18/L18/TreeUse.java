package L18;

import java.util.Scanner;

public class TreeUse {
	
	public static TreeNode<Integer> takeInputLevelWise() throws QueueEmptyException{
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
	
	public static Pair<TreeNode<Integer>> secondLargest(TreeNode<Integer> root) {
		if(root == null) {
			Pair<TreeNode<Integer>> ans = new Pair<TreeNode<Integer>>();
			ans.Largest = null;
			ans.secondLargest = null;
			return ans;
		}
		Pair<TreeNode<Integer>> ans = new Pair<TreeNode<Integer>>();
		ans.Largest = root;
		ans.secondLargest = null;
		for(TreeNode<Integer> child : root.children) {
			Pair<TreeNode<Integer>> childAns = secondLargest(child);
			if(childAns.Largest.data > ans.Largest.data) {
				if(childAns.secondLargest == null) {
					ans.secondLargest = ans.Largest;
				}
				else {
					if(ans.Largest.data > childAns.secondLargest.data) {
						ans.secondLargest = ans.Largest;
					}
					else {
						ans.secondLargest = childAns.secondLargest;
					}
				}
				ans.Largest = childAns.Largest;
			}
			else {
//				ans.Largest = ans.Largest;
				if(ans.secondLargest == null) {
					ans.secondLargest = childAns.Largest;
				}
				else {
					if(ans.secondLargest.data < childAns.Largest.data) {
						ans.secondLargest = childAns.Largest;
					}
					/*else {
						ans.secondLargest =  ans.secondLargest;
					}*/
				}
			}
		}
		return ans;
	}
	
	public static void main(String[] args) throws QueueEmptyException {
		TreeNode<Integer> root = takeInputLevelWise();
		Pair<TreeNode<Integer>> ans = secondLargest(root);
		System.out.println(ans.secondLargest.data);
	}
}
