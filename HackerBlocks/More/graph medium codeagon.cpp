//https://www.hackerrank.com/contests/codeagon/challenges/counting-princess-presents/problem

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
set<pll>special;
ll dpi[100005];
ll dpe[100005];
ll fin;

void init(){
  F(i,0,100000)adj[i].clear();
  fin=1ll;
  special.clear();
}

void dfs1(ll orig, ll par){
  ll sz=adj[orig].size();

  dpi[orig]=1;
  dpe[orig]=0;
  for(ll i=0;i<sz;i++){
    ll child=adj[orig][i].first;
    if(child==par)continue;
    dfs1(child,orig);
    dpi[orig]*=(1+dpi[child])%mod;
    dpe[orig]+=(dpi[child]+dpe[child])%mod;
    dpi[orig]%=mod; dpe[orig]%=mod;
  }
}


bool dfs2(ll orig,ll par){
  bool ret=false;
  for(ll i=0;i<adj[orig].size();i++){
    ll child=adj[orig][i].first;
    if(child==par)continue;
    if(adj[orig][i].second==1)ret=true;
    bool ch = dfs2(child,orig);
    if(ch||adj[orig][i].second){
      special.insert({child,orig});
      special.insert({orig,child});
    }
    ret=ret||ch;
  }
  return ret;
}

void dfs3(ll orig, ll par){
  for(ll i=0;i<adj[orig].size();i++){
    ll child=adj[orig][i].first;
    if(child==par)continue;
    if(special.find({child,orig})==special.end())fin*=(dpi[child]+1)%mod;
    else dfs3(child,orig);
    fin%=mod;
  }
}


int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
    init();
    ll n;
    s(n);
    ll orig=1;
    bool pres=0;
    F(i,1,n-1){
      ll u,v,g;
      s3(u,v,g);
      adj[u].push_back({v,g});
      adj[v].push_back({u,g});
      if(g==1){
        pres=1;
        orig=u;
      }
    }

    // for(auto ele:special)cout<<ele.first<<" "<<ele.second<<endl;

    dfs1(orig,-1);
    if(!pres){
      ll ans=(dpi[orig]+dpe[orig])%mod;
      cout<<ans<<endl;
    }
    else{
      dfs2(orig,-1);
      dfs3(orig,-1);
      cout<<fin<<endl;
    }
  }
}
