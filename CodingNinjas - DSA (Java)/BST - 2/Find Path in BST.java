import java.util.ArrayList;

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

	public static ArrayList<Integer> findPath(BinaryTreeNode<Integer> root, int data){
		/* Your class should be named Solution
		* Don't write main().
		* Don't read input, it is passed as function argument.
		* Return output and don't print it.
		* Taking input and printing output is handled automatically.
		*/
        if(root==null){
            return null;
        }
        if(root.data==data){
            ArrayList<Integer> output =new ArrayList<Integer>();
            output.add(root.data);
            return output;
        }
        
        if(data < root.data){
            ArrayList<Integer> leftoutput = findPath(root.left,data);
            if(leftoutput !=null){
                leftoutput.add(root.data);
                return leftoutput;
            }
            
        }
        else if(data > root.data){
          ArrayList<Integer> rightoutput =  findPath(root.right,data);
            if(rightoutput !=null){
                rightoutput.add(root.data);
                return rightoutput;
            }
        }
        else
            return null;
    return null;

	}
}