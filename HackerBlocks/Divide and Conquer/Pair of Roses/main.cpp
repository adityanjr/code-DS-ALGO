#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ll t,n,m;

	cin>>t;
	while(t--){
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}
		cin>>m;
		cout<<endl;
		sort(arr,arr+n);
		ll i=0;
		ll j=n-1;
         pair<int,int>pp={0,INT_MAX};
		while(i<j){
			if(arr[i]+arr[j]==m){
			      ll val = pp.second - pp.first;
                  ll val1 =  j - i;
				  if(val1<=val)
				     pp={i,j};
				     i++;
				     j--;
			}
			else if(arr[i]+arr[j]>m){
               j--;
			}
			else{
				i++;
			}
		}
		cout<<"Deepak should buy roses whose prices are "<<arr[pp.first]<<" and "<<arr[pp.second]<<".";
	}
	return 0;
}
