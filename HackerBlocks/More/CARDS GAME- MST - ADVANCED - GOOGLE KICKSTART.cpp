// https://code.google.com/codejam/contest/3254486/dashboard#s=p1&a=0

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
ll n;
vector<vector<pll>> adj;

ll prims(){
  priority_queue<pll,vector<pll>,greater<pll>> Q;
  
  vector<bool> vis(n+5,false);
  
  Q.push({0,1});
  ll ans=0ll;

  while(!Q.empty()){
    pll top = Q.top();
    Q.pop();
    ll node = top.second;
    ll cost = top.first;
    if(vis[node])continue;
    vis[node]=true;
    ans+=cost;
    F(i,0,adj[node].size()-1){
      ll ch = adj[node][i].first;
      ll wt = adj[node][i].second;
      if(vis[ch])continue;
      Q.push({wt,ch});
    }
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
    s(n);
    vector<ll>red(n+1),blue(n+1);
    adj.clear();
    adj.resize(n+4);
    F(i,1,n) cin>>red[i];
    F(i,1,n) cin>>blue[i];
    F(i,1,n){
      F(j,i+1,n){
        ll cost = min(red[i]^blue[j],red[j]^blue[i]);
        adj[i].pb({j,cost});
        adj[j].pb({i,cost});
      }
    }
    ll minCost = prims();
    cout<<"Case #"<<tc++<<": "<<minCost<<endl;
  }
  return 0;
 }