/*************** 
 * Following is the Node class already written 
class LinkedListNode<T> {
	T data;
	LinkedListNode<T> next;

	public Node(T data) {
		this.data = data;
	}
}
 ***************/

public class Solution {
	public static int indexOfNIter(LinkedListNode<Integer> head, int n) {
		/* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
         LinkedListNode<Integer>
		*/
     if(head==null){
        return -1;
      }
      if(head.data==n){
        return 0;
      }
      int index=indexOfNIter(head.next,n);
      if(index>=0){
        return ++index;
      }
      return -1;
	}
}