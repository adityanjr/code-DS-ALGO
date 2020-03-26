
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



vector<pll>adj[100005];

// ret will contain the total travel distance (travelled one-sidedly) by the visitors , 
// that's why at the end we are multiplying by 2 as people from both sides are crossing 
// a particular edge.
ll ret=0;
ll n;

ll dfs(ll par, ll u){
  ll ans=1;
  for(ll i=0;i<adj[u].size();i++){
    ll v = adj[u][i].first;
    ll wt = adj[u][i].second;

    if(v==par)continue;

    // nodes will contain the total number of nodes present in the tree subrooted at child 'v'
    ll nodes = dfs(u,v);
    ret+=2*min(nodes,n-nodes)*wt;
    ans+=nodes;
  }
  // ans contains the total number of nodes present in the tree subrooted at node 'u'
  return ans;
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  ll tc=1;
  while(t--){
    ret=0;
    s(n);
    F(i,1,n)adj[i].clear();

    F(i,1,n-1){
      ll u,v,x;
      s3(u,v,x);
      adj[u].pb({v,x});
      adj[v].pb({u,x});
    }

    dfs(-1,1);
    cout<<"Case #"<<tc++<<": "<<ret<<endl;
  }
}