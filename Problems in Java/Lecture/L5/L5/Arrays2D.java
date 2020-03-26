package L5;

import java.util.Scanner;

public class Arrays2D {

	public static int[][] takeInput() {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter row : ");
		int row = s.nextInt();
		System.out.println("Enter col : ");
		int col = s.nextInt();
		int input[][] = new int[row][col];
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				System.out.println("Enter element of " + i + "th row and " + j + "th col : ");
				input[i][j] = s.nextInt();
			}
		}
		return input;
		
	}
	
	public static int[][] takeInput2() {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter row : ");
		int row = s.nextInt();
		int[][] input = new int[row][]; 
		
		for(int i = 0; i < row; i++) {
			System.out.println("Enter cols : ");
			int col = s.nextInt();
			input[i] = new int[col];
			for(int j = 0; j < col; j++) {
				System.out.println("Enter element of " + i + "th row and " + j + "th col : ");
				input[i][j] = s.nextInt();
			}
		}
		
		return input;
	}
	
	public static void print(int[][] a) {
		for(int i = 0; i < a.length; i++) {
			for(int j = 0; j < a[i].length; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	
	public static void main(String[] args) {
		/*int a[] = new int[10];
		int b[][] = new int[4][4];
		
		int c[] = {1,2,3,4};
		int d[][] = {{1,2,3}, {4,5,6}};
		int g = b[2][3];*/
		
		int[][] a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
		
		int input[][] = takeInput2();
		print(input);
		
//		System.out.println(input[0]);
	}

}
