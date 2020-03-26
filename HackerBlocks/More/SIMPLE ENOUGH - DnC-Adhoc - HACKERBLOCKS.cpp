// https://hack.codingblocks.com/contests/c/133/907

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

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
  	ll n,l,r;
  	s3(n,l,r);
  	// ar will store the binary breakdown of n in reverse order. therefore we are reversing it also later.
  	vector<bool>ar;
  	ll temp=n;
  	while(temp){
  		ar.push_back(temp&1);
  		temp>>=1;
  	}
  	reverse(ar.begin(), ar.end());
  	ll ans=0ll;
  	ll sz=(ll)ar.size();
  	for(ll i=0ll;i<sz;i++){
  		if(ar[i]){
  			ll lf = l-1ll;
  			ll rt = r;
  			ll firstOccurence = pow(2,i);
  			ll repeatsAfter = pow(2,i+1);

  			if(firstOccurence<=rt)
  				ans+=1ll + (rt- firstOccurence)/repeatsAfter;
  			if(firstOccurence<=lf)
  				ans-=1ll + (lf- firstOccurence)/repeatsAfter;
  		}
  	}
  	p(ans);
  }
  return 0;
 }