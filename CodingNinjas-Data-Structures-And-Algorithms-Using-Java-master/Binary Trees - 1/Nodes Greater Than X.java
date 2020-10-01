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
        static int count; 
        public static int numNodesGreaterX(BinaryTreeNode<Integer> root,int x){
            /* Your class should be named Solution
             * Don't write main().
             * Don't read input, it is passed as function argument.
             * Return output and don't print it.
              * Taking input and printing output is handled automatically.
            */
            // int count;
            if(root==null){
                return -1;
            }
            else{
                if(root.data>x){
                    count++;
                }
                numNodesGreaterX(root.left,x);
                numNodesGreaterX(root.right,x);
            }
            return count;
            
    
        }
        
    }
    