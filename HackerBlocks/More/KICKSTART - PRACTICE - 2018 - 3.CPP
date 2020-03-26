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
    unordered_map<string,string>ump_places;
    unordered_map<string,int>ump_count;

    F(i,1,n){
      string u,v;
      cin>>u>>v;
      ump_places[u]=v;
      ump_count[u]++;
      ump_count[v]++;
    }
    unordered_map<string,int>::iterator it=ump_count.begin();
    string source,dest;
    while(it!=ump_count.end()){
      string city=it->first;
      ll count=it->second;
      if(count==1){
        if(ump_places.find(city)==ump_places.end())dest=city;
        else source=city;
      }
      it++;
    }
    cout<<"Case #"<<tc++<<": ";
    string city=source;
    while(city!=dest){
      cout<<city<<"-"<<ump_places[city]<<" ";
      city=ump_places[city];
    }
    cout<<endl;

  }
  return 0;
 }