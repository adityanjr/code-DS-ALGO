package L18;

public class StockSpan {

	public static void span(int[] price, int[] output) throws StackEmptyException {
		StackUsingLL<Integer> s = new StackUsingLL<Integer>();
		s.push(0);
		output[0] = 1;
		for(int i = 1; i < price.length; i++) {
			while(!s.isEmpty() && price[s.top()] < price[i]) {
				s.pop();
			}
			if(s.isEmpty()) {
				output[i] = i + 1;
			}
			else {
				output[i] = i - s.top();
			}
			s.push(i);
		}
	}
	
	public static void main(String[] args) {
		int input[] = {5, 8, 12, 7, 9};
		int output[] = new int[input.length];
		try {
			span(input, output);
		} catch (StackEmptyException e) {
			return;
		}
		for(int i : output) {
			System.out.print(i + " ");
		}
	}

}
