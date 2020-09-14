// Find maximum subarray sum of length in range [a,b]
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
    int n;
    ll a, b;
    cin >> n >> a >> b;
    ll c[n + 1];
    c[0] = 0;
    forn(i, 1, n)
    {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    set<pair<ll, int>>s;
    ll ans = -1e18;
    for(int i = 1; i <= n; i++)
    {
        if(i >= a)
            s.insert({c[i - a], i - a});
        if(s.size())
            ans = max(ans, c[i] - (*s.begin()).first);
        if(i >= b)
            s.erase({c[i - b], i - b});
    }
    cout << ans;
    return 0;
}