package L18;

public class StackUsingLL<T> {
	private Node<T> head;
	private int size;
	
	public StackUsingLL() {
		size = 0;
		head = null;
	}
	
	public int size() {
		return size;
	}
	
	public void push(T data) {
		Node<T> newNode = new Node<T>(data);
		if(head == null) {
			head = newNode;
		}
		else {
			newNode.next = head;
			head = newNode;
		}
		size++;
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public T pop() throws StackEmptyException {
		if(isEmpty()) {
			StackEmptyException e = new StackEmptyException();
			throw e;
		}
		T temp = head.data;
		head = head.next;
		size--;
		return temp;
	}
	
	public T top() throws StackEmptyException {
		if(isEmpty()) {
			StackEmptyException e = new StackEmptyException();
			throw e;
		}
		return head.data;
	}
	
}
