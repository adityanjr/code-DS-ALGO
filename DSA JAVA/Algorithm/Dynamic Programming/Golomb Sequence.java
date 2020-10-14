// Java Program to find first  
// n terms of Golomb sequence. 
import java.util.*; 
  
class Golomb 
{ 
      
    public static void printGolomb(int n) 
    { 
        int dp[] = new int[n + 1]; 
      
        // base cases 
        dp[1] = 1; 
        System.out.print(dp[1] + " "); 
      
        // Finding and printing first n  
        // terms of Golomb Sequence. 
        for (int i = 2; i <= n; i++)  
        { 
            dp[i] = 1 + dp[i - dp[dp[i - 1]]]; 
              
        System.out.print(dp[i] + " "); 
        } 
    } 
          
    // Driver code 
    public static void main (String[] args) 
    { 
        int n = 9;  
          
        printGolomb(n); 
    } 
} 