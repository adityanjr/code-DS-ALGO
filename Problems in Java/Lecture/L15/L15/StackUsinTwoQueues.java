package L15;

public class StackUsinTwoQueues {
	Queue q1;
	Queue q2;
	int size;

	public StackUsinTwoQueues() {
		q1 = new Queue(5);
		q2 = new Queue(5);
		size = 0;
	}
	
	public void push(int data) {
		q1.enqueue(data);
	}

	public int pop() {
		if(q1.isEmpty()) {
			// TODO queue empty
		}
		while(q1.size() > 1) {
			q2.enqueue(q1.dequeue());
		}
		int ans = q1.dequeue();
		Queue temp = q1;
		q1 = q2;
		q2 = temp;
		return ans;
	}
}
