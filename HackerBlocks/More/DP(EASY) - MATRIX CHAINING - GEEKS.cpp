// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0

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

vector<ll> dim;
ll n;

ll dp[105][105];

ll solve(ll lf,ll rt){
  if(dp[lf][rt]!=-1)return dp[lf][rt];
  ll ans=(ll)INT_MAX;
  F(i,lf+1,rt-1){
    ans=min(ans,solve(lf,i)+solve(i,rt)+dim[lf]*dim[i]*dim[rt]);
  }
  if(ans==INT_MAX) ans=0ll;
  return dp[lf][rt]=ans;
}


int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
    memset(dp,-1,sizeof(dp));
    s(n);
    dim.resize(n+5);
    F(i,1,n)s(dim[i]);
    p(solve(1,n));

  }
  return 0;
 }