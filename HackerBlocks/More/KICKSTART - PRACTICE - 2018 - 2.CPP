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

/**************************CODE GOES HERE*********************************************/

ll helper(ll lev,ll k){
  if(lev==1)return 0ll;
  ll totChars=pow(2,lev)-1ll;
  if(k==(totChars+1ll)/2)return 0;
  if(k<=totChars/2) return helper(lev-1ll,k);
  ll posInSecondHalf=k-((totChars+1ll)/2);
  ll temp = (totChars/2) - posInSecondHalf + 1ll;
  return 1-helper(lev-1ll,temp);
}

ll findKthChar(ll k){
  if(k==1)return 0ll;
  ll power;
  for(power=1;power<=70;power++){
    if(k<=(pow(2,power)-1ll))break;
  }
  return helper(power,k);
}

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  ll tc=1;
  while(t--){
    ll k;
    s(k);
    ll ans=findKthChar(k);
    cout<<"Case #"<<tc++<<": "<<ans<<endl;
  }
  return 0;
 }