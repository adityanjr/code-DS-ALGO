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
        static int sum=0;
        public static void replaceWithLargerNodesSum(BinaryTreeNode<Integer> root) {
            // Write your code here
            // 8
        //     5        10
        // 2    6
                // 7
            if(root==null)
                return ;
            replaceWithLargerNodesSum(root.right);
            sum+=root.data;
            root.data=sum;
            replaceWithLargerNodesSum(root.left);
            return;
            
        }
    }
    