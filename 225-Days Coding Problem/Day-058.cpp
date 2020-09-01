/*
   This problem was asked by Amazon.

   An sorted array of integers was rotated an unknown number of times.

   Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

   For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

   You can assume all the integers in the array are unique.
 */


/*
 *   LeetCode Problem : 33 , Search in Rotated Sorted Array
 *   
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& arr, int target) {
        if(!arr.size())
            return -1; // consider -1 as NULL here 
        auto get = [&](int start , int end)->int{
            int mid ; 
            if(arr[start] == target){
                return start;
            }else if(arr[end] == target){
                return end;
            }
            while(start<=end){
                mid = (start+end)/2;
                if(arr[mid] == target){
                    return mid;
                }
                if(arr[start] <= arr[mid]){ // we assumed that this is sorted
                    if(target>=arr[start] and target<=arr[mid]){
                        end = mid-1;
                    }else{
                        start = mid+1;
                    }
                }else if(arr[mid]<=target and target<=arr[end]){ // we now assume that [mid , end] portion is sorted and target value is there 
                    start = mid+1;
                }else{ // [start , mid] is not sorted and if [start , mid] isn't sorted than we claim that [mid+1 , end] will be sorted and if target isn't present there , now we will look for the target in unsorted portion 
                    end = mid-1;
                }
            }
            return -1;

        };
        return get(0 , arr.size()-1);
    }
};

int main(void){
    Solution s1;
    vector<int>v = {4,5,6,7,0,1,2};
    int target = 0;
    assert(s1.search(v , target) == 4);
    return 0;
}
