
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
    static LinkedListNode<Integer> left=null;
	public static boolean isPalindrome_2(LinkedListNode<Integer> head) {
        left=head;  
      return find(head);
    	
  	}
  public static boolean find(LinkedListNode<Integer> right){
   	 if(right==null){
        return true;
      }
      boolean val=find(right.next);
      if(val==true){
        if(left.data==right.data){
          left=left.next;
          return true;
        }
      }
      return false;
        
    }
}