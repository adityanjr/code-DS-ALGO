// https://www.hackerrank.com/contests/codeagon/challenges/happiness/problem

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
const ll lim = 5e5+5;

ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

vector<ll>adj[lim];
vector<pll>vec;
bool vis[lim];

void dfs(ll cur, ll par, ll &nodes, ll &edges){
  nodes++;
  edges+=adj[cur].size();
  vis[cur]=true;

  for(ll i=0;i<adj[cur].size();i++){
    ll child=adj[cur][i];
    if(child==par or vis[child])continue;
    dfs(child,cur,nodes,edges);
  }
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  //s(t);
  while(t--){
    ll n,m;
    s2(n,m);
    F(i,1,m){
      ll u,v;
      s2(u,v);
      adj[u].pb(v);
      adj[v].pb(u);
    }

    F(i,1,n){
      if(!vis[i]){
        ll nodes=0, edges=0;
        dfs(i,-1,nodes,edges);
        // cout<<i<<" "<<nodes<<" "<<edges/2<<endl;
        vec.pb({nodes,edges/2});
      }
    }

    ll ct=0;
    F(i,0,vec.size()-1){
      ll nodes=vec[i].first;
      ll edges=vec[i].second;
      if(edges>nodes-1){
        ct++;
        vec[i].second--;
        edges=vec[i].second;
        if(edges>nodes-1){
          ct++;
          break;
        }
        if(ct==2)break;
      }
    }

    if(ct<2){
      sort(vec.begin(), vec.end());
      F(i,0,vec.size()-1){
        ll edges=vec[i].second;
        if(edges>0){
          vec[i].first--;
          vec[i].second--;
          ct++;
          sort(vec.begin(), vec.end());
          i=0;
        }
        if(ct==2)break;
      }
    }

    ll ans=0; 
    F(i,0,vec.size()-1){
      ans+=(vec[i].first)*(vec[i].first-1);
    }
    p(ans);
  }
}
