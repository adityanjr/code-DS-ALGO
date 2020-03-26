package L7;

public class Recursion_2 {

	public static int lastIndex(int[] a, int si) {
		if(si >= a.length) {
			return -1;
		}
		int out = lastIndex(a, si+1);
		if(out != -1) {
			return out;
		}
		if(a[si] == 7) {
			return si;
		}
		else {
			return -1;
		}
	}
	
	public static String replacePi(String s) {
		if(s.length() <= 1) {
			return s;
		}
		String ans = replacePi(s.substring(1));
		
		if(s.charAt(0) == 'p' && s.charAt(1) == 'i') {
			return "3.14" + ans.substring(1);
		}
		else {
			return s.charAt(0) + ans;
		}
		
	}
	
	public static void bubbleSortRec(int a[], int lastIndex) {
		if(lastIndex <= 0) {
			return;
		}
		for(int i = 0; i < lastIndex; i++) {
			if(a[i] > a[i+1]) {
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
			}
		}
		bubbleSortRec(a, lastIndex-1);
	}

	public static int[] mergeSort(int a[]) {
		if(a.length <= 1) {
			return a;
		}
		
		int half1[] = new int[a.length/2];
		int half2[] = new int[a.length - half1.length];
		int k = 0;
		for(int i = 0; i < half1.length; i++) {
			half1[k] = a[i];
			k++;
		}
		k = 0;
		for(int i = half1.length; i < a.length; i++) {
			half2[k] = a[i];
			k++;
		}
		
		half1 = mergeSort(half1);
		half2 = mergeSort(half2);
		
		a = mergeTwoSortedArrays(half1, half2);
		return a;
		
	}

	// Incomplete
	public static int[] mergeTwoSortedArrays(int[] half1, int[] half2) {
		
		
		return null;
	}
	
	public static void main(String[] args) {
//		int a[] = {2,7,5,6,7,9,7};
//		System.out.println(lastIndex(a, 0));
		
//		System.out.println(replacePi("xpipix"));
		
		int a[] = {5,4,3,2,1};
		bubbleSortRec(a, a.length-1);
		for(int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}
	
}
