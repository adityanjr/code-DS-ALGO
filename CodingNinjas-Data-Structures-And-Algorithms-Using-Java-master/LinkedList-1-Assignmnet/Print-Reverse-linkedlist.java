
/*
class LinkedListNode<T> {
	public T data;
	public LinkedListNode<T> next;

	public LinkedListNode(T data) {
		this.setData(data);
		this.next = null;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

}
* */
public class Solution {
	public static void printReverseRecursive(LinkedListNode<Integer> root) {
   if(root==null){
        return;
      }
      printReverseRecursive(root.next);
      System.out.print(root.data+" ");
    }
}