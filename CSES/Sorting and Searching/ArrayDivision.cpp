// Divide array in k subarrays so that maximum subarray sum is minimal.
// Binary Search
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
    ll n, k;
    cin >> n >> k;
    ll a[n];
    rep(i, n)
    cin >> a[i];
    auto check = [&](ll x)
    {
        ll s{}, div = 1;
        rep(i, n)
        {
            if(s + a[i] <= x)
                s += a[i];
            else
            {
                div++;
                s = a[i];
            }
        }
        return div;
    };
    ll l = *max_element(a,a+n), r = 1e18;
    while(l < r)
    {
        ll m = (l + r) >> 1;
        if(check(m) <= k)
            r = m;
        else
            l = m + 1;
    }
    cout << r << "\n";
    return 0;
}