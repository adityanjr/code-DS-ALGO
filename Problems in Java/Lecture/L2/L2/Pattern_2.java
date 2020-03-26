import java.util.Scanner;


public class Pattern_2 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of rows : ");
		int n = s.nextInt();
		int currentRow = 1;
		while(currentRow <= n) {
			int spaces = 1;
			while(spaces <= n - currentRow) {
				System.out.print(" ");
				spaces = spaces + 1;
			}
			int value = currentRow;
			while(value <= 2*currentRow-1) {
				System.out.print(value);
				value = value + 1;
			}
			value = 2*currentRow - 2;
			while(value >= currentRow) {
				System.out.print(value);
				value = value - 1;
			}
			System.out.println();
			currentRow = currentRow + 1;
		}
	}

}
