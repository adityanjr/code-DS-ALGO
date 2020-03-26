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
    vector<ll>ar(n+1,0);
    F(i,1,n)s(ar[i]);
    // dp[i] will represent the number of portals needed to move to the next room
    vector<ll>dp(n+1,0ll);
    // sum[i] will represent the cumulative sum of the number of portals needed to
    // move to the i+1th room from the first room.
    vector<ll>sum(n+1,0ll);
    dp[1]=2;
    sum[1]=2;
    F(i,2,n){
      // if the second portal leads to the same room, you can move to the next room using
      // just two portals, one for coming back to the same portal and the other one to 
      // move to the next portal.
      if(ar[i]==i)dp[i]=2;
      // Else The total number of portals needed will be equal to the number of portals
      // needed to move from i-1 th room to the ith room which is computed using cumulative
      // sum array.
      else dp[i]= 2+(sum[i-1]-sum[ar[i]-1]+mod)%mod;
      sum[i]=sum[i-1]+dp[i];
      sum[i]%=mod;
    }
    // finally sum[n] contains the total number of portals needed to move to the n+1th room 
    // from the first room which is the needed question.
    p(sum[n]);
  }
  return 0;
 }