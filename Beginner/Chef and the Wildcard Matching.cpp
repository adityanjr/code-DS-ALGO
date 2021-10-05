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

int main(){
	c_p_c();

	t(x){
		string x,y;
		cin>>x>>y;
		int n= x.length();
		int i=0;
		while(i<n){
			if(x[i]!=y[i]){
				if(x[i]!='?'&& y[i]!='?') break;
			}
			i++;
		}
		if(i==n) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}