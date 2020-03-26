package L14;

import java.util.Scanner;

public class Test {
	
	public static void abc(int a, int b) throws DivideByZero {
//		int a = 3;
//		int b = 0;
		
		if(b == 0) {
			DivideByZero er = new DivideByZero();
			throw er;
		}
		
		double c = a/b;
		
	}
	
	public static void main(String[] args) throws DivideByZero {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter a and b");
		int a = s.nextInt();
		int b = s.nextInt();
		
		abc(a,b);
		
		/*try {
			abc(a, b);
		} catch (DivideByZero e) {
			System.out.println("you entered a wrong value of b");
		}*/
	}
}
