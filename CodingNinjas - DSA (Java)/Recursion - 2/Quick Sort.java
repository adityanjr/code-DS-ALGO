/* 
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 


*/


public class Solution {
    public static int sort(int[] input,int start,int end)
    {
        int pivot=input[start];
        int idx=start+1;
        for(int i=start+1;i<=end;i++)
        {
            if(input[i]<=pivot)
            {
                int temp=input[idx];
                input[idx]=input[i];
                input[i]=temp;
                idx++;
            }
        }
        int temp=input[start];
        input[start]=input[idx-1];
        input[idx-1]=temp;
        return idx-1;
    }
    public static void partition(int[] input,int start,int end)
    {
        if(start>=end)
            return;
        int idx=sort(input,start,end);
        partition(input,start,idx-1);
        partition(input,idx+1,end);
        // i=1 
        //     5<7?
        //     idx=2 i=2
        //     6 5
        }
    public static void quickSort(int[] input) {
        /* Your class should be named Solution
		 * Don't write main().
		 * Don't read input, it is passed as function argument.
		 * No need to print or return the output.
		 * Taking input and printing output is handled automatically.
		 */
        // 7 5  4 9 1 3 6 1  pivot=7 idx=0 i=1 5<7? 5 5 4 9 1 3 6 1 idx=1;
        // 5 4 1 3 6 1 7  9

        partition(input,0,input.length-1);
    }

}