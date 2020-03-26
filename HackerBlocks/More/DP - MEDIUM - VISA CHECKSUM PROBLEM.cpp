// https://www.hackerrank.com/contests/visa-codesprint/challenges/visa-checksum/problem

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

ll dp[5000][600];
ll mo;

ll solve(ll sum,ll ind){
  
  if(sum<0)return 0ll;

  if(ind==0){
    if(sum==0)return 1ll;
    return 0ll;
  }

  if(dp[sum][ind]!=-1)return dp[sum][ind];
  ll numOfCards=0ll;
  for(ll i=0;i<10;i++){
    ll num=i;
    if(num%2 ==0){
      num=2*num;
      if(num>9)num-=9;
    }

    numOfCards+=solve(sum-num,ind-1);
    numOfCards%=mod;
  } 
  return dp[sum][ind]=numOfCards;
}

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  memset(dp,-1,sizeof(dp));
  while(t--){
    
    ll x;
    s2(x,mo);
    ll ans=0ll;
    for(ll sum=0ll;sum<=x*9;sum+=mo){
      ans+=solve(sum,x);
      ans%=mod;
    }  
    p(ans);
  }
  return 0;
 }