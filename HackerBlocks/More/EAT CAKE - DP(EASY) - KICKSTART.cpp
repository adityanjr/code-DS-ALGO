// https://code.google.com/codejam/contest/7254486/dashboard#s=p3&a=3

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

ll dp[20000];
ll solve(ll n){
  if(n<0)return (ll)INT_MAX;
  if(n==0)return 0;
  if(dp[n]!=-1)return dp[n];
  ll up = floor(sqrt(n));
  ll ans = (ll)INT_MAX;
  RF(i,up,1)ans=min(ans,1+solve(n-i*i));
  return dp[n]=ans;
}

int main()
{
  freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1,tc=1;
  s(t);
  memset(dp,-1,sizeof(dp));
  while(t--){
    ll n;
    s(n);
    ll ans = solve(n);
    cout<<"Case #"<<tc++<<": "<<ans<<endl;  
  }
  return 0;
 }