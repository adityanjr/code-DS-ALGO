// http://www.geeksforgeeks.org/find-index-0-replaced-1-get-longest-continuous-sequence-1s-binary-array/
/*NOT understooo*/

#include <iostream>
#include "array.h"

int maxOnesIndex(bool *arr, int n){
	int max_count = 0;  // for maximum number of 1 around a zero
    int max_index;  // for storing result
    int prev_zero = -1;  // index of previous zero
    int prev_prev_zero = -1; // index of previous to previous zero
 
    // Traverse the input array
    for (int curr=0; curr<n; ++curr)
    {
        // If current element is 0, then calculate the difference
        // between curr and prev_prev_zero
        if (arr[curr] == 0)
        {
            // Update result if count of 1s around prev_zero is more
            if (curr - prev_prev_zero > max_count)
            {
                max_count = curr - prev_prev_zero;
                max_index = prev_zero;
            }
 
            // Update for next iteration
            prev_prev_zero = prev_zero;
            prev_zero = curr;
        }
    }
 
    // Check for the last encountered zero
    if (n-prev_prev_zero > max_count)
       max_index = prev_zero;
 
    return max_index;
}

int main(){
	bool arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of 0 to be replaced is "<< maxOnesIndex(arr, n);
	return 0;
}

