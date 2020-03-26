package L3;

import java.util.Scanner;

public class SquareRoot {

	public static int findSquareRoot(int num) {
		int output = 0;
		while(output*output <= num) {
			output = output + 1;
		}
		output = output - 1;
//		System.out.println(output);
		
		return output;
	}
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number : ");
		int n = s.nextInt();
		
		int ans = findSquareRoot(n);
		System.out.println(ans);
		
//		System.out.println(findSquareRoot(n));
	}

}
