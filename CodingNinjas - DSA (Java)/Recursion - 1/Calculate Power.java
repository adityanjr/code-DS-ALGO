public class Solution {

    public static int power(int x, int n) {
        /* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
		 * Taking input and printing output is handled automatically.
		 */
        int temp; 
        if( n == 0) 
            return 1; 
        temp = power(x, n/2); 
        if (n%2 == 0) 
            return temp*temp; 
        else
            return x*temp*temp; 


    }
}