// A hashing based Java program to find missing 
// elements from an array 
  
import java.util.Arrays; 
import java.util.HashSet; 
  
public class Print { 
    // Print all elements of range [low, high] that 
    // are not present in arr[0..n-1] 
    static void printMissing(int ar[], int low, int high) 
    { 
        HashSet<Integer> hs = new HashSet<>(); 
  
        // Insert all elements of arr[] in set 
        for (int i = 0; i < ar.length; i++) 
            hs.add(ar[i]); 
  
        // Traverse throught the range an print all 
        // missing elements 
        for (int i = low; i <= high; i++) { 
            if (!hs.contains(i)) { 
                System.out.print(i + " "); 
            } 
        } 
    } 
  
    // Driver program to test above function 
    public static void main(String[] args) 
    { 
        int arr[] = { 1, 3, 5, 4 }; 
        int low = 1, high = 10; 
        printMissing(arr, low, high); 
    } 
} 