#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bool isValid(ll arr[],ll n, ll mid, ll c){
	ll count=1;
	ll start=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]-start>=mid){
			count++;
			if(count==c)
				return true;
			start=arr[i];
		}
		else{
		}
	}
	if(count<c){
		return false;
	}
	else{
		return true;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	ll i,j,k,len,n,sum,count;
	string str;
	ll t;
	ll c;

	cin >> n >> c;

	ll arr[n];
	ll low,high;
	for(i=0;i<n;i++){
		cin >> arr[i];
	}
	sort(arr,arr+n);

	low = 1;
	high = arr[n-1]-arr[0];
	ll ans=0;
	while(low<=high){
		ll mid=(low+high)/2;
		if(isValid(arr,n,mid,c)){ // isValid() will check if we can place cows atleast at a distance mid from each other
			ans=mid;
			low = mid+1;
		}else{
			high = mid-1;
		}
	}
	cout << ans << endl;


	return 0;
}
