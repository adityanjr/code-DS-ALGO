// https://www.hackerrank.com/contests/visa-codesprint/challenges/defines/submissions/code/1305168490

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
   // freopen("output.txt","w",stdout);
  ll t=1;
  // s(t);
  while(t--){
    string str;
    cin>>str;
    stack<string> st;
    bool fg=0;
    ll sz=str.size();
    RF(i,sz-1,0){
      if(str[i]=='i')st.push("int");
      else if(str[i]=='p'){
        sz=st.size();
        if(sz<2){fg=1; break;}
        else {
          string newstr="pair<";
          string astr = st.top(); st.pop();
          string bstr = st.top(); st.pop();
          newstr+=astr+","+bstr+">";
          st.push(newstr);
        }
      }
      else {fg=1; break;}
    }
    sz=st.size();
    if(fg==1 or sz>1 or st.top()=="int")cout<<"-1\n";
    else cout<<st.top()<<endl;
  }
  return 0;
 }