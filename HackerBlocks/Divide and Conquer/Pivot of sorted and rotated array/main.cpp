#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll binarysearch(ll arr[], ll start, ll end){
    if(start<end){
        ll mid = start + (end-start)/2;
        if(arr[mid]<arr[mid-1] && mid>start)
            return mid-1;
        if(arr[mid]>arr[mid+1] && mid<end){
            return mid;
        }
        if(arr[mid]<=arr[start])
            return binarysearch(arr,start,mid-1);
        else
            return binarysearch(arr,mid+1,end);
    }
}
int main() {
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    cout<<binarysearch(arr,0,n-1)<<endl;

	return 0;
}
