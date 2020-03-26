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
    ll n;
    s(n);
    vector<ll> ar(n);
    F(i,0,n-1)cin>>ar[i];
    if(n==2)cout<<"Case #"<<tc++<<": "<<"YES\n";
    else if(n==2){
      if(ar[1]==1 or ar[1]==3)cout<<"Case #"<<tc++<<": "<<"YES\n";
      else cout<<"Case #"<<tc++<<": "<<"NO\n";
    }else{
      vector<ll>dupAr(ar);
      sort(dupAr.begin(),dupAr.end());
      ll dupLo=0;
      ll dupHi=n-1;
      ll st=(n-1)/2;
      bool fg=0;

      if(ar[st]==dupAr[dupLo])dupLo++;
      else if (ar[st]==dupAr[dupHi])dupHi--;
      else {cout<<"Case #"<<tc++<<": "<<"NO\n"; continue;}
      ll lo=st-1;
      ll hi=st+1;
      while(lo>=0 and hi<n and (dupHi-dupLo+1)>2){
        if(n%2 == 0){
          ll nex = ar[hi];
          if(nex==dupAr[dupLo])dupLo++;
          else if(nex == dupAr[dupHi])dupHi--;
          else {fg=1; break; }
          hi++;

          if(dupHi-dupLo+1 <=2 ) break;

          nex=ar[lo];
          if(nex==dupAr[dupLo])dupLo++;
          else if(nex == dupAr[dupHi])dupHi--;
          else {fg=1; break; }
          lo--;
        }else{

          ll nex=ar[lo];
          if(nex==dupAr[dupLo])dupLo++;
          else if(nex == dupAr[dupHi])dupHi--;
          else {fg=1; break; }
          lo--;

          if(dupHi-dupLo+1 <=2 ) break;

          nex = ar[hi];
          if(nex==dupAr[dupLo])dupLo++;
          else if(nex == dupAr[dupHi])dupHi--;
          else {fg=1; break; }
          hi++;
        }
      }
      if((dupHi-dupLo+1)==2)cout<<"Case #"<<tc++<<": "<<"YES\n";
      else cout<<"Case #"<<tc++<<": "<<"NO\n";
    }
  }
  return 0;
 }