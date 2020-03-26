package L14;

import java.util.Scanner;

public class StackUse {

	public static void main(String[] args) throws StackFullException, StackEmptyException {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter size : ");
		int size = s.nextInt();
		Stacks st = new Stacks(size); 
		for(int i = 0; i <= size; i++) {
			try {
				st.push(i);
			} catch (StackFullException e) {
				System.out.println("Stack Full !");
			}
		}
		System.out.println("Size = " + st.size());
		try {
			System.out.println("Top : " + st.top());
			System.out.println("Pop : " + st.pop());
			System.out.println("Pop : " + st.pop());
		} catch (StackEmptyException e) {
			System.out.println("Stack Empty !");
		}
		
		/*Scanner s = new Scanner(System.in);
		System.out.println("Enter size : ");
		int size = s.nextInt();
		Stacks st = new Stacks(size); 
		for(int i = 0; i <= size; i++) {
				st.push(i);
		}
		System.out.println("Size = " + st.size());
			System.out.println("Top : " + st.top());
			System.out.println("Pop : " + st.pop());
			System.out.println("Pop : " + st.pop());
			System.out.println("Stack Empty !");*/
		
	}

}
