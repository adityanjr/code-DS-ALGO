public class ArrayEquilibrium{	
	//arr is the given array in which you need to find the equilibrium index
	public static int arrayEquilibrium(int[] arr){  
		//write your code here
        int sum = 0; // initialize sum of whole array 
        int leftsum = 0; // initialize leftsum 
  
        /* Find sum of the whole array */
        for (int i = 0; i < arr.length; ++i) 
            sum += arr[i]; 
  
        for (int i = 0; i < arr.length; ++i) { 
            sum -= arr[i]; // sum is now right sum for index i 
  
            if (leftsum == sum) 
                return i; 
  
            leftsum += arr[i]; 
        } 
  
        return -1; 
       
        }
	}
