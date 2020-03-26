// https://www.hackerrank.com/contests/hackerrank-hiring-contest/challenges/winning-lottery-ticket/problem

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

// ll inf = 1e18;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/****************************************************************************/

int main()
{
  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    ll n;
    s(n);
    vector<int> maskVector;
    map<int,int> countMask;
    F(i,1,n){
      string str;
      cin>>str;
      int mask=0;
      ll sz=str.size();
      for(ll j=0;j<sz;j++){
        int shif = str[j]-'0';
        mask=mask|(1<<shif);
      }
      if(countMask[mask]!=0) countMask[mask]++;
      else {maskVector.pb(mask); countMask[mask]=1;}
    }
    
    long long int ans=0ll;
    if(countMask[1023]>0ll)ans+=(((countMask[1023]-1ll)*countMask[1023]))/2LL;

    n = maskVector.size();
    F(i,0,n-1){
      F(j,i+1,n-1){
        if((maskVector[i]|maskVector[j]) == (1023)){
          ans+=(long long int)countMask[maskVector[i]]*(long long int)countMask[maskVector[j]];
        }
      }
    }

    cout<<ans<<endl;
  }
  return 0;
 }