// import java.util.ArrayList;


// public class Solution {

// 	/*	Binary Tree Node class
// 	 * 
// 	 * class BinaryTreeNode<T> {
// 		T data;
// 		BinaryTreeNode<T> left;
// 		BinaryTreeNode<T> right;

// 		public BinaryTreeNode(T data) {
// 			this.data = data;
// 		}
// 	}
// 	 */

// 	/* class Node<T> {
// 		T data;
// 		Node<T> next;
// 		Node(T data){
// 			this.data = data;
// 		}
// 	}
// */
// 	public static ArrayList<Node<BinaryTreeNode<Integer>>> LLForEachLevel(BinaryTreeNode<Integer> root) {
		
// 		// Write your code here

// 	}
    
import java.util.ArrayList;
public class Solution {
public static ArrayList<Node<BinaryTreeNode<Integer>>> LLForEachLevel(BinaryTreeNode<Integer> root) { 
     QueueUsingLL<BinaryTreeNode<Integer>>    q  =new QueueUsingLL<BinaryTreeNode<Integer>>();
     ArrayList<Node<BinaryTreeNode<Integer>>> arr=new ArrayList<Node<BinaryTreeNode<Integer>>>();
     Node<BinaryTreeNode<Integer>> head=null;
     Node<BinaryTreeNode<Integer>> tail=null;
       q.enqueue(root); 
       q.enqueue(null);
       // first insert the root and null in the queue 
       // so that we can know the level is fully traversed or not
      while(!q.isEmpty()) {
         BinaryTreeNode<Integer> temp= null;
         try{ 
             temp = q.dequeue(); 
         }
         catch (QueueEmptyException e){}
          if(temp==null){
              // if the node which is dequeued is null than 
              // it has two meaning 
              // one is that the level is completed and the tree traversal is completed
              arr.add(head);
              head=null;
              tail=null;
              if(q.isEmpty()){
                  break;
              }
              q.enqueue(null);
              continue;
          }
            else{
              if(temp.left!=null)
              q.enqueue(temp.left);
              // insert the childrens
             if(temp.right!=null)
             q.enqueue(temp.right);
             
             Node<BinaryTreeNode<Integer>> ans1=new Node<BinaryTreeNode<Integer>>(temp);
             if(head==null){
             // check if this is the first node and if it is then we assign the both variables to ans1
                 head=ans1;
                 tail=ans1;
             }
             else{
             // we are using tail 
             // if we dont use the tail then we have to traverse the linked list again which make the algo worthless
                 tail.next=ans1;
                 tail=tail.next;
             }
         }
     }
    return arr;
  }
}



