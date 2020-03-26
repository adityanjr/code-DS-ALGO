#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bool isValid(ll arr[],ll n,ll mid, ll k){
	ll count = 1;
	ll sum=0;
	for(ll i=0;i<n;i++){
		if(arr[i]+sum>mid){
			count++;
			if(count>k){
				return false;
			}
			sum = arr[i];
		}else{
			sum+=arr[i];
		}
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	ll i,j,k,len,n,sum,count;
	string str;
	ll t;

	cin >> k;

	cin >> n;

	ll arr[n];
	ll low = 0;
	ll high =0;
	for(i=0;i<n;i++){
		cin >> arr[i];
		high+=arr[i];
		low=max(low,arr[i]);
	}

	ll ans = 0;
	while(low<=high){
		ll mid = low+(high-low)/2;

		if(isValid(arr,n,mid,k)){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}

	}

	cout << ans << endl;


	return 0;
}
