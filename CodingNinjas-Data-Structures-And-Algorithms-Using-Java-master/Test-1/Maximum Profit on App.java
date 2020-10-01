import java.util.Arrays;
import java.lang.*;
public class solution {

	public static int maximumProfit(int budget[]) {
		// Write your code here
        int ans =Integer.MIN_VALUE;
        int n=budget.length;
        Arrays.sort(budget);
        for(int i=0;i<n;i++){
        	ans=Math.max(ans,budget[i]*(n-i));
        }
        return ans;

	}
    

}


