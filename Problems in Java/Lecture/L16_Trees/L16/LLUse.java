package L16;

public class LLUse {

	public static Node<Integer> reverseLL(Node<Integer> head) {
		if(head == null || head.next == null) {
			return head;
		}
		
		Node<Integer> ans = reverseLL(head.next);
		Node<Integer> temp = ans;
		while(temp.next != null) {
			temp = temp.next;
		}
		temp.next = head;
		head.next = null;
		return ans;
	}
	
	public static Pair<Integer> reverseLL_1(Node<Integer> head) {
		if(head == null || head.next == null) {
			Pair<Integer> ans = new Pair<Integer>();
			ans.head = head;
			ans.tail = head;
			return ans;
		}
		Pair<Integer> ans = reverseLL_1(head.next);
		ans.tail.next = head;
		ans.tail = head;
		ans.tail.next = null;
		return ans;
	}
	
	public static void main(String[] args) {

	}

}
