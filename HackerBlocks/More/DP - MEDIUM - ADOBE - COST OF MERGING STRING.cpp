// https://www.hackerrank.com/contests/adobe-codiva/challenges/cost-of-merging-strings/problem
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
#define fio ios_base::sync_with_stdio(false)
 
#define ll int

#define s(x) scanf("%d",&x)
#define s2(x,y) s(x)+s(y)
#define s3(x,y,z) s(x)+s(y)+s(z)
 
#define p(x) printf("%d\n",x)
#define p2(x,y) p(x)+p(y)
#define p3(x,y,z) p(x)+p(y)+p(z)
#define F(i,a,b) for(ll i = (ll)(a); i <= (ll)(b); i++)
#define RF(i,a,b) for(ll i = (ll)(a); i >= (ll)(b); i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back

ll inf = 1e9;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/****************************************************************************/

ll dp[400][400][400];

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n,m,k;
    s3(n,m,k);
    string str1,str2;
    cin>>str1>>str2;
    str1="."+str1;
    str2="."+str2;

    if(k>min(n,m)){cout<<"-1\n"; break; }    

    F(i,0,n){
      F(j,0,m){
        F(len,0,k){
          dp[i][j][len]=inf;
          if(len==0)dp[i][j][len]=0;
          else if(i==0 or j==0)continue;
          else{
            dp[i][j][len]=dp[i-1][j-1][len-1]+((int)(str1[i]-'a')^(int)(str2[j]-'a'));
            dp[i][j][len]=min(dp[i][j][len],min(dp[i-1][j][len],dp[i][j-1][len]));
          }
        }
      }
    }
    cout<<dp[n][m][k]<<endl;
  }
  return 0;
 }