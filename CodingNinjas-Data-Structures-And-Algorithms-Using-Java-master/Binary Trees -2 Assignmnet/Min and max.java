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

	PairAns class - 
	class PairAns {
		int min;
		int max;
	}

	 */
    public static PairAns minMax(BinaryTreeNode<Integer> root) {
        /* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
		 * Taking input and printing output is handled automatically.
		 */
        PairAns pair=new PairAns();
        pair.min= findMin(root);
        pair.max =findMax(root);
        return pair;

    }
    static int findMax(BinaryTreeNode<Integer> node) 
    { 
        if (node == null) 
            return Integer.MIN_VALUE; 

        int res = node.data; 
        int lres = findMax(node.left); 
        int rres = findMax(node.right); 

        if (lres > res) 
            res = lres; 
        if (rres > res) 
            res = rres; 
        return res; 
    } 

    static int findMin(BinaryTreeNode<Integer> node) 
    { 
        if (node == null) 
            return Integer.MAX_VALUE; 

        int res = node.data; 
        int lres = findMin(node.left); 
        int rres = findMin(node.right); 

        if (lres < res) 
            res = lres; 
        if (rres < res) 
            res = rres; 
        return res; 
    } 

}
