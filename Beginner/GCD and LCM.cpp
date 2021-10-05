#include<bits/stdc++.h>
using namespace std;

#define ll              long long
#define pb              push_back
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n)       int *arr=new int[n];
#define t(x)            int x; cin>>x; while(x--)
#define f(x,y)          for(int i=x; i<=y; i++)


void c_p_c(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int gcd(int a, int b){
	if (a==0) return b;
	return gcd(b%a, a);
}

int main(){
	c_p_c();

	t(x){
		ll a, b;
		cin>>a>>b;
		ll lcm = (a*b)/gcd(a,b);
		cout<<gcd(a,b)<<" "<<lcm<<endl;
	}

	return 0;
}