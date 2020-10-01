import java.util.Arrays;
public class TripletSum {	

	public static void FindTriplet(int[] arr, int x){
		/* Your class should be named TripletSum.
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Print output and don't return it.
		 * Taking input is handled automatically.
		 */
             // int l, r; 
        Arrays.sort(arr);
       
        for (int i = 0; i < arr.length - 2; i++) { 
  
            
            for (int j = i + 1; j < arr.length- 1; j++) { 
  
               
                for (int k = j + 1; k < arr.length; k++) { 
                    if (arr[i] + arr[j] + arr[k] == x) { 
                        
                        System.out.println( arr[i] +" "+ arr[j] + " "+ arr[k]); 

                    } 
                } 
            } 
        } 
  
        // If we reach here, then no triplet was found 
        // return false; 
	}
}