package L20;

import java.util.ArrayList;

public class PriorityQueue {
	ArrayList<Integer> heap;

	public PriorityQueue() {
		heap = new ArrayList<Integer>();
		heap.add(null);
	}

	public int getSize() {
		return heap.size() - 1;
	}

	public boolean isEmpty() {
		return (getSize() == 0);
	}

	public int min() {
		if(isEmpty()) {
			// PQ empty Exception
		}
		return heap.get(1);
	}

	public void insert(int priority) {
		heap.add(priority);
		int childIndex = heap.size() - 1;
		int parentIndex = childIndex / 2;
		while(childIndex > 1) {
			int child = heap.get(childIndex);
			int parent = heap.get(parentIndex);
			if(child > parent) {
				return;
			}
			int temp = child;
			heap.set(childIndex, parent);
			heap.set(parentIndex, temp);

			childIndex = parentIndex;
			parentIndex = childIndex / 2;
		}
	}

	public int removeMin() {
		if(isEmpty()) {
			// PQ empty Exception
		}
		int min = heap.get(1);
		int lastIndex = heap.size()-1;
		heap.set(1, heap.get(lastIndex));
		heap.remove(lastIndex);

		int parentIndex = 1;
		int leftChildIndex = 2*parentIndex;
		int rightChildIndex = leftChildIndex + 1;
		while(parentIndex <= heap.size()-1) {
			int minIndex = parentIndex;
			int minValue = heap.get(minIndex);

			if(leftChildIndex <= heap.size()-1) {
				int leftChild = heap.get(leftChildIndex);
				if(leftChild < minValue) {
					minIndex = leftChildIndex;
					minValue = heap.get(minIndex);
				}
			}

			if(rightChildIndex <= heap.size()-1) {
				int rightChild = heap.get(rightChildIndex);
				if(rightChild < minValue) {
					minIndex = rightChildIndex;
					minValue = heap.get(minIndex);
				}
			}
			
			
			if(parentIndex == minIndex) {
				break;
			}
			else {
				heap.set(minIndex, heap.get(parentIndex));
				heap.set(parentIndex, minValue);
			}
			parentIndex = minIndex;
			leftChildIndex = 2*parentIndex;
			rightChildIndex = leftChildIndex + 1;
		}

		return min;
	}
}
