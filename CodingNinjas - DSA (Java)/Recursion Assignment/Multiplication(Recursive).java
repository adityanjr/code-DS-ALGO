
public class solution {

	public static int multiplyTwoIntegers(int x, int y){
		// Write your code here
         if (y == 0) 
            return 0; 
      
        /* Add x one by one */
        if (y > 0) 
            return (x + multiplyTwoIntegers(x, y - 1)); 
      
        /* the case where y is negative */
        if (y < 0) 
            return -multiplyTwoIntegers(x, -y); 
              
        return -1; 
	}
}
