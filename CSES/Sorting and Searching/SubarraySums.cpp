// Number of Subarrays having sum equal to x
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define rep(i,n) for (int i = 0; i < n; ++i)
#define forn(i,a,b) for (int i =a; i <=b; ++i)
#define revforn(i,a,b) for (int i =a; i >=b; --i)
#define trav(a,x) for(auto & a : x)
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n>>x;
    ll a[n];
    rep(i, n)
    cin >> a[i];
    ll ans=0,s=0;
    map<ll,ll>mp;
    mp[0]=1;
    rep(i,n)
    {
        s+=a[i];
        ans+=mp[s-x];
        mp[s]++;
    }
    cout<<ans;
    return 0;
}