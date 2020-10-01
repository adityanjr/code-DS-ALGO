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

	public static BinaryTreeNode<Integer> getTreeFromPostorderAndInorder(int[] postorder,int[] inorder){
		
			// Write your code here
		 return helper(0,inorder.length-1,inorder,postorder,0);
	}
   public static BinaryTreeNode<Integer> helper(int start,int end,int[] inorder, int[] postorder,int offset){

        if(postorder == null || start > end)
            return null;

        if(end-offset < 0)
            return null;
        
         BinaryTreeNode<Integer> root = new  BinaryTreeNode<Integer>(postorder[end-offset]);
        int index = getIndex(inorder,postorder[end-offset]);
        root.left = helper(start,index-1,inorder,postorder,offset);
        root.right = helper(index+1,end,inorder,postorder,offset+1);

        return root;
    }
	 private static int getIndex(int[] nums,int value){
        if(nums == null || nums.length == 0)
            return -1;

        for(int i=0;i<nums.length;i++)
            if(nums[i] == value)
                return i;

        return -1;
    }
}



