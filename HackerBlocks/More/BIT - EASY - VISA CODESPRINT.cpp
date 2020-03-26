// https://www.hackerrank.com/contests/visa-codesprint/challenges/fee-queries/problem
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

vector<ll> ar;
vector<ll> BIT;

void updateBit(ll ind,ll val){
  while(ind<5000001){
    BIT[ind]+=val;
    ind+=ind&-ind;
  }
}

ll RMQ(ll ind){
  ll ans=0ll;
  while(ind>0){
    ans+=BIT[ind];
    ind-=ind&-ind;
  }
  return ans;
}

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n,q;
    s2(n,q);
    ar.resize(n+5);
    BIT.resize(5000000+5,0);
    F(i,0,n-1){
      cin>>ar[i];
      updateBit(ar[i],1ll);
    }

    while(q--){
      string query;
      cin>>query;
      if(query=="count"){
        ll x;
        s(x); 
        cout<< RMQ(5000000)-RMQ(x-1)<<endl;
      }
      else{
        ll i,x;
        s2(i,x);
        updateBit(ar[i],-1ll);
        ar[i]=x;
        updateBit(ar[i],1ll);
      }
    }
  }
  return 0;
 }