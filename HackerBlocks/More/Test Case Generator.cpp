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
  // freopen("input.txt","r",stdin);
   freopen("input.txt","w",stdout);
  ll t=1;
  
  srand(time(NULL));
  // t = 10;
  // s(t);
  // cout<<t<<endl;
  F(i,1,t){

    // ll n = ((ll)rand()*(ll)rand())%100000 + 1ll;
    // ll k = ((ll)rand()*(ll)rand())%100000 + 1ll;
    // ll x = ((ll)rand()*(ll)rand()*(ll)rand())%100000000 + 1ll;
    
    // ll c = rand()%1000 + 1;
    
    // ll T = (rand()*rand())%1000000000 + 1;
    // ll k = ((ll)rand()*(ll)rand())%5000000001 ;
    ll n=1;
    ll k=100000;
    // ll a=1;
    // ll b=1;
    // ll T=100000000;
    cout<<n<<" "<<k<<endl;
    ll inc=0ll;
    F(i,1,n){
      inc = inc+ rand()%100 + 1;
      if(inc>1000000){
        cout<<"sorry \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        return 0;
      }
      cout<<inc<<" ";
    }
    cout<<endl;
  }
  return 0;
 }
