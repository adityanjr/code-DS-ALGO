package L6;

public class Recursion {

	public static int factorial(int n) {
		if(n == 0) {
			return 1;
		}
		return n * factorial(n-1);
	}
	
	public static int fibonacci(int n) {
		if(n == 0) {
			return 0;
		}
		if(n == 1) {
			return 1;
		}
		return fibonacci(n-1) + fibonacci(n-2);
	}
	
	public static boolean isSorted(int[] a) {
		if(a.length <= 1) {
			return true;
		}
		
		if(a[0] > a[1]) {
			return false;
		}
		
		int[] smallInput = new int[a.length-1];
		for(int i = 1; i < a.length; i++) {
			smallInput[i-1] = a[i];
		}
		return isSorted(smallInput);
	}
	
	public static boolean isSorted_2(int[] a, int startIndex) {
		if(startIndex >= a.length-1) {
			return true;
		}
		if(a[startIndex] > a[startIndex+1]) {
			return false;
		}
		return isSorted_2(a, startIndex+1);
	}
	
	public static int[]  allIndicesOf7(int[] a, int si) {
		if(si == a.length) {
			int[] output = new int[0];
			return output;
		}
		int smallAns[] = allIndicesOf7(a, si+1);
		
		int[] output = new int[0];
		
		if(a[si] == 7) {
			output = new int[smallAns.length + 1];
			output[0] = si;
			for(int i = 0; i < smallAns.length; i++) {
				output[i+1] = smallAns[i];
			}
		}
		else {
			output = new int[smallAns.length];
			for(int i = 0; i < smallAns.length; i++) {
				output[i] = smallAns[i];
			}
		}
		
		return output;
	}
	
	public static void main(String[] args) {
//		System.out.println(factorial(5));
		
//		System.out.println(fibonacci(5));
		
		int[] a = {7,8};
//		System.out.println(isSorted(a));
		int[] ans = allIndicesOf7(a, 0);
		
		for(int i = 0; i < ans.length; i++) {
			System.out.println(ans[i]);
		}
		
	}

}
