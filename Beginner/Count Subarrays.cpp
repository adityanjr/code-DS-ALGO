#include<bits/stdc++.h>
using namespace std;

// Author - ADITYA SINGH (https://github.com/adityanjr)

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
		int n;
		cin>>n;
		mk(a,n+1);
		f(1,n){
			cin>>a[i];
		}
		int dp[100005]= {0};
		dp[1] = 1;
		for (int i = 2; i <= n; i++){

			if (a[i] < a[i - 1])
				dp[i] = 1;
			
			else{
				dp[i] = dp[i - 1] + 1;
			}
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++)
			ans += dp[i];
		cout << ans<< endl;
	}

	return 0;

}