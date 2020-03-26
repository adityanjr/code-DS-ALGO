package L18;


public class QueueUsingLL<T> {
	private Node<T> front;
	private Node<T> rear;
	private int size;

	public QueueUsingLL() {
		front = null;
		rear = null;
		size = 0;
	}

	public void enqueue(T data) {
		Node<T> newNode = new Node<T>(data);
		if(front == null && rear == null) {
			front = newNode;
			rear = newNode;
		}
		else {
			rear.next = newNode;
			rear = newNode;
		}
		size++;
	}

	public int size() {
		return size;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	public T dequeue() throws QueueEmptyException {
		if(isEmpty()) {
			QueueEmptyException e = new QueueEmptyException();
			throw e;
		}
		Node<T> temp = front;
		if(size == 1) {
			front = null;
			rear = null;
		}
		else {
			front = front.next;
			temp.next = null;
		}
		size--;
		return temp.data;
	}
}
