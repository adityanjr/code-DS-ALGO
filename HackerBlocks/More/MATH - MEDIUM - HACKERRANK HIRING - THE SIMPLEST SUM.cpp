// https://www.hackerrank.com/contests/hackerrank-hiring-contest/challenges/the-simplest-sum

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

ll fun(ll a,ll b,ll k){
  ll ret=0ll;
  ll cumulative_sum=1ll;
  ll sum=1ll;
  ll mul=k;
  while(sum<=a){
    if((sum+mul)>a)break;
    sum+=mul;
    cumulative_sum+=sum;
    mul*=k;
    cumulative_sum%=mod;
  }
  ret+=(b-a+1ll)*cumulative_sum;
  ret%=mod;
  sum+=mul;
  while(sum<=b){
    ret+=((b-sum+1ll)%mod)*(sum%mod);
    ret%=mod;
    mul=mul*k;
    sum+=mul;
  }
  return ret;
}

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
    ll a,b,k;
    s3(k,a,b);
    cout<<fun(a,b,k)<<endl;
  }
  return 0;
 }