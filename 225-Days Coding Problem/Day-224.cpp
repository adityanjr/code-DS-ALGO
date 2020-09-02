/*
 * This problem was asked by Amazon.  
 * Given a sorted array, find the smallest positive integer that is not the sum of a subset of the array.
 * For example, for the input [1, 2, 3, 10], you should return 7.
 * Do this in O(N) time.
 *
 *
 *  ping me if you find any error : offamitkumar@gmail.com
 */

#include <bits/stdc++.h>
using std::cin;
using std::endl;
using std::cout;
using std::vector;
auto get_Solution(vector<int>&arr)->int{
    int ans = 1; // minimum answer possible 
    // idea is to check whether we can form a answer of prefix_sum[i] + 1  ,, or not 
    for(int i=0;i<static_cast<int>(arr.size());++i){
        if(ans>=arr[i]){
            ans+=arr[i]; // because we can make a sum of 1 to (ans-1) by using the array form 0 to i 
        }else{
            break;
        }
    }
    return ans;
}
int main(int argc , char *argv[]){
    int n;
    cin>>n;//array size
    vector<int>arr(n,0);
    for(auto &itr:arr)
        cin>>itr;
    cout<<get_Solution(arr)<<endl;
    return 0;
}
