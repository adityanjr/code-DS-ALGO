/*
 *
 * This problem was asked by Google.

    Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

    For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

    10 = max(10, 5, 2)
    7 = max(5, 2, 7)
    8 = max(2, 7, 8)
    8 = max(7, 8, 7)

    Do this in O(n) time and O(k) space. 

    You can modify the input array in-place and you do not need to store the results. 

    You can simply print them out as you compute them.

 */
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;// size of array
    cin>>n;
    vector<int>v(n);
    for(auto &itr:v){
        cin>>itr;
    }
    int k; // window size
    cin>>k;
    int i=0;
    deque<int>q;
    for(i=0;i<k;++i){
        if(!q.empty() && v.at(q.back())<v.at(i)){
            q.pop_back();
        }
        q.push_back(i);
    }
    for(;i<n;++i){
        cout<<v.at(q.front())<<' ';
        // remove the out of range elements
        while(!q.empty() && q.front()<=i-k){
            q.pop_front();
        }
        // remove the element not needed from this window
        while(!q.empty() && v.at(q.back())<v.at(i)){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<v.at(q.front())<<endl;
}
