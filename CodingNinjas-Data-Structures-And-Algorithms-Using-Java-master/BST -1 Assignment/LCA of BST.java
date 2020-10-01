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
        static boolean found;
        public static int lcaInBST(BinaryTreeNode<Integer> root , int a , int b){
            // Write your code here
           
            if(root==null){
                return -1;
            }
            
           
            if(root.data > a && root.data > b){
                
               return lcaInBST(root.left,a,b);
                
                // return (root.data);
            }
            if(root.data< a && root.data < b){
                return lcaInBST(root.right,a,b);
           
            }
            
            return (root.data);
        
        }
    }