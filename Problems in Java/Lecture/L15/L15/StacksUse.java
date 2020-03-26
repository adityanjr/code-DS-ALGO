package L15;

public class StacksUse {
	
	public static void reverseStack(Stacks s1, Stacks s2) throws StackEmptyException, StackFullException {
		if(s1.isEmpty()) {
			return;
		}
		int top = s1.pop();
		reverseStack(s1, s2);
		while(!s1.isEmpty()) {
			s2.push(s1.pop());
		}
		s1.push(top);
		while(!s2.isEmpty()) {
			s1.push(s2.pop());
		}
	}
	
	public static boolean checkBalanced(String exp) throws StackFullException, StackEmptyException {
		if(exp.length() == 0) {
			return true;
		}
		Stacks s = new Stacks(20);
		for(int i = 0; i < exp.length(); i++) {
			if(exp.charAt(i) == '(' || exp.charAt(i) == '{' || exp.charAt(i) == '[') {
				s.push(exp.charAt(i));
			}
			else if(exp.charAt(i) == ')') {
				int lastOpeningBracket = s.pop();
				if(lastOpeningBracket != '(') {
					return false;
				}
			}
			else if(exp.charAt(i) == '}') {
				int lastOpeningBracket = s.pop();
				if(lastOpeningBracket != '{') {
					return false;
				}
			}
			else if(exp.charAt(i) == ']') {
				int lastOpeningBracket = s.pop();
				if(lastOpeningBracket != '[') {
					return false;
				}
			}
		}
		if(s.isEmpty()) {
			return true;
		}
		else {
			return false;
		}
	}
	
	public static void main(String[] args) throws StackFullException, StackEmptyException {
		/*Stacks s1 = new Stacks(5);
		Stacks s2 = new Stacks(5);
		for(int i = 0; i < 5; i++) {
			s1.push(i);
		}
		reverseStack(s1, s2);
		while(!s1.isEmpty()) {
			System.out.println(s1.pop());
		}*/
		
		StackUsinTwoQueues sq = new StackUsinTwoQueues();
		for(int i = 0; i < 5; i++) {
			sq.push(i);
		}
		
		System.out.println(sq.pop());
		System.out.println(sq.pop());
		System.out.println(sq.pop());
		System.out.println(sq.pop());
	}
}
