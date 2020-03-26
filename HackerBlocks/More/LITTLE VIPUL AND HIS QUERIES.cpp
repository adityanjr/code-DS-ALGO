// https://www.hackerearth.com/problem/algorithm/vaishu-and-queries/

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

ll dp[101][101][101]={0};

int main()
{
//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);
  ll t=1;
  //s(t);
  while(t--){
    ll n;
    s(n);
    ll rd[201]={0};
    ll bl[201]={0};

    F(i,1,n){
      string str;
      cin>>str;
      for(char ch:str){
        if(ch=='R')rd[i]++;
        else bl[i]++;
      }
    }

    
// dp[i][j][k] = maximum rows upto the ith row which can be mimicked if the person has
// j red and k blue balls.
// Concept is very simple: Either we mimick a row or we don't mimick a row, take the maximum one.    

    for(ll i=1;i<=n;i++){
      for(ll x=0;x<=100;x++){
        for(ll y=0;y<=100;y++){
          if(i==1){
            if(x>=rd[i] and y>=bl[i])dp[i][x][y]=1;
          }else{
            dp[i][x][y]=dp[i-1][x][y];
            if(x>=rd[i] and y>=bl[i])dp[i][x][y]=max(dp[i][x][y],1+dp[i-1][x-rd[i]][y-bl[i]]);
          }
        }
      }
    }

    ll q;
    s(q);
    while(q--){
      ll x,y;
      cin>>x>>y;
      cout<<dp[n][x][y]<<endl;
    }
  }
}
