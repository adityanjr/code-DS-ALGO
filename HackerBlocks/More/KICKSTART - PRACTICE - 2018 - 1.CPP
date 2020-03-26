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

const int UP_LIM=5000;
int cum_sum[5050];

void updateBIT(int ind,int val){
  while(ind<=UP_LIM){
    cum_sum[ind]+=val;
    ind+=ind&-ind;
  }
}

int queryBIT(int ind){
  int ans=0;
  while(ind>0){
    ans+=cum_sum[ind];
    ind-=ind&-ind;
  }
  return ans;
}

int main()
{
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  ll tc=1;
  s(t);
  while(t--){
    ll n;
    memset(cum_sum,0,sizeof(cum_sum));
    s(n);
    F(i,1,n){
      ll st,en;
      s2(st,en);
      updateBIT(st,1);
      updateBIT(en+1,-1);
    }
    ll p;
    s(p);
    cout<<"Case #"<<tc++<<": ";
    while(p--){
      ll ind;
      s(ind);
      int ans = queryBIT(ind);
      cout<<ans<<" ";
    }
    cout<<endl;
  }
  return 0;
 }