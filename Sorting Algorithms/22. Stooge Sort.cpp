// The Stooge sort is a recursive sorting algorithm. It is defined as below (for ascending order sorting).

// Step 1 : If value at index 0 is greater than
//          value at last index, swap them.
// Step 2:  Recursively, 
//        a) Stooge sort the initial 2/3rd of the array.
//        b) Stooge sort the last 2/3rd of the array.
//        c) Stooge sort the initial 2/3rd again to confirm.
// NOTE: Always take the ceil of ((2/3)*N) for selecting elements.

// Illustration:

// Input :   2 4 5 3 1
// Output : 1 2 3 4 5
// Explanation:
// Initially, swap 2 and 1 following above step 1.
//           1 4 5 3 2
//           Now, recursively sort initial 2/3rd of the elements.
//           1 4 5 3 2
//           1 3 4 5 2 
//           Then, recursively sort last 2/3rd of the elements.
//           1 3 4 5 2
//           1 2 3 4 5
//           Again, sort the initial 2/3rd of the elements to confirm final data is sorted.
//           1 2 3 4 5


#include <iostream> 
using namespace std; 
  
// Function to implement stooge sort 
void stoogesort(int arr[], int l, int h) 
{ 
    if (l >= h) 
        return; 
  
    // If first element is smaller than last, 
    // swap them 
    if (arr[l] > arr[h]) 
        swap(arr[l], arr[h]); 
  
    // If there are more than 2 elements in 
    // the array 
    if (h - l + 1 > 2) { 
        int t = (h - l + 1) / 3; 
  
        // Recursively sort first 2/3 elements 
        stoogesort(arr, l, h - t); 
  
        // Recursively sort last 2/3 elements 
        stoogesort(arr, l + t, h); 
  
        // Recursively sort first 2/3 elements 
        // again to confirm 
        stoogesort(arr, l, h - t); 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int arr[] = { 2, 4, 5, 3, 1 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Calling Stooge Sort function to sort 
    // the array 
    stoogesort(arr, 0, n - 1); 
  
    // Display the sorted array 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
  
    return 0; 
} 

// Output:
// 1 2 3 4 5

// The running time complexity of stooge sort can be written as,
// T(n) = 3T(3n/2) + ?(1)
// Solution of above recurrence is O(n(log3/log1.5)) = O(n2.709), hence it is slower than even bubble sort(n^2).