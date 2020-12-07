import java.util.Arrays;
public class PairSum{	

	public static void pairSum(int[] arr, int num){
		/* Your class should be named PairSum
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Print output and don't return it.
	 	 * Taking input is handled automatically.
		 */
        Arrays.sort(arr);
		int start = 0;
		int end = arr.length-1;
		while(start < end) {
			if(arr[start] + arr[end] == num) {
				if(arr[start] == arr[end]) {
					int count = end - start + 1;
					int n = count - 1;
					int totalCount = ((n) * (n + 1)) / 2;
					while(totalCount > 0) {
						System.out.println(arr[start] + " " + arr[end]);
						totalCount--;
					}
					start = end;
				}
				else {
					int countStart = 0, countEnd = 0;
					int temp = arr[start], i = start;
					while(arr[i] == temp && i < end){
						i++;
						countStart++;
					}
					temp = arr[end];
					int j = end;
					while(arr[j] == temp && j > start){
						j--;
						countEnd++;
					}
					start = i;
					end = j;
					int totalTimes = countStart * countEnd;
					while(totalTimes > 0) {
						System.out.println(arr[start-1] + " " + arr[end+1]);
						totalTimes--;
					}
				}
			}
			else if(arr[start] + arr[end] < num)
				start++;
			else
				end--;
		}
        
	}
}