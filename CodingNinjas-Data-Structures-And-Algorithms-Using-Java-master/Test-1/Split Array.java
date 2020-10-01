
public class solution {
    static boolean helper(int arr[], int n, int start, int lsum, int rsum) 
{ 
  
    // If reached the end 
    if (start == n) 
        return lsum == rsum; 
  
    // If divisible by 5 then add to the left sum 
    if (arr[start] % 5 == 0) 
        lsum += arr[start]; 
  
    // If divisible by 3 but not by 5 
    // then add to the right sum 
    else if (arr[start] % 3 == 0) 
        rsum += arr[start]; 
  
    // Else it can be added to any of the sub-arrays 
    else
  
        // Try adding in both the sub-arrays (one by one) 
        // and check whether the condition satisfies 
        return helper(arr, n, start + 1, lsum + arr[start], rsum) || helper(arr, n, start + 1, lsum, rsum + arr[start]); 
  
    // For cases when element is multiple of 3 or 5. 
    return helper(arr, n, start + 1, lsum, rsum); 
} 

	public static boolean splitArray(int arr[]) {
		/* Your class should be named solution
		* Don't write main().
		* Don't read input, it is passed as function argument.
		* Return output and don't print it.
		* Taking input and printing output is handled automatically.
		*/
        int n=arr.length;
        return helper(arr, n, 0, 0, 0);
		
	}
	

}
