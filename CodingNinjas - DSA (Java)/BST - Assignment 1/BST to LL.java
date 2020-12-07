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
    
    /* LinkedList Node Class
    *
    *	
    class LinkedListNode<T> {
        T data;
        LinkedListNode<T> next;
        
        public LinkedListNode(T data) {
            this.data = data;
        }
    }
    */
    
        public static LinkedListNode<Integer> BSTToSortedLL(BinaryTreeNode<Integer> root){
            /* Your class should be named Solution
             * Don't write main().
             * Don't read input, it is passed as function argument.
             * Return output and don't print it.
              * Taking input and printing output is handled automatically.
            */
    LinkedListNode<Integer> head=new LinkedListNode<Integer>(root.data);
            
            if(root.left==null&&root.right==null)
            {
                return head;
            }
            
            else if(root.left!=null&&root.right!=null)
            {
                LinkedListNode<Integer> temp=BSTToSortedLL(root.left);
                LinkedListNode<Integer> tempp=temp;
                while(temp.next!=null)
                {
                    temp=temp.next;
                }
                temp.next=head;
                head.next=BSTToSortedLL(root.right);
                return tempp;
            }
            
            else if(root.left!=null)
            {
                LinkedListNode<Integer> temp=BSTToSortedLL(root.left);
                LinkedListNode<Integer> tempp=temp;
                while(temp.next!=null)
                {
                    temp=temp.next;
                }
                temp.next=head;
                return tempp;
            }
            else
            {
                head.next=BSTToSortedLL(root.right);
                return head;
            }
            
            
        }
    }	