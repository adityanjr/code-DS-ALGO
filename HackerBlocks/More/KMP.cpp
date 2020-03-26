
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

vector<int> preComputeLPS(string text){
  int sz = text.size();
  vector<int> lps;
  if(sz==0)return lps;
  lps = vector<int>(sz+1,0);

  int len=0;
  lps[0]=0;
  int i=1;
  while(i<sz){
    if(text[i]==text[len]){
      lps[i]=len+1;
      i++;
      len++;
    }else{
      if(len==0) lps[i++]=0;
      else{
        len=lps[len-1];
      }
    }
  }
  return lps;
}

void findOccurenceByKMP(string text, string pat){
  if(text.size()==0 or pat.size()==0)return;

  vector<int> lps = preComputeLPS(pat);
  int i=0;
  int j=0;
  int sz = text.size();
  int pat_sz = pat.size();
  while(i<sz){
    if(text[i]==pat[j]){
      i++;
      j++;
    }

    if(j==pat_sz){
      cout<<"Pattern found at index "<<i-j<<endl;
      j=lps[j-1];
    }else if(i<sz and pat[j]!=text[i]){
      
      if(j>0)j=lps[j-1];
      else i++;
    }
  }
  cout<<endl;
}

int main()
{
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    string text,pat;
    cin>>text>>pat;
    findOccurenceByKMP(text,pat);
  }
}
