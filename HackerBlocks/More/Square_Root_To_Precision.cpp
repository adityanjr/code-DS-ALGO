#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	ll i,j,k,len,sum,count;
	string str;
	ll t;
	ll p;
	double n;
	cin >> n >> p;

	cout << setprecision(p);
   cout << fixed;

	ll low=1;
	ll high=n;
	double ans=1;
	while(low<=high){
		ll mid=(low+high)/2;
		if(mid*mid>n){
			high=mid-1;
		}
		else if(mid*mid<=n){
			ans=mid;
			low=mid+1;
		}
	}
	double dec=0.0;
	ll den=1;
	for(i=1;i<=p;i++){
		den=den*10;
		dec=1.0/(den);

		while(ans*ans<=n){
			ans+=dec;
		}
		if(ans*ans>n){
			ans-=dec;
		}
	}

	cout << ans << endl;


	return 0;
}
