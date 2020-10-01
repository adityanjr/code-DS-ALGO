public class Solution {  

    public static void rotate(int[] arr, int d) {
        //Your code goes here
        int temp=0;
      	int j=0;
      	for(int i=0;i<d;i++){
          temp=arr[0];
          for(j=0;j<arr.length-1;j++){
            arr[j]=arr[j+1];
          }
          arr[j]=temp;
        }	
        
    }
}