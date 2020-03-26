package L3;

import java.util.Scanner;

public class Arrays {
	
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

	public static int findLargest(int[] a) {
		int large = Integer.MIN_VALUE;
		for(int i = 0; i < a.length; i++) {
			if(a[i] > large) {
				large = a[i];
			}
		}
		return large;
	}
	
	public static void printArray(int[] a) {
		for(int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}
	
	public static int findSum(int[] a) {
		int sum = 0;
		for(int i = 0; i < a.length; i++) {
			sum = sum + a[i];
		}
		return sum;
	}
	
	
	public static void increment(int[] a, int n) {
		a[0] = a[0] + 1;
		n = n + 1;
	}
	
	public static void main(String[] args) {
		int[] input = {1,2,3,4};
		int n = 10;
		for(int i = 0; i < input.length; i++) {
			System.out.println(input[i]);
		}
		System.out.println("n = " + n);
		
		System.out.println("After function calling : ");
		increment(input, n);
		for(int i = 0; i < input.length; i++) {
			System.out.println(input[i]);
		}
		System.out.println("n = " + n);
		
		
		
//		printArray(input);
		
//		int sum = findSum(input);
//		System.out.println(sum);
		
	}

}
