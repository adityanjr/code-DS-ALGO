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
    

	public static BinaryTreeNode<Integer> getTreeFromPreorderAndInorder(int[] preorder,int[] inorder){
		
			// Write your code here
        // int len=pre.length-1;
        return helper(preorder,0,preorder.length-1, inorder, 0, inorder.length-1);
		}
     static BinaryTreeNode<Integer> helper(int[] preorder, int p_start, int p_end, int[] inorder, int i_start, int i_end){
        // recursive termination condition to avoid infinite loop
        if(p_start > p_end || i_start>i_end) return null;
        
        //root node from preorder[]
        BinaryTreeNode<Integer> root = new BinaryTreeNode<Integer>(preorder[p_start]);
        // find the root index of inorder[] first, then to determine left and right subtree
        int index =0;
        while(inorder[i_start+index] != preorder[p_start] )
        {
            index++;
        }
                
        //rebuild left_subtree & right_subtree recursively
        root.left = helper(preorder, p_start+1, p_start+index, inorder, i_start,i_start+index-1);
        root.right = helper(preorder,p_start+index+1, p_end, inorder, i_start+index+1,i_end); 

        return root;    
    }
        
}


