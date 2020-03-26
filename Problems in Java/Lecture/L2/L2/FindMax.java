import java.util.Scanner;

public class FindMax {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		System.out.println("Enter 3 numbers : ");
		int a = s.nextInt();
		int b = s.nextInt();
		int c = s.nextInt();

		if(a >= b && a >= c) {
			System.out.println(a);
//			return;
		}
		else if(b >= c && b >= a) {
			System.out.println(b);
//			return;
		}
		else 
			System.out.println(c);
		
	}
}
