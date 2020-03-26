package L10;

public class QuickSort {

	public static void quickSort(int a[], int startIndex, int endIndex) {
		if(startIndex >= endIndex) {
			return;
		}
		int pivotIndex = partitionArray(a, startIndex, endIndex);
		quickSort(a, startIndex, pivotIndex-1);
		quickSort(a, pivotIndex+1, endIndex);
	}

	public static int partitionArray(int[] a, int startIndex, int endIndex) {
		int pivot = a[startIndex];
		int count = 0;
		for(int i = startIndex+1; i <= endIndex; i++) {
			if(a[i] <= pivot) {
				count++;
			}
		}
		int pivotIndex = startIndex + count;
		a[startIndex] = a[pivotIndex];
		a[pivotIndex] = pivot;

		// Rearrange
		int i = startIndex, j = endIndex;
		while(i < j) {
			while(i <= endIndex && a[i] <= pivot) {
				i++;
			}
			while(j >= 0 && a[j] > pivot) {
				j--;
			}
			if(i <= j) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
				j--;
			}
		}

		return pivotIndex;
	}

	public static void main(String[] args) {
		int a[] = {4, 3, 2, 6, 9, 6, 12};
		quickSort(a, 0, a.length-1);
		for(int i = 0; i < a.length; i++) {
			System.out.println(a[i]);
		}
	}
}
