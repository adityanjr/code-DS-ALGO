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
        
        public static void insertDuplicateNode(BinaryTreeNode<Integer> node) {
            // Write your code here
           BinaryTreeNode<Integer> oldleft; 
       
            if (node == null) 
                return; 
       
            /* do the subtrees */
            insertDuplicateNode(node.left); 
            insertDuplicateNode(node.right); 
       
            /* duplicate this node to its left */
            oldleft = node.left; 
            node.left = new BinaryTreeNode<Integer>(node.data); 
            node.left.left = oldleft;
            
        }
    }
    