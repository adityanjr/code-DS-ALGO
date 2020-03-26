package L4;

import java.util.Scanner;

public class ReverseArray {

	public static int[] takeInput() {
		Scanner s = new Scanner(System.in);
		System.out.println("Enter size of array : ");
		int size = s.nextInt();
		int array[] = new int[size];
		for(int i = 0; i < size; i++) {
			System.out.println("Enter " + i + "th value : ");
			array[i] = s.nextInt();
		}
		return array;
	}
	
	public static void reverse(int[] input) {
		int i = 0, j = input.length-1;
		while(i <= j) {
			int temp = input[i];
			input[i] = input[j];
			input[j] = temp;
			i++;
			j--;
		}
	}
	
	public static void main(String[] args) {
		int[] a = takeInput();
		reverse(a);
		for(int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}

}
