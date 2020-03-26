package L13;

import java.util.Scanner;

public class LinkedListUse {

	public static Node<Integer> takeInput() {
		Scanner s = new Scanner(System.in);
		Node<Integer> head = null, tail = null;
		System.out.println("Enter next node : ");
		int data = s.nextInt();
		while(data != -1) {
			Node<Integer> newNode = new Node<Integer>(data);
			if(head == null) {
				head = newNode;
				tail = newNode;
			}
			else {
				tail.next = newNode;
				tail = newNode;
			}
			System.out.println("Enter next node : ");
			data = s.nextInt();
		}
		return head;
	}
	
	public static void printLL(Node<Integer> head) {
		Node<Integer> temp = head;
		while(temp != null) {
			System.out.print(temp.data + "->");
			temp = temp.next;
		}
		System.out.println();
	}
	
	public static Node<Integer> insertR(Node<Integer> head, int i, int data) {
		if(i == 0) {
			Node<Integer> newNode = new Node<Integer>(data);
			newNode.next = head;
			head = newNode;
			return head;
		}
		head.next = insertR(head.next, i-1, data);
		
		return head;
	}
	
	public static void main(String[] args) {
		Node<Integer> head = takeInput();
		printLL(head);
		
		head = insertR(head, 4, 9);
		printLL(head);
	}

}
