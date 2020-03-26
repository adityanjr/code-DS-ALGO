// http://codeforces.com/problemset/problem/698/A

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

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n;
    s(n);
    vector<ll> ar(n+1);
    F(i,0,n-1)s(ar[i+1]);
    // dp[i][j] represents the maximum number of days Singham will NOT take rest till ith day 
    // if he does the jth activity :
    // j=0 if he is resting, j is 1 if he is giving contest,j is 2 if he is gymming .
    ll dp[n+1][3]={0};
    F(i,1,n){
      dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));
      if(ar[i]==1 or ar[i]==3)dp[i][1]=1+max(dp[i-1][0],dp[i-1][2]);
      if(ar[i]==2 or ar[i]==3)dp[i][2]=1+max(dp[i-1][0],dp[i-1][1]);
    }
    // Since we have found the complementary answer i.e. Maximum days Singham will not take rest,
    // we will subtract it with the total days to get the actual answer,i.e. Minimum days when 
    // Singham will take rest.
    p(n-max(dp[n][0],max(dp[n][1],dp[n][2])));
  }

  return 0;
 }