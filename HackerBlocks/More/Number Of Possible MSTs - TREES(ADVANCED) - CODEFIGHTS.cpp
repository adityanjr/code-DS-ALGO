// https://codefights.com/interview-practice/task/TJ7hGeey6JYNFjBBg/description

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
// ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/***********************************CODE GOES HERE***************************************/
#define ll long long int
const ll mod = 1e9 + 7;
vector<vector<double>> L,U,mat;

ll modPower(ll a,ll e){
  if(a==1)return 1ll;
  ll res=1ll;
  while(e>0){
    if(e%2 == 1)res=(res*a)%mod;
    a=(a*a)%mod;
    e=e/2;
  }
  return res;
}

void computeLU(){
  int n=mat.size();
  L=vector<vector<double>>(n,vector<double>(n,0.0));
  U=vector<vector<double>>(n,vector<double>(n,0.0));

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)L[i][j]=1.0;
      else if(i<j)L[i][j]=0.0;

      if(i<=j)U[i][j]=(double)mat[i][j];
      else if(i>j and mat[i][j]!=0.0){
        double multiple = 0.0;
        if(mat[j][j]!=0.0)multiple=(double)(mod-(((ll)mat[i][j]*modPower((ll)mat[j][j],(ll)mod-2ll))%mod));
        while(multiple<0)multiple+=mod;
        multiple=(double)multiple;
        for(int k=0;k<n;k++){
          mat[i][k]+=(double)((ll)((ll)multiple*(ll)mat[j][k])%mod);
          mat[i][k]=(double)((ll)mat[i][k]%mod);
        }
        U[i][j]=(double)mat[i][j];
        L[i][j]=(double)((double)mod-multiple);
      }else{
        U[i][j]=(double)mat[i][j];
      }
    }
  }
}


vector<vector<double>> adjMat;
int hierarchiesCount(int n, std::vector<std::vector<int>> respectList) {
  int edges=respectList.size();
  if(n<=2)return n;
  adjMat=vector<vector<double>>(n,vector<double>(n));
  for(int i=0;i<edges;i++){
    int u=respectList[i][0];
    int v=respectList[i][1];
    adjMat[u][v]=1.0;
    adjMat[v][u]=1.0;
  }

  for(int i=0;i<n;i++){
    double ct=0.0;
    for(int j=0;j<n;j++)if(adjMat[i][j]==1.0)ct=ct+1.0;
    adjMat[i][i]=ct;
    for(int j=0;j<n;j++)if(i!=j and adjMat[i][j]==1.0)adjMat[i][j]=(double)((double)mod-1.0);
  }

  mat=vector<vector<double>>(n-1,vector<double>(n-1));
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      mat[i-1][j-1]=adjMat[i][j];
    }
  }

  computeLU();

  ll res=1ll;
  for(int i=0;i<n-1;i++){
    res=(ll)(res*(ll)U[i][i])%mod;
    
  }
  return (int)(((ll)res*(ll)n)%mod);
}



int main(){
  freopen("input.txt","r",stdin);
  int n,edges;
  cin>>n;
  cin>>edges;
  vector<vector<int>>respect(edges,vector<int>(2));
  F(i,0,edges-1){
    int u,v;
    cin>>u>>v;
    respect[i][0]=u;
    respect[i][1]=v;
  }
  cout<<hierarchiesCount(n,respect)<<endl;
}
