
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


ll inf = 1e6+1;
ll mod = 1e9 + 7 ;
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}

int main()
{
    // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);
    ll t=1;
    //s(t);
    while(t--){
        ll n,k;
        s2(n,k);
        vector<ll>ar(n,0);
        for(ll i=0;i<n;i++)cin>>ar[i];
          // Keep two pointers
        ll lf=0,rt=0;
      // Best stores the maximum subset of consecutive integers found so far
        ll best=k;
        do{
          // while the gap between the coordinates represented by ar[lf] and ar[rt] is greater than k,increment the left pointer
            while(ar[rt]-ar[lf]-(rt-lf) > k)lf++;
            best=max(best,rt-lf+1+k);
            // Increment the right pointer anyway
            rt++;
        }while(rt<n);
        cout<<best<<endl;
    }
}
