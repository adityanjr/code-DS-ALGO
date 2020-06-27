/*

 This problem was asked by Google.

 We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.

 Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

 You may assume each element in the array is distinct.

 For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). 
 
 The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion. 
  
  
 */
#include <bits/stdc++.h>
using namespace std;
int inv_counter{};
void merge(vector<int>&v, int start , int end){
    vector<int>temp(v.size(),0);
    int mid = (start+end)/2;
    int i{start} , j{(start+end)/2+1} ,k{};
    while(i<=mid && j<=end){
        if(v[i]>v[j]){
            inv_counter+=(mid-i+1);
            temp[k++]=v[j++];
        }else{
            temp[k++]=v[i++];
        }
    }
    while(i<=mid){
        temp[k++] = v[i++];
    }
    while(j<=end){
        temp[k++] = v[j++];
    }
    k = 0;
    for(int i{start};i<=end;++i){
        v[i] = temp[k++];
    }
}
void count_inversion(vector<int>&v , int start , int end){
    if(start>=end){
        return;
    }
    int mid{(start+end)/2};
    count_inversion(v,start,mid);
    count_inversion(v,mid+1,end);
    merge(v,start,end);
}
int main(int argc , char *argv[]){
    // write you code here
    vector<int>v{2,4,1,3,5};
    count_inversion(v,0,4);
    cout<<inv_counter<<'\n';
    v.clear();
    inv_counter = 0;
    v = {5,4,3,2,1};
    count_inversion(v,0,4);
    cout<<inv_counter<<'\n';
    return 0;
}
