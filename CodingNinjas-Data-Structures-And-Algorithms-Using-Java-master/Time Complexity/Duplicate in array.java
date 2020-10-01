public class DuplicateInArray{	

	public static int duplicate(int[] arr){  
		/* Your class should be named DuplicateInArray
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * Return output and don't print it.
	 	 * Taking input and printing output is handled automatically.
		*/
       
        int count[] = new int[arr.length]; 
        int i; 
        int temp=0 ;
  
       // System.out.println("Repeated elements are : "); 
        for (i = 0; i < arr.length; i++)  
        { 
            if (count[arr[i]] == 1) 
               // System.out.print(arr[i] + " "); 
                temp=arr[i];
            else
                count[arr[i]]++; 
        } 
        return temp;
	}
}