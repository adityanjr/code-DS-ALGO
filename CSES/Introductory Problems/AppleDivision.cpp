// Divide array in two groups so that absolute difference between sums is minimal.
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (int i = 0; i < n; ++i)
#define forn(i,a,b) for (int i =a; i <b; ++i)
#define revforn(i,a,b) for (int i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
const int maxn=21;
ll a[maxn];
ll ans=1e18;
ll x=0,y=0;
int n;
void rec(int i)
{
    if(i==n)
    {
        ans=min(ans,abs(y-x));
        return;
    }
    x+=a[i];
    rec(i+1);
    x-=a[i];
    y+=a[i];
    rec(i+1);
    y-=a[i];
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rep(i,n)
    cin>>a[i];
    rec(0);
    cout<<ans;
    return 0;
}
