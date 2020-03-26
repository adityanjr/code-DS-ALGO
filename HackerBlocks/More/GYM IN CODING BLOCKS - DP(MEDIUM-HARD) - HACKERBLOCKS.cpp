// http://codeforces.com/contest/429/problem/B

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
 
#define ll long long int

#define s(x) scanf("%lld",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%lld\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/****************************************************************************/

ll dp[5][1005][1005];

int main()
{
  freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
  	ll n,m;
  	s2(n,m);
  	vector<vector<ll>> gym(n+5,vector<ll>(m+5,0ll));
  	memset(dp,0ll,sizeof(dp));
  	F(i,1,n){
  		F(j,1,m){
  			s(gym[i][j]);
  		}
  	}

  	// From top left to (i,j)
  	F(i,1,n){
  		F(j,1,m){
  			dp[1][i][j]=max(dp[1][i][j-1],dp[1][i-1][j])+gym[i][j];
  		}
  	}

  	// From (i,j) to bottom right
  	RF(i,n,1){
  		RF(j,m,1){
  			dp[2][i][j]=max(dp[2][i][j+1],dp[2][i+1][j])+gym[i][j];
  		}
  	}

  	// From bottom left to (i,j)
  	RF(i,n,1){
  		F(j,1,m){
  			dp[3][i][j]=max(dp[3][i][j-1],dp[3][i+1][j])+gym[i][j];
  		}
  	}

  	// From (i,j) to top right
  	F(i,1,n){
  		RF(j,m,1){
  			dp[4][i][j]=max(dp[4][i][j+1],dp[4][i-1][j])+gym[i][j];
  		}
  	}
  	ll ans=0ll;

  	F(i,2,n-1){
  		F(j,2,m-1){
  			// Path in which Prateek Bhaiya comes from top and Arnav Bhaiya comes from left to (i,j)
  			ans=max(ans,dp[1][i][j-1]+dp[2][i][j+1]+dp[3][i+1][j]+dp[4][i-1][j]);
  			
  			// Path in which Prateek Bhaiya comes from left and Arnav Bhaiya comes from bottom to (i,j)
  			ans=max(ans,dp[1][i-1][j]+dp[2][i+1][j]+dp[3][i][j-1]+dp[4][i][j+1]);
  		}
  	}
  	p(ans);
  }
  return 0;
 }