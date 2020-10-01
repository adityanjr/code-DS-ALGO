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
        public static void printLevelWise(BinaryTreeNode<Integer> root) {
            /* Your class should be named Solution
            * Don't write main().
            * Don't read input, it is passed as function argument.
            * Print output and don't return it.
            * Taking input is handled automatically.
            */
            QueueUsingLL<BinaryTreeNode<Integer>> q = new QueueUsingLL<>();
            q.enqueue(root);
            BinaryTreeNode<Integer> current = null;
            while(!q.isEmpty()) {
        try{
                current = q.dequeue();
        }catch(Exception e)
        {}
                System.out.print(current.data + ":");
                
                if(current.left!=null) {
                    System.out.print("L:"+current.left.data + ",");
                    q.enqueue(current.left);
                }
               else
                    System.out.print("L:-1,");
                if(current.right!=null) {
                    System.out.print( "R:" + current.right.data);
                    q.enqueue(current.right);
    
            }
                else
                    
                    System.out.print("R:-1");
                System.out.println();
            }
         
        }
    
    }
    