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
    ll n,k;
    s2(n,k);
    // dp[i] represents the number possible number of ways Singham can have laddu if
    // i laddus are presented to him.
    vector<ll>dp(100005,0);
    // cum_sum[i] represents the cumulative sum of all the ways in which Singham can
    // have laddu for all number of laddus less than equal to i
    vector<ll>cum_sum(100005,0);
    dp[0]=1ll;
    F(i,1,100000){
      if(i<k)dp[i]=1ll;
      else dp[i]=(dp[i-1]+dp[i-k])%mod;
      cum_sum[i]=(cum_sum[i-1]+dp[i])%mod;
    }
    while(n--){
      ll a,b;
      s2(a,b);
      ll ans=(cum_sum[b]-cum_sum[a-1]+mod)%mod;
      p(ans);
    }
  }
  return 0;
 }