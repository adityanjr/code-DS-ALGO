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

int compare(int a, int b){
	return a<=b;
}

int main(){
	c_p_c();

	int n; cin>>n;
	int even=0, odd=0;
	f(0,n-1){
		int x;
		cin>>x;
		if(x%2==0) even++;
		else odd++;
	}
	if(even>odd) cout<<"READY FOR BATTLE";
	else cout<<"NOT READY";

	return 0;
}