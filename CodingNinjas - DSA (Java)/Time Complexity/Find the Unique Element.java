public class FindUnique{	

	public static int findUnique(int[] arr){
		/* Your class should be named FindUnique
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		 */
      int result = 0;
    for(int i=0;i<arr.length;i++)
    {
        result ^= arr[i];
    }
                    
    return (result>0 ? result : -1);
	}
}