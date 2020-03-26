package L7;

public class Sort012 {

	public static void sort(int[] a) {
		if(a.length <= 1) {
			return;
		}
		int i = 0, nextZero = 0, nextTwo = a.length-1;
		while(i <= nextTwo) {
			if(a[i] == 0) {
				int temp = a[i];
				a[i] = a[nextZero];
				a[nextZero] = temp;
				i++;
				nextZero++;
			}
			else if(a[i] == 2) {
				int temp = a[i];
				a[i] = a[nextTwo];
				a[nextTwo] = temp;
				nextTwo--;
			}
			else {
				i++;
			}
		}
		
	}
	
	public static void main(String[] args) {
		int a[] = {0,1,1,0,1,2,1,2,0,0,0,1};
		sort(a);
		for(int i : a) {
			System.out.println(i);
		}
	}

}
