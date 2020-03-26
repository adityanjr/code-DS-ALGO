// https://www.geeksforgeeks.org/construct-unique-matrix-n-x-n-input-n/

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

class SquareMatrix{
  vector<vector<ll>> mat;
  ll sz;

  void fillMatrix(ll i,ll j){
    ll toFill = 1;
    F(in,i,sz-1)mat[in][j]=toFill++;
    F(in,0,i-1)mat[in][j]=toFill++;
  }

public:
  SquareMatrix(ll n=0):sz(n){
    assert(n%2 != 0);
    mat = vector<vector<ll>>(n,vector<ll>(n,0));
  }

  void printMatrix(){
    F(i,0,sz-1){
      F(j,0,sz-1){
        cout<<mat[i][j]<<" ";
      }
      cout<<endl;
    }
  }

  void constructMatrix(){
    ll rt=sz-1;
    ll lf=0;
    F(i,0,sz-1){
      if(!(i&1)){
        fillMatrix(i,rt);
        rt--;
      }else{
        fillMatrix(i,lf);
        lf++;
      }
    }
  }
};

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n;
    s(n);
    SquareMatrix matrix(n);
    matrix.constructMatrix();
    matrix.printMatrix();
  }
  return 0;
 }