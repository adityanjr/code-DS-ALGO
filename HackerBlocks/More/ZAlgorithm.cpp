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

vector<int> computeZArray(string str){
  int lf=0;
  int rt=0;
  vector<int> Z;
  int sz=str.size();
  Z.resize(sz);
  Z[0]=0;
  for(int i=1;i<sz;i++){
      if(i>rt){
          lf=rt=i;
          while(rt<sz and str[rt]==str[rt-lf])rt++;
          Z[i]=rt-lf;
          rt--;
      }else{
          if(Z[i-lf]<rt-i+1)Z[i]=Z[i-lf];
          else{
              lf=i;
              while(rt<sz and str[rt]==str[rt-lf])rt++;
              Z[i]=rt-lf;
              rt--;
          } 
      }
  }
  return Z;
}

vector<int> ZAlgo(string str,string pat){
  int n=str.size();
  int m=pat.size();
  vector<int> ret;
  if(m>n)return ret; 
  str=pat+"$"+str;

  vector<int> ZArray = computeZArray(str);
  for(int i=m+1;i<m+n+1;i++){
    if(ZArray[i]==m)ret.push_back(i-m-1);
  }
  return ret;
}
int main()
{
   freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    string str;
    string pat;
    cin>>str>>pat;
    vector<int> matchedIndicesList = ZAlgo(str,pat);
    cout<<"The string contains the pattern at the following indices(0-based): \n";
    int sz=matchedIndicesList.size();
    for(int i=0;i<sz;i++)cout<<matchedIndicesList[i]<<" ";
  }
  return 0;
 }

 