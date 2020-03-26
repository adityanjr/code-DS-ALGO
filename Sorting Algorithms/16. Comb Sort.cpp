// ##Comb Sort

// Comb sort is a relatively simple sorting algorithm originally designed by Włodzimierz Dobosiewicz in 1980. 
// Later it was rediscovered by Stephen Lacey and Richard Box in 1991. Comb sort improves on bubble sort.

// Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares adjacent values. 
// So all inversions are removed one by one. Comb Sort improves on Bubble Sort by using gap of size more than 1. 
// The gap starts with a large value and shrinks by a factor of 1.3 in every iteration until it reaches the value 1. 
// Thus Comb Sort removes more than one inversion counts with one swap and performs better than Bubble Sort.

// The shrink factor has been empirically found to be 1.3 (by testing Combsort on over 200,000 random lists)

// Although, it works better than Bubble Sort on average, worst case remains O(n2).

// href="https://en.wikipedia.org/wiki/Comb_sort" Source --> Wikipedia


#include<bits/stdc++.h> 
using namespace std; 
  
// To find gap between elements 
int getNextGap(int gap) 
{ 
    // Shrink gap by Shrink factor 
    gap = (gap*10)/13; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 
  
// Function to sort a[0..n-1] using Comb Sort 
void combSort(int a[], int n) 
{ 
    // Initialize gap 
    int gap = n; 
  
    // Initialize swapped as true to make sure that 
    // loop runs 
    bool swapped = true; 
  
    // Keep running while gap is more than 1 and last 
    // iteration caused a swap 
    while (gap != 1 || swapped == true) 
    { 
        // Find next gap 
        gap = getNextGap(gap); 
  
        // Initialize swapped as false so that we can 
        // check if swap happened or not 
        swapped = false; 
  
        // Compare all elements with current gap 
        for (int i=0; i<n-gap; i++) 
        { 
            if (a[i] > a[i+gap]) 
            { 
                swap(a[i], a[i+gap]); 
                swapped = true; 
            } 
        } 
    } 
} 
  
// Driver program 
int main() 
{ 
    int a[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    combSort(a, n); 
  
    printf("Sorted array: \n"); 
    for (int i=0; i<n; i++) 
        printf("%d ", a[i]); 
  
    return 0; 
} 