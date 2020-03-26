// https://www.hackerrank.com/contests/codeagon/challenges/counting-princess-presents

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
vector<vector<pll>>adj;
vector<bool>isSpecial;

bool dfs_markSpecial(ll node, ll par=-1){
  bool ret=0;
  F(i,0,adj[node].size()-1){
    ll child = adj[node][i].first;
    ll spec = adj[node][i].second;
    if(child==par)continue;
    bool res = dfs_markSpecial(child,node);
    if(spec==0)spec=res;
    isSpecial[child]=spec;
    ret = ret or spec;
  }
  return ret;
}

ll dfs(ll node,ll par=-1){
  ll ret=1ll;
  F(i,0,adj[node].size()-1){
    ll child = adj[node][i].first;
    ll spec = adj[node][i].second;
    if(child==par or isSpecial[child])continue;
    ret=(ret*(1+dfs(child,node)))%mod;
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
    ll n;
    s(n);
    adj=vector<vector<pll>>(n+5);
    isSpecial=vector<bool>(n+5,false);
    ll specNode=-1;
    F(i,1,n-1){
      ll u,v,g;
      s3(u,v,g);
      adj[u].pb({v,g});
      adj[v].pb({u,g});
      if(isSpecial[v]==0)isSpecial[v]=g;
      if(isSpecial[u]==0)isSpecial[u]=g;
      if(g==1)specNode=u;
    }
   
   // make a connected component of all the special nodes and those that fall between them
    if(specNode!=-1)dfs_markSpecial(specNode);

    vector<ll> res;
    F(i,1,n){
      if(isSpecial[i])res.pb(dfs(i));
    }
    ll ans=1ll;
    ll sz=res.size();

    F(i,0,sz-1)ans=(ans*res[i])%mod;
    p(ans);
  }
  return 0;
 }