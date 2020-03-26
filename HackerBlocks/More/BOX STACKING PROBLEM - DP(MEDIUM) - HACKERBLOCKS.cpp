
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

// array to store a box as a three value tuple (length, breadth, height)
vector<pair<ll,pll>> dims;

// dp array to store the maximum height possible with ith box at top
vector<ll> maxHtPossibleWithIthBoxAtTop;

// list for storing all boxes over which ith box can be placed
vector<vector<ll>>adj;

// boolean array to prevent redundant computations
vector<bool>vis;

void dfs(ll i){
  vis[i]=true;

  ll ans=dims[i].first;
  for(ll j=0;j<adj[i].size();j++){
    if(!vis[adj[i][j]])dfs(adj[i][j]);
    ans=max(ans,maxHtPossibleWithIthBoxAtTop[adj[i][j]]+dims[i].first);
  }
  // Store the answer as done in dp and use it whenever ith box is needed
  maxHtPossibleWithIthBoxAtTop[i]=ans;
}

int main()
{
  // freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
  ll t=1;
  s(t);
  while(t--){
    ll n;
    s(n);
    dims.clear();
    maxHtPossibleWithIthBoxAtTop.clear();
    adj.clear();
    vis.clear();

    F(i,0,n-1){
      ll h,w,b;
      vector<ll>temp;
      s3(h,w,b);
      temp.pb(h);temp.pb(w);temp.pb(b);
      sort(temp.begin(), temp.end());
      h=temp[0];
      w=temp[1];
      b=temp[2];
      // Generate all possible boxes from the given box by just exchanging the height,width and length.
      // and store them in the dims[] array.
      dims.push_back({h,{w,b}});
      dims.push_back({w,{h,b}});
      dims.push_back({b,{h,w}});
    }

    
    adj.resize(dims.size());
    vis.resize(dims.size());

    maxHtPossibleWithIthBoxAtTop.resize(dims.size());

    for(ll i=0;i<dims.size();i++){
      for(ll j=0;j<dims.size();j++){
        if(i==j)continue;
        if(dims[i].second.first<dims[j].second.first){
          if(dims[i].second.second<dims[j].second.second)
            // means ith box can be placed over jth box.
            adj[i].push_back(j);
        }
      }
    }

    for(ll i=0;i<dims.size();i++){
      if(vis[i])continue;
      dfs(i);
    }

    ll ans=0;
    for(ll i=0;i<maxHtPossibleWithIthBoxAtTop.size();i++)
      ans=max(ans,maxHtPossibleWithIthBoxAtTop[i]);

    p(ans);
  }
}
