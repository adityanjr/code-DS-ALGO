// https://www.hackerrank.com/contests/hourrank-25/challenges/maximum-palindromes/problem
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

const ll inf = 1e18;
const ll mod = 1e9 + 7 ;
const ll maxi = 1e5 + 5;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

/**************************CODE GOES HERE*********************************************/

ll modExpo(ll a,ll e){
  if(a<=1)return a;
  ll ans=1ll;
  while(e>0){
    if(e&1)ans=(ans*a)%mod;
    e>>=1;
    a=(a*a)%mod;
  }  
  return ans;
}

ll fact[maxi];
ll rfact[maxi];
ll freq[30][maxi];

void init(string str){

  memset(freq,0,sizeof(freq));

  fact[0]=1ll;
  rfact[0]=1ll;
  for(ll i=1;i<=maxi;i++){
    fact[i]=(fact[i-1]*i)%mod;
    rfact[i]=modExpo(fact[i],mod-2);
  }

  str="."+str;
  ll sz=str.size();
  for(ll i=1;i<sz;i++){
    freq[str[i]-'a'][i]= (freq[str[i]-'a'][i-1]+1ll)%mod;

    for(char ch='a';ch<='z';ch++){
      if(str[i]!=ch) {
        freq[ch-'a'][i]= freq[ch-'a'][i-1];
      }
    }
  }
}
int main()
{

  freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  while(t--){
    string str;
    cin>>str;
    init(str);
    ll q;
    s(q);
    while(q--){
      ll l,r;
      s2(l,r);
      ll ans=1ll;
      ll sum=0ll;
      ll odd=0ll;
      for(char ch='a';ch<='z';ch++){
        ll cur = freq[ch-'a'][r]-freq[ch-'a'][l-1];
        if((cur%2) == 1)odd++;
        ans=(ans*rfact[(cur/2)])%mod;
        sum+=(cur/2ll);
      }
      ans=(ans*max(1ll,odd))%mod;
      ans=(ans*fact[sum])%mod;
      cout<<ans<<endl;
    }
  }
  return 0;
 }