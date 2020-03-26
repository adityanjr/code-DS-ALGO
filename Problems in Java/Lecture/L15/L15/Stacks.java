package L15;

public class Stacks {
	private int data[];
	private int nextIndex;
	
	public Stacks(int size) {
		data = new int[size];
		nextIndex = 0;
	}
	
	public boolean isEmpty() {
		return nextIndex == 0;
	}
	
	public int size() {
		return nextIndex;
	}
	
	public void push(int element) throws StackFullException {
		/*if(nextIndex == data.length) {
			StackFullException e = new StackFullException();
			throw e;
		}*/
		
		if(nextIndex == data.length) {
			int newArray[] = new int[2*data.length];
			int i;
			for(i = 0; i < data.length; i++) {
				newArray[i] = data[i];
			}
			newArray[i] = element;
			data = newArray;
			return;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	public int pop() throws StackEmptyException {
		if(nextIndex == 0) {
			StackEmptyException e = new StackEmptyException();
			throw e;
		}
		int value = data[nextIndex-1];
		nextIndex--;
		return value;
	}
	
	public int top() throws StackEmptyException {
		if(nextIndex == 0) {
			StackEmptyException e = new StackEmptyException();
			throw e;
		}
		int value = data[nextIndex-1];
		return value;
	}
}
