#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bool isValid(ll arr[],ll l,ll mid,ll p){
	ll count=0;

	for(int i=0;i<l;i++){
		ll mul=1;
		ll sum=0;
		while(sum+(arr[i]*mul)<=mid){
			count++;
			if(count>=p){
				return true;
			}
			sum+=(arr[i]*mul);
			// cout << sum << " ";
			mul+=1;
		}
		// cout << count << endl;
	}
	return false;
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
	ll p;
	ll l;

	cin >> p;
	cin >> l;

	ll arr[l];
	ll low=0;
	ll high=INT_MAX;
	for(i=0;i<l;i++){
		cin >> arr[i];
	}
	sort(arr,arr+l,greater<ll>());
	ll ans=0;
	while(low<=high){
		ll mid=low+(high-low)/2;
		// cout << low << " " << mid << " " << high << endl;
		if(isValid(arr,l,mid,p)){
			ans=mid;
			high=mid-1;
		}else{
			low=mid+1;
		}
	}

	cout << ans << endl;


	return 0;
}
