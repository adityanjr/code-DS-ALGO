// http://www.spoj.com/problems/DQUERY/

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

/**************************CODE GOES HERE*********************************************/
vector<ll>ar;
unordered_map<ll,ll> resmp;
vector<pair<pll,ll>> queries;
ll freq[1000000 + 5];
ll n;
ll sqrtn;

bool comp(pair<pll,ll> a,pair<pll,ll> b){
  if(a.first.first/sqrtn == b.first.first/sqrtn)return a.first.second<b.first.second;
  return (a.first.first/sqrtn)<(b.first.first/sqrtn);
}

int main()
{
  ios_base::sync_with_stdio(false);
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    s(n);
    sqrtn=sqrt(n);
    F(i,1,n){
      ll num;
      s(num);
      ar.pb(num);
    }
    ll q;
    s(q);
    F(i,1,q){
      ll lf,rt;
      s2(lf,rt);
      lf--;
      rt--;
      queries.pb({{lf,rt},i});
    }
    sort(queries.begin(), queries.end(),comp);
    ll start=-1;
    ll end=-1;
    ll ct=0ll;

    F(i,0,q-1){
      ll lf,rt;
      lf=queries[i].first.first;
      rt=queries[i].first.second;
      ll ind = queries[i].second;
      if(start==-1){
        start=lf;
        end=lf;
        freq[ar[lf]]++;
        ct++;
      }

      while(start>lf){
        start--;
        freq[ar[start]]++;
        if(freq[ar[start]]==1)ct++;
      }

      while(start<lf){
        freq[ar[start]]--;
        if(freq[ar[start]]==0)ct--;
        start++;
      }

      while(end<rt){
        end++;
        freq[ar[end]]++;
        if(freq[ar[end]]==1)ct++;
      }

      while(end>rt){
        freq[ar[end]]--;
        if(freq[ar[end]]==0)ct--;
        end--;
      }
      resmp[ind]=ct;
    }
    F(i,1,q)p(resmp[i]);
  }
  return 0;
 }