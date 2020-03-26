// https://code.google.com/codejam/contest/7254486/dashboard#s=p1&a=0

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

int main()
{
  freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  ll t=1;
  ll tc=1;
  s(t);
  while(t--){
    ll E,n;
    s2(E,n);
    vector<ll> dance(n);
    F(i,0,n-1)cin>>dance[i];
    sort(dance.begin(),dance.end());
    ll lo=0;
    ll hi=n-1;
    ll hon=0;
    ll ene=E;
    ll maxHon=0;
    while(lo<=hi){
      if(ene-dance[lo]>0){ene-=dance[lo++]; hon++; }
      else if(hon>0){ ene+=dance[hi--]; hon--; }
      else break;
      maxHon=max(maxHon,hon);
    }
    cout<<"Case #"<<tc++<<": "<<maxHon<<endl;
  }
  return 0;
 }