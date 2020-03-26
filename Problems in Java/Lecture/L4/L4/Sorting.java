package L4;

public class Sorting {

	public static void bubbleSort(int[] a) {
		for(int j = 0; j < a.length; j++) {
			for(int i = 0; i < a.length-1-j; i++) {
				if(a[i] > a[i+1]) {
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
			}
		}
	}

	public static void main(String[] args) {
		int a[] = {5,4,3,2,1};
		bubbleSort(a);
		for(int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}

}
