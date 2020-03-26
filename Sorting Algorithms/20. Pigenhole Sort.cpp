// Pigeonhole sorting is a sorting algorithm that is suitable for sorting lists of elements 
// where the number of elements and the number of possible key values are approximately the same.
// It requires O(n + Range) time where n is number of elements in input array and ‘Range’ is number of possible values in array.

// Working of Algorithm :

// Find minimum and maximum values in array. Let the minimum and maximum values be ‘min’ and ‘max’ respectively. Also find range as ‘max-min-1’.
// Set up an array of initially empty “pigeonholes” the same size as of the range.
// Visit each element of the array and then put each element in its pigeonhole. An element arr[i] is put in hole at index arr[i] – min.
// Start the loop all over the pigeonhole array in order and put the elements from non- empty holes back into the original array.
// Comparison with Counting Sort :
// It is similar to counting sort, but differs in that it “moves items twice: once to the bucket array and again to the final destination “.


#include <bits/stdc++.h> 
using namespace std; 
  
/* Sorts the array using pigeonhole algorithm */
void pigeonholeSort(int arr[], int n) 
{ 
    // Find minimum and maximum values in arr[] 
    int min = arr[0], max = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < min) 
            min = arr[i]; 
        if (arr[i] > max) 
            max = arr[i]; 
    } 
    int range = max - min + 1; // Find range 
  
    // Create an array of vectors. Size of array 
    // range. Each vector represents a hole that 
    // is going to contain matching elements. 
    vector<int> holes[range]; 
  
    // Traverse through input array and put every 
    // element in its respective hole 
    for (int i = 0; i < n; i++) 
        holes[arr[i]-min].push_back(arr[i]); 
  
    // Traverse through all holes one by one. For 
    // every hole, take its elements and put in 
    // array. 
    int index = 0;  // index in sorted array 
    for (int i = 0; i < range; i++) 
    { 
       vector<int>::iterator it; 
       for (it = holes[i].begin(); it != holes[i].end(); ++it) 
            arr[index++]  = *it; 
    } 
} 
  
// Driver program to test the above function 
int main() 
{ 
    int arr[] = {8, 3, 2, 7, 4, 6, 8}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    pigeonholeSort(arr, n); 
  
    printf("Sorted order is : "); 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
  
    return 0; 
} 

// Output:
// Sorted order is : 2 3 4 6 7 8 8 

// Pigeonhole sort has limited use as requirements are rarely met. 
// For arrays where range is much larger than n, bucket sort is a generalization that is more efficient in space and time.