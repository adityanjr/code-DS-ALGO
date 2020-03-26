// https://codefights.com/interview-practice/task/kfus4H4CSZBjCukwo/solutions

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


#define pii pair<int,int>
vector<vector<pii>>adj;
vector<bool>vis;

int findMSTlength(int node){
  cout<<"Finding MST\n";
  unordered_map<int,int> nodeEdgeWt;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  nodeEdgeWt[node]=0;
  pq.push({0,node});
  int totLen=0;
  while(!pq.empty()){
    pii tp=pq.top();
    pq.pop();
    int par=tp.second;
    if(vis[par])continue;
    vis[par]=true;
    int parEdge=tp.first;
    cout<<par<<" "<<parEdge<<endl;
    totLen+=parEdge;
    for(int i=0;i<adj[par].size();i++){
      int child=adj[par][i].first;
      int wt=adj[par][i].second;
      if(vis[child])continue;
      if(nodeEdgeWt.find(child)==nodeEdgeWt.end()){
        nodeEdgeWt[child]=wt;
        pq.push({nodeEdgeWt[child],child});
      }else{
        if(nodeEdgeWt[child]>wt){
          nodeEdgeWt[child]=wt;
          pq.push({nodeEdgeWt[child],child});
        }
      }
    }
  }
  cout<<"Exiting MST\n";
  return totLen;
}

int networkWires(int n, std::vector<std::vector<int>> wires) {
  adj.resize(n);
  vis=vector<bool>(n,false);
  int sz=wires.size();
  for(int i=0;i<sz;i++){
    int u=wires[i][0];
    int v=wires[i][1];
    int wt=wires[i][2];
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(!vis[i]){
      int temp=findMSTlength(i);
      cout<<i<<" "<<temp<<endl;
      ans+=temp;
    }
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
    int n;
    cin>>n;
    vector<vector<int>> wires(n,vector<int>(3,0));
    for(int i=0;i<n;i++){
      int u,v,w;
      cin>>u>>v>>w;
      wires[i][0]=u;
      wires[i][1]=v;
      wires[i][2]=w;
    }
    cout<<networkWires(4,wires)<<endl;

  }
  return 0;
 }