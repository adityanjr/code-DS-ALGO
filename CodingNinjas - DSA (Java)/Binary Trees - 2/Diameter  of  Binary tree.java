public class Solution {

    /*	Binary Tree Node class 
     * 
     * 	class BinaryTreeNode<T> {
            T data;
            BinaryTreeNode<T> left;
            BinaryTreeNode<T> right;
            
            public BinaryTreeNode(T data) {
                this.data = data;
            }
        }
        */
        
        public static int diameterOfBinaryTree(BinaryTreeNode<Integer> root){
            /* Your class should be named Solution
             * Don't write main().
             * Don't read input, it is passed as function argument.
             * Return output and don't print it.
              * Taking input and printing output is handled automatically.
            */
          
            /* base case if tree is empty */
            if (root == null) 
                return 0; 
      
            /* get the height of left and right sub trees */
            int lheight = height(root.left); 
            int rheight = height(root.right); 
      
            /* get the diameter of left and right subtrees */
            int ldiameter = diameterOfBinaryTree(root.left); 
            int rdiameter = diameterOfBinaryTree(root.right); 
      
            /* Return max of following three 
              1) Diameter of left subtree 
             2) Diameter of right subtree 
             3) Height of left subtree + height of right subtree + 1 */
            return Math.max(lheight + rheight + 1,  Math.max(ldiameter, rdiameter)); 
      
    
        }
          static int height(BinaryTreeNode<Integer> node) 
        { 
            /* base case tree is empty */
            if (node == null) 
                return 0; 
      
            /* If tree is not empty then height = 1 + max of left 
               height and right heights */
            return (1 + Math.max(height(node.left), height(node.right))); 
        } 
        
        
    }
    