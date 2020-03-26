import java.util.Scanner;


public class CheckPrime {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter a number : ");
		int number = s.nextInt();
		int divisor = 2;
		while(divisor < number) {
			if(number % divisor == 0) {
				System.out.println("Not prime");
//				return;
				break;
			}
			divisor = divisor + 1;
		}
		if(divisor == number) {
			System.out.println("Prime");
		}

	}
}
