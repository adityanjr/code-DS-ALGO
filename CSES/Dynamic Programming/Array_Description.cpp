#include <bits/stdc++.h>
#define MOD 1000000007
#define INF INT_MAX
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(c) c.begin() , c.end()
#define gcd(m,n) __gcd(m,n)
#define lcm(m,n) (m*n)/gcd(m,n)
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL);
using namespace std;
 
 
int main(){
 
	int n,m;
	cin >> n >> m;
	int x[n];
	for (int i = 0; i < n ; i ++){
		cin >> x[i];
	}	
 
	ll dp[n][m+1];
 
	for (int i = 0 ; i < n; i ++){
		for (int j = 0 ; j <= m ; j ++){
			dp[i][j] = 0;
		}
	}
 
	if (x[0]){
		dp[0][x[0]] = 1;
	}else{
		for (int i = 1 ; i <= m ; i ++){
			dp[0][i] = 1;
		}
	}
 
	for (int i = 1; i < n; i ++){
		if (x[i]){
			dp[i][x[i]] = dp[i-1][x[i]];
			if (x[i] > 1){
				dp[i][x[i]] += dp[i-1][x[i] -1];
			}
 
			if (x[i] < m){
				dp[i][x[i]] += dp[i-1][x[i] + 1];
			}
			dp[i][x[i]] %= MOD;
		}else{
			for (int j = 1 ; j <= m ; j ++){
				dp[i][j] = dp[i-1][j];
				if (j > 1){
					dp[i][j] += dp[i-1][j -1];
				}
 
				if (j < m){
					dp[i][j] += dp[i-1][j + 1];
				}
				dp[i][j] %= MOD;
			}
		}
	}
 
	ll s =0;
	for (int i = 1 ; i <= m ; i ++){
		s = ( s+ dp[n-1][i])%MOD;
	}
 
	cout << s << endl;
}
