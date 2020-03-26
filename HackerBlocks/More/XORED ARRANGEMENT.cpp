// https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/when-the-integers-got-upset/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
 
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
ll n;
// dp[mask][first][second] gives the answer for the arrangement where only those
// integers are considered so far for which the bits are set in the mask and 
// the 'first' and 'second' represent numbers which were taken first and second 
//  in the given combination.
ll dp[5000][13][13];


vector<ll> ar,pos;


ll solveDP(ll mask,ll fr,ll sc){
  if(dp[mask][fr][sc]!=-1) return dp[mask][fr][sc];

  // po contains the number of set bits in the mask
  ll po = __builtin_popcountll(mask);

  // if all numbers have been considered, return 0
  if(po==n)return 0;

  
  ll ans=inf;
  // th represents the third number to be chosen after first 'fr' 
  // and second number 'sc',all from the last in the chosen arrangement,
  // have been considered
  for(ll th=0;th<n;th++){
    // if that number has already been considered, continue
    if((mask&(1<<th))!=0)continue;
    // take the xor of the last three numbers just taken and multiply it with
    // pos[po] which tells that the third number just chosen will be placed at
    // the position 'po' in the finally chosen subset.
    ans=min(ans,(ar[fr]^ar[sc]^ar[th])*pos[po] + solveDP(mask|(1<<th),sc,th));
  }
  dp[mask][fr][sc]=ans;
  return ans;
}


int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  ll t;
  s(t);
  while(t--){
    s(n);
    memset(dp,-1,sizeof(dp));
    ar = vector<ll>(n);
    pos = vector<ll>(n);
    
    F(i,0,n-1)cin>>ar[i];
    F(i,0,n-1)cin>>pos[i];
    
    if(n<3) { cout<<"0\n"; continue; }

    ll ans=inf;
    // i and j indicates the possible values of the first and second numbers 
    // which can be chosen in any possible arrangement of numbers
    for(ll i=0;i<n;i++){
      for(ll j=0;j<n;j++){
        if(i==j)continue;
        ans=min(ans,solveDP((1<<i)|(1<<j),i,j));
      }
    }
    p(ans);
  }
}