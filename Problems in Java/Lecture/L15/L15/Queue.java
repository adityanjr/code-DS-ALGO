package L15;

public class Queue {
	private int data[];
	private int firstIndex;		// Element to be deleted
	private int nextIndex;		// position for addition
	private int size;
	
	public Queue(int size) {
		data = new int[size];
		firstIndex = -1;
		nextIndex = 0;
		this.size = 0;
	}
	
	public int size() {
		return size;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
	
	public void enqueue(int element) {
		if(nextIndex == firstIndex) {
			// TODO Queue full exception
		}
		if(firstIndex == -1) {
			firstIndex = 0;
		}
		data[nextIndex] = element;
		nextIndex = (nextIndex + 1) % data.length;
		size++;
	}
	
	public int dequeue() {
		if(size == 0) {
			// TODO Queue empty
		}
		int ans = data[firstIndex];
		size--;
		firstIndex = (firstIndex + 1) % data.length;
		if(size == 0) {
			firstIndex = -1;
		}
		return ans;
	}
	
	public int front() {
		if(size == 0) {
			// TODO Queue empty
		}
		return data[firstIndex];
	}
}
