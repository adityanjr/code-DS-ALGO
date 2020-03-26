import java.util.Scanner;


public class CheckPrime {
	
	public static boolean isPrime(int n) {
//		System.out.println(number);
		
		int divisor = 2;
		while(divisor < n) {
			if(n % divisor == 0) {
				return false;
//				System.out.println("Not prime");
//				return;
//				break;
			}
			divisor = divisor + 1;
		}
		if(divisor == n) {
			System.out.println("Prime");
		}
		
		return true;
	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter a number : ");
		int number = s.nextInt();
		
		boolean ans = isPrime(number);
		System.out.println(ans);
//		System.out.println(divisor);
	}
}
