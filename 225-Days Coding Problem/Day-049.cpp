/*

   This problem was asked by Amazon.

   Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

   For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

   Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

   Do this in O(N) time.

 */
#include <bits/stdc++.h>
using namespace std;
int getMaxSum(vector<int> & arr){
    int max_sum{} , temp_sum{};
    for(auto&itr:arr){
        temp_sum+=itr;
        if(temp_sum>0){
            max_sum = max(temp_sum , max_sum);
        }else{
            temp_sum = 0;
        }
    }
    return max_sum;
}
int main(void){

    vector<int> arr1 = { 34, -50, 42, 14, -5, 86 };
    vector<int> arr2 = { -5, -1, -8, -9 };
    cout<< getMaxSum(arr1) << '\n';
    cout<< getMaxSum(arr2) << '\n';
    return 0;
}
