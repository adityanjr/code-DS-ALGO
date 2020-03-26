package L14;

public class LLUse {

	public static Node<Integer> findMid(Node<Integer> head) {
		Node<Integer> slow = head, fast = head;
		while(fast.next != null || fast.next.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;
	}

	public static Node<Integer> bubbleSort(Node<Integer> head) {
		if(head == null || head.next == null) {
			return head;
		}

		for(int i = 0; i < 5; i++) {
			Node<Integer> prev = null, current = head;

			while(current.next != null) {
				if(current.data <= current.next.data) {
					prev = current;
					current = current.next;
				}
				else {
					if(prev != null) {
						Node<Integer> currNext = current.next;
						current.next = current.next.next;
						prev.next = currNext;
						currNext.next = current;
						prev = prev.next;
					}
					else {
						Node<Integer> currNext = current.next;
						current.next = current.next.next;
						currNext.next = current;
						head = currNext;
						prev = head;
					}
				}
			}
		}
		return head;
	}


	public static void main(String[] args) {
		Node<Integer> head = LinkedListUse.takeInput();
//		Node<Integer> mid = findMid(head);
//		System.out.println(mid.data);
		
		head = bubbleSort(head);
		LinkedListUse.printLL(head);
	}
}
