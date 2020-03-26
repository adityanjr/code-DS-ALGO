// https://code.google.com/codejam/contest/3254486/dashboard#s=p2&a=2

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

vector<vector<ll>> grid;
ll dp[50][50][50][50];

ll findMaxCoins(ll sr,ll er,ll sc,ll ec){
    if(sr>er or sc>ec)return 0;
    if(sr==er and sc==ec) return 0;
    if(dp[sr][er][sc][ec]!=-1)return dp[sr][er][sc][ec];

    ll mini=(ll)INT_MAX;
    F(r,sr,er){
        F(c,sc,ec){
            mini=min(mini,grid[r][c]);
        }
    }

    ll ans=mini;
    F(r,sr,er-1) ans=max(ans,mini+findMaxCoins(sr,r,sc,ec)+findMaxCoins(r+1,er,sc,ec));
    F(c,sc,ec-1) ans=max(ans,mini+findMaxCoins(sr,er,sc,c)+findMaxCoins(sr,er,c+1,ec));
    
    return dp[sr][er][sc][ec]=ans;
}

int main()
{
  freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  ll tc=1;
  s(t);
  while(t--){
    grid.clear();
    memset(dp,-1,sizeof(dp));
    ll r,c;
    s2(r,c);
    grid=vector<vector<ll>>(r+1,vector<ll>(c+1,0));
    F(i,1,r)
        F(j,1,c)
            s(grid[i][j]);
    
    ll ans = findMaxCoins(1,r,1,c);
    cout<<"Case #"<<tc++<<": "<<ans<<endl;  
    
  }
  return 0;
 }