#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll binarysearch(ll arr[], ll start, ll end, ll search){
	if(start<=end){
		ll mid = start + (end-start)/2;
		if(arr[mid]==search)
		   return mid;

		if(arr[mid]<=arr[end]){
			if(search>arr[mid] && search<=arr[end])
			  return binarysearch(arr,mid+1,end,search);
			else
			  return binarysearch(arr,start,mid-1,search);
		}

		else{
			if(search<arr[mid] && search>=arr[start])
			  return binarysearch(arr,start,mid-1,search);
			else
			  return binarysearch(arr,mid+1,end,search);
		}
	}
}
int main() {
    ll n;
	ll search;
	cin>>n;
    ll arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>search;
	cout<<binarysearch(arr,0,n-1,search);
	return 0;
}
