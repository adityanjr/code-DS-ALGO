
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
	public static LinkedListNode<Integer> append(LinkedListNode<Integer> root, int n) {
        LinkedListNode<Integer> temp=null;
    
        LinkedListNode<Integer> end=null;
        end =root;
        int length=1;
        while(end.next!=null){
            length++;
            end=end.next;
        }
        int i=1;
        temp=root;
        while(i<length-n){
            i++;
            temp=temp.next;
        }
        end.next=root;
        root=temp.next;
        temp.next=null;
        return root;
        
    }
}
