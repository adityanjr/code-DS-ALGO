// ##Cocktail Shaker Sort
// Cocktail shaker sort, also known as bidirectional bubble sort, cocktail sort, 
// shaker sort (which can also refer to a variant of selection sort), ripple sort, 
// shuffle sort, or shuttle sort, is a variation of bubble sort that is both a stable 
// sorting algorithm and a comparison sort. The algorithm differs from a bubble sort in 
// that it sorts in both directions on each pass through the list. This sorting algorithm is only 
// marginally more difficult to implement than a bubble sort, and solves the problem of 
// turtles in bubble sorts. It provides only marginal performance improvements, and does not improve 
// asymptotic performance; like the bubble sort, it is not of practical interest (insertion sort is preferred for simple sorts), 
// though it finds some use in education.</p>

// src="https://upload.wikimedia.org/wikipedia/commons/e/ef/Sorting_shaker_sort_anim.gif"
// href="https://en.wikipedia.org/wiki/Bubble_sort" Source --> Wikipedia

#include <bits/stdc++.h> 
using namespace std; 
  
// Sorts arrar a[0..n-1] using Cocktail sort 
void CocktailSort(int a[], int n) 
{ 
    bool swapped = true; 
    int start = 0; 
    int end = n - 1; 
  
    while (swapped) { 
        // reset the swapped flag on entering 
        // the loop, because it might be true from 
        // a previous iteration. 
        swapped = false; 
  
        // loop from left to right same as 
        // the bubble sort 
        for (int i = start; i < end; ++i) { 
            if (a[i] > a[i + 1]) { 
                swap(a[i], a[i + 1]); 
                swapped = true; 
            } 
        } 
  
        // if nothing moved, then array is sorted. 
        if (!swapped) 
            break; 
  
        // otherwise, reset the swapped flag so that it 
        // can be used in the next stage 
        swapped = false; 
  
        // move the end point back by one, because 
        // item at the end is in its rightful spot 
        --end; 
  
        // from right to left, doing the 
        // same comparison as in the previous stage 
        for (int i = end - 1; i >= start; --i) { 
            if (a[i] > a[i + 1]) { 
                swap(a[i], a[i + 1]); 
                swapped = true; 
            } 
        } 
  
        // increase the starting point, because 
        // the last stage would have moved the next 
        // smallest number to its rightful spot. 
        ++start; 
    } 
} 
  
/* Prints the array */
void printArray(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", a[i]); 
    printf("\n"); 
} 
  
// Driver code 
int main() 
{ 
    int arr[] = { 5, 1, 4, 2, 8, 0, 2 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    CocktailSort(a, n); 
    printf("Sorted array :\n"); 
    printArray(a, n); 
    return 0; 
} 

// Output:
// Sorted array is:
// 0 1 2 2 4 5 8

// Worst and Average Case Time Complexity: O(n*n).
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

// Auxiliary Space: O(1)

// Sorting In Place: Yes

// Stable: Yes

// Comparison with Bubble Sort:
// Time complexities are same, but Cocktail performs better than Bubble Sort. Typically cocktail sort is 
// less than two times faster than bubble sort. Consider the example (2, 3, 4, 5, 1). Bubble sort requires 
// four traversals of array for this example, while Cocktail sort requires only two traversals.