// http://codeforces.com/contest/920/problem/E

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

const ll maxi = 2e5 + 5;
ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/**************************CODE GOES HERE*********************************************/

unordered_map<int,bool> edge[maxi];
vector<ll>ans;
bitset<maxi> notVis;
ll k;
void dfs(ll src){
  notVis[src]=0;
  ans[k]++;
  for(int i=notVis._Find_first();i<notVis.size();i=notVis._Find_next(i)){
    if(edge[src][i]!=1)dfs(i);
  }
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n,e;
    s2(n,e);
    ans.resize(n+5);
    F(i,1,n)notVis[i]=1;
    F(i,1,e){
      ll u,v;
      s2(u,v);
      edge[u][v]=1;
      edge[v][u]=1;
    }
    k=0;
    F(i,1,n){
      if(notVis[i]){
        k++;
        dfs(i);
      }
    }
    sort(ans.rbegin(),ans.rend());
    cout<<k<<endl;
    RF(i,k-1,0)cout<<ans[i]<<" ";
  }
  return 0;
 }