// https://code.google.com/codejam/contest/7254486/dashboard#s=p2&a=2
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
 
#define ll long long int
#define ld  double

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
vector<vector<ld>> id;
vector<vector<ld>> matMul(vector<vector<ld>> mat1,vector<vector<ld>> mat2);

vector<vector<ld>> matExpo(vector<vector<ld>> grid,ll e){
  id = vector<vector<ld>>(n+2,vector<ld>(n+2,0.0));
  F(i,1,n+1)id[i][i]=1.0;

  if(e==0)return id;
  if(e==1)return grid;

  vector<vector<ld>>ans(id);
  while(e>0){
    if(e==1)ans=matMul(ans,grid);

    grid = matMul(grid,grid);
    e=e/2;
  }
  return ans;
}

vector<vector<ld>> matMul(vector<vector<ld>> mat1,vector<vector<ld>> mat2){
  vector<vector<ld>> fin(id);

  F(i,1,n+1){
    F(j,1,n+1){
      F(k,1,n+1){
        fin[i][j]+=mat1[i][k]*mat2[k][j];
      }
    }
  }
  return fin;
}

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  ll tc=1;
  s(t);
  while(t--){
    ll m,P;
    s3(n,m,P);
    ll dis[110][110];
  
    F(i,1,n){
      F(j,1,n){
        dis[i][j]=inf;
      }
    }    

    F(i,1,m){
      ll u,v,w;
      s3(u,v,w);
      dis[u][v]=w;
      dis[v][u]=w;
    }

    F(i,1,n)dis[i][i]=0;

    F(k,1,n){
      F(i,1,n){ 
        if(dis[i][k]==inf or i==k)continue;
        F(j,1,n){
          if(dis[k][j]==inf or j==k or i==j)continue;
          dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
      }
    }

    //  F(i,1,n){
    //   F(j,1,n){
    //     cout<<dis[i][j]<<" ";
    //   }
    //   cout<<endl;
    // } 

    vector<ll> dis_sum(n+1,0);
    F(i,1,n){
      dis_sum[i]=0ll;
      F(j,1,n){
        if(j==i)continue;
        dis_sum[i]+=dis[i][j];
      }
    }

    vector<vector<ld>>grid(n+2,vector<ld>(n+2,0.0));
    F(i,1,n+1){
      F(j,1,n+1){
        if(i==n+1 and j==i)grid[i][j]=1.0;
        else if(i==n+1)grid[i][j]=0.0;
        else if(j==n+1)grid[i][j]=(ld)((ld)dis_sum[i]/(ld)(n-1));
        else if(i!=j)grid[i][j]=(ld)((ld)1.0/(ld)(n-1));
        else grid[i][j]=0.0;
      }
    }

    // F(i,1,n+1){
    //   F(j,1,n+1){
    //     cout<<grid[i][j]<<" ";
    //     // printf("%L ",grid[i][j]);
    //   }
    //   cout<<endl;
    // }

    vector<vector<ld>> newGrid = matExpo(grid,P);
    cout.precision(6);
    cout<<std::fixed;
    cout<<"Case #"<<tc++<<": "<<newGrid[1][n+1]<<endl;
  }
  
  return 0;
 }