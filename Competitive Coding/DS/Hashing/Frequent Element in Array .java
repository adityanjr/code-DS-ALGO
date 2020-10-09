
        //Java program to find the most frequent element 
//in an array 
import java.util.HashMap; 
import java.util.Map; 
import java.util.Map.Entry; 
  
class Frequent { 
      
    static int mostFrequent(int arr[], int n) 
    { 
          
        // Insert all elements in hash 
        Map<Integer, Integer> hp = 
               new HashMap<Integer, Integer>(); 
          
        for(int i = 0; i < n; i++) 
        { 
            int key = arr[i]; 
            if(hp.containsKey(key)) 
            { 
                int freq = hp.get(key); 
                freq++; 
                hp.put(key, freq); 
            } 
            else
            { 
                hp.put(key, 1); 
            } 
        } 
          
        // find max frequency. 
        int max_count = 0, res = -1; 
          
        for(Entry<Integer, Integer> val : hp.entrySet()) 
        { 
            if (max_count < val.getValue()) 
            { 
                res = val.getKey(); 
                max_count = val.getValue(); 
            } 
        } 
          
        return res; 
    } 
      
    // Driver code 
    public static void main (String[] args) { 
          
        int arr[] = {1, 5, 2, 1, 3, 2, 1}; 
        int n = arr.length; 
          
        System.out.println(mostFrequent(arr, n)); 
    } 
} 
  