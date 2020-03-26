package L15;

public class QueueUse {

	public static void reverseQueue(Queue q) {
		if(q.size() <= 1) {
			return;
		}
		int front = q.dequeue();
		reverseQueue(q);
		q.enqueue(front);
	}
	
	public static void main(String[] args) {
		Queue q = new Queue(5);
		for(int i = 0; i < 5; i++) {
			q.enqueue(i);
		}
		reverseQueue(q);
		System.out.println("Size = " + q.size());
		System.out.println("Front : " + q.front());
		System.out.println("Dequeue : " + q.dequeue());
		System.out.println("Dequeue : " + q.dequeue());
		System.out.println("Dequeue : " + q.dequeue());
	}

}
