import java.util.Scanner;

public class Pattern_1 {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter number of rows : ");
		int totalRows = s.nextInt();
		int currentRow = 1;
		int value = 1;
		while(currentRow <= totalRows) {
			int currentCol = 1;
			while(currentCol <= currentRow) {
				System.out.print(value);
				value = value + 1;
				currentCol = currentCol + 1;
			}
			currentRow = currentRow + 1;
			System.out.println();
		}
	}

}
