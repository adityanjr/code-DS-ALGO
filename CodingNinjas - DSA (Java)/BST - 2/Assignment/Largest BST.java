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
    public static class Triplet{
        boolean isbst;
        int maximum;
        int minimum;
        int height;

    }
    public static Triplet largestbst(BinaryTreeNode<Integer>root){
        if(root == null){
            Triplet ans = new Triplet();
            ans.isbst = true;
            ans.maximum = Integer.MIN_VALUE;
            ans.height=0;
            ans.minimum = Integer.MAX_VALUE;
            return ans;
        }
        Triplet left = largestbst(root.left);
        Triplet right = largestbst(root.right);
        Triplet ans = new Triplet();
        if(left.isbst && root.data > left.maximum&& root.data <= right.minimum){
            ans.isbst = true;
        }
        else{
            ans.isbst = false;
        }
        ans.maximum = Math.max(root.data,right.maximum);
        ans.minimum = Math.min(root.data,left.minimum);
        if(ans.isbst==true)
        {
            ans.height=Math.max(left.height,right.height)+1 ;    
        }
        else {
            ans.height=Math.max(left.height,right.height);
        }
        return ans;
    }
    public static int largestBSTSubtree(BinaryTreeNode<Integer> root) {
        // Write your code here
        Triplet s = new Triplet();
        s = largestbst(root);
        return s.height;
    }
}
