// https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/monk-in-the-magical-land/description/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 
#define ll long long int
// typedef __int128_t ll
 
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

ll mod = 1e9 + 7 ;
ll inf = 1e18 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ll t;
  cin>>t;
  while(t--){
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>K(n),C(m),Z(m);

    // Chose this data type as we need atleast 100 bits to keep track of 100 possible chests
    __int128_t one=1;

    // key[i] will contain the bit representation of the chests ith key can open
    vector<__int128_t>key(n,0);

    for(ll i=0;i<n;i++)cin>>K[i];
    for(ll i=0;i<m;i++)cin>>C[i];
    for(ll i=0;i<m;i++)cin>>Z[i];

    for(ll i=0;i<n;i++){
      for(ll j=0;j<m;j++){
        if(__gcd(K[i],C[j])>1){
          key[i]|=one<<j;
        }
      }
    }
    ll ans=-inf;
    // all possible combination of K keys from the given n are checked 
    for(ll mask=1;mask<(1<<n);mask++){
      if(__builtin_popcount(mask) > k)continue;
      
      // 'chests' contain the bit representation of the chests which K keys
      // (set bits in the mask)can together open.
      __int128_t chests=0;
      for(ll j=0;j<n;j++){
        if(mask&(1<<j)){
          chests|=key[j];
        }
      }
      ll sum=0;
      // Calculate the total treasure which can be obtained together from 
      // all the chests indicated by the set bits in the variable 'chest'
      for(ll z=0;z<m;z++){
        if(chests&(one<<z))sum+=Z[z];
      }
      ans=max(ans,sum);
    }
    p(ans);
  }
}