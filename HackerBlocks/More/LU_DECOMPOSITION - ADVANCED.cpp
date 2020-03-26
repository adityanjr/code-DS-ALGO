
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

/***********************************CODE GOES HERE***************************************/
vector<vector<double>> L,U,mat;

void computeLU(){
  int n=mat.size();
  L=vector<vector<double>>(n,vector<double>(n,0.0));
  U=vector<vector<double>>(n,vector<double>(n,0.0));

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)L[i][j]=1.0;
      else if(i<j)L[i][j]=0.0;

      if(i<=j)U[i][j]=mat[i][j];
      else if(i>j and mat[i][j]!=0.0){
        double multiple = 0.0;
        if(mat[j][j]!=0.0)multiple=-mat[i][j]/mat[j][j];
        for(int k=0;k<n;k++){
          mat[i][k]+=multiple*mat[j][k];
        }
        U[i][j]=mat[i][j];
        L[i][j]=-multiple;
      }else{
        U[i][j]=mat[i][j];
      }
    }
  }
}

int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n;
    s(n);
    mat=vector<vector<double>>(n,vector<double>(n,0.0));
    F(i,0,n-1){
      F(j,0,n-1){
        cin>>mat[i][j];
      }
    }
    computeLU();
    
    F(i,0,n-1){
      F(j,0,n-1){
        cout<<L[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
    F(i,0,n-1){
      F(j,0,n-1){
        cout<<U[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
 }

// ---------------- INPUTS AND OUTPUTS -------------------//

// 3
// 2 4 -4
// 1 -4 3
// -6 -9 5

// ans:
// 1 0 0 
// 0.5 1 0 
// -3 -0.5 1 

// 2 4 -4 
// 0 -6 5 
// 0 0 -4.5 

// -------------


// 3
// 1 4 -3
// -2 8 5
// 3 4 7

// ans: 

// 1 0 0 
// -2 1 0 
// 3 -0.5 1 

// 1 4 -3 
// 0 16 -1 
// 0 0 15.5

// ----------------


// 4
// 3 -7 -2 2
// -3 5 1 0
// 6 -4 0 -5
// -9 5 -5 12

// ans:
// 1 0 0 0 
// -1 1 0 0 
// 2 -5 1 0 
// -3 8 3 1 

// 3 -7 -2 2 
// 0 -2 -1 2 
// 0 0 -1 1 
// 0 0 0 -1 

// -----------------