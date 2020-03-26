package L4;

public class BinarySearch {

	public static int binarySeacrh(int[] a, int ele) {
		int start = 0;
		int end = a.length - 1;
		while(start <= end) {
			int mid = (start+end)/2;
			if(a[mid] == ele) {
				return mid;
			}
			if(a[mid] < ele) {
				start = mid+1;
			}
			else {
				end = mid-1;
			}
		}
		return -1;
	}
	
	public static void main(String[] args) {
		int a[] = {1,2,3,4,5,6,7};
		System.out.println(binarySeacrh(a, 3));
		
	}

}
