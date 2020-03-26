// https://www.hackerrank.com/challenges/journey-to-the-moon

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

vector<ll> par;
vector<ll> lev;

ll findPar(ll ele){
  if(par[ele]==ele)return ele;
  return par[ele]=findPar(par[ele]);
}

void makeUnion(ll a, ll b){
  ll parA = findPar(a);
  ll parB = findPar(b);

  if(parA==parB)return;
  if(lev[parA]>=lev[parB]){
    par[parB]=parA;
    if(lev[parA]==lev[parB])lev[parA]++;
    return;
  }
  par[parA]=parB;
}

int main()
{
  // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  //s(t);
  while(t--){
    ll n,p;
    s2(n,p);

    par = vector<ll>(n+1);
    for(ll i=0;i<n;i++)par[i]=i;
    lev = vector<ll>(n+1,0);
  
    F(i,1,p){
      ll u,v;
      s2(u,v);
      makeUnion(u,v);
    }

    F(i,0,n-1)findPar(i);

    // F(i,0,n-1)cout<<"par[ "<<i<<" ] = "<< par[i]<<endl;

    vector<ll> freq(n,0);
    F(i,0,n-1){
      freq[par[i]]++;     
    }

    ll freqSz =  freq.size();
    // F(i,0,freqSz-1)cout<<"freq[ "<<i<<" ] = "<< freq[i]<<endl;
    // return 0;

    ll ans=0;
    
    vector<ll>dp(freqSz,0);
    for(ll i=1;i<freqSz;i++){
      dp[i]=freq[i-1]+dp[i-1];
      ans+=dp[i]*freq[i];
    }
    p(ans);
  }
}
