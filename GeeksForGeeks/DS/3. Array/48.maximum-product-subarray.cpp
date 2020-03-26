// http://www.geeksforgeeks.org/maximum-product-subarray/

#include <iostream>
#include <cstdio>
using namespace std;

int maxSubarrayProduct(int *arr, int n){
    int min_prod=1, max_ending=1, max_so_far = 1;
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            max_ending = max_ending*arr[i];
            min_prod = min(min_prod*arr[i], 1);
        }
        else if(arr[i] == 0){
            max_ending = 1;
            min_prod = 1;
        }
        else {
            int tmp = max_ending;
            max_ending = max(min_prod*arr[i], 1);
            min_prod = tmp*arr[i];
        }
        if(max_so_far < max_ending)
            max_so_far = max_ending;
    }
    return max_so_far;
}

// All case covered
int maxProduct(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int max_overall = INT_MIN;
    int max_here = A[0];
    int min_here = A[0];
    if(n == 1){
        return A[0];
    }
    for(int i=1; i<n; i++){
        int maxProd = A[i]*max_here;
        int minProd = A[i]*min_here;
        max_here = max(A[i], max(maxProd, minProd));
        min_here = min(A[i], min(maxProd, minProd));
        max_overall = max(max_here, max_overall);
    }
    return max_overall;
}

int main(){
	int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Sub array product is %d", maxSubarrayProduct(arr, n));
    getchar();
}
