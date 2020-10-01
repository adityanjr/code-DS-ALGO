

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
	public static LinkedListNode<Integer> removeDuplicates(LinkedListNode<Integer> head) {
        LinkedListNode<Integer> temp=head;
        while(temp.next!=null){
            if(temp.data.equals((temp.next).data)){
                temp.next=temp.next.next;
            }
            else
                temp=temp.next;
        }
        return head;
    }
}