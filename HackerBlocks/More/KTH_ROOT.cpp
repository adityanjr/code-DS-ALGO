#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

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

	cin >> t;

	while(t--){
		cin >> n >> k;
		ll low = 1;
		ll high = n;
		ll finalans=-1;
		if(n>=10000000000){
			low=1;
			high=10000000000;
		}
		while(low<=high){
			ll mid=(low+high)/2;
			ll ans=1;
			for(i=1;i<=k;i++){
				ans=ans*mid;
				if(ans>n){
					high = mid-1;
					break;
				}
			}
			if(ans<=n){
				finalans=mid;
				low=mid+1;
			}
		}
		cout << finalans << endl;
	}


	return 0;
}
