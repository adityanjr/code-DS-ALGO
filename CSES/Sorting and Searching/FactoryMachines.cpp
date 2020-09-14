// Binary Search
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
    int n,t;
    cin >> n>>t;
    int a[n];
    rep(i, n)
    {
        cin>>a[i];
    }
    ll l=1,r=1e18;
    while(l<r)
    {
        ll m=(l+r)>>1;
        ll res{};
        rep(i,n)
        {
            res+=min(m/a[i],(ll)1e9);
        }
        if(res<t)
            l=m+1;
        else
            r=m;
    }
    cout<<l;
    return 0;
}
