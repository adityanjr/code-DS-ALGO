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

ll dp[1005][1005][15][2];
ll n,m;
string str1,str2;

// Note: when the flag is set, it means, that there is already some common substring which is being continued
// from the last call.
// if flag==1, 
//      dp[i][j][k][flag] = Maximum length of the disjoint subset of the required substring upto length of
//                          i for string s, j for string t and considering the total subsets needed to be k. 
ll solve(ll i,ll j,ll k,ll flag){

  // if k<0, then we can't use this configuration at all, so return Minimum possible value since we are maximising 
  // in the calling function.
  if(k<0)return INT_MIN;

  // if this condition is satisfied, then we can safely assume that required number of disjoint subsets have been already
  // formed and we can return 0.
  if((i>=n or j>=m) and k==0)return 0;

  // same as the first condition
  if((i>=n or j>=m) and k!=0)return INT_MIN;

  if(dp[i][j][k][flag] != -1)return dp[i][j][k][flag];

  // Choice 1: We are simply not comparing the s[i] and t[j] and trying to find other subsequences 
  ll ans = max(solve(i,j+1,k,0),solve(i+1,j,k,0));

  if(str1[i]==str2[j]){
    // Choice 2: since s[i] and t[j] are same and the flag is set, so we are continuing with the last substring itself.
    if(flag) ans=max(ans,1+solve(i+1,j+1,k,1));

    // Choice 3: Here, we have discontinued the previous common substring and started a new one, so k is decremented by 1.
    ans=max(ans,1+solve(i+1,j+1,k-1,1));
  }
  dp[i][j][k][flag]=ans;
  return ans;
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll k;
    memset(dp,-1,sizeof(dp));
    s3(n,m,k);
    cin>>str1>>str2;
    cout<<solve(0,0,k,0)<<endl;
  }
}