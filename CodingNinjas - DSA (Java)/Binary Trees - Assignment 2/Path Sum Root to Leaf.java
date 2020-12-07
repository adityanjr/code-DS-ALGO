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
	static Vector<Integer> path = new Vector<Integer>();
	public static void rootToLeafPathsSumToK(BinaryTreeNode<Integer> root, int k) {
		// Write your code here
        if (root == null)  
            return;  

        // add current node to the path  
        path.add(root.data);  

        // check if there's any k sum path  
        // in the left sub-tree.  
         rootToLeafPathsSumToK(root.left, k);  

        // check if there's any k sum path  
        // in the right sub-tree.  
         rootToLeafPathsSumToK(root.right, k);  

        // check if there's any k sum path that  
        // terminates at this node  
        // Traverse the entire path as  
        // there can be negative elements too  
        int f = 0;  
        for (int j = path.size() - 1; j >= 0; j--)  
        {  
            f += path.get(j);  

            // If path sum is k, print the path  
            if (f == k)  
                printVector(path, j);  
        }  

        // Remove the current element from the path  
        path.remove(path.size() - 1); 

    }
    static void printKPath(BinaryTreeNode<Integer>  root, int k)  
    {  
        path = new Vector<Integer>(); 
        rootToLeafPathsSumToK(root, k);  
    }  
    
    
    static void printVector( Vector<Integer> v, int i)  
    {  
        for (int j = i; j < v.size(); j++)  
            System.out.print( v.get(j) + " ");  
        System.out.println();  
    }  
}
