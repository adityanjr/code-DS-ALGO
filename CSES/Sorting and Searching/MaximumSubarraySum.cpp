// Find max subarray sum of length greater than zero.
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
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll ans=-1e18;
    ll maxi=-1e18;
    rep(i,n)
    {
        maxi=max(maxi+a[i],a[i]);
        ans=max(ans,maxi);
    }
    cout<<ans;
    return 0;
}
